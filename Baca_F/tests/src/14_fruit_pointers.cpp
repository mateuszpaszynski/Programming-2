#include "../include/memory_manager.hpp"
#include "../include/new_delete_overrides.hpp"
#include "../include/printer.hpp"
#include "../include/classes.hpp"

#include <cassert>

void run() {
	BRANCH_CLASS* branch = new BRANCH_CLASS();

	for(unsigned int i = 0; i < 10; i += 1)
		branch -> growthBranch();

	FRUIT_CLASS* fruit = branch -> getFruitPointer(4);

	BRANCH_CLASS* fruit_parrent = fruit -> getBranchPointer();

	assert(fruit_parrent == branch);

	delete branch;
	branch = NULL;
	fruit_parrent = NULL;
	fruit = NULL;


	FRUIT_CLASS* standalone_fruit = new FRUIT_CLASS();

	BRANCH_CLASS* standalone_fruit_parrent = standalone_fruit -> getBranchPointer();

	assert(standalone_fruit_parrent == NULL);

	delete standalone_fruit;
	standalone_fruit = NULL;
}

int main() {
	run(); //so that objects allocated on stack in run() will be freed and report_leaks won't falsly claim leaks

	return memory_manager::report_leaks();
}
