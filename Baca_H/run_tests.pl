#!/usr/bin/env perl
use File::Temp qw(tempdir);
use File::Basename;
use Time::HiRes qw(usleep time);
use POSIX ":sys_wait_h";


#check required files
die "Plik z kodem powinien nazywać się POLYNOMIAL.cpp\n" unless -f "POLYNOMIAL.cpp";

#macos malloc fix
if (`uname` =~ /Darwin/) {
	$ENV{MallocNanoZone} = 0;
}

#workspace setup
my $dir = tempdir("/tmp/baca_XXXXXXXX", CLEANUP => 1);
system("mkdir $dir/bins");

system("cp -r tests/src $dir/src");
system("cp -r tests/io $dir/io");
system("cp -r tests/times $dir/times");

system("cp POLYNOMIAL.cpp $dir/POLYNOMIAL.cpp");

#compile tests
foreach my $test (<$dir/src/*.cpp>) {
	my $test_name = basename($test, ".cpp");
	print "[\033[34mINFO\033[0m]  COMPILING $test_name.cpp\n";

	my $compile_cmd = "g++ -std=c++11 -ggdb -Wall -Wextra -Wno-comment -Wno-self-assign-overloaded -Wshadow -Wformat=2 -pedantic -pedantic-errors -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector -o $dir/bins/$test_name.x $dir/src/$test_name.cpp";

	my $compile_status = system($compile_cmd);
	if ($compile_status != 0) {
		print "Compilation failed for $test_name\n";
		exit 1;
	}
}

#runtime
foreach my $exe (<$dir/bins/*.x>) {
	my $test_name = basename($exe, '.x');
	my $time_file = "$dir/times/$test_name.time";
	my $io_file   = "$dir/io/$test_name.out";
	my $tmp_out   = "$dir/tmp.out";

	my $time_limit_ms = -f $time_file ? int(`cat $time_file`) : undef;

	my $pid = fork();
	if (!defined $pid) {
		die "Fork failed";
	}

	my $start_time = time();
	if ($pid == 0) {
		open(STDOUT, '>', $tmp_out) or die "Can't redirect stdout";
		exec($exe);
		exit 1;
	}

	my $timed_out = 0;
	while (1) {
		my $elapsed_ms = (time() - $start_time) * 1000;

		my $kid = waitpid($pid, WNOHANG);
		if ($kid > 0) {
			last; # child exited
		}

		if (defined $time_limit_ms && $elapsed_ms >= $time_limit_ms) {
			kill 9, $pid;
			waitpid($pid, 0);
			$timed_out = 1;
			last;
		}

		usleep(10_000);
	}

	if ($timed_out) {
		print "[\033[35mTLE\033[0m] ! $test_name\n";
		next;
	}

	if ($? != 0) {
		print "[\033[0;31mRTE\033[0m] ! $test_name\n";
		next;
	}

	my $diff = system("diff -q $tmp_out $io_file > /dev/null");
	if ($diff == 0) {
		print "[\033[0;32mOK\033[0m]    $test_name\n";
	} else {
		print "[\033[0;91mANS\033[0m] ! $test_name\n";
	}
}
