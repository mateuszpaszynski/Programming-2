#include "../include/memory_manager.hpp"
#include "../include/new_delete_overrides.hpp"
#include "../include/printer.hpp"
#include "../include/classes.hpp"

void run() {
	GARDEN_CLASS* garden = new GARDEN_CLASS();

	garden -> plantTree();
	garden -> plantTree();
	garden -> plantTree();
	garden -> plantTree();

	TREE_CLASS* tree0 = garden -> getTreePointer(0);
	TREE_CLASS* tree1 = garden -> getTreePointer(1);
	TREE_CLASS* tree2 = garden -> getTreePointer(2);
	TREE_CLASS* tree3 = garden -> getTreePointer(3);

	for(unsigned int i = 0; i < 10; i += 1)
		tree0 -> growthTree();

	for(unsigned int i = 0; i < 20; i += 1)
		tree1 -> growthTree();

	for(unsigned int i = 0; i < 30; i += 1)
		tree2 -> growthTree();

	for(unsigned int i = 0; i < 40; i += 1)
		tree3 -> growthTree();

	garden -> harvestGarden(10);

	print(garden);

	GARDEN_CLASS* garden_copy = new GARDEN_CLASS(*garden);

	garden -> extractTree(2);
	garden -> extractTree(3);

	print(garden);
	print(garden_copy);

	delete garden;
	garden = NULL;
	tree0 = NULL;
	tree1 = NULL;
	tree2 = NULL;
	tree3 = NULL;

	garden_copy -> fadeGarden();
	garden_copy -> fadeGarden();
	garden_copy -> fadeGarden();
	garden_copy -> fadeGarden();
	garden_copy -> fadeGarden();

	print(garden_copy);

	delete garden_copy;
	garden_copy = NULL;
}

int main() {
	run(); //so that objects allocated on stack in run() will be freed and report_leaks won't falsly claim leaks

	return memory_manager::report_leaks();
}
