#include "../include/memory_manager.hpp"
#include "../include/new_delete_overrides.hpp"
#include "../include/printer.hpp"
#include "../include/classes.hpp"

void run() {
	BRANCH_CLASS* branch = new BRANCH_CLASS();

	for(unsigned int i = 0; i < 10; i += 1)
		branch -> growthBranch();

	print(branch);

	FRUIT_CLASS* fruit = branch -> getFruitPointer(4);

	print(fruit);

	FRUIT_CLASS* fruit_detached = new FRUIT_CLASS(*fruit);

	print(fruit_detached);

	fruit_detached -> growthFruit();
	fruit_detached -> growthFruit();
	fruit_detached -> growthFruit();

	print(branch);
	print(fruit);
	print(fruit_detached);

	delete branch;
	branch = NULL;
	fruit = NULL;

	print(fruit_detached);

	fruit_detached -> fadeFruit();
	fruit_detached -> fadeFruit();

	print(fruit_detached);

	delete fruit_detached;
	fruit_detached = NULL;
}

int main() {
	run(); //so that objects allocated on stack in run() will be freed and report_leaks won't falsly claim leaks

	return memory_manager::report_leaks();
}
