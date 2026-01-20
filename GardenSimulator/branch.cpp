//Pawel Jandula
#include "tree.hpp"
#include "fruit.hpp"
#include "branch.hpp"
#include<cstdlib>
BRANCH_CLASS::BRANCH_CLASS(){
    this->Height = 0;
    this->Length = 0;
    this->TotalFruits = 0;
    this->TotalWeights = 0;
    this->pierwszyOwoc = NULL;
    this->ostatniOwoc = NULL;
    this->KtoreDrzewo = NULL;
    this->prev = NULL;
    this->next = NULL;
}

BRANCH_CLASS::~BRANCH_CLASS(){
    FRUIT_CLASS* currentFruit = pierwszyOwoc;
    FRUIT_CLASS* nextFruit = NULL;
    while (currentFruit != NULL) {
        nextFruit = currentFruit->getNextPointer();
        delete currentFruit;
        currentFruit = nextFruit;
    }
    pierwszyOwoc = NULL;
    ostatniOwoc = NULL;
    TotalFruits = 0;
    TotalWeights = 0;
}

BRANCH_CLASS::BRANCH_CLASS(int Wysokosc, int Dlugosc, int TotalFruits1,int TotalWeights1, FRUIT_CLASS* pierwszyOwoc1, FRUIT_CLASS* ostatniOwoc1, TREE_CLASS* KtoreDrzewo1, BRANCH_CLASS* poprzedni,BRANCH_CLASS* nastepny) {
    this->Height = Wysokosc;
    this->Length = Dlugosc;
    this->TotalFruits = TotalFruits1;
    this->TotalWeights = TotalWeights1;
    this->pierwszyOwoc = pierwszyOwoc1;
    this->ostatniOwoc = ostatniOwoc1;
    this->KtoreDrzewo = KtoreDrzewo1;
    this->prev = poprzedni;
    this->next = nastepny;
    if (this->KtoreDrzewo != NULL) {
        if (TotalFruits1 > 0) {
            this->KtoreDrzewo->addTreeFruits(TotalFruits1);
        }
        if (TotalWeights1 > 0) {
            this->KtoreDrzewo->addTreeWeight(TotalWeights1);
        }
    }
}
BRANCH_CLASS::BRANCH_CLASS(const BRANCH_CLASS& kopia){
    this->Height = kopia.Height;
    this->Length = kopia.Length;
    this->KtoreDrzewo = NULL;
    this->TotalWeights = 0;
    this->TotalFruits = 0;
    this->pierwszyOwoc = NULL;
    this->ostatniOwoc = NULL;
    this->prev = NULL;
    this->next = NULL;
    FRUIT_CLASS* currentKopiaFruit = kopia.pierwszyOwoc;
    while(currentKopiaFruit != NULL){
        FRUIT_CLASS* newFruit = new FRUIT_CLASS(*currentKopiaFruit);
        newFruit->setBranchPointer(this);
        if (this->pierwszyOwoc == NULL) {
            this->pierwszyOwoc = newFruit;
        }
        else {
            this->ostatniOwoc->setNextPointer(newFruit);
            newFruit->setPrevPointer(this->ostatniOwoc);
        }
        this->ostatniOwoc = newFruit;
        this->TotalFruits++;
        this->TotalWeights += newFruit->getWeight();
        currentKopiaFruit = currentKopiaFruit->getNextPointer();
    }
}

unsigned int BRANCH_CLASS::getFruitsTotal() {
    return TotalFruits;
}

unsigned int BRANCH_CLASS::getWeightsTotal() {
    return TotalWeights;
}
unsigned int BRANCH_CLASS::getHeight() {
    return Height;
}

unsigned int BRANCH_CLASS::getLength() {
    return Length;
}

void BRANCH_CLASS::growthBranch() {
    Length++;
    FRUIT_CLASS* przemieszczacz = pierwszyOwoc;
    while(przemieszczacz != NULL){
        przemieszczacz->growthFruit();
        przemieszczacz = przemieszczacz->getNextPointer();
    }
    if(Length % 2 == 0){
        FRUIT_CLASS* nowyOwoc = new FRUIT_CLASS(0,Length, this->ostatniOwoc, NULL, this);
        if (this->pierwszyOwoc == NULL) {
            this->pierwszyOwoc = nowyOwoc;
            this->ostatniOwoc = nowyOwoc;
        }
        else {
            if (this->ostatniOwoc != NULL) {
                this->ostatniOwoc->setNextPointer(nowyOwoc);
            }
            this->ostatniOwoc = nowyOwoc;
        }
    }
}

void BRANCH_CLASS::fadeBranch() {
    if (Length > 0) {
        Length--;
        FRUIT_CLASS* pomocniczy = pierwszyOwoc;
        while (pomocniczy != NULL) {
            FRUIT_CLASS* nastepnyDoIteracji = pomocniczy->getNextPointer();

            if (pomocniczy->getLength() > Length) {
                FRUIT_CLASS* pomocniczyDoUsuniecia = pomocniczy;

                FRUIT_CLASS* poprzedni = pomocniczyDoUsuniecia->getPrevPointer();
                FRUIT_CLASS* nastepny = pomocniczyDoUsuniecia->getNextPointer();

                if (poprzedni != NULL) {
                    poprzedni->setNextPointer(nastepny);
                }
                else {
                    pierwszyOwoc = nastepny;
                }
                if (nastepny != NULL) {
                    nastepny->setPrevPointer(poprzedni);
                }
                else {
                    ostatniOwoc = poprzedni;
                }
                delete pomocniczyDoUsuniecia;
                pomocniczyDoUsuniecia = NULL;
            }
            else {
                pomocniczy->fadeFruit();
            }
            pomocniczy = nastepnyDoIteracji;
        }
    }
}

void BRANCH_CLASS::harvestBranch(unsigned int zmienna) {
    FRUIT_CLASS* pomocniczy = pierwszyOwoc;
    while(pomocniczy != NULL){
        if(zmienna <= pomocniczy->getWeight()){
            pomocniczy->pluckFruit();
        }
        pomocniczy = pomocniczy->getNextPointer();
    }
}

void BRANCH_CLASS::cutBranch(unsigned int zmienna) {
    if(Length <= zmienna) return;
    FRUIT_CLASS* pomocniczy = pierwszyOwoc;
    while(pomocniczy != NULL){
        if(pomocniczy->getLength() > zmienna){
            FRUIT_CLASS* pomocniczyDoUsuniecia = pomocniczy;
            pomocniczy = pomocniczy->getNextPointer();

            FRUIT_CLASS* poprzedni = pomocniczyDoUsuniecia->getPrevPointer();
            FRUIT_CLASS* nastepny = pomocniczyDoUsuniecia->getNextPointer();

            if(poprzedni != NULL){
                poprzedni->setNextPointer(nastepny);
            }
            else{
                pierwszyOwoc = nastepny;
            }

            if(nastepny != NULL){
               nastepny ->setPrevPointer(poprzedni);
            }
            else{
                ostatniOwoc = poprzedni;
            }

            delete pomocniczyDoUsuniecia;
            pomocniczyDoUsuniecia = NULL;
        }
        else{
            pomocniczy = pomocniczy->getNextPointer();
        }
    }
    Length = zmienna;
}

FRUIT_CLASS *BRANCH_CLASS::getFruitPointer(unsigned int zmienna) {
    if(zmienna > Length) return NULL;
    FRUIT_CLASS* pomocniczy = pierwszyOwoc;
    while(pomocniczy != NULL){
        if(pomocniczy->getLength() == zmienna)
            return pomocniczy;
        pomocniczy = pomocniczy->getNextPointer();
    }
    return pomocniczy;
}

TREE_CLASS *BRANCH_CLASS::getTreePointer() {
    return this->KtoreDrzewo;
}

void BRANCH_CLASS::addTotalFruits(unsigned int ilosc){
    this->TotalFruits += ilosc;
    if (this->KtoreDrzewo != NULL) {
        this->KtoreDrzewo->addTreeFruits(ilosc);
    }
}

void BRANCH_CLASS::addTotalWeights(unsigned int waga){
    this->TotalWeights += waga;
    if (this->KtoreDrzewo != NULL) {
        this->KtoreDrzewo->addTreeWeight(waga);
    }
}

void BRANCH_CLASS::minusTotalFruits(unsigned int ilosc){
    if(this->TotalFruits >= ilosc)
        this->TotalFruits -= ilosc;
    else
        this->TotalFruits = 0;

    if (this->KtoreDrzewo != NULL) {
        this->KtoreDrzewo->minusTreeFruits(ilosc);
    }
}

void BRANCH_CLASS::minusTotalWeights(unsigned int waga){
    if(this->TotalWeights >= waga)
        this->TotalWeights -= waga;
    else
        this->TotalWeights = 0;

    if (this->KtoreDrzewo != NULL) {
        this->KtoreDrzewo->minusTreeWeight(waga);
    }
}

BRANCH_CLASS *BRANCH_CLASS::getPrevBranch() {
        return prev;
}

BRANCH_CLASS *BRANCH_CLASS::getNextBranch() {
        return next;
}
void BRANCH_CLASS::setNextBranch(BRANCH_CLASS* nastepny){
    next = nastepny;
}

void BRANCH_CLASS::setPrevBranch(BRANCH_CLASS* poprzedni){
    prev = poprzedni;
}

void BRANCH_CLASS::setTreePointer(TREE_CLASS *drzewo) {
    this->KtoreDrzewo = drzewo;
}
void BRANCH_CLASS::setHeight(unsigned int zmienna) {
    this->Height = zmienna;
}