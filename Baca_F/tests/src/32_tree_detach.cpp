#include "../include/memory_manager.hpp"
#include "../include/new_delete_overrides.hpp"
#include "../include/printer.hpp"
#include "../include/classes.hpp"

void run() {
	GARDEN_CLASS* garden = new GARDEN_CLASS();

	garden -> plantTree();

	for(unsigned int i = 0; i < 10; i += 1)
		garden -> growthGarden();

	print(garden);

	TREE_CLASS* tree = garden -> getTreePointer(0);

	print(tree);

	TREE_CLASS* tree_detached = new TREE_CLASS(*tree);

	print(tree_detached);

	tree_detached -> growthTree();
	tree_detached -> growthTree();
	tree_detached -> growthTree();
	tree_detached -> growthTree();

	print(garden);
	print(tree);
	print(tree_detached);

	delete garden;
	garden = NULL;
	tree = NULL;

	print(tree_detached);

	tree_detached -> fadeTree();
	tree_detached -> fadeTree();
	tree_detached -> fadeTree();
	tree_detached -> fadeTree();

	print(tree_detached);

	delete tree_detached;
	tree_detached = NULL;
}

int main() {
	run(); //so that objects allocated on stack in run() will be freed and report_leaks won't falsly claim leaks

	return memory_manager::report_leaks();
}
