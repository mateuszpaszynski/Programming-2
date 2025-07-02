#include "../include/memory_manager.hpp"
#include "../include/new_delete_overrides.hpp"
#include "../include/printer.hpp"
#include "../include/classes.hpp"

void run() {
	FRUIT_CLASS fruit;

	print(fruit);

	for(unsigned int i = 0; i < 1000000; i += 1)
		fruit.growthFruit();

	print(fruit);

	fruit.pluckFruit();

	print(fruit);

	fruit.fadeFruit();
	fruit.fadeFruit();
	fruit.fadeFruit();
	fruit.fadeFruit();
	fruit.fadeFruit();

	print(fruit);

	for(unsigned int i = 0; i < 100; i += 1)
		fruit.growthFruit();

	print(fruit);

	fruit.fadeFruit();
	fruit.fadeFruit();
	fruit.fadeFruit();
	fruit.fadeFruit();
	fruit.fadeFruit();

	print(fruit);
}

int main() {
	run(); //so that objects allocated on stack in run() will be freed and report_leaks won't falsly claim leaks

	return memory_manager::report_leaks();
}
