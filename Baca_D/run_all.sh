#!/bin/sh

if ! [ -f Sum.cpp ]; then
	echo "Brak pliku Sum.cpp"
	exit 1
fi

if ! [ -f Mult.cpp ]; then
	echo "Brak pliku Mult.cpp"
	exit 1
fi

if ! [ -f Operation.cpp ]; then
	echo "Brak pliku Operation.cpp"
	exit 1
fi

DIR=$(mktemp -d /tmp/baca_XXXXXXXX);

cp -r tests/include $DIR/include
cp -r tests/mult $DIR/mult
cp -r tests/sum $DIR/sum
cp -r tests/src $DIR/src

cp ./Mult.cpp $DIR/include/Mult.cpp
cp ./Sum.cpp $DIR/include/Sum.cpp
cp ./Operation.cpp $DIR/include/Operation.cpp

mkdir $DIR/bins

for test in $DIR/src/*.cpp; do
	TEST_NAME=$(basename $test '.cpp')
	echo "[\033[34mINFO\033[0m]  COMPILING $TEST_NAME.cpp"
	g++ -ggdb -Wall -Wextra -Wno-vla -Wno-comment -Wno-unused -Wshadow -Wformat=2 -pedantic -pedantic-errors -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector -o $DIR/bins/$TEST_NAME.elf $DIR/src/$TEST_NAME.cpp $DIR/include/Mult.cpp $DIR/include/Sum.cpp $DIR/include/Operation.cpp
	if [ $? != 0 ]; then
		rm -rf $DIR
		exit 1
	fi
done


for exe in $DIR/bins/mult*; do
	TEST_NAME=$(basename $exe '.elf')
	for io in $DIR/mult/*.in; do
		IO_NAME=${io%.in}
		TEST_NAME=$(basename $exe '.elf')/$(basename $io '.in')

		$exe $TEST_NAME $IO_NAME
	done
done
for exe in $DIR/bins/sum*; do
	TEST_NAME=$(basename $exe '.elf')
	for io in $DIR/sum/*.in; do
		IO_NAME=${io%.in}
		TEST_NAME=$(basename $exe '.elf')/$(basename $io '.in')

		$exe $TEST_NAME $IO_NAME
	done
done

rm -rf $DIR
