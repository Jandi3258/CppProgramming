//Pawel Jandula
#include "tree.hpp"
#include "branch.hpp"
#include "garden.hpp"
#include<cstdlib>
TREE_CLASS::TREE_CLASS() {
    this->UnikalnyNumer = 0;
    this->height = 0;
    this->BranchesTotal = 0;
    this->FruitsTotal = 0;
    this->WeightsTotal = 0;
    this->wKtorymOgrodzie = NULL;
    this->prevT = NULL;
    this->nextT = NULL;
    this->firstB = NULL;
    this->lastB = NULL;
}
TREE_CLASS::TREE_CLASS(unsigned int id, GARDEN_CLASS* ogrod, TREE_CLASS* prev, TREE_CLASS* next){
    this->UnikalnyNumer = id;
    this->height = 0;
    this->BranchesTotal = 0;
    this->FruitsTotal = 0;
    this->WeightsTotal = 0;
    this->wKtorymOgrodzie = ogrod;
    this->prevT = prev;
    this->nextT = next;
    this->firstB = NULL;
    this->lastB = NULL;
}


TREE_CLASS::TREE_CLASS(const TREE_CLASS &copy) {
    this->UnikalnyNumer = 0; //ogrod nada mu id
    this->height = copy.height;
    this->BranchesTotal = 0;
    this->FruitsTotal = 0;
    this->WeightsTotal = 0;
    this->wKtorymOgrodzie = NULL;
    this->prevT = NULL;
    this->nextT = NULL;
    this->firstB = NULL;
    this->lastB = NULL;

    //kopiujemy krzaczki
    BRANCH_CLASS* wskaznik = copy.firstB;
    while(wskaznik != NULL){
        BRANCH_CLASS* newBranch = new BRANCH_CLASS(*wskaznik);
        newBranch->setTreePointer(this);
        if (this->firstB == NULL) {
            this->firstB = newBranch;
        }
        else {
            this->lastB->setNextBranch(newBranch);
            newBranch->setPrevBranch(this->lastB);
        }
        this->lastB = newBranch;
        this->BranchesTotal++;
        this->FruitsTotal += newBranch->getFruitsTotal();
        this->WeightsTotal += newBranch->getWeightsTotal();

        wskaznik = wskaznik->getNextBranch();
    }
}

TREE_CLASS::~TREE_CLASS(){
    BRANCH_CLASS* currentBranch = firstB;
    BRANCH_CLASS* nextBranch = NULL;
    while (currentBranch != NULL) {
        nextBranch = currentBranch->getNextBranch();
        delete currentBranch;
        currentBranch = nextBranch;
    }
    this->firstB = NULL;
    this->lastB = NULL;
    this->UnikalnyNumer = 0;
    this->height = 0;
    this->BranchesTotal = 0;
    this->FruitsTotal = 0;
    this->WeightsTotal = 0;
}

unsigned int TREE_CLASS::getBranchesTotal() {
    return this->BranchesTotal;
}

unsigned int TREE_CLASS::getFruitsTotal() {
    return this->FruitsTotal;
}

unsigned int TREE_CLASS::getWeightsTotal() {
    return this->WeightsTotal;
}

unsigned int TREE_CLASS::getNumber() {
    return this->UnikalnyNumer;
}

unsigned int TREE_CLASS::getHeight() {
    return this->height;
}

void TREE_CLASS::growthTree() {
    height++;
    BRANCH_CLASS* wskaznik;
    wskaznik = firstB;
    while(wskaznik != NULL){
        wskaznik->growthBranch();
        wskaznik = wskaznik->getNextBranch();
    }
    if(height % 3 == 0){
        BRANCH_CLASS* nowyBranch = new BRANCH_CLASS(height, 0, 0, 0, NULL, NULL, this, lastB, NULL);
        if(firstB == NULL){
            firstB = nowyBranch;
            lastB = nowyBranch;
        }
        else { //firstB != NULL
            lastB->setNextBranch(nowyBranch);
            lastB = nowyBranch;

        }
        BranchesTotal++;
        if(this->wKtorymOgrodzie != NULL){
            this->wKtorymOgrodzie->addBranchesTotal(1);
        }
    }
}

void TREE_CLASS::fadeTree() {
    if(height > 0){
        height--;
        BRANCH_CLASS* wskaznik = firstB;
        while(wskaznik != NULL){
            if(height < wskaznik->getHeight()){//usuwamy brancha i przepinamy
                BRANCH_CLASS* doUsuniecia = wskaznik;
                BRANCH_CLASS* prevBranch = doUsuniecia->getPrevBranch();
                BRANCH_CLASS* nextBranch = doUsuniecia->getNextBranch();
                wskaznik = nextBranch;
                if (prevBranch != NULL){
                    prevBranch->setNextBranch(nextBranch);
                }
                else{
                    firstB = nextBranch;
                }
                if(nextBranch != NULL){
                    nextBranch->setPrevBranch(prevBranch);
                }
                else {
                    lastB = prevBranch;
                }
                if(BranchesTotal > 0){
                    BranchesTotal -= 1;
                    if (this->wKtorymOgrodzie != NULL) {
                        this->wKtorymOgrodzie->minusBranchesTotal(1);
                    }
                }

                delete doUsuniecia;//zeby nie usuwac aktualnego i zrobic przepiecie
                doUsuniecia = NULL;
            }
            else{
                wskaznik->fadeBranch();
                wskaznik = wskaznik->getNextBranch();
            }
        }
    }
}

void TREE_CLASS::harvestTree(unsigned int waga) {
    BRANCH_CLASS* wskaznik = firstB;
    while(wskaznik != NULL){
        wskaznik->harvestBranch(waga);
        wskaznik = wskaznik->getNextBranch();
    }
}

void TREE_CLASS::cutTree(unsigned int zmienna) {
    if(zmienna < height){
        height = zmienna;
        BRANCH_CLASS* wskaznik = firstB;
        unsigned int ileBranchesDoUsuniecia = 0;
        while(wskaznik != NULL){
            if(wskaznik->getHeight() > height){
                BRANCH_CLASS* doUsuniecia = wskaznik;
                BRANCH_CLASS* prevBranch = doUsuniecia->getPrevBranch();
                BRANCH_CLASS* nextBranch = doUsuniecia->getNextBranch();
                wskaznik = nextBranch;
                if (prevBranch != NULL) {
                    prevBranch->setNextBranch(nextBranch);
                }
                else {
                    firstB = nextBranch;
                }
                if(nextBranch != NULL){
                    nextBranch->setPrevBranch(prevBranch);
                }
                else {
                    lastB = prevBranch;
                }
                ileBranchesDoUsuniecia += 1;

                delete doUsuniecia;
                doUsuniecia = NULL;

            }
            else
                wskaznik = wskaznik->getNextBranch();
        }
        if(ileBranchesDoUsuniecia > 0) {
            BranchesTotal -= ileBranchesDoUsuniecia;
            if (this->wKtorymOgrodzie != NULL) {
                this->wKtorymOgrodzie->minusBranchesTotal(ileBranchesDoUsuniecia);
            }
        }
    }
}

void TREE_CLASS::cloneBranch(BRANCH_CLASS* Klon) {
    if (Klon == NULL) {
        return;
    }
    BRANCH_CLASS *wskaznik = firstB;
    while (wskaznik != NULL) {
        if (wskaznik->getLength() == 0) {
            BRANCH_CLASS *nowyKlon = new BRANCH_CLASS(*Klon);
            nowyKlon->setTreePointer(this);
            nowyKlon->setHeight(wskaznik->getHeight());
            this->addTreeFruits(nowyKlon->getFruitsTotal());
            this->addTreeWeight(nowyKlon->getWeightsTotal());

            BRANCH_CLASS *prevBranch = wskaznik->getPrevBranch();
            BRANCH_CLASS *nextBranch = wskaznik->getNextBranch();

            nowyKlon->setNextBranch(nextBranch);
            nowyKlon->setPrevBranch(prevBranch);
            if (prevBranch != NULL) {
                prevBranch->setNextBranch(nowyKlon);
            }
            else {
                this->firstB = nowyKlon;
            }
            if (nextBranch != NULL) {
                nextBranch->setPrevBranch(nowyKlon);
            }
            else {
                this->lastB = nowyKlon;
            }
            delete wskaznik;
            wskaznik = NULL;
            break;
        }
        wskaznik = wskaznik->getNextBranch();
    }
}

GARDEN_CLASS *TREE_CLASS::getGardenPointer() {
    return wKtorymOgrodzie;
}

BRANCH_CLASS *TREE_CLASS::getBranchPointer(unsigned int n) {
    if(height < n) return NULL;
    BRANCH_CLASS* wskaznik;
    wskaznik = firstB;
    while(wskaznik != NULL){
        if(wskaznik->getHeight() == n){
            return wskaznik;
        }
        wskaznik = wskaznik->getNextBranch();
    }
    return wskaznik;
}

void TREE_CLASS::setGardenPointer(GARDEN_CLASS* ogrod){
    this->wKtorymOgrodzie = ogrod;
}


void TREE_CLASS::addTreeFruits(unsigned int count) {
    this->FruitsTotal += count;
    if (this->wKtorymOgrodzie != NULL) {
        this->wKtorymOgrodzie->addFruitsTotal(count);
    }
}

void TREE_CLASS::minusTreeFruits(unsigned int count) {
    unsigned int odejmowanie = 0;
    if (this->FruitsTotal >= count) {
        this->FruitsTotal -= count;
        odejmowanie = count;
    } else {
        odejmowanie = this->FruitsTotal;
        this->FruitsTotal = 0;
    }
    if (this->wKtorymOgrodzie != NULL && odejmowanie > 0) {
        this->wKtorymOgrodzie->minusFruitsTotal(odejmowanie);
    }
}
void TREE_CLASS::addTreeWeight(unsigned int weight) {
    this->WeightsTotal += weight;
    if (this->wKtorymOgrodzie != NULL) {
        this->wKtorymOgrodzie->addWeightsTotal(weight);
    }
}

void TREE_CLASS::minusTreeWeight(unsigned int weight) {
    unsigned int odejmowanie = 0;
    if (this->WeightsTotal >= weight) {
        this->WeightsTotal -= weight;
        odejmowanie = weight;
    } else {
        odejmowanie = this->WeightsTotal;
        this->WeightsTotal = 0;
    }
    if (this->wKtorymOgrodzie != NULL && odejmowanie > 0) {
        this->wKtorymOgrodzie->minusWeightsTotal(odejmowanie);
    }
}

TREE_CLASS* TREE_CLASS::getNextTree(){
    return this->nextT;
}
TREE_CLASS* TREE_CLASS::getPrevTree(){
    return this->prevT;
}

void TREE_CLASS::setUnikalnyNumer(unsigned int numer) {
    this->UnikalnyNumer = numer;
}
void TREE_CLASS::setNextTree(TREE_CLASS* drzewo){
     this->nextT = drzewo;
}
void TREE_CLASS::setPrevTree(TREE_CLASS* drzewo){
     this->prevT = drzewo;
}



