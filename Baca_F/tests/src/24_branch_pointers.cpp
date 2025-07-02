#include "../include/memory_manager.hpp"
#include "../include/new_delete_overrides.hpp"
#include "../include/printer.hpp"
#include "../include/classes.hpp"

#include <cassert>

void run() {
	TREE_CLASS* tree = new TREE_CLASS();

	for(unsigned int i = 0; i < 10; i += 1)
		tree -> growthTree();

	BRANCH_CLASS* branch = tree -> getBranchPointer(6);

	TREE_CLASS* branch_parrent = branch -> getTreePointer();

	assert(branch_parrent == tree);

	delete tree;
	tree = NULL;
	branch_parrent = NULL;
	branch = NULL;


	BRANCH_CLASS* standalone_branch = new BRANCH_CLASS();

	TREE_CLASS* standalone_branch_parrent = standalone_branch -> getTreePointer();

	assert(standalone_branch_parrent == NULL);

	delete standalone_branch;
	standalone_branch = NULL;
}

int main() {
	run(); //so that objects allocated on stack in run() will be freed and report_leaks won't falsly claim leaks

	return memory_manager::report_leaks();
}
