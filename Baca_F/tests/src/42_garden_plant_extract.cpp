#include "../include/memory_manager.hpp"
#include "../include/new_delete_overrides.hpp"
#include "../include/printer.hpp"
#include "../include/classes.hpp"

void run() {
	GARDEN_CLASS garden;

	garden.extractTree(0);
	garden.extractTree(5);

	garden.plantTree();
	garden.plantTree();
	garden.plantTree();
	garden.plantTree();

	print(garden);

	garden.extractTree(1);
	garden.extractTree(8);
	garden.extractTree(2);

	garden.plantTree();

	print(garden);

	garden.extractTree(0);

	print(garden);

	garden.plantTree();
	garden.plantTree();

	print(garden);

	garden.extractTree(3);

	print(garden);

	garden.extractTree(2);
	garden.extractTree(3);

	print(garden);

	garden.extractTree(10000);

	print(garden);
}

int main() {
	run(); //so that objects allocated on stack in run() will be freed and report_leaks won't falsly claim leaks

	return memory_manager::report_leaks();
}
