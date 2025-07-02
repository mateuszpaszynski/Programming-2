#include "../include/memory_manager.hpp"
#include "../include/new_delete_overrides.hpp"
#include "../include/printer.hpp"
#include "../include/classes.hpp"

void run() {
	GARDEN_CLASS garden;

	for(unsigned int i = 0; i < 10; i += 1)
		garden.plantTree();

	for(unsigned int i = 0; i < 5; i += 1)
		garden.extractTree(i);

	for(unsigned int i = 5; i < 10; i += 1)
		for(unsigned int j = 0; j < i; j += 1)
			garden.getTreePointer(i) -> growthTree();

	print(garden);

	for(unsigned int i = 5; i < 10; i += 1)
		garden.cloneTree(i);

	print(garden);

	for(unsigned int i = 0; i < 5; i += 1)
		for(unsigned int j = 0; j < 3; j += 1)
			garden.getTreePointer(i) -> fadeTree();

	garden.cloneTree(10);

	garden.extractTree(4);
	garden.extractTree(5);
	garden.extractTree(6);

	print(garden);

	garden.cloneTree(10);
	garden.cloneTree(9);
	garden.cloneTree(8);

	print(garden);

	garden.cloneTree(1);
	garden.cloneTree(1);
	garden.cloneTree(1);
	garden.cloneTree(1);
	garden.cloneTree(1);

	garden.getTreePointer(11) -> harvestTree(3);
	garden.getTreePointer(10) -> cutTree(6);

	print(garden);
}

int main() {
	run(); //so that objects allocated on stack in run() will be freed and report_leaks won't falsly claim leaks

	return memory_manager::report_leaks();
}
