//Mateusz Paszynski
class TREE_CLASS;
class FRUIT_CLASS;
class BRANCH_CLASS;
class GARDEN_CLASS {

    unsigned int trees_total;
    TREE_CLASS* first_tree;

    TREE_CLASS* last_tree;

    unsigned int fruits_total;
    unsigned int branches_total;
    unsigned int weights_total;
    struct LISTA_ID;
    LISTA_ID* lista;
    unsigned int max_id;
    unsigned int lista_total;
    LISTA_ID* last_id;

public :
    //constructors & destructors
    GARDEN_CLASS();
    ~GARDEN_CLASS();

    //getters
    unsigned int getListaTotal();
    unsigned int getTreesTotal();
    unsigned int getBranchesTotal();
    unsigned int getFruitsTotal();
    unsigned int getWeightsTotal();
    TREE_CLASS* getFirstTree();
    TREE_CLASS*getTreePointer(unsigned int);
    void printList();
    unsigned int getList();
    unsigned int getMaxId();

    //setters
    void update();
    void setMaxId(unsigned int);
    void insert(unsigned int);
    void setFirstTree(TREE_CLASS*);
    void setTreesTotal(char,unsigned int);
    void setBranchesTotal(char, unsigned int);
    void setFruitsTotal(char, unsigned int);
    void setWeightsTotal(char, unsigned int);

    //methods
    void plantTree();
    void extractTree(unsigned int);
    void growthGarden();
    void fadeGarden();
    void harvestGarden(unsigned int);
    void cloneTree(unsigned int);
};