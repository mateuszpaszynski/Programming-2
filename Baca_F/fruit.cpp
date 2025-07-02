//Mateusz Paszynski
#include "fruit.hpp"
#include "branch.hpp"
#include "tree.hpp"
#include "garden.hpp"
#include <cstdlib>
//getters
unsigned int FRUIT_CLASS::getLength()
{
    return pos;
}
unsigned int FRUIT_CLASS::getWeight()
{
    return weight;
}
BRANCH_CLASS* FRUIT_CLASS::getBranchPointer()
{
    return branch_ptr;
}
FRUIT_CLASS* FRUIT_CLASS::getNextFruit()
{
    return next_fruit;
}
//setters
void FRUIT_CLASS::setWeight(unsigned int val)
{
    weight = val;
}
void FRUIT_CLASS::setNextFruit(FRUIT_CLASS* ptr)
{
    next_fruit = ptr;
}
void FRUIT_CLASS::setBranchPtr(BRANCH_CLASS* ptr)
{
    branch_ptr = ptr;
}
//konstruktory
FRUIT_CLASS::FRUIT_CLASS(BRANCH_CLASS* ptr ,unsigned int position)
{
    branch_ptr = ptr;
    next_fruit = NULL;
    pos = position;
    weight = 0;
}
FRUIT_CLASS::FRUIT_CLASS(const FRUIT_CLASS& klon)
{
    branch_ptr = NULL;
    weight = klon.weight;
    next_fruit = NULL;
    pos = klon.pos;

}
FRUIT_CLASS::FRUIT_CLASS()
{
    branch_ptr = NULL;
    next_fruit = NULL;
    pos = 0;
    weight = 0;
}
//funkcje
void FRUIT_CLASS::growthFruit()
{
    weight++;
    if ( branch_ptr!=NULL)
    {
        branch_ptr->setWeightsTotal('+',1);
        if ( branch_ptr->getTreePointer() != NULL)
        {
            branch_ptr->getTreePointer()->setWeightsTotal('c',1);
            if ( branch_ptr->getTreePointer()->getGardenPointer()!=NULL)branch_ptr->getTreePointer()->getGardenPointer()->setWeightsTotal('c',1);
        }
    }
}
void FRUIT_CLASS::fadeFruit()
{
    if (weight>0)
    {
        weight--;
        if ( branch_ptr!=NULL)
        {
            branch_ptr->setWeightsTotal('-',1);
            if (branch_ptr->getTreePointer()!=NULL)
            {
                branch_ptr->getTreePointer()->setWeightsTotal('-',1);
                if ( branch_ptr->getTreePointer()->getGardenPointer()!=NULL)branch_ptr->getTreePointer()->getGardenPointer()->setWeightsTotal('-',1);
            }
        }
    }
    }
void FRUIT_CLASS::pluckFruit()
{
    if ( branch_ptr!=NULL){
        branch_ptr->setWeightsTotal('-',weight);
    if ( branch_ptr->getTreePointer()!=NULL)
    {
        branch_ptr->getTreePointer()->setWeightsTotal('-',weight);
        if ( branch_ptr->getTreePointer()->getGardenPointer()!=NULL)branch_ptr->getTreePointer()->getGardenPointer()->setWeightsTotal('-',weight);
    }
}
    weight = 0;
}