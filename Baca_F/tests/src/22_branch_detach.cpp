#include "../include/memory_manager.hpp"
#include "../include/new_delete_overrides.hpp"
#include "../include/printer.hpp"
#include "../include/classes.hpp"

void run() {
	TREE_CLASS* tree = new TREE_CLASS();

	for(unsigned int i = 0; i < 10; i += 1)
		tree -> growthTree();

	print(tree);

	BRANCH_CLASS* branch = tree -> getBranchPointer(6);

	print(branch);

	BRANCH_CLASS* branch_detached = new BRANCH_CLASS(*branch);

	print(branch_detached);

	branch_detached -> growthBranch();
	branch_detached -> growthBranch();
	branch_detached -> growthBranch();

	print(tree);
	print(branch);
	print(branch_detached);

	delete tree;
	tree = NULL;
	branch = NULL;

	print(branch_detached);

	branch_detached -> fadeBranch();
	branch_detached -> fadeBranch();

	print(branch_detached);

	delete branch_detached;
	branch_detached = NULL;
}

int main() {
	run(); //so that objects allocated on stack in run() will be freed and report_leaks won't falsly claim leaks

	return memory_manager::report_leaks();
}
