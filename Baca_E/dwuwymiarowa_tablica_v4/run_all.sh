#!/bin/sh
if ! [ -f "main.c" ]; then
	echo "Plik z kodem powinien nazywać się main.c"
	exit 1
fi

if [ "$(uname)" = "Darwin" ]; then
	export MallocNanoZone=0
fi

DIR=$(mktemp -d /tmp/baca_XXXXXXXX);
mkdir $DIR/files
cp tests/files/filesums.md5 $DIR/files/filesums.md5
cp tests/files/pan_tadeusz.bin $DIR/files/pan_tadeusz.bin
cp main.c $DIR/main.c
cp -r tests/io $DIR/io

echo "[\033[34mINFO\033[0m]  COMPILING main.c"
gcc -std=c99 -ggdb -Wall -Wextra -Wno-comment -Wshadow -Wformat=2 -pedantic -pedantic-errors -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector -o $DIR/main.x $DIR/main.c

if [ $? -ne 0 ]; then
	exit 1
fi
cd $DIR/files
for test in $DIR/io/*.in; do
	($DIR/main.x < $test > $DIR/tmp.out 2>/dev/null) > /dev/null 2>&1
	if [ $? -ne 0 ]; then
		echo "[\033[0;31mRTE\033[0m] ! " $(basename $test '.in')
	elif diff $DIR/tmp.out "${test%.in}.out" > /dev/null; then
		echo "[\033[0;32mOK\033[0m]    " $(basename $test '.in')
	else
		echo "[\033[0;91mANS\033[0m] ! " $(basename $test '.in')
	fi
done

md5sum -c filesums.md5 > /dev/null 2>&1

if [ $? -eq 0 ]; then
	echo "[\033[0;32mOK\033[0m]     90_file_sums"
else
	echo "[\033[0;91mANS\033[0m] !  90_file_sums"
fi

cd - > /dev/null
rm -rf $DIR
