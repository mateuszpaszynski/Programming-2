#include <iostream>
void print(BRANCH_CLASS* branch)
{
    printf("BRANCH CLASS ");
    printf("pos: %u ",branch->getHeight());
    printf("length: %u ",branch->getLength());
    printf("fruitcount: %u ",branch->getFruitsTotal());
    printf("weightTotal: %u\n",branch->getWeightsTotal());
    FRUIT_CLASS* fruit = branch->getFirst_Fruit();
    for ( int i = 0; i<branch->getFruitsTotal();i++)
    {
        printf("fruit[%u]:",fruit->getLength());
        if ( fruit != nullptr)
        {
            printf("%u ",fruit->getWeight());

        }
        fruit = fruit->getNextFruit();
    }
    printf("\n");
}
void print(TREE_CLASS* tree)
{
    printf("TREE CLASS ");
    BRANCH_CLASS* branch = tree->getFirstBranch();
    for ( int i = 0;i<tree->getBranchesTotal();i++)
    {
        print(branch);
        branch = branch->getNextBranch();
    }
    printf("\n");
}
