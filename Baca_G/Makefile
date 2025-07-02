SHELL := /bin/sh

all:
	echo "Compiling file runner.cpp"; \
	cp source.cpp tests/source.cpp; \
	$$(cat .compiler) $$(cat .flags) -o main.x tests/runner.cpp tests/helpers/memory_manager.cpp tests/helpers/new_delete_overrides.cpp; \
	rm tests/source.cpp

prod:
	cp source.cpp tests/source.cpp; \
	$$(cat .compiler) -O3 -fvisibility=hidden -g0 -o main.x tests/runner.cpp tests/helpers/memory_manager.cpp tests/helpers/new_delete_overrides.cpp; \
	rm tests/source.cpp

test:
	perl -f check.pl; \
	perl -f run_tests.pl

clean:
	rm -rf main.x main.x.dSYM

submit:
	baca submit --no-save --task-id $$(cat .taskid) --file source.cpp;

refresh:
	baca refresh
