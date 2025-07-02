//Mateusz Paszynski
class GARDEN_CLASS;
class FRUIT_CLASS;
class BRANCH_CLASS;
class TREE_CLASS
{
    unsigned int id;
    unsigned int height;
    unsigned int branches_count;
    BRANCH_CLASS* first_branch;
    unsigned int weights_total;
    unsigned int fruits_total;
    TREE_CLASS* next_tree;
    TREE_CLASS* prev_tree;
    GARDEN_CLASS* garden_ptr;
public :
    //constructors & destructors
    TREE_CLASS();
    TREE_CLASS(GARDEN_CLASS*,unsigned int);
    TREE_CLASS(const TREE_CLASS&);
    ~TREE_CLASS();

    //getters
    TREE_CLASS* getPrevTree();
    void setPrevTree(TREE_CLASS*);
    TREE_CLASS* getNextTree();
    BRANCH_CLASS* getFirstBranch();
    unsigned int getBranchesTotal();
    unsigned int getFruitsTotal();
    unsigned int getWeightsTotal();
    unsigned int getNumber();
    unsigned int getHeight();
    void setNumber(unsigned int num);
    GARDEN_CLASS*getGardenPointer();
    BRANCH_CLASS* getBranchPointer(unsigned int);
   void setGardenPtr(GARDEN_CLASS* ptr);
    //setters
    void setBranchesTotal(unsigned int);
    void setWeightsTotal(char, unsigned int);
    void setFruitsTotal(char c, unsigned int val);
    void setNextTree(TREE_CLASS*);
    void setFirstBranch(BRANCH_CLASS*);

    //methods
    void growthTree();
    void fadeTree();
    void harvestTree(unsigned int);
    void cutTree(unsigned int);
    void cloneBranch(BRANCH_CLASS*);

};