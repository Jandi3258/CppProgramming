//Pawel Jandula
class BRANCH_CLASS;

class FRUIT_CLASS{
private:
    unsigned int weight;
    unsigned int length;
    FRUIT_CLASS* prev;
    FRUIT_CLASS* next;
    BRANCH_CLASS* NaKtorymKrzaku;

public:
    FRUIT_CLASS();

    //Konstruktor z argumentami
    FRUIT_CLASS(unsigned int weight, unsigned int length, FRUIT_CLASS* prev, FRUIT_CLASS* next, BRANCH_CLASS* NaKtorymKrzaku);

    //Konstruktor kopiujacy
    FRUIT_CLASS(const FRUIT_CLASS& fruit);

    //konstruktor do brancha
    FRUIT_CLASS(unsigned int lengthPom, BRANCH_CLASS* brbr, FRUIT_CLASS* prevPom, FRUIT_CLASS* nextPom);
    ~FRUIT_CLASS();

    unsigned int getLength();

    unsigned int getWeight();

    void growthFruit();

    void fadeFruit();

    void pluckFruit();

    BRANCH_CLASS* getBranchPointer();
    ///////////////////////////////////////////////////////////////
    FRUIT_CLASS* getNextPointer();

    FRUIT_CLASS* getPrevPointer();
    void setNextPointer(FRUIT_CLASS* zmienna);
    void setPrevPointer(FRUIT_CLASS* zmienna);
    void setBranchPointer(BRANCH_CLASS* branch);
};
