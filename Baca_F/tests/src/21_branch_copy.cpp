#include "../include/memory_manager.hpp"
#include "../include/new_delete_overrides.hpp"
#include "../include/printer.hpp"
#include "../include/classes.hpp"

void run() {
	BRANCH_CLASS* branch = new BRANCH_CLASS();

	print(branch);

	for(unsigned int i = 0; i < 20; i += 1)
		branch -> growthBranch();

	print(branch);

	BRANCH_CLASS* branch_copy = new BRANCH_CLASS(*branch);

	print(branch_copy);

	for(unsigned int i = 0; i < 10; i += 1)
		branch_copy -> fadeBranch();

	print(branch);
	print(branch_copy);

	delete branch;
	branch = NULL;

	branch_copy -> growthBranch();
	branch_copy -> growthBranch();
	branch_copy -> growthBranch();

	print(branch_copy);

	delete branch_copy;
	branch_copy = NULL;
}

int main() {
	run(); //so that objects allocated on stack in run() will be freed and report_leaks won't falsly claim leaks

	return memory_manager::report_leaks();
}
