//Mateusz Paszynski
class BRANCH_CLASS;
class GARDEN_CLASS;
class TREE_CLASS;
class FRUIT_CLASS
{
    unsigned int weight;
    BRANCH_CLASS* branch_ptr;
    FRUIT_CLASS* next_fruit;
    unsigned int pos;
public:
    void setWeight(unsigned int val);
    FRUIT_CLASS(const FRUIT_CLASS&);
    FRUIT_CLASS(BRANCH_CLASS*,unsigned int);
    void setBranchPtr(BRANCH_CLASS* ptr);
    FRUIT_CLASS();
    FRUIT_CLASS* getNextFruit();
    void setNextFruit(FRUIT_CLASS*);
    unsigned int getLength();
    unsigned int getWeight();
    void growthFruit();
    void fadeFruit();
    void pluckFruit();
    BRANCH_CLASS* getBranchPointer();
};
