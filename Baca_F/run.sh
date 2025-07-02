#!/bin/bash
mkdir -p wyniki
./run_tests.pl 2>wyniki/err.txt |grep -v 'COMPILING' > wyniki/out.txt
grep 'OK' wyniki/out.txt>wyniki/ok.txt
grep 'ANS' wyniki/out.txt>wyniki/ans.txt
grep 'RTE' wyniki/out.txt >wyniki/rte.txt
grep 'MEM' wyniki/err.txt > wyniki/mem.txt
grep 'TLE' wyniki/out.txt >wyniki/tle.txt
echo "OK: $(wc -l < wyniki/ok.txt)"
echo "ANS: $(wc -l < wyniki/ans.txt)"
echo "RTE: $(wc -l < wyniki/rte.txt)"
echo "MEM: $(wc -l < wyniki/mem.txt)"
echo "TLE: $(wc -l < wyniki/tle.txt)"
zip source.cpp.zip garden.cpp garden.hpp tree.cpp tree.hpp branch.cpp branch.hpp fruit.cpp fruit.hpp
