//Mateusz Paszynski
#include "branch.hpp"
#include "fruit.hpp"
#include "tree.hpp"
#include "garden.hpp"
#include <cstdlib>
#include <iostream>
//getters
unsigned int BRANCH_CLASS::getFruitsTotal()
{
    return fruit_count;
}
unsigned int BRANCH_CLASS::getHeight()
{
    return height;
}
unsigned int BRANCH_CLASS::getLength()
{
    return length;
}
FRUIT_CLASS* BRANCH_CLASS::getFruitPointer(unsigned int search)
{
    FRUIT_CLASS* root = first_fruit;
    while ( root != NULL)
    {
        if (root->getLength() == search)
        {
            return root;
        }
        root = root->getNextFruit();
    }
    return NULL;
}
FRUIT_CLASS* BRANCH_CLASS::getFirst_Fruit()
{
    return first_fruit;
}
TREE_CLASS* BRANCH_CLASS::getTreePointer()
{
    return tree_ptr;
}
unsigned int BRANCH_CLASS::getWeightsTotal()
{
    return weights_total;
}
BRANCH_CLASS* BRANCH_CLASS::getNextBranch()
{
    return next_branch;
}
//setters
void BRANCH_CLASS:: setWeightsTotal(char c, unsigned int w)
{
    if ( c == '-')
    {
        weights_total -=w;
    }
    else { weights_total+=w;}

}
void BRANCH_CLASS::setFruitsTotal(char c, unsigned int val)
{
    if ( c == '-')
    {
        fruit_count-=val;
    }
    else fruit_count+=val;

}
void BRANCH_CLASS::setNextBranch(BRANCH_CLASS* next)
{
    next_branch=next;
}
void BRANCH_CLASS::setTreePointer(TREE_CLASS* ptr)
{
    tree_ptr = ptr;
}
void BRANCH_CLASS::setHeight(unsigned int val)
{
    height = val;
}
//construtors & desctructors
BRANCH_CLASS::~BRANCH_CLASS()
{
    FRUIT_CLASS* fruit = first_fruit;
    while (fruit != NULL)
    {
        FRUIT_CLASS* next = fruit->getNextFruit();
        delete fruit;
        fruit = next;
    }
}
BRANCH_CLASS::BRANCH_CLASS()
{
    length = 0;
    fruit_count = 0;
    height= 0;
    weights_total = 0;
    first_fruit = NULL;
    tree_ptr = NULL;
    next_branch = NULL;
}
BRANCH_CLASS::BRANCH_CLASS(TREE_CLASS*ptr,unsigned int pos)
{
    tree_ptr = ptr;
    length = 0;
    height = pos;
    fruit_count = 0;
    weights_total = 0;
    first_fruit = NULL;
    next_branch = NULL;
}
BRANCH_CLASS::BRANCH_CLASS( const BRANCH_CLASS& other)
{
    tree_ptr = NULL;
    //weights_total = other.weights_total;
    height = other.height;
    length = other.length;
    fruit_count = other.fruit_count;
    weights_total = other.weights_total;
    FRUIT_CLASS* klon = other.first_fruit;
    FRUIT_CLASS* prev = NULL;
    FRUIT_CLASS* new_fruit;
    for (unsigned int i = 0; i < other.fruit_count; i++)
    {
        new_fruit = new FRUIT_CLASS(*klon);
        new_fruit->setBranchPtr(this);
        if ( prev != NULL)
        {
            prev->setNextFruit(new_fruit);
        }

        if ( prev == NULL)first_fruit = new_fruit;
        prev = new_fruit;
        klon=klon->getNextFruit();
    }

    next_branch = NULL;
}

//funkcje
void BRANCH_CLASS::harvestBranch(unsigned int waga)
{
    FRUIT_CLASS* fruit = first_fruit;
    while (fruit != NULL)
    {
        if (fruit->getWeight() >= waga)
        {
            fruit->pluckFruit();
        }
        fruit = fruit->getNextFruit();
    }
}
void BRANCH_CLASS::growthBranch()
{
    FRUIT_CLASS* root = first_fruit;
    for ( unsigned int i = 0;i<fruit_count;i++)
    {
        if ( root !=NULL)
        {
            root->growthFruit();
            if ( root->getNextFruit()!=NULL)root = root->getNextFruit();
        }
    }
    length++;
    if (length % 2 == 0)
    {
        FRUIT_CLASS* fruit = new FRUIT_CLASS(this,length);
        if ( length == 2)first_fruit = fruit;
        else
        {
            if ( root!=NULL)
            {
                root->setNextFruit(fruit);
            }
        }
            fruit_count++;
            if ( tree_ptr!=NULL)
            {
                tree_ptr->setFruitsTotal('+',1);
                if ( tree_ptr->getGardenPointer()!=NULL)tree_ptr->getGardenPointer()->setFruitsTotal('+',1);
            }
    }
}
void BRANCH_CLASS::fadeBranch()
{
    if ( length > 0) {

        FRUIT_CLASS* root = first_fruit;
    FRUIT_CLASS* parent = NULL;
    FRUIT_CLASS* parents_parent = NULL;
    while ( root != NULL)
    {
        root->fadeFruit();
        parents_parent = parent;
        parent = root;
        root = root->getNextFruit();
    }
    if ( parent != NULL && parent->getLength() == length)
    {
        fruit_count--;
        if ( tree_ptr!=NULL)
        {
            tree_ptr->setFruitsTotal('-',1);
            if ( tree_ptr->getGardenPointer()!=NULL)tree_ptr->getGardenPointer()->setFruitsTotal('-',1);
        }
        if ( parents_parent != NULL)
        {
            weights_total-=parent->getWeight();
            if ( tree_ptr!=NULL)
            {
                tree_ptr->setWeightsTotal('-',parent->getWeight());
                if ( tree_ptr->getGardenPointer()!=NULL)tree_ptr->getGardenPointer()->setWeightsTotal('-',parent->getWeight());
            }
            parents_parent->setNextFruit(NULL);
        }
       if ( parent == first_fruit)
       {
           first_fruit = NULL;
       }
        delete parent;
        parent = NULL;
    }
    length--;
}
}
void BRANCH_CLASS::cutBranch(unsigned int pos)
{
    if (pos < length)
    {
        if (pos < 2)
        {
            FRUIT_CLASS* fruit = first_fruit;
            while (fruit != NULL)
            {
                FRUIT_CLASS* next = fruit->getNextFruit();
                delete fruit;
                fruit = next;
            }
            first_fruit = NULL;
            length = pos;
            if ( tree_ptr!=NULL)
            {
                tree_ptr->setFruitsTotal('-',fruit_count);
                tree_ptr->setWeightsTotal('-',weights_total);
                if ( tree_ptr->getGardenPointer()!=NULL)
                {
                    tree_ptr->getGardenPointer()->setWeightsTotal('-',weights_total);
                    tree_ptr->getGardenPointer()->setFruitsTotal('-',fruit_count);
                }
            }
            fruit_count = 0;
            weights_total = 0;
            return;
        }
        FRUIT_CLASS* fruit = first_fruit;
        FRUIT_CLASS* parent = NULL;

        while (fruit != NULL && fruit->getLength() <= pos)
        {
            parent = fruit;
            fruit = fruit->getNextFruit();
        }

        if (parent != NULL)
        {
            parent->setNextFruit(NULL);
        }

        while (fruit != NULL)
        {
            weights_total -= fruit->getWeight();
            if ( tree_ptr!=NULL)
            {
                tree_ptr->setWeightsTotal('-',fruit->getWeight());
                if ( tree_ptr->getGardenPointer()!=NULL)tree_ptr->getGardenPointer()->setWeightsTotal('-',fruit->getWeight());
            }
            FRUIT_CLASS* next = fruit->getNextFruit();
            delete fruit;
            fruit = next;
            fruit_count--;
            if ( tree_ptr!=NULL)
            {
                tree_ptr->setFruitsTotal('-',fruit_count);
                if ( tree_ptr->getGardenPointer()!=NULL)setFruitsTotal('-',fruit_count);
            }
        }
        length = pos;
    }
}