#include "../include/memory_manager.hpp"
#include "../include/new_delete_overrides.hpp"
#include "../include/printer.hpp"
#include "../include/classes.hpp"

void run() {
	TREE_CLASS tree;

	for(unsigned int i = 0; i < 30; i += 1)
		tree.growthTree();

	print(tree);

	tree.cutTree(0);

	print(tree);

	for(unsigned int i = 0; i < 30; i += 1)
		tree.growthTree();

	tree.cutTree(10);

	print(tree);

	tree.fadeTree();
	tree.fadeTree();
	tree.fadeTree();
	tree.fadeTree();
	tree.fadeTree();

	print(tree);
}

int main() {
	run(); //so that objects allocated on stack in run() will be freed and report_leaks won't falsly claim leaks

	return memory_manager::report_leaks();
}
