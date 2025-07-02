#!/usr/bin/env perl
use strict;
use warnings;

my @files = qw(fruit.hpp fruit.cpp branch.hpp branch.cpp tree.hpp tree.cpp garden.hpp garden.cpp);

# Check all files exist
foreach my $file (@files) {
    unless (-f $file) {
        print "Brak pliku $file\n";
        exit 1;
    }
}

# Load allowed includes if present
my %allowed_includes;
if (-f ".allowed_includes") {
    open(my $ai, "<", ".allowed_includes") or die "Cannot open .allowed_includes: $!";
    while (my $line = <$ai>) {
        chomp $line;
        $allowed_includes{$line} = 1 if $line ne '';
    }
    close $ai;
}

# Load forbidden sequences if present
my @forbidden_sequences;
if (-f ".forbidden_sequences") {
    open(my $fs, "<", ".forbidden_sequences") or die "Cannot open .forbidden_sequences: $!";
    while (my $line = <$fs>) {
        chomp $line;
        push @forbidden_sequences, $line if $line ne '';
    }
    close $fs;
}

# Analyze each file
foreach my $file (@files) {
    open(my $fh, "<", $file) or die "Cannot open $file: $!";

    while (my $line = <$fh>) {
        chomp $line;

        # Check includes
        if (%allowed_includes && $line =~ /^\s*#\s*include\s*[<"](.*?)[>"]/) {
            my $header = $1;
            if (!$allowed_includes{$header}) {
                print "[\033[0;33mINC\033[0m] ! FORBIDDEN HEADER: '$header'\n";
            }
        }

        # Check forbidden sequences
        foreach my $seq (@forbidden_sequences) {
            if (index($line, $seq) != -1) {
                print "[\033[0;33mSEQ\033[0m] ! FORBIDDEN SEQUENCE: '$seq'\n";
            }
        }
    }

    close $fh;
}
