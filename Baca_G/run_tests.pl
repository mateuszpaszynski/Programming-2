#!/usr/bin/env perl
use File::Temp qw(tempdir);
use File::Basename;
use Time::HiRes qw(usleep time);
use POSIX ":sys_wait_h";


#check required files
die "Plik z kodem powinien nazywać się source.cpp\n" unless -f "source.cpp";

#macos malloc fix
if (`uname` =~ /Darwin/) {
	$ENV{MallocNanoZone} = 0;
}

#workspace setup
my $dir = tempdir("/tmp/baca_XXXXXXXX", CLEANUP => 1);

system("cp -r tests/io $dir/io");
system("cp -r tests/times $dir/times");
system("cp -r tests/include $dir/include");
system("cp -r tests/helpers $dir/helpers");
system("cp tests/runner.cpp $dir/runner.cpp");

system("cp source.cpp $dir/source.cpp");

#compile exec
print "[\033[34mINFO\033[0m]  COMPILING runner.cpp\n";

my $compile_cmd = "g++ -std=c++98 -ggdb -Wall -Wextra -Wno-comment -Wshadow -Wformat=2 -pedantic -pedantic-errors -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector -o $dir/runner.x $dir/runner.cpp $dir/helpers/memory_manager.cpp $dir/helpers/new_delete_overrides.cpp";
my $compile_status = system($compile_cmd);
exit 1 if $compile_status != 0;

#runtime
foreach my $infile (<$dir/io/*.in>)  {
	my $basename = basename($infile, '.in');
	my $outfile = "$dir/io/$basename.out";
	my $timefile = "$dir/times/$basename.time";
	my $timeout_ms = -f $timefile ? int(`cat $timefile`) : undef;
	my $output_tmp = "$dir/tmp.out";

	my $pid = fork();
	die "Fork failed" unless defined $pid;
	my $start_time = time();

	if ($pid == 0) {
		open(STDIN,  '<', $infile)	  or die "Can't redirect input";
		open(STDOUT, '>', $output_tmp)  or die "Can't redirect output";
		open(STDERR, '>', '/dev/null'); # Suppress error output
		exec("$dir/runner.x");
		exit 1;
	}

	my $timed_out = 0;
	while (1) {
		my $elapsed = (time() - $start_time) * 1000;

		my $res = waitpid($pid, WNOHANG);
		if ($res > 0) {
			last;
		}

		if (defined $timeout_ms && $elapsed >= $timeout_ms) {
			kill 9, $pid;
			waitpid($pid, 0);
			$timed_out = 1;
			last;
		}

		usleep(10_000); # Poll every 10ms
	}

	if ($timed_out) {
		print "[\033[35mTLE\033[0m] ! $basename\n";
		next;
	}

	my $exit_code = $? >> 8;
	if ($exit_code != 0) {
		print "[\033[0;31mRTE\033[0m] ! $basename\n";
		next;
	}

	my $diff = system("diff -q $output_tmp $outfile > /dev/null");
	if ($diff == 0) {
		print "[\033[0;32mOK\033[0m]	$basename\n";
	} else {
		print "[\033[0;91mANS\033[0m] ! $basename\n";
	}
}
