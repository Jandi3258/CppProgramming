//Pawel Jandula
class GARDEN_CLASS;
class BRANCH_CLASS;

class TREE_CLASS{
private:
    unsigned int UnikalnyNumer;
    unsigned int height;
    unsigned int BranchesTotal;
    unsigned int FruitsTotal;
    unsigned int WeightsTotal;

    GARDEN_CLASS* wKtorymOgrodzie;

    TREE_CLASS* prevT;
    TREE_CLASS* nextT;

    BRANCH_CLASS* firstB;
    BRANCH_CLASS* lastB;

public:
    TREE_CLASS();

    TREE_CLASS(const TREE_CLASS& copy);

    TREE_CLASS(unsigned int id, GARDEN_CLASS* ogrod, TREE_CLASS* prev, TREE_CLASS* next);

    ~TREE_CLASS();

    unsigned int getBranchesTotal();

    unsigned int getFruitsTotal();

    unsigned int getWeightsTotal();

    unsigned int getNumber();

    unsigned int getHeight();

    void growthTree();

    void fadeTree();

    void harvestTree(unsigned int waga);

    void cutTree(unsigned int zmienna);

    void cloneBranch(BRANCH_CLASS* nazwa);

    GARDEN_CLASS* getGardenPointer();

    BRANCH_CLASS* getBranchPointer(unsigned int n);

    //////////////////////////////////////////

    void setGardenPointer(GARDEN_CLASS* ogrod);

    void addTotalBranches();
    void minusTotalBranches();

    void addTreeFruits(unsigned int count);
    void minusTreeFruits(unsigned int count);
    void addTreeWeight(unsigned int weight);
    void minusTreeWeight(unsigned int weight);

    TREE_CLASS* getNextTree();
    TREE_CLASS* getPrevTree();

    void setUnikalnyNumer(unsigned int numer);

    void setPrevTree(TREE_CLASS* drzewo);
    void setNextTree(TREE_CLASS* drzewo);
};
