#include "../include/memory_manager.hpp"
#include "../include/new_delete_overrides.hpp"
#include "../include/printer.hpp"
#include "../include/classes.hpp"

void run() {
	TREE_CLASS* tree = new TREE_CLASS();

	print(tree);

	for(unsigned int i = 0; i < 20; i += 1)
		tree -> growthTree();

	print(tree);

	TREE_CLASS* tree_copy = new TREE_CLASS(*tree);

	print(tree_copy);

	for(unsigned int i = 0; i < 10; i += 1)
		tree_copy -> fadeTree();

	print(tree);
	print(tree_copy);

	delete tree;
	tree = NULL;

	tree_copy -> growthTree();
	tree_copy -> growthTree();
	tree_copy -> growthTree();
	tree_copy -> growthTree();
	tree_copy -> growthTree();

	print(tree_copy);

	delete tree_copy;
	tree_copy = NULL;
}

int main() {
	run(); //so that objects allocated on stack in run() will be freed and report_leaks won't falsly claim leaks

	return memory_manager::report_leaks();
}
