#include <cstdio>
#include "../include/classes.hpp"

void print_indent(unsigned char indent) {
	printf("%*s", indent * 4, "");
}

void print_fruit(FRUIT_CLASS* fruit, unsigned char indent = 0) {
	if(fruit == NULL) {
		print_indent(indent);
		printf("- type: FRUIT_CLASS_NULL\n\n");

		return;
	}

	unsigned int fruit_weight = fruit -> getWeight();
	unsigned int fruit_id = fruit -> getLength();

	BRANCH_CLASS* parrent_branch = fruit -> getBranchPointer();

	TREE_CLASS* parrent_tree = NULL;
	if(parrent_branch != NULL)
		parrent_tree = parrent_branch -> getTreePointer();

	GARDEN_CLASS* parrent_garden = NULL;
	if(parrent_tree != NULL)
		parrent_garden = parrent_tree -> getGardenPointer();

	print_indent(indent);
	printf("- type: FRUIT_CLASS\n");

	print_indent(indent);
	printf("  fruit_id: %u\n", fruit_id);

	print_indent(indent);
	printf("  path:");

	if(parrent_garden != NULL)
		printf(" G ->");

	if(parrent_tree != NULL)
		printf(" T%u ->", parrent_tree -> getNumber());

	if(parrent_branch != NULL)
		printf(" B%u ->", parrent_branch -> getHeight());

	printf(" F%u\n", fruit_id);


	print_indent(indent);
	printf("  fruit_weight: %u\n", fruit_weight);
}

void print_branch(BRANCH_CLASS* branch, unsigned char indent = 0) {
	if(branch == NULL) {
		print_indent(indent);
		printf("- type: BRANCH_CLASS_NULL\n\n");

		return;
	}

	unsigned int fruit_total_weight = branch -> getWeightsTotal();
	unsigned int fruit_total_count = branch -> getFruitsTotal();

	unsigned int branch_length = branch -> getLength();

	unsigned int branch_id = branch -> getHeight();

	TREE_CLASS* parrent_tree = branch -> getTreePointer();

	GARDEN_CLASS* parrent_garden = NULL;
	if(parrent_tree != NULL)
		parrent_garden = parrent_tree -> getGardenPointer();

	print_indent(indent);
	printf("- type: BRANCH_CLASS\n");

	print_indent(indent);
	printf("  branch_id: %u\n", branch_id);


	print_indent(indent);
	printf("  path:");

	if(parrent_garden != NULL)
		printf(" G ->");

	if(parrent_tree != NULL)
		printf(" T%u ->", parrent_tree -> getNumber());

	printf(" B%u\n", branch_id);


	print_indent(indent);
	printf("  branch_length: %u\n", branch_length);

	print_indent(indent);
	printf("  fruit_total_weight: %u\n", fruit_total_weight);

	print_indent(indent);
	printf("  fruit_total_count: %u\n", fruit_total_count);

	print_indent(indent);
	if(branch_length < 2)
		printf("  fruits: NONE\n");
	if(branch_length >= 2){
		printf("  fruits:\n");
		for(unsigned int i = 2; i <= branch_length; i += 2)
			print_fruit(branch -> getFruitPointer(i), indent + 1);
	}
}

void print_tree(TREE_CLASS* tree, unsigned char indent = 0) {
	if(tree == NULL) {
		print_indent(indent);
		printf("- type: TREE_CLASS_NULL\n\n");

		return;
	}

	unsigned int fruit_total_weight = tree -> getWeightsTotal();
	unsigned int fruit_total_count = tree -> getFruitsTotal();
	unsigned int branch_total_count = tree -> getBranchesTotal();

	unsigned int tree_height = tree -> getHeight();

	unsigned int tree_id = tree -> getNumber();

	GARDEN_CLASS* parrent_garden = tree -> getGardenPointer();

	print_indent(indent);
	printf("- type: TREE_CLASS\n");

	print_indent(indent);
	printf("  tree_id: %u\n", tree_id);


	print_indent(indent);
	printf("  path:");

	if(parrent_garden != NULL)
		printf(" G ->");

	printf(" T%u\n", tree_id);


	print_indent(indent);
	printf("  tree_height: %u\n", tree_height);

	print_indent(indent);
	printf("  fruit_total_weight: %u\n", fruit_total_weight);

	print_indent(indent);
	printf("  fruit_total_count: %u\n", fruit_total_count);

	print_indent(indent);
	printf("  branch_total_count: %u\n", branch_total_count);

	print_indent(indent);
	if(tree_height < 3)
		printf("  branches: NONE\n");
	if(tree_height >= 3){
		printf("  branches:\n");
		for(unsigned int i = 3; i <= tree_height; i += 3)
			print_branch(tree -> getBranchPointer(i), indent + 1);
	}
}

void print_garden(GARDEN_CLASS* garden, unsigned char indent = 0) {
	if(garden == NULL) {
		print_indent(indent);
		printf("- type: GARDEN_CLASS_NULL\n\n");

		return;
	}

	unsigned int fruit_total_weight = garden -> getWeightsTotal();
	unsigned int fruit_total_count = garden -> getFruitsTotal();
	unsigned int branch_total_count = garden -> getBranchesTotal();
	unsigned int tree_total_count = garden -> getTreesTotal();

	print_indent(indent);
	printf("- type: GARDEN_CLASS\n");

	print_indent(indent);
	printf("  fruit_total_weight: %u\n", fruit_total_weight);

	print_indent(indent);
	printf("  fruit_total_count: %u\n", fruit_total_count);

	print_indent(indent);
	printf("  branch_total_count: %u\n", branch_total_count);

	print_indent(indent);
	printf("  tree_total_count: %u\n", tree_total_count);

	print_indent(indent);
	if(tree_total_count == 0) {
		printf("  trees: NONE\n");
	}
	if(tree_total_count > 0) {
		printf("  trees:\n");
		unsigned int current_id = 0, trees_printed = 0;
		while(trees_printed < tree_total_count) {
			TREE_CLASS* current_tree = garden -> getTreePointer(current_id);
			if(current_tree != NULL) {
				print_tree(current_tree, indent + 1);
				trees_printed += 1;
			}

			current_id += 1;
		}
	}
}

void print(FRUIT_CLASS& fruit) {
	printf("=====BEGIN PRINT=====\n");
	print_fruit(&fruit, 0);
	printf("=====END PRINT=====\n");
}

void print(BRANCH_CLASS& branch) {
	printf("=====BEGIN PRINT=====\n");
	print_branch(&branch, 0);
	printf("=====END PRINT=====\n");
}

void print(TREE_CLASS& tree) {
	printf("=====BEGIN PRINT=====\n");
	print_tree(&tree, 0);
	printf("=====END PRINT=====\n");
}

void print(GARDEN_CLASS& garden) {
	printf("=====BEGIN PRINT=====\n");
	print_garden(&garden, 0);
	printf("=====END PRINT=====\n");
}

void print(FRUIT_CLASS* fruit) {
	printf("=====BEGIN PRINT=====\n");
	print_fruit(fruit, 0);
	printf("=====END PRINT=====\n");
}

void print(BRANCH_CLASS* branch) {
	printf("=====BEGIN PRINT=====\n");
	print_branch(branch, 0);
	printf("=====END PRINT=====\n");
}

void print(TREE_CLASS* tree) {
	printf("=====BEGIN PRINT=====\n");
	print_tree(tree, 0);
	printf("=====END PRINT=====\n");
}

void print(GARDEN_CLASS* garden) {
	printf("=====BEGIN PRINT=====\n");
	print_garden(garden, 0);
	printf("=====END PRINT=====\n");
}
