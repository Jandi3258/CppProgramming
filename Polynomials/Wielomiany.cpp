//Pawel Jandula
#include<iostream>
#include<cstdarg>
using namespace std;
int NWD(int a, int b){
    if(a == 0) return b;
    if(b == 0) return a;
    while(b != 0) {
        int pom = b;
        b = a % b;
        a = pom;
    }
    return a;
}
int NWW(int a, int b){
    return (a * b) / NWD(a,b);
}
int ABS(int a){
    if(a < 0) return (-1) * a;
    else return a;
}

class STOPIEN{
public:
    int wspolczynnik;
    STOPIEN* poprzedni;
    STOPIEN* nastepny;

    STOPIEN(int wartosc){
        this->wspolczynnik = wartosc;
        this->poprzedni = NULL;
        this->nastepny = NULL;
    }
    ~STOPIEN(){
        this->wspolczynnik = 0;
        this->poprzedni = NULL;
        this->nastepny = NULL;
    }
};

class POLYNOMIAL{
public:
    int stopienmax;
    static int overloaded; //ile mamy stworzonych polynomials
    STOPIEN* pierwszy;
    STOPIEN* ostatni;
    void deleteZerosInTheEnd(){
        while(ostatni != NULL && ostatni->wspolczynnik == 0 && ostatni != pierwszy){
            STOPIEN* doUsuniecia = ostatni;
            ostatni = ostatni->poprzedni;
            if (ostatni != NULL) {
                ostatni->nastepny = NULL;
            }
            else {
                pierwszy = NULL;
            }
            delete doUsuniecia;
            stopienmax--;
        }
    }
    void simplify(){
        if (pierwszy == NULL) return;
        STOPIEN* wskaznik = pierwszy;
        int NWDwspolczynnik = wskaznik->wspolczynnik;
        while(wskaznik != NULL){
            NWDwspolczynnik = NWD(NWDwspolczynnik, wskaznik->wspolczynnik);
            wskaznik = wskaznik->nastepny;
        }
        if (NWDwspolczynnik < 0) {
            NWDwspolczynnik = -NWDwspolczynnik;
        }
        wskaznik = pierwszy;
        while(wskaznik != NULL){
            if(NWDwspolczynnik != 0) {
                wskaznik->wspolczynnik = (wskaznik->wspolczynnik / NWDwspolczynnik);
            }
                wskaznik = wskaznik->nastepny;
        }
    }

    POLYNOMIAL(){
        this->stopienmax = 0;
        pierwszy = new STOPIEN(0);
        ostatni = pierwszy;
        overloaded++;
    }

    POLYNOMIAL(int stopienzerowy, int v) {
        this->stopienmax = 0;
        if (v != 0) {
            v = (v < 0) ? -1 : 1;
        }
        STOPIEN *a = new STOPIEN(v);
        pierwszy = a;
        ostatni = a;
        overloaded++;
    }
    POLYNOMIAL(const POLYNOMIAL& kopia){
        this->stopienmax = kopia.stopienmax;
        this->pierwszy = NULL;
        this->ostatni = NULL;
        if (kopia.pierwszy == NULL) {
            this->stopienmax = 0;
            this->pierwszy = new STOPIEN(0);
            this->ostatni = this->pierwszy;
            return;
        }
        STOPIEN* wskaznik = kopia.pierwszy;
        while(wskaznik != NULL){
            STOPIEN* nowyStopien = new STOPIEN(wskaznik->wspolczynnik);
            if(pierwszy == NULL && ostatni == NULL){
                pierwszy = nowyStopien;
                ostatni = nowyStopien;
            }
            else if(pierwszy != NULL && ostatni != NULL){
                nowyStopien->poprzedni = ostatni;
                ostatni->nastepny = nowyStopien;
                ostatni = nowyStopien;
            }
            wskaznik = wskaznik->nastepny;
        }
        overloaded++;
    }
    POLYNOMIAL(int stopien, ...){
        this->stopienmax = stopien;
        va_list stopnie;
        va_start(stopnie, stopien);
        pierwszy = NULL;
        ostatni = NULL;
        for(int i = 0; i <= stopienmax; ++i){
            int argument = va_arg(stopnie, int);
            STOPIEN* nowy = new STOPIEN(argument);
            if(pierwszy != NULL){
                nowy->poprzedni = ostatni;
                ostatni->nastepny = nowy;
                ostatni = nowy;
            }
            else{
                pierwszy = nowy;
                ostatni = nowy;
            }
        }
        va_end(stopnie);
        deleteZerosInTheEnd();
        simplify();
        overloaded++;
    }
    POLYNOMIAL(int stopien, int wartosci[]) {
        this->stopienmax = stopien;
        pierwszy = NULL;
        ostatni = NULL;
        for (int i = 0; i <= stopien; ++i) {
            STOPIEN *nowy = new STOPIEN(wartosci[i]);
            if (pierwszy == NULL) {
                pierwszy = nowy;
                ostatni = nowy;
            }
            else {
                nowy->poprzedni = ostatni;
                ostatni->nastepny = nowy;
                ostatni = nowy;
            }
        }
        deleteZerosInTheEnd();
        simplify();
        overloaded++;
    }
    ~POLYNOMIAL(){
        STOPIEN* wskaznik = pierwszy;
        while(wskaznik != NULL){
            STOPIEN* nastepny = wskaznik->nastepny;
            delete wskaznik;
            wskaznik = nastepny;
        }
        pierwszy = NULL;
        ostatni = NULL;
        stopienmax = 0;
        overloaded--;
    }
    POLYNOMIAL &operator=(const POLYNOMIAL &zastepujacy){
        if (this == &zastepujacy) {
            return *this;
        }
        STOPIEN* wskaznik = pierwszy;
        //najpierw usuwamy cały
        while(wskaznik != NULL){
            STOPIEN* nastepny = wskaznik->nastepny;
            delete wskaznik;
            wskaznik = nastepny;
        }
        this->pierwszy = NULL;
        this->ostatni = NULL;
        //teraz dajemy w jego miejsce nowy
        this->stopienmax = zastepujacy.stopienmax;
        wskaznik = zastepujacy.pierwszy;
        while(wskaznik != NULL){
            STOPIEN* nowy = new STOPIEN(wskaznik->wspolczynnik);
            if(pierwszy != NULL){
                nowy->poprzedni = ostatni;
                ostatni->nastepny = nowy;
                ostatni = nowy;
            }
            else{
                pierwszy = nowy;
                ostatni = nowy;
            }
            wskaznik = wskaznik->nastepny;
        }
        return *this;
    }
    POLYNOMIAL operator+(const POLYNOMIAL &dodawany) const{
        int najwiekszyStopien = 0;
        if(this->stopienmax > dodawany.stopienmax)
            najwiekszyStopien = this->stopienmax;
        else
            najwiekszyStopien = dodawany.stopienmax;

            STOPIEN *aktualnywskaznik = this->pierwszy;
            STOPIEN *dodawanywskaznik = dodawany.pierwszy;
            int TablicaWynikow[najwiekszyStopien + 1];
            for(int i = 0; i <= najwiekszyStopien; i++){
                if((aktualnywskaznik) != NULL &&(dodawanywskaznik) != NULL) {
                    TablicaWynikow[i] = (aktualnywskaznik)->wspolczynnik + (dodawanywskaznik)->wspolczynnik;
                    aktualnywskaznik = aktualnywskaznik->nastepny;
                    dodawanywskaznik = dodawanywskaznik->nastepny;
                }
                else if((aktualnywskaznik) == NULL){
                    TablicaWynikow[i] = (dodawanywskaznik)->wspolczynnik;
                    dodawanywskaznik = dodawanywskaznik->nastepny;
                }
                else{
                    TablicaWynikow[i] = (aktualnywskaznik)->wspolczynnik;
                    aktualnywskaznik = aktualnywskaznik->nastepny;
                }
            }
        POLYNOMIAL wynik(najwiekszyStopien, TablicaWynikow);
        wynik.simplify();
            return wynik;
    }
    POLYNOMIAL operator-(const POLYNOMIAL &dodawany) const {
        POLYNOMIAL pom(-dodawany);
        return *this + pom;
    }

    POLYNOMIAL operator-() const{//operator unarny
        POLYNOMIAL wynik = *this;
        STOPIEN* wskaznik = wynik.pierwszy;
        for(int i = 0; i <= wynik.stopienmax; i++){
            wskaznik->wspolczynnik = wskaznik->wspolczynnik * (-1);
            wskaznik = wskaznik->nastepny;
        }
        return wynik;
    }
    POLYNOMIAL operator*(const POLYNOMIAL &pomnozony) const{
        int najwiekszystopien = this->stopienmax + pomnozony.stopienmax;
        int nowaTablica[najwiekszystopien + 1];
        for(int i = 0; i <= najwiekszystopien; i++) {
            nowaTablica[i] = 0;
        }
        STOPIEN* wskaznik1 = this->pierwszy;
        for(int i = 0; i <= this->stopienmax; i++){
            STOPIEN* wskaznik2 = pomnozony.pierwszy;
            for(int j = 0; j <= pomnozony.stopienmax; j++){
                nowaTablica[i + j] += wskaznik1->wspolczynnik * wskaznik2->wspolczynnik;
                if(wskaznik2->nastepny != NULL){
                    wskaznik2 = wskaznik2->nastepny;
                }
            }
            if(wskaznik1->nastepny != NULL){
                wskaznik1 = wskaznik1->nastepny;
            }
        }
        POLYNOMIAL wynik(najwiekszystopien, nowaTablica);
        return wynik;
    }
    POLYNOMIAL operator/(const POLYNOMIAL& dzielacy) const {

        if (this->stopienmax < dzielacy.stopienmax || (dzielacy.stopienmax == 0 && dzielacy.pierwszy->wspolczynnik == 0)) {
            return POLYNOMIAL();
        }
        int* reszta_licz = new int[this->stopienmax + 1]();
        int* reszta_mian = new int[this->stopienmax + 1];
        int* dzielnik_arr = new int[dzielacy.stopienmax + 1]();

        STOPIEN* ptr = this->pierwszy;
        int i = 0;
        while (ptr != NULL) {
            reszta_licz[i] = ptr->wspolczynnik;
            reszta_mian[i] = 1;
            ptr = ptr->nastepny;
            i++;
        }

        ptr = dzielacy.pierwszy;
        i = 0;
        while (ptr != NULL) {
            dzielnik_arr[i] = ptr->wspolczynnik;
            ptr = ptr->nastepny;
            i++;
        }

        int wynikowystopien = this->stopienmax - dzielacy.stopienmax;
        int* wynik_licz = new int[wynikowystopien + 1]();
        int* wynik_mian = new int[wynikowystopien + 1];
        for (i = 0; i <= wynikowystopien; ++i) wynik_mian[i] = 1;

        for (i = this->stopienmax; i >= dzielacy.stopienmax; i--) {
            if (reszta_licz[i] == 0) continue;
            int glowny_dzielnik = dzielnik_arr[dzielacy.stopienmax];
            if (glowny_dzielnik == 0) {
                delete[] reszta_licz;
                delete[] reszta_mian;
                delete[] dzielnik_arr;
                delete[] wynik_licz;
                delete[] wynik_mian;
                return POLYNOMIAL();
            }
            int iloraz_licz = reszta_licz[i];
            int iloraz_mian = reszta_mian[i] * glowny_dzielnik;
            int wsp_nwd = NWD(ABS(iloraz_licz), ABS(iloraz_mian));
            iloraz_licz /= wsp_nwd;
            iloraz_mian /= wsp_nwd;
            if (iloraz_mian < 0) {
                iloraz_licz = -iloraz_licz;
                iloraz_mian = -iloraz_mian;
            }
            int index_wyniku = i - dzielacy.stopienmax;
            wynik_licz[index_wyniku] = iloraz_licz;
            wynik_mian[index_wyniku] = iloraz_mian;
            for (int j = 0; j <= dzielacy.stopienmax; j++) {
                int idx_reszty = i - j;
                int idx_dzielnika = dzielacy.stopienmax - j;
                int do_odjecia_licz = iloraz_licz * dzielnik_arr[idx_dzielnika];
                int do_odjecia_mian = iloraz_mian;
                int nowy_licz = reszta_licz[idx_reszty] * do_odjecia_mian - do_odjecia_licz * reszta_mian[idx_reszty];
                int nowy_mian = reszta_mian[idx_reszty] * do_odjecia_mian;
                if (nowy_licz != 0) {
                    int nwd_reszty = NWD(ABS(nowy_licz), ABS(nowy_mian));
                    reszta_licz[idx_reszty] = nowy_licz / nwd_reszty;
                    reszta_mian[idx_reszty] = nowy_mian / nwd_reszty;
                } else {
                    reszta_licz[idx_reszty] = 0;
                    reszta_mian[idx_reszty] = 1;
                }
            }
        }

        int nww_ilorazu = 1;
        for (i = 0; i <= wynikowystopien; ++i) {
            if (wynik_mian[i] != 1) {
                nww_ilorazu = NWW(nww_ilorazu, ABS(wynik_mian[i]));
            }
        }

        int* final_coeffs = new int[wynikowystopien + 1]();
        for (i = 0; i <= wynikowystopien; ++i) {
            if (wynik_mian[i] != 0) {
                final_coeffs[i] = (wynik_licz[i] * nww_ilorazu) / wynik_mian[i];
            }
        }

        POLYNOMIAL wynik(wynikowystopien, final_coeffs);

        delete[] reszta_licz;
        delete[] reszta_mian;
        delete[] dzielnik_arr;
        delete[] wynik_licz;
        delete[] wynik_mian;
        delete[] final_coeffs;

        return wynik;
    }

    POLYNOMIAL operator%(const POLYNOMIAL& dzielacy) const {
        if (this->stopienmax < dzielacy.stopienmax) {
            return *this;
        }
        if (dzielacy.stopienmax == 0 && dzielacy.pierwszy->wspolczynnik == 0) {
            return *this;
        }

        int* reszta_licz = new int[this->stopienmax + 1]();
        int* reszta_mian = new int[this->stopienmax + 1];
        int* dzielnik_arr = new int[dzielacy.stopienmax + 1]();

        STOPIEN* ptr = this->pierwszy;
        int i = 0;
        while (ptr != NULL) {
            reszta_licz[i] = ptr->wspolczynnik;
            reszta_mian[i] = 1;
            ptr = ptr->nastepny;
            i++;
        }
        ptr = dzielacy.pierwszy;
        i = 0;
        while (ptr != NULL) {
            dzielnik_arr[i] = ptr->wspolczynnik;
            ptr = ptr->nastepny;
            i++;
        }

        for (i = this->stopienmax; i >= dzielacy.stopienmax; i--) {
            if (reszta_licz[i] == 0) continue;
            int glowny_dzielnik = dzielnik_arr[dzielacy.stopienmax];
            if (glowny_dzielnik == 0) {
                delete[] reszta_licz;
                delete[] reszta_mian;
                delete[] dzielnik_arr;
                return *this;
            }
            int iloraz_licz = reszta_licz[i];
            int iloraz_mian = reszta_mian[i] * glowny_dzielnik;
            int wsp_nwd = NWD(ABS(iloraz_licz), ABS(iloraz_mian));
            iloraz_licz /= wsp_nwd;
            iloraz_mian /= wsp_nwd;
            if (iloraz_mian < 0) {
                iloraz_licz = -iloraz_licz;
                iloraz_mian = -iloraz_mian;
            }
            for (int j = 0; j <= dzielacy.stopienmax; j++) {
                int idx_reszty = i - j;
                int idx_dzielnika = dzielacy.stopienmax - j;
                int do_odjecia_licz = iloraz_licz * dzielnik_arr[idx_dzielnika];
                int do_odjecia_mian = iloraz_mian;
                int nowy_licz = reszta_licz[idx_reszty] * do_odjecia_mian - do_odjecia_licz * reszta_mian[idx_reszty];
                int nowy_mian = reszta_mian[idx_reszty] * do_odjecia_mian;
                if (nowy_licz != 0) {
                    int nwd_reszty = NWD(ABS(nowy_licz), ABS(nowy_mian));
                    reszta_licz[idx_reszty] = nowy_licz / nwd_reszty;
                    reszta_mian[idx_reszty] = nowy_mian / nwd_reszty;
                } else {
                    reszta_licz[idx_reszty] = 0;
                    reszta_mian[idx_reszty] = 1;
                }
            }
        }
        int nww_reszty = 1;
        for (i = 0; i <= this->stopienmax; ++i) {
            if (reszta_mian[i] != 1) {
                nww_reszty = NWW(nww_reszty, ABS(reszta_mian[i]));
            }
        }

        int* final_coeffs = new int[this->stopienmax + 1]();
        int stopien_reszty = -1;
        for (i = 0; i <= this->stopienmax; ++i) {
            if (reszta_mian[i] != 0) {
                final_coeffs[i] = (reszta_licz[i] * nww_reszty) / reszta_mian[i];
                if (final_coeffs[i] != 0) {
                    stopien_reszty = i;
                }
            }
        }

        POLYNOMIAL wynik;
        if (stopien_reszty != -1) {
            wynik = POLYNOMIAL(stopien_reszty, final_coeffs);
        }

        delete[] reszta_licz;
        delete[] reszta_mian;
        delete[] dzielnik_arr;
        delete[] final_coeffs;

        return wynik;
    }

    POLYNOMIAL operator<<(int shift){//zmniejszanie ,,lancucha" o jeden bym powiedzial
        if(shift < 0 ||((this->stopienmax - shift) < 0)){
            POLYNOMIAL pusty(0, 0);
            return pusty;
        }
        POLYNOMIAL wynik(*this);
        for(int i = 0; i < shift; i++){
            if(wynik.pierwszy == NULL){
                break;
            }
            STOPIEN* doUsuniecia = wynik.pierwszy;
            wynik.pierwszy = wynik.pierwszy->nastepny;
            if(wynik.pierwszy != NULL){
                wynik.pierwszy->poprzedni = NULL;
            }
            else
                wynik.ostatni = NULL;
            delete doUsuniecia;
        }
        wynik.stopienmax = stopienmax - shift;
        wynik.deleteZerosInTheEnd();
        wynik.simplify();
        return wynik;
    }
    POLYNOMIAL operator>>(int shift){//po prostu dopisanie zer na poczatku
        if(shift < 0){
            POLYNOMIAL pusty(0, 0);
            return pusty;
        }
        POLYNOMIAL zwracany(*this);
        STOPIEN* wskaznik = zwracany.pierwszy;
        for(int i = 0; i < shift; i++){
            STOPIEN* ZeraNaPoczatku = new STOPIEN(0);
            ZeraNaPoczatku->nastepny = wskaznik;
            wskaznik->poprzedni = ZeraNaPoczatku;
            zwracany.pierwszy = ZeraNaPoczatku;
            wskaznik = ZeraNaPoczatku;
        }
        zwracany.stopienmax = this->stopienmax + shift;
        zwracany.deleteZerosInTheEnd();
        zwracany.simplify();
        return zwracany;
    }
    friend istream &operator>>(istream &is, POLYNOMIAL &poly){
            STOPIEN* wskaznik = poly.pierwszy;
            while(wskaznik != NULL){
                STOPIEN* nastepny = wskaznik->nastepny;
                delete wskaznik;
                wskaznik = nastepny;
            }
            poly.pierwszy = NULL;
            poly.ostatni = NULL;
            is >> poly.stopienmax;
            for(int i = 0; i <= poly.stopienmax; i++){
                int WartoscStopnia;
                is >> WartoscStopnia;
                STOPIEN* nowyStopien = new STOPIEN(WartoscStopnia);
                if(poly.pierwszy == NULL){
                    poly.pierwszy = nowyStopien;
                    poly.ostatni = nowyStopien;
                }
                else{
                    nowyStopien->poprzedni = poly.ostatni;
                    poly.ostatni->nastepny = nowyStopien;
                    poly.ostatni = nowyStopien;
                }
            }
            poly.deleteZerosInTheEnd();
            poly.simplify();
            if (poly.pierwszy == NULL) {
                poly.stopienmax = 0;
                poly.pierwszy = new STOPIEN(0);
                poly.ostatni = poly.pierwszy;
            }
            return is;
    }
    friend ostream &operator<<(ostream &os, const POLYNOMIAL &poly){
            os << "( ";
            STOPIEN* wskaznik = poly.pierwszy;
            while(wskaznik != NULL){
                os << wskaznik->wspolczynnik;
                if(wskaznik != poly.ostatni)
                os << ", ";

                wskaznik = wskaznik->nastepny;
            }
            os << " )";
            return os;
    }
    POLYNOMIAL &operator+=(const POLYNOMIAL &p1){
        *this = *this + p1;
        return *this;
    }
    POLYNOMIAL &operator-=(const POLYNOMIAL &p1){
        *this = *this - p1;
        return *this;
    }
    POLYNOMIAL &operator*=(const POLYNOMIAL &p1){
        *this = *this * p1;
        return *this;
    }
    POLYNOMIAL &operator/=(const POLYNOMIAL &p1){
        *this = *this / p1;
        return *this;
    }
    POLYNOMIAL &operator%=(const POLYNOMIAL &p1){
        *this = *this % p1;
        return *this;
    }
    POLYNOMIAL operator<<=(int shift){
        *this = *this << shift;
        return *this;
    }
    POLYNOMIAL operator>>=(int shift){
        *this = *this >> shift;
        return *this;
    }
    POLYNOMIAL operator++(){//preinkrementacja ++zmienna
        STOPIEN* wskaznik = this->pierwszy;
        while (wskaznik != NULL) {
            wskaznik->wspolczynnik++;
            wskaznik = wskaznik->nastepny;
        }
        deleteZerosInTheEnd();
        simplify();
        return *this;
    }
    POLYNOMIAL operator++(int){
        POLYNOMIAL kopiaPrzedModyfikacja(*this);
        ++(*this);
        return kopiaPrzedModyfikacja;
    }
    POLYNOMIAL operator--(){//predekrementaja --zmienna
        STOPIEN* wskaznik = this->pierwszy;
        while (wskaznik != NULL) {
            wskaznik->wspolczynnik--;
            wskaznik = wskaznik->nastepny;
        }
        deleteZerosInTheEnd();
        simplify();
        return *this;
    }
    POLYNOMIAL operator--(int){//postdekrementaja zmienna--
        POLYNOMIAL kopiaPrzedModyfikacja(*this);
        --(*this);
        return kopiaPrzedModyfikacja;
    }

};
//Konieczna jest globalna implementacja przeladowania operatorow relacyjnych - no to machamy
bool operator<(const POLYNOMIAL &p1, const POLYNOMIAL &p2){//zeby nie tworzyc kopii
        if(p1.stopienmax < p2.stopienmax) return true;
        if(p1.stopienmax > p2.stopienmax) return false;
        STOPIEN* wskaznikp1 = p1.ostatni;
        STOPIEN* wskaznikp2 = p2.ostatni;
        for(int i = p1.stopienmax; i >= 0; i--){
            if(wskaznikp1->wspolczynnik < wskaznikp2->wspolczynnik)
                return true;
            if(wskaznikp1->wspolczynnik > wskaznikp2->wspolczynnik)
                return false;
            wskaznikp1 = wskaznikp1->poprzedni;
            wskaznikp2 = wskaznikp2->poprzedni;
        }
    return false;
}
bool operator<=(const POLYNOMIAL &p1, const POLYNOMIAL &p2){
    if(p1.stopienmax < p2.stopienmax) return true;
    if(p1.stopienmax > p2.stopienmax) return false;
    STOPIEN* wskaznikp1 = p1.ostatni;
    STOPIEN* wskaznikp2 = p2.ostatni;
    for(int i = p1.stopienmax; i >= 0; i--){
        if(wskaznikp1->wspolczynnik < wskaznikp2->wspolczynnik)
            return true;
        if(wskaznikp1->wspolczynnik > wskaznikp2->wspolczynnik)
            return false;
        wskaznikp1 = wskaznikp1->poprzedni;
        wskaznikp2 = wskaznikp2->poprzedni;
    }
    return true;
}
bool operator>(const POLYNOMIAL &p1, const POLYNOMIAL &p2){
    return !(p1 <= p2);
}
bool operator==(const POLYNOMIAL &p1, const POLYNOMIAL &p2){
    return !((p1 > p2) || (p1 < p2));
}
bool operator>=(const POLYNOMIAL &p1, const POLYNOMIAL &p2){
    return !(p1 < p2);
}
bool operator!=(const POLYNOMIAL &p1, const POLYNOMIAL &p2) {
    return !(p1 == p2);
}




