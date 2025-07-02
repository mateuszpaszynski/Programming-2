#include "../include/memory_manager.hpp"
#include "../include/new_delete_overrides.hpp"
#include "../include/printer.hpp"
#include "../include/classes.hpp"

#define LOT_SIZE 1000000

void run() {
	GARDEN_CLASS garden;

	for(unsigned int i = 0; i < LOT_SIZE; i += 1)
		garden.plantTree();
}

int main() {
	run(); //so that objects allocated on stack in run() will be freed and report_leaks won't falsly claim leaks

	return memory_manager::report_leaks();
}
