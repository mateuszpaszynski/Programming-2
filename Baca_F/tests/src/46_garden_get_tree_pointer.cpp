#include "../include/memory_manager.hpp"
#include "../include/new_delete_overrides.hpp"
#include "../include/printer.hpp"
#include "../include/classes.hpp"

#include <cassert>

void run() {
	GARDEN_CLASS garden;

	for(unsigned int i = 0; i < 20; i += 1)
		garden.plantTree();

	for(unsigned int i = 7; i < 14; i += 1)
		garden.extractTree(i);

	print(garden);

	assert(garden.getTreePointer(7) == NULL);

	assert(garden.getTreePointer(9) == NULL);

	assert(garden.getTreePointer(13) == NULL);

	assert(garden.getTreePointer(20) == NULL);

	garden.extractTree(0);
	garden.extractTree(2);
	garden.extractTree(4);

	assert(garden.getTreePointer(4) == NULL);

	assert(garden.getTreePointer(2) == NULL);

	assert(garden.getTreePointer(0) == NULL);
}

int main() {
	run(); //so that objects allocated on stack in run() will be freed and report_leaks won't falsly claim leaks

	return memory_manager::report_leaks();
}
