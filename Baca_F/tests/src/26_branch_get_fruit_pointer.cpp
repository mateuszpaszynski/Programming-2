#include "../include/memory_manager.hpp"
#include "../include/new_delete_overrides.hpp"
#include "../include/printer.hpp"
#include "../include/classes.hpp"

#include <cassert>

void run() {
	BRANCH_CLASS branch;

	for(unsigned int i = 0; i < 10; i += 1)
		branch.growthBranch();

	print(branch);

	assert(branch.getFruitPointer(0) == NULL);

	assert(branch.getFruitPointer(1) == NULL);

	assert(branch.getFruitPointer(3) == NULL);

	assert(branch.getFruitPointer(9) == NULL);

	assert(branch.getFruitPointer(11) == NULL);

	assert(branch.getFruitPointer(12) == NULL);

	assert(branch.getFruitPointer(40000) == NULL);
}

int main() {
	run(); //so that objects allocated on stack in run() will be freed and report_leaks won't falsly claim leaks

	return memory_manager::report_leaks();
}
