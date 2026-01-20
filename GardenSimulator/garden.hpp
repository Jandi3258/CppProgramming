//Pawel Jandula
class TREE_CLASS;

class GARDEN_CLASS{
private:
    TREE_CLASS* firstT;
    TREE_CLASS* lastT;
    TREE_CLASS* firstFreeSortedID;
    TREE_CLASS* lastFreeSortedID;
    unsigned int IleDrzewWOgrodzie;
    unsigned int IleGaleziWOgrodzie;
    unsigned int IleOwocowWOgrodzie;
    unsigned int WeightsTotal;
public:
    GARDEN_CLASS();

    GARDEN_CLASS(const GARDEN_CLASS& kopia);

    ~GARDEN_CLASS();

    unsigned int getTreesTotal();

    unsigned int getBranchesTotal();

    unsigned int getFruitsTotal();

    unsigned int getWeightsTotal();

    void plantTree();

    void extractTree(unsigned int h);

    void growthGarden();

    void fadeGarden();

    void harvestGarden(unsigned int h);

    TREE_CLASS* getTreePointer(unsigned int h);

    void cloneTree(unsigned int h);

    void addIdToFreeList(unsigned int id);

    void addTreesTotal(unsigned int zmienna);
    void addBranchesTotal(unsigned int zmienna);
    void addFruitsTotal(unsigned int zmienna);
    void addWeightsTotal(unsigned int zmienna);

    void minusTreesTotal(unsigned int zmienna);
    void minusBranchesTotal(unsigned int zmienna);
    void minusFruitsTotal(unsigned int zmienna);
    void minusWeightsTotal(unsigned int zmienna);
};
