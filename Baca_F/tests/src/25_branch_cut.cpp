#include "../include/memory_manager.hpp"
#include "../include/new_delete_overrides.hpp"
#include "../include/printer.hpp"
#include "../include/classes.hpp"

void run() {
	BRANCH_CLASS branch;

	for(unsigned int i = 0; i < 30; i += 1)
		branch.growthBranch();

	print(branch);

	branch.cutBranch(0);

	print(branch);

	for(unsigned int i = 0; i < 30; i += 1)
		branch.growthBranch();

	branch.cutBranch(10);

	print(branch);

	branch.fadeBranch();
	branch.fadeBranch();
	branch.fadeBranch();
	branch.fadeBranch();
	branch.fadeBranch();

	print(branch);
}

int main() {
	run(); //so that objects allocated on stack in run() will be freed and report_leaks won't falsly claim leaks

	return memory_manager::report_leaks();
}
