#include "../include/memory_manager.hpp"
#include "../include/new_delete_overrides.hpp"
#include "../include/printer.hpp"
#include "../include/classes.hpp"

void run() {
	GARDEN_CLASS garden;

	garden.plantTree();

	print(garden);

	TREE_CLASS* tree = garden.getTreePointer(0);

	for(unsigned int i = 0; i < 10; i += 1)
		tree -> growthTree();
	print(garden);

	for(unsigned int i = 0; i < 5; i += 1)
		tree -> fadeTree();
	print(garden);

	tree -> harvestTree(3);
	print(garden);
}

int main() {
	run(); //so that objects allocated on stack in run() will be freed and report_leaks won't falsly claim leaks

	return memory_manager::report_leaks();
}
