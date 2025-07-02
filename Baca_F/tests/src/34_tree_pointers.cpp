#include "../include/memory_manager.hpp"
#include "../include/new_delete_overrides.hpp"
#include "../include/printer.hpp"
#include "../include/classes.hpp"

#include <cassert>

void run() {
	GARDEN_CLASS* garden = new GARDEN_CLASS();

	garden -> plantTree();

	for(unsigned int i = 0; i < 10; i += 1)
		garden -> growthGarden();

	TREE_CLASS* tree = garden -> getTreePointer(0);

	GARDEN_CLASS* tree_parrent = tree -> getGardenPointer();
	assert(tree_parrent == garden);

	delete garden;
	garden = NULL;
	tree_parrent = NULL;
	tree = NULL;


	TREE_CLASS* standalone_tree = new TREE_CLASS();

	GARDEN_CLASS* standalone_tree_parrent = standalone_tree -> getGardenPointer();

	assert(standalone_tree_parrent == NULL);

	delete standalone_tree;
	standalone_tree = NULL;
}

int main() {
	run(); //so that objects allocated on stack in run() will be freed and report_leaks won't falsly claim leaks

	return memory_manager::report_leaks();
}
