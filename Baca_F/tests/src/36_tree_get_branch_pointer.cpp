#include "../include/memory_manager.hpp"
#include "../include/new_delete_overrides.hpp"
#include "../include/printer.hpp"
#include "../include/classes.hpp"

#include <cassert>

void run() {
	TREE_CLASS tree;

	for(unsigned int i = 0; i < 10; i += 1)
		tree.growthTree();

	print(tree);

	assert(tree.getBranchPointer(0) == NULL);

	assert(tree.getBranchPointer(1) == NULL);

	assert(tree.getBranchPointer(2) == NULL);

	assert(tree.getBranchPointer(5) == NULL);

	assert(tree.getBranchPointer(10) == NULL);

	assert(tree.getBranchPointer(12) == NULL);

	assert(tree.getBranchPointer(30000) == NULL);
}

int main() {
	run(); //so that objects allocated on stack in run() will be freed and report_leaks won't falsly claim leaks

	return memory_manager::report_leaks();
}
