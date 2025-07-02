#include "../include/memory_manager.hpp"
#include "../include/new_delete_overrides.hpp"
#include "../include/printer.hpp"
#include "../include/classes.hpp"

void run() {
	GARDEN_CLASS garden;

	garden.plantTree();
	garden.plantTree();

	garden.growthGarden();
	garden.growthGarden();
	garden.growthGarden();
	garden.growthGarden();
	garden.growthGarden();
	garden.growthGarden();
	garden.growthGarden();
	garden.growthGarden();
	garden.growthGarden();
	garden.growthGarden();

	garden.plantTree();

	garden.growthGarden();
	garden.growthGarden();
	garden.growthGarden();
	garden.growthGarden();

	garden.plantTree();

	garden.growthGarden();
	garden.growthGarden();


	print(garden);

	TREE_CLASS* tree1 = garden.getTreePointer(1);
	BRANCH_CLASS* tree1_branch6 = tree1 -> getBranchPointer(6);
	FRUIT_CLASS* tree1_branch6_fruit4 = tree1_branch6 -> getFruitPointer(4);

	tree1 -> growthTree();
	tree1 -> growthTree();

	tree1_branch6 -> growthBranch();
	tree1_branch6 -> growthBranch();

	tree1_branch6 -> harvestBranch(6);

	tree1_branch6_fruit4 -> pluckFruit();

	print(garden);

	tree1 = NULL;
	tree1_branch6 = NULL;
	tree1_branch6_fruit4 = NULL;

	garden.fadeGarden();
	garden.fadeGarden();
	garden.fadeGarden();
	garden.fadeGarden();
	garden.fadeGarden();

	print(garden);

	garden.harvestGarden(4);

	print(garden);

}

int main() {
	run(); //so that objects allocated on stack in run() will be freed and report_leaks won't falsly claim leaks

	return memory_manager::report_leaks();
}
