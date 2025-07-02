//Mateusz Paszynski
#include "garden.hpp"
#include <cstdio>
#include "tree.hpp"
#include <cstdlib>
#include <list>
struct GARDEN_CLASS::LISTA_ID
{
    unsigned int id;
    LISTA_ID* next;
    LISTA_ID* prev;
};
//getters
unsigned int GARDEN_CLASS::getTreesTotal()
{
    return trees_total;
}
unsigned int GARDEN_CLASS::getBranchesTotal()
{
    return branches_total;
}
unsigned int GARDEN_CLASS::getFruitsTotal()
{
    return fruits_total;
}
unsigned int GARDEN_CLASS::getWeightsTotal()
{
    return weights_total;
}
unsigned int GARDEN_CLASS::getListaTotal()
{
    return lista_total;
}
TREE_CLASS* GARDEN_CLASS::getTreePointer(unsigned int pos)
{
    TREE_CLASS* head = first_tree;
    TREE_CLASS*tail = last_tree;
    while ( head!=NULL && tail!=NULL)
    {

        if ( head->getNumber() == pos)
        {
            return head;
        }

        if ( tail->getNumber() == pos)
        {
            return tail;
        }
        if (head == tail || head->getNextTree() == tail || tail->getPrevTree() == head)return NULL;
        head = head->getNextTree();
        tail=tail->getPrevTree();
    }
    return NULL;
}
TREE_CLASS* GARDEN_CLASS::getFirstTree()
{
    return first_tree;
}
void GARDEN_CLASS::printList()
{
    LISTA_ID* current = lista;
    while (current!=NULL)
    {
        //printf("%u ", current->id);
        current = current->next;
    }
}
void GARDEN_CLASS::update()
{
    if ( lista_total>0)
    {
        lista_total--;
        LISTA_ID* new_first = lista->next;
        delete lista;
        lista = new_first;
    }
}
unsigned int GARDEN_CLASS::getList()
{
    return lista->id;
}
unsigned int GARDEN_CLASS::getMaxId()
{
    return max_id;
}

//setters
void GARDEN_CLASS::setMaxId(unsigned int id)
{
    if ( max_id < id)
    {
        max_id = id;
    }
}
void  GARDEN_CLASS::setTreesTotal(char c,unsigned int val)
{
    if ( c == '-')trees_total-=val;
    else trees_total+=val;

}
void GARDEN_CLASS::setBranchesTotal(char c,unsigned int val)
{
    if (c == '-')branches_total-=val;
    else branches_total+=val;
}
void GARDEN_CLASS::setFruitsTotal(char c,unsigned int val)
{
    if (c=='-')fruits_total-=val;
    else fruits_total+=val;
}
void GARDEN_CLASS::setWeightsTotal(char c,unsigned int val)
{
    if (c=='-')weights_total-=val;
    else weights_total+=val;
}
void GARDEN_CLASS:: setFirstTree(TREE_CLASS* ptr)
{
    first_tree = ptr;
}
void GARDEN_CLASS::insert(unsigned int val)
{
    LISTA_ID* curr = lista;
    LISTA_ID* prev = NULL;
    while (curr != NULL && curr->id < val)
    {
        prev = curr;
        curr = curr->next;
    }
    LISTA_ID* new_node = new LISTA_ID;
    lista_total++;
    new_node->id = val;
    new_node->next = curr;
    new_node->prev = prev;

    if (prev != NULL)
    {
        prev->next = new_node;
    }
    else
    {
        lista = new_node;
    }
    if (curr != NULL)
    {
        curr->prev = new_node;
    }
    if ( curr ==NULL)
    {
        last_id = prev;
    }
}

//constructors & destructors
GARDEN_CLASS::~GARDEN_CLASS()
{
    TREE_CLASS* root= first_tree;
    while(root!=NULL)
    {
        TREE_CLASS* next = root->getNextTree();
        delete root;
        root = next;
    }
    LISTA_ID* curr = lista;
    while(curr!=NULL)
    {
        LISTA_ID* next = curr->next;
        delete curr;
        curr = next;
    }

}
GARDEN_CLASS::GARDEN_CLASS()
{
    last_id = NULL;
    last_tree = NULL;
    trees_total = 0;
    first_tree = NULL;
    fruits_total = 0;
    branches_total = 0;
    weights_total = 0;
    max_id = 0;
    lista_total = 0;
    lista = NULL;

}
//metody
void GARDEN_CLASS::growthGarden()
{
    TREE_CLASS* root = first_tree;
        while( root !=NULL)
        {
            root->growthTree();
            root = root->getNextTree();
        }
    }

void GARDEN_CLASS::fadeGarden()
{
    if ( trees_total>0)
    {
        TREE_CLASS* root = first_tree;
    for ( unsigned int i = 0;i<trees_total;i++)
    {
        if ( root !=NULL)
        {
            root->fadeTree();
            root = root->getNextTree();
        }
    }
}
}
void GARDEN_CLASS::harvestGarden(unsigned int waga)
{
    TREE_CLASS* tree = first_tree;
    while (tree != NULL)
    {
        tree->harvestTree(waga);

        tree = tree->getNextTree();
    }
}
void GARDEN_CLASS::cloneTree(unsigned int id)
{
    TREE_CLASS* head_f = first_tree;
    TREE_CLASS* tail_f = last_tree;
    TREE_CLASS* gdzie_wstawie = NULL;
    unsigned int newId;
    if ( lista_total == 0)
    {
        newId = max_id;
    }
    else
    {
        newId = lista->id;
    }
    int found = 0;
    while (head_f != NULL && tail_f!=NULL)
    {
        if (( newId < head_f->getNumber()) && (found == 0))
        {
            found = -1;
            gdzie_wstawie = head_f;
        }
        if ((newId>tail_f->getNumber()) && (found == 0))
        {
            found = 1;
            gdzie_wstawie = tail_f;
        }
        if ( head_f->getNumber()==id || tail_f->getNumber()==id)
        {
            TREE_CLASS* new_tree;
            //printf("znalazlem");return;
            if ( head_f->getNumber()==id)new_tree = new TREE_CLASS(*head_f);
            else  new_tree = new TREE_CLASS(*tail_f);
            new_tree->setGardenPtr(this);
            if ( lista_total == 0)
            {
                new_tree->setNumber(max_id++);
            }
            else
            {
                new_tree->setNumber(lista->id);
                lista_total--;
                LISTA_ID* new_first = lista->next;
                delete lista;
                lista = new_first;
            }
            trees_total++;
            weights_total+=new_tree->getWeightsTotal();
            fruits_total+=new_tree->getFruitsTotal();
            branches_total+=new_tree->getBranchesTotal();
            if ( found == 1)
            {
                if (gdzie_wstawie && gdzie_wstawie->getNextTree()==NULL)
                {
                    last_tree = new_tree;
                }
                else
                {
                    if (gdzie_wstawie)gdzie_wstawie->setNextTree(gdzie_wstawie->getNextTree());
                    if (gdzie_wstawie)gdzie_wstawie->getNextTree()->setPrevTree(new_tree);
                }
                new_tree->setPrevTree(gdzie_wstawie);
                if (gdzie_wstawie)gdzie_wstawie->setNextTree(new_tree);
            }
            if (found == -1)
            {
                if ( gdzie_wstawie&& gdzie_wstawie->getPrevTree()==NULL)
                {
                    first_tree = new_tree;
                }
                else
                {
                    if (gdzie_wstawie)new_tree->setPrevTree(gdzie_wstawie->getPrevTree());
                   if (gdzie_wstawie) gdzie_wstawie->getPrevTree()->setNextTree(new_tree);
                }
                new_tree->setNextTree(gdzie_wstawie);
                if (gdzie_wstawie)gdzie_wstawie->setPrevTree(new_tree);
            }
            return;
        }
        head_f=head_f->getNextTree();
        tail_f=tail_f->getPrevTree();
    }
}
void GARDEN_CLASS::plantTree()
{
    TREE_CLASS* new_tree;
    if ( lista_total == 0)
    {
       new_tree = new TREE_CLASS(this,max_id++);
    }
    else
    {
       new_tree = new TREE_CLASS(this,lista->id);
        lista_total--;
        LISTA_ID* new_first = lista->next;
        delete lista;
        lista = new_first;
    }
    trees_total++;

    TREE_CLASS* head = first_tree;
    TREE_CLASS* tail = last_tree;
    if ( head == NULL)
    {
        first_tree = new_tree;
        last_tree = new_tree;
        new_tree->setNextTree(NULL);
        new_tree->setPrevTree(NULL);
        return;
    }
    while ( (head!=NULL && tail!=NULL) )
    {
        if ( head->getNumber() > new_tree->getNumber())
        {
            if ( head->getPrevTree()==NULL)
            {
                first_tree = new_tree;
                new_tree->setPrevTree(NULL);
            }
            else {
                head->getPrevTree()->setNextTree(new_tree);
                new_tree->setPrevTree(head->getPrevTree());
        }
            head->setPrevTree(new_tree);
            new_tree->setNextTree(head);


            return;
        }
        head=head->getNextTree();
        if ( tail->getNumber() < new_tree->getNumber())
        {
            if ( tail->getNextTree() == NULL)
            {
                last_tree = new_tree;
                new_tree->setNextTree(NULL);
            }
            else
            {
                tail->getNextTree()->setPrevTree(new_tree);
                new_tree->setNextTree(tail->getNextTree());
            }
            new_tree->setPrevTree(tail);
            tail->setNextTree(new_tree);
            return;
        }
        tail = tail->getPrevTree();
    }
    // if (head == tail)
    // {
    //     head->setNextTree(new_tree);
    //     new_tree->setPrevTree(head);
    // }
}
void GARDEN_CLASS::extractTree(unsigned int pos)
{
    if ( pos < max_id)
    {
        TREE_CLASS* head = first_tree;
        TREE_CLASS*tail = last_tree;
        if ( first_tree == last_tree && head->getNumber()==pos)
        {
            trees_total--;
            weights_total-=head->getWeightsTotal();
            fruits_total-=head->getFruitsTotal();
            branches_total-=head->getBranchesTotal();
            first_tree = NULL;
            last_tree = NULL;
            delete head;
            return;
        }
    while (head!=NULL && tail!=NULL)
    {

        if (head->getNumber()==pos)
        {
            insert(head->getNumber());
            if ( head->getPrevTree() == NULL)
            {
                first_tree = head->getNextTree();
                head->getNextTree()->setPrevTree(NULL);
            }
            else
            {
                head->getPrevTree()->setNextTree(head->getNextTree());
                head->getNextTree()->setPrevTree(head->getPrevTree());
               // prev->setNextTree(root->getNextTree());
            }
            weights_total-=head->getWeightsTotal();
            fruits_total-=head->getFruitsTotal();
            branches_total-=head->getBranchesTotal();
            trees_total--;
            delete head;
            return;
        }
        head = head->getNextTree();
        if (tail->getNumber()==pos)
        {
            insert(tail->getNumber());
            if ( tail->getNextTree() == NULL)
            {
                last_tree =tail->getPrevTree();
                tail->getPrevTree()->setNextTree(NULL);
            }
            else
            {
                tail->getNextTree()->setPrevTree(tail->getPrevTree());
                tail->getPrevTree()->setNextTree(tail->getNextTree());
                //prev->setNextTree(root->getNextTree());
            }
            weights_total-=tail->getWeightsTotal();
            fruits_total-=tail->getFruitsTotal();
            branches_total-=tail->getBranchesTotal();
            trees_total--;
            delete tail;
            return;
        }
        tail = tail->getPrevTree();

    }
}
}