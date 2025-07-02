#include "../include/memory_manager.hpp"
#include "../include/new_delete_overrides.hpp"
#include "../include/printer.hpp"
#include "../include/classes.hpp"

#define ARRAY_SIZE 256

void run() {
	FRUIT_CLASS* fruits = new FRUIT_CLASS[ARRAY_SIZE];

	for(unsigned int i = 0; i < ARRAY_SIZE; i += 1)
		for(unsigned int j = 0; j < i; j += 1)
			fruits[i].growthFruit();

	for(unsigned int i = 0; i < ARRAY_SIZE; i += 1)
		print(fruits[i]);

	delete[] fruits;
	fruits = NULL;
}

int main() {
	run(); //so that objects allocated on stack in run() will be freed and report_leaks won't falsly claim leaks

	return memory_manager::report_leaks();
}
