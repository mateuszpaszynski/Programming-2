#include "../include/memory_manager.hpp"
#include "../include/new_delete_overrides.hpp"
#include "../include/printer.hpp"
#include "../include/classes.hpp"

void run() {
	FRUIT_CLASS* fruit = new FRUIT_CLASS();

	fruit -> growthFruit();
	fruit -> growthFruit();
	fruit -> growthFruit();
	fruit -> growthFruit();
	fruit -> growthFruit();
	fruit -> growthFruit();

	print(fruit);

	FRUIT_CLASS* fruit_copy = new FRUIT_CLASS(*fruit);

	delete fruit;
	fruit = NULL;

	print(fruit_copy);

	fruit_copy -> fadeFruit();
	fruit_copy -> fadeFruit();

	print(fruit_copy);

	delete fruit_copy;
	fruit_copy = NULL;
}

int main() {
	run(); //so that objects allocated on stack in run() will be freed and report_leaks won't falsly claim leaks

	return memory_manager::report_leaks();
}
