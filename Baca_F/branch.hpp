//Mateusz Paszynski
class TREE_CLASS;
class FRUIT_CLASS;
class GARDEN_CLASS;
class BRANCH_CLASS
{
private:
    unsigned int height;
    unsigned int length;
    unsigned int fruit_count;
    unsigned int weights_total;
    FRUIT_CLASS* first_fruit;
    TREE_CLASS* tree_ptr;
    BRANCH_CLASS* next_branch;
public:
    //constructors & destructors
    void setHeight(unsigned int);
    void setTreePointer(TREE_CLASS* ptr);
    ~BRANCH_CLASS();
    BRANCH_CLASS();
    BRANCH_CLASS(const BRANCH_CLASS&);
    BRANCH_CLASS(TREE_CLASS*ptr,unsigned int pos);

    //getters
    unsigned int getFruitsTotal() ;
    unsigned int getWeightsTotal();
    unsigned int getHeight();
    unsigned int getLength();
    FRUIT_CLASS*getFruitPointer(unsigned int);
    TREE_CLASS*getTreePointer();
    FRUIT_CLASS* getFirst_Fruit();
    BRANCH_CLASS* getNextBranch();

    //setters
    void setFruitsTotal(char c, unsigned int val);
    void setNextBranch(BRANCH_CLASS*);
    void setWeightsTotal( char ,unsigned int );


    //methods

    void growthBranch();
    void fadeBranch();
    void harvestBranch(unsigned int);
    void cutBranch(unsigned int);

};