#include "../include/memory_manager.hpp"
#include "../include/new_delete_overrides.hpp"
#include "../include/printer.hpp"
#include "../include/classes.hpp"

void run() {
	FRUIT_CLASS fruit;

	fruit.growthFruit();
	fruit.fadeFruit();
	fruit.pluckFruit();

	print(fruit);
}

int main() {
	run(); //so that objects allocated on stack in run() will be freed and report_leaks won't falsly claim leaks

	return memory_manager::report_leaks();
}
