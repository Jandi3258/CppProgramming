//Pawel Jandula
class FRUIT_CLASS;
class TREE_CLASS;

class BRANCH_CLASS {
private:
    unsigned int Height; // na jakiej wys rosnie galaz
    unsigned int Length;
    unsigned int TotalFruits;
    unsigned int TotalWeights;

    FRUIT_CLASS* pierwszyOwoc;
    FRUIT_CLASS* ostatniOwoc; //potrzebne nam do growth na pewno

    TREE_CLASS* KtoreDrzewo;

    BRANCH_CLASS* prev;
    BRANCH_CLASS* next;

public:
    BRANCH_CLASS();

    BRANCH_CLASS(int Wysokosc, int Dlugosc, int TotalFruits1,int TotalWeights1, FRUIT_CLASS* pierwszyOwoc1, FRUIT_CLASS* ostatniOwoc1, TREE_CLASS* KtoreDrzewo1, BRANCH_CLASS* poprzedni,BRANCH_CLASS* nastepny);

    //kopiujacy do tree bedzie potrzebny
    BRANCH_CLASS(const BRANCH_CLASS& copy);



    ~BRANCH_CLASS();

    unsigned int getFruitsTotal();

    unsigned int getWeightsTotal();

    unsigned int getHeight();

    unsigned int getLength();

    void growthBranch();

    void fadeBranch();

    void harvestBranch(unsigned int zmienna);

    void cutBranch(unsigned int zmienna);

    FRUIT_CLASS* getFruitPointer(unsigned int zmienna);

    TREE_CLASS* getTreePointer();

    void addTotalFruits(unsigned int ilosc);

    void addTotalWeights(unsigned int waga);

    void minusTotalFruits(unsigned int ilosc);

    void minusTotalWeights(unsigned int waga);

    BRANCH_CLASS* getNextBranch();
    BRANCH_CLASS* getPrevBranch();
    void setNextBranch(BRANCH_CLASS* nastepny);
    void setPrevBranch(BRANCH_CLASS* poprzedni);
    void setTreePointer(TREE_CLASS* drzewo);

    void setHeight(unsigned int zmienna);
};

