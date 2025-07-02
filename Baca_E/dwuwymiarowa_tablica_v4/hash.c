//		AUTOR: KAROL PESZEK
//		WSZLEKIE PRAWA ZASTRZEZONE
//
//		PROGRAMOWANIE 2
//		PROGRAM POMOCNICZY DO ZADANIA E - DWUWYMIAROWA TABLICA DYNAMICZNA

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const char instructions[][4] = { "AFR", "ALR", "AFC", "ALC", "IBR", "IAR", "IBC", "IAC", "SWR", "SWC", "DFR", "DLR", "DFC", "DLC", "RMR", "RMC", "RMB", "ISB", "WRF", "RDF", "PRT", "END" };

unsigned char hash(const char operation[4], unsigned char a0, unsigned char a1, unsigned char a2) {
	return a0 * operation[0] + a1 * operation[1] + a2 * operation[2];
}

unsigned char test_hash_collision(unsigned char a0, unsigned char a1, unsigned char a2) {
        unsigned char hash_map[256];
        for(unsigned short i = 0; i < 256; i = i + 1)
                hash_map[i] = 0;

        for(unsigned short i = 0; i < sizeof(instructions)/sizeof(instructions[0]); i = i + 1) {
                unsigned char h = hash(instructions[i], a0, a1, a2);
                if(hash_map[h])
                        return 1;
                hash_map[h] = 1;
        }

        return 0;
}

unsigned char get_random_value() {
        return rand() % 256;
}

int main() {
	srand((unsigned int)time(NULL));
	unsigned char a1, a2, a3;
	do {
			a1 = get_random_value();
			a2 = get_random_value();
			a3 = get_random_value();
	} while(test_hash_collision(a1, a2, a3));

	printf("unsigned char hash(const char operation[4]) {\n\treturn 0x%02x * operation[0] + 0x%02x * operation[1] + 0x%02x * operation[2];\n}\n", a1, a2, a3);

    return 0;
}
