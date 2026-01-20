//Pawel Jandula
#include<iostream>
#include<string>
using namespace std;
class PLAYER_CLASS;
class CAESAR_CLASS;
class ARENA_CLASS;
class HUMAN_CLASS;
class BEAST_CLASS;
class SQUAD_CLASS;

class PLAYER_CLASS{
protected:
    unsigned int MaxHealth;
    unsigned int CurrentHealth;
    unsigned int Attack;
    unsigned int Agility;
    bool CzyZyje;
public:
    PLAYER_CLASS() {
        MaxHealth = 0;
        CurrentHealth = 0;
        Attack = 0;
        Agility = 0;
        CzyZyje = true;
    }
    virtual unsigned int getRemainingHealth(){
        return ((CurrentHealth * 100)/MaxHealth);
    };
    virtual unsigned int getDamage(){
        return Attack;
    };
    virtual unsigned int getAgility(){
        return Agility;
    };
    virtual void takeDamage(unsigned int Damage){
        if (CurrentHealth == 0) return;
        if (CurrentHealth > Damage) {
            CurrentHealth -= Damage;
        }
        else {
            die();
        }
    }
    virtual void applyWinnerReward(){
        Attack += 2;
        Agility += 2;
    };
    virtual void cure(){
        CurrentHealth = MaxHealth;
    };
    virtual void printParams() = 0;
    virtual string getName(){
        return "";
    }
    virtual unsigned int getDefence(){
        return 0;
    }
private:
    virtual void die() = 0;
public:
    friend class CAESAR_CLASS;
    friend class SQUAD_CLASS;
};

class CAESAR_CLASS{
    friend class PLAYER_CLASS;
private:
    unsigned int KtorySadzony;
public:
    CAESAR_CLASS() : KtorySadzony(0) {};
    void judgeDeathOrLife(PLAYER_CLASS* player){
        KtorySadzony++;
        if(player == NULL) return;
        if(KtorySadzony % 3 == 0){
            player->die();
        }
    };

};

class ARENA_CLASS{
    friend class PLAYER_CLASS;
    friend class CAESAR_CLASS;
protected:
    CAESAR_CLASS* Cezar;
public:
    unsigned int KtoryAtak;
    ARENA_CLASS(CAESAR_CLASS* cezar) : Cezar(cezar){
    };
    void fight(PLAYER_CLASS* p1, PLAYER_CLASS* p2){
        if(p1 == NULL || p2 == NULL) return;
        if(p1->getRemainingHealth() == 0 || p2->getRemainingHealth() == 0) return;
        if(p1->getAgility() < p2->getAgility()){
            PLAYER_CLASS* pom = p2;
            p2 = p1;
            p1 = pom;
        }
        p1->printParams();
        p2->printParams();
        KtoryAtak = 0;
        while(p1->getRemainingHealth() >= 10 && p2->getRemainingHealth() >= 10 && KtoryAtak < 40){
            p2->takeDamage(p1->getDamage());
            KtoryAtak++;
            p2->printParams();
            if(p2->getRemainingHealth() >= 10 && KtoryAtak < 40){
                p1->takeDamage(p2->getDamage());
                KtoryAtak++;
                p1->printParams();
            }
            else break;
        }

        if(p1->getRemainingHealth() != 0) {
            if (KtoryAtak % 2 == 0)
                Cezar->judgeDeathOrLife(p1);
            else
                Cezar->judgeDeathOrLife(NULL);
            p1->printParams();
        }
        if(p2->getRemainingHealth() != 0) {
            if (KtoryAtak % 2 == 0)
                Cezar->judgeDeathOrLife(p2);
            else
                Cezar->judgeDeathOrLife(NULL);

            p2->printParams();
        }
        if(p1->getRemainingHealth() > 0){
            p1->applyWinnerReward();
            p1->cure();
        }
        if(p2->getRemainingHealth() > 0){
            p2->applyWinnerReward();
            p2->cure();
        }
        p1->printParams();
        p2->printParams();
    };

};


class HUMAN_CLASS : public virtual PLAYER_CLASS{
private:
    string ID;
public:
    unsigned int Defence;
    HUMAN_CLASS(string identyfikator){
        this->ID = identyfikator;
        MaxHealth = 200;
        CurrentHealth = 200;
        Attack = 30;
        Agility = 10;
        Defence = 10;
        CzyZyje = true;
    }
    virtual unsigned int getAgility(){
        return Agility;
    }
    virtual unsigned int getDamage(){
        return Attack;
    }
    virtual unsigned int getDefence(){
        return Defence;
    }
    virtual void die(){
        CzyZyje = false;
        CurrentHealth = 0;
    }
    virtual void takeDamage(unsigned int takenDamage){
        if(takenDamage < getAgility() + getDefence()) return;
        if(CurrentHealth > takenDamage - getAgility() - getDefence()){
            CurrentHealth -= (takenDamage - getAgility() - getDefence());
        }
        else {
            die();
        }
    }
    virtual void printParams(){
        if(CzyZyje){
            cout << ID <<":"<< MaxHealth << ":" << CurrentHealth << ":" << getRemainingHealth() << "%:"<< Attack << ":" << Agility <<":" << Defence << endl;
        }
        else
            cout << ID <<":R.I.P." << endl;
    }
    virtual void setID(string id){
        this->ID = id;
    }
    virtual string getID(){
        return this->ID;
    }
    virtual string getName(){
        return this->ID;
    }
};

class BEAST_CLASS : public virtual PLAYER_CLASS{
protected:
    string ID;
public:
    BEAST_CLASS(string identyfikator){
        this->ID = identyfikator;
        MaxHealth = 150;
        CurrentHealth = 150;
        Attack = 40;
        Agility = 20;
        CzyZyje = true;
    }
    unsigned int getDamage(){
        if(getRemainingHealth() < 25)
            return (2 * Attack);
        else return Attack;
    }
    virtual void takeDamage(unsigned int TakenDamage){
        if (CurrentHealth == 0) return;
        unsigned int reduction = Agility / 2;
        unsigned int actualDamage;
        if (reduction >= TakenDamage) {
            actualDamage = 0;
        }
        else {
            actualDamage = TakenDamage - reduction;
        }
        PLAYER_CLASS::takeDamage(actualDamage);
    }

    virtual void printParams(){
        if(CurrentHealth != 0){
            cout << ID <<":"<< MaxHealth << ":" << CurrentHealth << ":" << this->getRemainingHealth() << '%' << ':' << getDamage() << ":" << Agility << endl;
        }
        else
            cout << ID <<":R.I.P." << endl;
    }
    virtual void setID(string id){
        this->ID = id;
    }
    virtual string getID(){
        return this->ID;
    }
    virtual string getName(){
        return this->ID;
    }

    virtual void die(){
        CzyZyje = false;
        CurrentHealth = 0;
    }
    virtual unsigned int getDefence(){
        return 0;
    }
};

class BERSERKER_CLASS : public HUMAN_CLASS, public BEAST_CLASS{
public:
    BERSERKER_CLASS(string identyfikatorHuman, string identyfikatorBeast) : PLAYER_CLASS(),
                                                                            HUMAN_CLASS(identyfikatorHuman), BEAST_CLASS(identyfikatorBeast){
        HUMAN_CLASS::setID(identyfikatorHuman);
        BEAST_CLASS::setID(identyfikatorBeast);
        MaxHealth = 200;
        CurrentHealth = 200;
        Attack = 35;
        Agility = 5;
        Defence = 15;
        CzyZyje = true;
    }
    unsigned int getAgility(){
        if(getRemainingHealth() >= 25)
            return HUMAN_CLASS::getAgility();
        else
            return BEAST_CLASS::getAgility();
    }
    unsigned int getDamage(){
        if(getRemainingHealth() >= 25)
            return HUMAN_CLASS::getDamage();
        else
            return BEAST_CLASS::getDamage();
    }
    void takeDamage(unsigned int TakenDamage){
        if(getRemainingHealth() >= 25){
            HUMAN_CLASS::takeDamage(TakenDamage);
        }
        else
            BEAST_CLASS::takeDamage(TakenDamage);
    }
    void printParams(){
        if(getRemainingHealth() > 0){
            if(getRemainingHealth() >= 25){
                HUMAN_CLASS::printParams();
            }
            else
                BEAST_CLASS::printParams();
        }
        else {
            cout << HUMAN_CLASS::getID() <<":R.I.P." << endl;
        }
    }
    void die(){
        CzyZyje = false;
        CurrentHealth = 0;
    }
    virtual string getName(){
        if(getRemainingHealth() >= 25){
            return HUMAN_CLASS::getName();
        }
        else
            return BEAST_CLASS::getName();
    }
    virtual unsigned int getDefence(){ // by sie wykonalo w squadzie
        if(getRemainingHealth() >= 25)
            return HUMAN_CLASS::Defence;
        else
            return 0;
    }
};
class ListaPlayerow{
    ListaPlayerow* prev;
    ListaPlayerow* next;
    PLAYER_CLASS* ActualPlayer;
    ListaPlayerow(ListaPlayerow* poprzedni, ListaPlayerow* nastepny, PLAYER_CLASS* aktualny){
        this->prev = poprzedni;
        this->next = nastepny;
        this->ActualPlayer = aktualny;
    }
    friend class SQUAD_CLASS;
};
class SQUAD_CLASS : public virtual PLAYER_CLASS{
private:
    string ID;
    unsigned int IluPlayerow;
    ListaPlayerow* poczatek;
public:
    SQUAD_CLASS(string identyfikator) : PLAYER_CLASS(){
        this->ID = identyfikator;
        IluPlayerow = 0;
        poczatek = NULL;
    }
    void addPlayer(PLAYER_CLASS* Player){
        if(Player->getRemainingHealth() == 0) return;
        ListaPlayerow* nowy = new ListaPlayerow(NULL, NULL, Player);
        if(poczatek == NULL){
            this->poczatek = nowy;
            IluPlayerow++;
        }
        else{
            ListaPlayerow* wskaznik = poczatek;
            while(wskaznik->next != NULL){
                wskaznik = wskaznik->next;
            }
            wskaznik->next = nowy;
            nowy->prev = wskaznik;
            IluPlayerow++;
        }
    }

    unsigned int getAgility(){
        unsigned int minAgility = poczatek->ActualPlayer->getAgility();
        ListaPlayerow* wskaznik = poczatek;
        while(wskaznik != NULL){
            if(minAgility > wskaznik->ActualPlayer->getAgility())
                minAgility = wskaznik->ActualPlayer->getAgility();
            wskaznik = wskaznik->next;
        }
        return minAgility;
    }
    unsigned int getDamage(){
        unsigned int sumOfDamage = 0;
        ListaPlayerow* wskaznik = poczatek;
        while(wskaznik != NULL){
            sumOfDamage += wskaznik->ActualPlayer->getDamage();
            wskaznik = wskaznik->next;
        }
        return sumOfDamage;
    }
    void takeDamage(unsigned int TakenDamage){
        if(this->IluPlayerow == 0 && this->poczatek == NULL){
            return;
        }
        DeleteDeathsFromSquad();
        unsigned int ileZywych = IluPlayerow;
        ListaPlayerow* wskaznik = poczatek;
        while(wskaznik != NULL){
            wskaznik->ActualPlayer->takeDamage(TakenDamage / IluPlayerow);
            wskaznik = wskaznik->next;
        }
        DeleteDeathsFromSquad();
    }
    unsigned int getRemainingHealth(){
        if(this->poczatek == NULL || this->IluPlayerow == 0)return 0;
        unsigned int MaksOfHealth = 0;
        ListaPlayerow* wskaznik = poczatek;
        while(wskaznik != NULL){
            if(MaksOfHealth < wskaznik->ActualPlayer->getRemainingHealth())
                MaksOfHealth = wskaznik->ActualPlayer->getRemainingHealth();
            wskaznik = wskaznik->next;
        }
        return MaksOfHealth;
    }
    void applyWinnerReward(){
        ListaPlayerow* wskaznik = poczatek;
        while(wskaznik != NULL){
            wskaznik->ActualPlayer->applyWinnerReward();
            wskaznik = wskaznik->next;
        }
    }
    void cure(){
        ListaPlayerow* wskaznik = poczatek;
        while(wskaznik != NULL){
            wskaznik->ActualPlayer->cure();
            wskaznik = wskaznik->next;
        }
    }
    void printParams(){
        if(IluPlayerow != 0 && poczatek != NULL){
            cout << ID << ':' << IluPlayerow << ':' << getRemainingHealth() << "%:" << getDamage() << ':' << getAgility() << endl;
            sortowanko();
            ListaPlayerow* wskaznik = poczatek;
            while(wskaznik != NULL){
                wskaznik->ActualPlayer->printParams();
                wskaznik = wskaznik->next;
            }
        }
        else{
            cout << ID << ":nemo" << endl;
        }
    }
    void die(){// zweryfikuj
        ListaPlayerow* wskaznik = poczatek;
        while(wskaznik != NULL){
            wskaznik->ActualPlayer->die();
            wskaznik = wskaznik->next;
        }
        ListaPlayerow* current = poczatek;
        while (current != NULL) {
            ListaPlayerow* next = current->next;
            delete current;
            current = next;
        }
        this->poczatek = NULL;
        this->IluPlayerow = 0;
    }

    void swapPlayers(ListaPlayerow* p1, ListaPlayerow* p2){
        PLAYER_CLASS* pom = p1->ActualPlayer;
        p1->ActualPlayer = p2->ActualPlayer;
        p2->ActualPlayer = pom;
    }

    bool comparePlayers(PLAYER_CLASS* p1, PLAYER_CLASS* p2){// true gdy pierwszy mniejszy, false gdy drugi mniejszy
        if(p1->getName() < p2->getName()) return true;
        if(p1->getName() > p2->getName()) return false;

        if(p1->MaxHealth < p2->MaxHealth) return true;
        if(p1->MaxHealth > p2->MaxHealth) return false;

        if(p1->CurrentHealth < p2->CurrentHealth) return true;
        if(p1->CurrentHealth > p2->CurrentHealth) return false;

        if(p1->getDamage() < p2->getDamage()) return true;
        if(p1->getDamage() > p2->getDamage()) return false;

        if(p1->getAgility() < p2->getAgility()) return true;
        if(p1->getAgility() > p2->getAgility()) return false;

        if(p1->getDefence() < p2->getDefence()) return true;
        if(p1->getDefence() > p2->getDefence()) return false;
        return false;
    }

    void sortowanko(){
        unsigned int n = IluPlayerow;
        bool swapped;
        for(int i = 0; i < n - 1; i++){
            ListaPlayerow* wskaznik = poczatek;
            swapped = false;
            for(int j = i + 1;j < n; j++){
                if (wskaznik != NULL && wskaznik->next != NULL) {
                    if(!comparePlayers(wskaznik->ActualPlayer, wskaznik->next->ActualPlayer)){
                        swapPlayers(wskaznik, wskaznik->next);
                        swapped = true;
                    }
                    wskaznik = wskaznik->next;
                }
            }
            if(!swapped) break;
        }
    }
    unsigned int getDefence(){
        return 0;
    }
    void DeleteDeathsFromSquad(){
        if(poczatek == NULL || IluPlayerow == 0) return;
        ListaPlayerow* wskaznik = poczatek;
        ListaPlayerow* doUsuniecia = NULL;
        while(wskaznik != NULL){
            if(wskaznik->ActualPlayer->CurrentHealth == 0){
                doUsuniecia = wskaznik;
                if(doUsuniecia == poczatek){
                    poczatek = wskaznik->next;
                    if(poczatek != NULL)
                        poczatek->prev = NULL;
                    wskaznik = poczatek;
                }
                else{
                    doUsuniecia->prev->next = wskaznik->next;
                    if(wskaznik->next != NULL)
                        wskaznik->next->prev = doUsuniecia->prev;
                    wskaznik = wskaznik->next;
                }
                delete doUsuniecia;
                doUsuniecia = NULL;
                IluPlayerow--;
                if(IluPlayerow == 0){ //pusta druzyna
                    poczatek = NULL;
                }
            }
            else
                wskaznik = wskaznik->next;
        }
    }

};
