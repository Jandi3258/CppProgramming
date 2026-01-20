//Pawel Jandula
#include "garden.hpp"
#include "tree.hpp"
#include<cstdlib>
GARDEN_CLASS::GARDEN_CLASS() {
    this->IleDrzewWOgrodzie = 0;
    this->IleGaleziWOgrodzie = 0;
    this->IleOwocowWOgrodzie = 0;
    this->WeightsTotal = 0;
    this->firstT = NULL;
    this->lastT = NULL;
    this->firstFreeSortedID = NULL;
    this->lastFreeSortedID = NULL;
}
GARDEN_CLASS::GARDEN_CLASS(const GARDEN_CLASS& other) {
    this->IleDrzewWOgrodzie = 0;
    this->IleGaleziWOgrodzie = 0;
    this->IleOwocowWOgrodzie = 0;
    this->WeightsTotal = 0;
    this->firstT = NULL;
    this->lastT = NULL;
    this->firstFreeSortedID = NULL;
    this->lastFreeSortedID = NULL;

    TREE_CLASS* currentOtherTree = other.firstT;
    while (currentOtherTree != NULL) {
        TREE_CLASS* newTree = new TREE_CLASS(*currentOtherTree);

        newTree->setGardenPointer(this);
        newTree->setUnikalnyNumer(currentOtherTree->getNumber());
        if (this->firstT == NULL) {
            this->firstT = newTree;
            this->lastT = newTree;
        }
        else {
            this->lastT->setNextTree(newTree);
            newTree->setPrevTree(this->lastT);
            this->lastT = newTree;
        }
        this->IleDrzewWOgrodzie++;
        this->IleGaleziWOgrodzie += newTree->getBranchesTotal();
        this->IleOwocowWOgrodzie += newTree->getFruitsTotal();
        this->WeightsTotal += newTree->getWeightsTotal();

        currentOtherTree = currentOtherTree->getNextTree();
    }
    TREE_CLASS* currentOtherFreeID = other.firstFreeSortedID;
    while (currentOtherFreeID != NULL) {
        TREE_CLASS* newFreeIDNode = new TREE_CLASS(currentOtherFreeID->getNumber(), this, NULL, NULL);
        if (this->firstFreeSortedID == NULL) {
            this->firstFreeSortedID = newFreeIDNode;
            this->lastFreeSortedID = newFreeIDNode;
        } else {
            this->lastFreeSortedID->setNextTree(newFreeIDNode);
            newFreeIDNode->setPrevTree(this->lastFreeSortedID);
            this->lastFreeSortedID = newFreeIDNode;
        }
        currentOtherFreeID = currentOtherFreeID->getNextTree();
    }
}
GARDEN_CLASS::~GARDEN_CLASS(){
    TREE_CLASS* wskaznik = firstT;
    TREE_CLASS* next = NULL;
    while(wskaznik != NULL){
        next = wskaznik->getNextTree();
        delete wskaznik;
        wskaznik = next;
    }
    TREE_CLASS* freewskaznik = firstFreeSortedID;
    TREE_CLASS* nextfree = NULL;
    while(freewskaznik != NULL){
        nextfree = freewskaznik->getNextTree();
        delete freewskaznik;
        freewskaznik = nextfree;
    }
    this->firstT =NULL;
    this->lastT = NULL;
    this->firstFreeSortedID = NULL;
    this->lastFreeSortedID = NULL;
    this->IleDrzewWOgrodzie = 0;
    this->IleGaleziWOgrodzie = 0;
    this->IleOwocowWOgrodzie = 0;
    this->WeightsTotal = 0;
}

unsigned int GARDEN_CLASS::getTreesTotal() {
    return IleDrzewWOgrodzie;
}

unsigned int GARDEN_CLASS::getBranchesTotal() {
    return IleGaleziWOgrodzie;
}

unsigned int GARDEN_CLASS::getFruitsTotal() {
    return IleOwocowWOgrodzie;
}

unsigned int GARDEN_CLASS::getWeightsTotal() {
    return WeightsTotal;
}

void GARDEN_CLASS::plantTree() {
    unsigned int idik;
    TREE_CLASS* pierwszywolny = firstFreeSortedID;
    if(pierwszywolny != NULL){
        idik = pierwszywolny->getNumber();
        TREE_CLASS* nastepnyWolny = pierwszywolny->getNextTree();
        if(firstFreeSortedID == lastFreeSortedID) {
            firstFreeSortedID = NULL;
            lastFreeSortedID = NULL;
        }
        else {
            firstFreeSortedID = nastepnyWolny;
            if (firstFreeSortedID != NULL) {
                firstFreeSortedID->setPrevTree(NULL);
            }
        }
        delete pierwszywolny;
        pierwszywolny = NULL;
    }
    else {
        idik = this->IleDrzewWOgrodzie;
    }
    IleDrzewWOgrodzie++;

    TREE_CLASS* nowedrzewo = new TREE_CLASS(idik, this, NULL, firstT);
    if (this->firstT != NULL) {
        this->firstT->setPrevTree(nowedrzewo);
    }
    else {
        this->lastT = nowedrzewo;
    }
    this->firstT = nowedrzewo;
}
void GARDEN_CLASS::addIdToFreeList(unsigned int id) {
    TREE_CLASS* newFreeNode = new TREE_CLASS(id, this, NULL, NULL);
    if (firstFreeSortedID == NULL) {
        firstFreeSortedID = newFreeNode;
        lastFreeSortedID = newFreeNode;
    }
    else if (id < firstFreeSortedID->getNumber()) {
        newFreeNode->setNextTree(firstFreeSortedID);
        firstFreeSortedID->setPrevTree(newFreeNode);
        firstFreeSortedID = newFreeNode;
    }
    else if (id > lastFreeSortedID->getNumber()) {
        newFreeNode->setPrevTree(lastFreeSortedID);
        lastFreeSortedID->setNextTree(newFreeNode);
        lastFreeSortedID = newFreeNode;
    }
    else {
        TREE_CLASS* current = firstFreeSortedID->getNextTree();
        while (current != NULL && current->getNumber() < id) {
            current = current->getNextTree();
        }
        if (current != NULL) {
            newFreeNode->setNextTree(current);
            newFreeNode->setPrevTree(current->getPrevTree());
            current->getPrevTree()->setNextTree(newFreeNode);
            current->setPrevTree(newFreeNode);
        }

    }
}
void GARDEN_CLASS::extractTree(unsigned int id) {
    if (firstT == NULL) {
        return;
    }
    TREE_CLASS* wskaznik = NULL;
    if (firstT->getNumber() == id) {
        wskaznik = firstT;
        firstT = firstT->getNextTree();
        if (firstT != NULL) {
            firstT->setPrevTree(NULL);
        } else {
            lastT = NULL;
        }
    }
    else if (lastT != NULL && lastT->getNumber() == id) {
        wskaznik = lastT;
        lastT = lastT->getPrevTree();
        if (lastT != NULL) {
            lastT->setNextTree(NULL);
        }
        else {
            firstT = NULL;
        }
    }
    else {
        TREE_CLASS* current = firstT->getNextTree();
        while (current != NULL && current != lastT) {
            if (current->getNumber() == id) {
                wskaznik = current;
                current->getPrevTree()->setNextTree(current->getNextTree());
                current->getNextTree()->setPrevTree(current->getPrevTree());
                break;
            }
            current = current->getNextTree();
        }
    }

    if (wskaznik != NULL) {
        unsigned int freedID = wskaznik->getNumber();
        IleDrzewWOgrodzie--;
        this->minusBranchesTotal(wskaznik->getBranchesTotal());
        addIdToFreeList(freedID);
        delete wskaznik;
        wskaznik = NULL;
    }
}
void GARDEN_CLASS::growthGarden() {
    TREE_CLASS* wskaznik = firstT;
    while(wskaznik != NULL){
        wskaznik->growthTree();
        wskaznik = wskaznik->getNextTree();
    }
}

void GARDEN_CLASS::fadeGarden() {
    TREE_CLASS* wskaznik = firstT;
    while(wskaznik != NULL){
        wskaznik->fadeTree();
        wskaznik = wskaznik->getNextTree();
    }
}

void GARDEN_CLASS::harvestGarden(unsigned int h) {
    TREE_CLASS* wskaznik = firstT;
    while(wskaznik != NULL){
        wskaznik->harvestTree(h);
        wskaznik = wskaznik->getNextTree();
    }
}

TREE_CLASS *GARDEN_CLASS::getTreePointer(unsigned int id) {// tu mozliwe ze optymalizacja bedzie potrzebna
    TREE_CLASS* wskaznik = firstT;
    while(wskaznik != NULL){
        if(wskaznik->getNumber() == id){
            return wskaznik;
        }
        wskaznik = wskaznik->getNextTree();
    }
    return NULL; //lub return wskaznik na to samo wyjdzie
}


void GARDEN_CLASS::cloneTree(unsigned int id) {
    TREE_CLASS* pom = getTreePointer(id);
    if (pom == NULL) {
        return;
    }
    unsigned int CloneID;
    TREE_CLASS* pierwszywolny = this->firstFreeSortedID;
    if (pierwszywolny != NULL) {
        CloneID = pierwszywolny->getNumber();
        TREE_CLASS* NastepnyWolny = pierwszywolny->getNextTree();
        if (this->firstFreeSortedID == this->lastFreeSortedID) {
            this->firstFreeSortedID = NULL;
            this->lastFreeSortedID = NULL;
        }
        else {
            this->firstFreeSortedID = NastepnyWolny;
            if (this->firstFreeSortedID != NULL) {
                this->firstFreeSortedID->setPrevTree(NULL);
            }
        }
        delete pierwszywolny;
        pierwszywolny = NULL;
    }
    else {
        CloneID = this->IleDrzewWOgrodzie;
    }
    TREE_CLASS* TreeClone = new TREE_CLASS(*pom);
    TreeClone->setUnikalnyNumer(CloneID);
    TreeClone->setGardenPointer(this);
    TreeClone->setNextTree(this->firstT);
    TreeClone->setPrevTree(NULL);

    if (this->firstT != NULL) {
        this->firstT->setPrevTree(TreeClone);
    }
    else {
        this->lastT = TreeClone;
    }
    this->firstT = TreeClone;
    this->IleDrzewWOgrodzie++;
    this->IleGaleziWOgrodzie += TreeClone->getBranchesTotal();
    this->IleOwocowWOgrodzie += TreeClone->getFruitsTotal();
    this->WeightsTotal += TreeClone->getWeightsTotal();
}

void GARDEN_CLASS::addTreesTotal(unsigned int zmienna) {
    this->IleDrzewWOgrodzie += zmienna;
}

void GARDEN_CLASS::addBranchesTotal(unsigned int zmienna) {
    this->IleGaleziWOgrodzie += zmienna;
}

void GARDEN_CLASS::addFruitsTotal(unsigned int zmienna) {
    this->IleOwocowWOgrodzie += zmienna;
}

void GARDEN_CLASS::addWeightsTotal(unsigned int zmienna) {
    this->WeightsTotal += zmienna;
}
void GARDEN_CLASS::minusTreesTotal(unsigned int zmienna) {
    this->IleDrzewWOgrodzie -= zmienna;
}

void GARDEN_CLASS::minusBranchesTotal(unsigned int zmienna) {
    this->IleGaleziWOgrodzie -= zmienna;
}

void GARDEN_CLASS::minusFruitsTotal(unsigned int zmienna) {
    this->IleOwocowWOgrodzie -= zmienna;
}

void GARDEN_CLASS::minusWeightsTotal(unsigned int zmienna) {
    this->WeightsTotal -= zmienna;
}


