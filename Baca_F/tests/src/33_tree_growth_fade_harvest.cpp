#include "../include/memory_manager.hpp"
#include "../include/new_delete_overrides.hpp"
#include "../include/printer.hpp"
#include "../include/classes.hpp"

void run() {
	TREE_CLASS tree;

	for(unsigned int i = 0; i < 20; i += 1)
		tree.growthTree();

	print(tree);

	BRANCH_CLASS* branch1 = tree.getBranchPointer(15);

	branch1 -> growthBranch();
	branch1 -> growthBranch();
	branch1 -> growthBranch();
	branch1 -> growthBranch();

	FRUIT_CLASS* fruit1 = branch1 -> getFruitPointer(4);

	fruit1 -> growthFruit();
	fruit1 -> growthFruit();
	fruit1 -> growthFruit();

	print(tree);

	branch1 = NULL;
	fruit1 = NULL;

	for(unsigned int i = 0; i < 8; i += 1)
		tree.fadeTree();

	BRANCH_CLASS* branch2 = tree.getBranchPointer(6);

	print(tree);

	FRUIT_CLASS* fruit2 = branch2 -> getFruitPointer(2);
	fruit2 -> pluckFruit();

	branch2 -> growthBranch();
	branch2 -> growthBranch();
	branch2 -> growthBranch();
	branch2 -> growthBranch();

	FRUIT_CLASS* fruit3 = branch2 -> getFruitPointer(4);
	fruit3 -> growthFruit();
	fruit3 -> growthFruit();
	fruit3 -> growthFruit();

	print(tree);

	tree.harvestTree(5);

	print(tree);
}

int main() {
	run(); //so that objects allocated on stack in run() will be freed and report_leaks won't falsly claim leaks

	return memory_manager::report_leaks();
}
