//Mateusz Paszynski
#include "tree.hpp"
#include <cstdio>
#include "branch.hpp"
#include "garden.hpp"
#include <cstdlib>
using namespace std;
//getters
TREE_CLASS* TREE_CLASS::getPrevTree()
{
    return prev_tree;
}
void TREE_CLASS::setPrevTree(TREE_CLASS* ptr)
{
    prev_tree = ptr;
}


unsigned int TREE_CLASS::getNumber()
{
    return id;
}
BRANCH_CLASS* TREE_CLASS::getFirstBranch()
{
    return first_branch;
}
unsigned int TREE_CLASS::getBranchesTotal()
{
    return branches_count;
}
unsigned int TREE_CLASS::getWeightsTotal()
{
    return weights_total;
}
unsigned int TREE_CLASS::getFruitsTotal()
{
    return fruits_total;
}
unsigned int TREE_CLASS::getHeight()
{
    return height;
}
GARDEN_CLASS* TREE_CLASS::getGardenPointer()
{
    return garden_ptr;
}
BRANCH_CLASS* TREE_CLASS::getBranchPointer(unsigned int search)
{
    BRANCH_CLASS* root = first_branch;
    while ( root != NULL)
    {
        if (root->getHeight() == search)
        {
            return root;
        }
        root = root->getNextBranch();
    }
    return NULL;
}
TREE_CLASS* TREE_CLASS::getNextTree()
{
    return next_tree;
}
//setters
void TREE_CLASS::setFirstBranch(BRANCH_CLASS* ptr)
{
    first_branch = ptr;
}
void TREE_CLASS::setNextTree(TREE_CLASS* ptr)
{
    next_tree = ptr;
}
void TREE_CLASS::setWeightsTotal(char c, unsigned int val)
{
    if ( c == '-')
        {
        weights_total-=val;
        }
    else weights_total+=val;

}
void TREE_CLASS::setFruitsTotal(char c, unsigned int val)
{
    if ( c == '-')
    {
        fruits_total-=val;
    }
    else fruits_total+=val;

}
void TREE_CLASS::setBranchesTotal(unsigned int val)
{
    branches_count +=val;
}
//constructors & destructors
TREE_CLASS::TREE_CLASS(GARDEN_CLASS* ptr,unsigned int num)
{
    prev_tree = NULL;
    id = num;
    height = 0;
    branches_count = 0;
    first_branch = NULL;
    weights_total = 0;
    fruits_total = 0;
    next_tree = NULL;
    garden_ptr = ptr;
}
void TREE_CLASS::setGardenPtr(GARDEN_CLASS* ptr)
{
    garden_ptr = ptr;
}
void TREE_CLASS::setNumber(unsigned int num)
{
    id = num;
}
TREE_CLASS::TREE_CLASS( const TREE_CLASS & other)
{
    garden_ptr = NULL;
    branches_count = other.branches_count;
    height = other.height;
    fruits_total = other.fruits_total;
    weights_total = other.weights_total;
    BRANCH_CLASS* klon = other.first_branch;
    BRANCH_CLASS* prev = NULL;
    BRANCH_CLASS* new_fruit;
    for (unsigned int i = 0; i < other.branches_count; i++)
    {
        new_fruit = new BRANCH_CLASS(*klon);
        new_fruit->setTreePointer(this);
        if ( prev != NULL)
        {
            prev->setNextBranch(new_fruit);
        }

        if ( prev == NULL)first_branch = new_fruit;
        prev = new_fruit;
        klon=klon->getNextBranch();
    }

    next_tree = NULL;
    prev_tree = NULL;
}

TREE_CLASS::TREE_CLASS()
{
    id = 0  ;
    height = 0;
    branches_count = 0;
    first_branch = NULL;
    weights_total = 0;
    fruits_total = 0;
    next_tree = NULL;
    garden_ptr = NULL;
    prev_tree = NULL;
}
TREE_CLASS::~TREE_CLASS()
{
    BRANCH_CLASS* root = first_branch;
    while (root != NULL)
    {
        BRANCH_CLASS* next = root->getNextBranch();
        delete root;
        root = next;
    }
}
//functions
void TREE_CLASS::growthTree()
{
    BRANCH_CLASS* root = first_branch;
    for (unsigned int i = 0;i<branches_count;i++)
    {
        if ( root !=NULL)
        {
            root->growthBranch();
            if ( root->getNextBranch()!=NULL)root = root->getNextBranch();
        }
    }
    height++;
    if (height % 3 == 0)
    {
        BRANCH_CLASS* branch= new BRANCH_CLASS(this,height);
        if ( height == 3)first_branch = branch;
        else
        {
           if ( root!=NULL) root->setNextBranch(branch);
        }
        branches_count++;
        if ( garden_ptr!=NULL)garden_ptr->setBranchesTotal('+',1);
    }
}
void TREE_CLASS::fadeTree()
{
    if ( height > 0 )
    {
        BRANCH_CLASS* root = first_branch;
    BRANCH_CLASS* parent = NULL;
    BRANCH_CLASS* parents_parent = NULL;
    while ( root != NULL)
    {
        root->fadeBranch();
        parents_parent = parent;
        parent = root;
        root = root->getNextBranch();
    }

    if ( parent != NULL && parent->getHeight() == height)
    {
        branches_count--;
        if ( garden_ptr!=NULL)garden_ptr->setBranchesTotal('-',1);
        //return;
        if ( parents_parent != NULL)
        {
            parents_parent->setNextBranch(NULL);
            weights_total-=parent->getWeightsTotal();
            fruits_total-=parent->getFruitsTotal();
            if ( garden_ptr!=NULL)
            {
                garden_ptr->setWeightsTotal('-',parent->getWeightsTotal());
                garden_ptr->setFruitsTotal('-',parent->getFruitsTotal());
            }
            if ( parent == first_branch)
            {
                first_branch = NULL;
            }
            delete parent;
        }

    }
        height--;
}
}
void TREE_CLASS::harvestTree(unsigned int waga)
{
    BRANCH_CLASS* branch = first_branch;
    while (branch != NULL)
    {
        branch->harvestBranch(waga);
        branch = branch->getNextBranch();
    }
}
void TREE_CLASS::cutTree(unsigned int pos)
{
    if (pos < height)
    {
        if (pos < 3)
        {
            BRANCH_CLASS* branch= first_branch;
            while (branch != NULL)
            {
                BRANCH_CLASS* next = branch->getNextBranch();
                delete branch;
                branch = next;
            }
            first_branch = NULL;
            height = pos;
            if ( garden_ptr!=NULL)garden_ptr->setFruitsTotal('-',fruits_total);
            if ( garden_ptr!=NULL)garden_ptr->setWeightsTotal('-',weights_total);
            branches_count=0;
            fruits_total = 0;
            weights_total = 0;
            return;
        }
        BRANCH_CLASS* branch = first_branch;
        BRANCH_CLASS* parent = NULL;
        while (branch != NULL && branch->getHeight() <= pos)
        {
            parent = branch;
            branch = branch->getNextBranch();
        }
        if (parent != NULL)
        {
            parent->setNextBranch(NULL);
        }
        while (branch != NULL)
        {
            weights_total -= branch->getWeightsTotal();
            fruits_total -= branch->getFruitsTotal();
            if ( garden_ptr!=NULL)
            {
                garden_ptr->setWeightsTotal('-',branch->getWeightsTotal());
                garden_ptr->setFruitsTotal('-',branch->getFruitsTotal());
            }
            BRANCH_CLASS* next = branch->getNextBranch();
            delete branch;
            branch = next;
            branches_count--;
            if ( garden_ptr!=NULL)garden_ptr->setBranchesTotal('-',1);
        }
        height = pos;
    }
}
void TREE_CLASS::cloneBranch(BRANCH_CLASS* klon)
{
    BRANCH_CLASS* branch = first_branch;
    BRANCH_CLASS* prev = NULL;
    while (branch!=NULL)
    {
        if ( branch->getLength()==0)
        {

            unsigned int wysokosc = branch->getHeight();
            BRANCH_CLASS* next = branch->getNextBranch();
            TREE_CLASS* temp = branch->getTreePointer();
            delete branch;
            BRANCH_CLASS* new_branch = new BRANCH_CLASS(*klon);
            if ( prev == NULL)
            {
                first_branch = new_branch;
            }
            else
            {
                prev->setNextBranch(new_branch);
            }
            new_branch->setHeight(wysokosc);
            new_branch->setNextBranch(next);
            new_branch->setTreePointer(temp);
            weights_total+=new_branch->getWeightsTotal();
            fruits_total+=new_branch->getFruitsTotal();
            if ( garden_ptr!=NULL)
            {
                garden_ptr->setWeightsTotal('+',new_branch->getWeightsTotal());
                garden_ptr->setFruitsTotal('+',new_branch->getFruitsTotal());
            }
            return;
        }
        prev = branch;
        branch = branch->getNextBranch();
    }
}