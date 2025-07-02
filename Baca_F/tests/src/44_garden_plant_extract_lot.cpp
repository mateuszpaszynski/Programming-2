#include "../include/memory_manager.hpp"
#include "../include/new_delete_overrides.hpp"
#include "../include/printer.hpp"
#include "../include/classes.hpp"

#define LOT_SIZE 1000000

void run() {
	GARDEN_CLASS garden;

	//forward
	for(unsigned int i = 0; i < LOT_SIZE; i += 1)
		garden.plantTree();

	for(unsigned int i = 0; i < LOT_SIZE; i += 1)
		garden.extractTree(i);

	print(garden);


	//backward
	for(unsigned int i = 0; i < LOT_SIZE; i += 1)
		garden.plantTree();

	for(unsigned int i = LOT_SIZE; i > 0; i -= 1)
		garden.extractTree(i - 1);

	print(garden);


	//forward batches
	for(unsigned int i = 0; i < LOT_SIZE; i += 1)
		garden.plantTree();

	for(unsigned int batch = 0; batch < LOT_SIZE / 100; batch += 1)
		for(unsigned int i = 100; i > 0; i -= 1)
			garden.extractTree(batch * 100 + i - 1);

	print(garden);


	//backward batches
	for(unsigned int i = 0; i < LOT_SIZE; i += 1)
		garden.plantTree();

	for(unsigned int batch = LOT_SIZE / 100; batch > 0; batch -= 1)
		for(unsigned int i = 0; i < 100; i += 1)
			garden.extractTree((batch - 1) * 100 + i);

	print(garden);
}

int main() {
	run(); //so that objects allocated on stack in run() will be freed and report_leaks won't falsly claim leaks

	return memory_manager::report_leaks();
}
