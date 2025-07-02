#!/bin/sh

if ! [ -f "main.c" ]; then
	echo "Plik z kodem powinien nazywać się main.c"
	exit 1
fi

if [ -f ".allowed_includes" ]; then
	includes=$(grep -E '^\s*#\s*include\s*[<"].*[>"]' main.c)
	echo "$includes" | while read -r line; do
		header=$(echo "$line" | sed -E 's/^[[:space:]]*#[[:space:]]*include[[:space:]]*[<"]([^>"]+)[>"].*/\1/')

		if [ -z "$header" ]; then
			continue
		fi

		if ! grep -qFx "$header" ".allowed_includes"; then
			echo "[\033[0;33mINC\033[0m] ! FORBIDDEN HEADER: '$header'"
		fi
	done
fi

if [ -f ".forbidden_sequences" ]; then
	while read -r sequence; do
		if [ -z "$sequence" ]; then
			continue
		fi

		if grep -q "$sequence" "main.c"; then
			echo "[\033[0;33mSEQ\033[0m] ! FORBIDDEN SEQUENCE: '$sequence'"
		fi
	done < ".forbidden_sequences"
fi
