//Pawel Jandula
#include "fruit.hpp"
#include "garden.hpp"
#include "tree.hpp"
#include "branch.hpp"
#include<cstdlib>
FRUIT_CLASS::FRUIT_CLASS(){
    this->length = 0;
    this->weight = 0;
    this->prev = NULL;
    this->next = NULL;
    this->NaKtorymKrzaku = NULL;
}
FRUIT_CLASS::FRUIT_CLASS(unsigned int weight1, unsigned int length1, FRUIT_CLASS* prev1, FRUIT_CLASS* next1, BRANCH_CLASS* NaKtorymKrzaku1){
    this->weight = weight1;
    this->length = length1;
    this->prev = prev1;
    this->next = next1;
    this->NaKtorymKrzaku = NaKtorymKrzaku1;
    if(NaKtorymKrzaku != NULL){
        NaKtorymKrzaku->addTotalFruits(1);
        NaKtorymKrzaku->addTotalWeights(weight1);
    }
}

//tu jeszcze roznoargumentowe fruit
FRUIT_CLASS::FRUIT_CLASS(unsigned int lengthPom, BRANCH_CLASS* brbr, FRUIT_CLASS* prevPom, FRUIT_CLASS* nextPom){
    this->weight = 0;
    this->length = lengthPom;
    this->prev = prevPom;
    this->next = nextPom;
    this->NaKtorymKrzaku = brbr;
    if (this->NaKtorymKrzaku != NULL) {
        this->NaKtorymKrzaku->addTotalFruits(1);
        this->NaKtorymKrzaku->addTotalWeights(this->weight);
    }
}
//kopiujacy potrzebny na potem
FRUIT_CLASS::FRUIT_CLASS(const FRUIT_CLASS& other) {
    this->weight = other.weight;
    this->length = other.length;
    this->NaKtorymKrzaku = NULL;
    this->prev = NULL;
    this->next = NULL;
}

FRUIT_CLASS::~FRUIT_CLASS() {
    if(NaKtorymKrzaku != NULL) {
        NaKtorymKrzaku->minusTotalWeights(this->weight);
        NaKtorymKrzaku->minusTotalFruits(1);
    }
}

unsigned int FRUIT_CLASS::getWeight() {
    return weight;
}

unsigned int FRUIT_CLASS::getLength() {
    return length;
}

void FRUIT_CLASS::growthFruit() {
    this->weight += 1;
    if(NaKtorymKrzaku != NULL) {
        NaKtorymKrzaku->addTotalWeights(1);
    }
}

void FRUIT_CLASS::fadeFruit() {
    if(this->weight > 0) {
        this->weight -= 1;
        if (NaKtorymKrzaku != NULL) {
            NaKtorymKrzaku->minusTotalWeights(1);
        }
    }
}

void FRUIT_CLASS::pluckFruit() {
    if(NaKtorymKrzaku != NULL) {
        NaKtorymKrzaku->minusTotalWeights(this->weight);
    }
    this->weight = 0;
}

BRANCH_CLASS *FRUIT_CLASS::getBranchPointer() {
    return NaKtorymKrzaku;
}

FRUIT_CLASS *FRUIT_CLASS::getNextPointer() {
    return next;
}
FRUIT_CLASS *FRUIT_CLASS::getPrevPointer() {
    return prev;
}
void FRUIT_CLASS::setNextPointer(FRUIT_CLASS* zmienna) {
    this->next = zmienna;
}
void FRUIT_CLASS::setPrevPointer(FRUIT_CLASS* zmienna) {
    this->prev = zmienna;
}
void FRUIT_CLASS::setBranchPointer(BRANCH_CLASS* branch) {
    this->NaKtorymKrzaku = branch;
}

