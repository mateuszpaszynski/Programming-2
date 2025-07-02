#!/usr/bin/env perl
use strict;
use warnings;
use File::Temp qw(tempdir);
use File::Basename;
use File::Copy;
use POSIX ":sys_wait_h";
use Time::HiRes qw(usleep time);

# === Required files ===
my @required_files = qw(fruit.hpp fruit.cpp branch.hpp branch.cpp tree.hpp tree.cpp garden.hpp garden.cpp);
foreach my $file (@required_files) {
    if (! -f $file) {
        print "Brak pliku $file\n";
        exit 1;
    }
}

# === macOS memory zone tweak ===
if (`uname` =~ /Darwin/) {
	$ENV{MallocNanoZone} = 0;
}

# === Create temp dir ===
my $dir = tempdir("/tmp/baca_XXXXXXXX", CLEANUP => 1);

# === Copy test files ===
system("cp -r tests/include $dir/include");
system("cp -r tests/helpers $dir/helpers");
system("cp -r tests/src $dir/src");
system("cp -r tests/io $dir/io");
system("cp -r tests/times $dir/times");

# === Copy solution files ===
foreach my $file (@required_files) {
    copy($file, "$dir/$file") or die "Copy failed: $!";
}

# === Make bins dir ===
mkdir("$dir/bins") or die "Cannot create bin dir";

# === Compile each test ===
opendir(my $dh, "$dir/src") or die "Can't open src dir";
my @tests = grep { /\.cpp$/ } readdir($dh);
closedir($dh);

foreach my $test (@tests) {
    my $test_name = basename($test, '.cpp');
    print "[\033[34mINFO\033[0m]  COMPILING $test_name.cpp\n";

    my $cmd = "g++ -std=c++98 -ggdb -Wall -Wextra -Wno-vla -Wno-comment -Wno-unused -Wshadow -Wformat=2 -pedantic -pedantic-errors -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector $dir/branch.cpp $dir/fruit.cpp $dir/garden.cpp $dir/tree.cpp $dir/helpers/printer.cpp $dir/helpers/memory_manager.cpp $dir/helpers/new_delete_overrides.cpp $dir/src/$test -o $dir/bins/$test_name.x";

    my $ret = system($cmd);
    if ($ret != 0) {
        print "Compilation failed for $test_name\n";
        exit 1;
    }
}

# === Run tests ===
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
        exit 1; # exec failed
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

        usleep(10_000); # 10ms polling
    }

    if ($timed_out) {
        print "[\033[35mTLE\033[0m] ! $test_name\n";
        next;
    }

    my $exit_status = $? >> 8;
    if ($exit_status != 0) {
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
