#include "../include/memory_manager.hpp"
#include "../include/new_delete_overrides.hpp"
#include "../include/printer.hpp"
#include "../include/classes.hpp"

void run() {
	TREE_CLASS tree;
	BRANCH_CLASS branch;

	for(unsigned int i = 0; i < 20; i += 1)
		branch.growthBranch();
	branch.cutBranch(10);
	branch.getFruitPointer(2) -> pluckFruit();

	tree.cutTree(0);
	for(unsigned int i = 0; i < 10; i += 1)
		tree.growthTree();

	tree.getBranchPointer(3) -> cutBranch(0);
	tree.cloneBranch(&branch);

	print(tree);
	print(branch);

	tree.getBranchPointer(3) -> fadeBranch();
	tree.getBranchPointer(3) -> fadeBranch();
	tree.getBranchPointer(3) -> fadeBranch();
	tree.getBranchPointer(3) -> fadeBranch();
	tree.getBranchPointer(3) -> fadeBranch();

	print(tree);
	print(branch);


	tree.cutTree(0);
	for(unsigned int i = 0; i < 10; i += 1)
		tree.growthTree();

	tree.getBranchPointer(6) -> cutBranch(0);
	tree.cloneBranch(&branch);

	print(tree);
	print(branch);

	tree.getBranchPointer(6) -> fadeBranch();
	tree.getBranchPointer(6) -> fadeBranch();
	tree.getBranchPointer(6) -> fadeBranch();
	tree.getBranchPointer(6) -> fadeBranch();
	tree.getBranchPointer(6) -> fadeBranch();

	print(tree);
	print(branch);


	tree.cutTree(0);
	for(unsigned int i = 0; i < 10; i += 1)
		tree.growthTree();

	tree.getBranchPointer(9) -> cutBranch(0);
	tree.cloneBranch(&branch);

	print(tree);
	print(branch);

	tree.getBranchPointer(9) -> fadeBranch();
	tree.getBranchPointer(9) -> fadeBranch();
	tree.getBranchPointer(9) -> fadeBranch();
	tree.getBranchPointer(9) -> fadeBranch();
	tree.getBranchPointer(9) -> fadeBranch();

	print(tree);
	print(branch);


	tree.cutTree(0);
	for(unsigned int i = 0; i < 10; i += 1)
		tree.growthTree();

	tree.cloneBranch(&branch);

	print(tree);
	print(branch);
}

int main() {
	run(); //so that objects allocated on stack in run() will be freed and report_leaks won't falsly claim leaks

	return memory_manager::report_leaks();
}
