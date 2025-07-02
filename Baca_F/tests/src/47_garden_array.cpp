#include "../include/memory_manager.hpp"
#include "../include/new_delete_overrides.hpp"
#include "../include/printer.hpp"
#include "../include/classes.hpp"

#define ARRAY_SIZE 32

void run() {
	GARDEN_CLASS* gardens = new GARDEN_CLASS[ARRAY_SIZE];

	for(unsigned int i = 0; i < ARRAY_SIZE; i += 1)
		for(unsigned int j = 0; j < i; j += 1)
			gardens[i].plantTree();

	for(unsigned int i = 0; i < ARRAY_SIZE; i += 1)
		for(unsigned int j = 0; j < i; j += 1)
			gardens[i].growthGarden();

	for(unsigned int i = 0; i < ARRAY_SIZE; i += 1)
		print(gardens[i]);

	delete[] gardens;
	gardens = NULL;
}

int main() {
	run(); //so that objects allocated on stack in run() will be freed and report_leaks won't falsly claim leaks

	return memory_manager::report_leaks();
}
