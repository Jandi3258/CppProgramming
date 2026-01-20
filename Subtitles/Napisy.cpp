//Pawel Jandula
#include <string>
using namespace std;
string FormatujNapis(string tekst, string pierwszyedytor, string drugiedytor, string trzeciedytor){
    string napis = tekst;
    char TypPolecenia;
    char LiczbaZnakow;
    char Typ;
    if(napis == "") return "";
    for(int i = 0; i < napis.size(); i++){//napis.size() - 4
        if(napis.size() < 4) return napis;
        if(napis == "") return "";
        if(napis[i] == '{'){
            TypPolecenia = napis[i + 1];
            if(TypPolecenia == 'p' && napis[i + 6] == '}'){
                LiczbaZnakow = napis[i + 3];
                Typ = napis [i + 5];
                int PowiekszenieStringa = LiczbaZnakow - '0';
                if(PowiekszenieStringa > 7){
                    napis.resize(napis.size() + PowiekszenieStringa - 7);
                    for(int j = napis.size() - 1; j >= i + PowiekszenieStringa; j--){
                        napis[j] = napis[j - PowiekszenieStringa + 7];
                    }
                    for(int j = i; j < i + PowiekszenieStringa; j++){
                        napis[j] = Typ;
                    }
                }
                else {
                    for(int j = i; j < i + PowiekszenieStringa; j++){
                        napis[j] = Typ;
                    }
                    for(int j = i + PowiekszenieStringa; j <= napis.size() - 1 - 7 + PowiekszenieStringa;j++){
                        napis[j] = napis[j - PowiekszenieStringa + 7];
                    }
                    napis.resize(napis.size() - 7 + PowiekszenieStringa);
                }
            }
            if (TypPolecenia == 'u' && napis[i + 4] == '}') {
                int LiczbaZnakow = napis[i + 3] - '0';
                if(i + LiczbaZnakow + 4 > napis.size() - 1){
                    LiczbaZnakow = napis.size() - 5 - i;
                }
                int j = i;
                while (j + 5 + LiczbaZnakow < napis.size()) {
                    napis[j] = napis[j + 5 + LiczbaZnakow];
                    j++;
                }
                napis.resize(napis.size() - (5 + LiczbaZnakow));
                i = i - 1;
            }
            if (TypPolecenia == 'U' && napis[i + 4] == '}') {
                LiczbaZnakow = napis[i + 3];
                int UsuwanieZnakow = LiczbaZnakow - '0';
                if (UsuwanieZnakow > i) {
                    UsuwanieZnakow = i;
                }
                if (UsuwanieZnakow == 0 && i == (napis.size() - 1 - 2)) {
                    napis.resize(napis.size() - 5);
                }

                else {
                    int DostepneZnaki = i;
                    if (DostepneZnaki < UsuwanieZnakow) {
                        UsuwanieZnakow = DostepneZnaki;
                    }
                    for (int j = i - UsuwanieZnakow; j + UsuwanieZnakow + 5 < napis.size(); j++) {
                        napis[j] = napis[j + UsuwanieZnakow + 5];
                    }
                    napis.resize(napis.size() - UsuwanieZnakow - 5);
                    i = i - UsuwanieZnakow - 1;
                }
            }

            if(TypPolecenia == 'w' && napis[i + 4] == '}'){
                LiczbaZnakow = napis[i + 3];
                string tekst;
                int KtoryCiag = LiczbaZnakow - '0';
                if(KtoryCiag == 1){
                    tekst = pierwszyedytor;
                }
                if(KtoryCiag == 2){
                    tekst = drugiedytor;
                }
                if(KtoryCiag == 3){
                    tekst = trzeciedytor;
                }
                if(tekst.size() > 5) {//to dobrze
                    napis.resize(napis.size() - 5 + tekst.size());
                    for (int j = napis.size() - 1; j > i + tekst.size() - 1; j--) {
                        napis[j] = napis[j + 5 - tekst.size()];
                    }
                    int licznik = 0;
                    for(int j = i; j < i + tekst.size(); j++){
                        napis[j] = tekst[licznik];
                        licznik++;
                    }
                }
                if(tekst.size() <= 5){//naprawione chyba
                    int licznik = 0;
                    for(int j = i; j < i + tekst.size(); j++){
                        napis[j] = tekst[licznik];
                        licznik++;
                    }
                    for(int j = i + tekst.size(); j < napis.size() - 5 + tekst.size();j++){
                        napis[j] = napis[j + 5 - tekst.size()];
                    }
                    napis.resize(napis.size() - 5 + tekst.size());
                }
                i = i - 1;
            }
            if(TypPolecenia == 'W' && napis[i + 6] == '}'){
                LiczbaZnakow = napis[i + 3];
                int IleZnakow = napis[i + 5] - '0';
                string tekst;
                int KtoryCiag = LiczbaZnakow - '0';
                if(KtoryCiag == 1){
                    tekst = pierwszyedytor;
                }
                if(KtoryCiag == 2){
                    tekst = drugiedytor;
                }
                if(KtoryCiag == 3){
                    tekst = trzeciedytor;
                }
                if(IleZnakow > tekst.size()){
                    while(IleZnakow > tekst.size()){
                        //tekst.resize(tekst.size() + 1);
                        //tekst = tekst + ' ';
                        tekst += ' ';
                    }
                }
                /*if(IleZnakow < tekst.size()){
                    while(IleZnakow < tekst.size()){
                        //tekst[tekst.size() - 1] = ' ';
                        tekst.resize(tekst.size() - 1);
                    }
                    }*/
                if(IleZnakow < tekst.size()){
                    tekst.resize(IleZnakow);
                }

                //return tekst;
                if(tekst.size() > 7) {//to dobrze
                    napis.resize(napis.size() - 7 + tekst.size());
                    for (int j = napis.size() - 1; j > i + tekst.size() - 1; j--) {
                        napis[j] = napis[j + 7 - tekst.size()];
                    }
                    int licznik = 0;
                    for(int j = i; j < i + tekst.size(); j++){
                        napis[j] = tekst[licznik];
                        licznik++;
                    }
                }

                else{
                    int licznik = 0;
                    for(int j = i; j < i + tekst.size(); j++){
                        napis[j] = tekst[licznik];
                        licznik++;
                    }
                    for(int j = i + tekst.size(); j < napis.size() - 7 + tekst.size();j++){
                        napis[j] = napis[j + 7 - tekst.size()];
                    }
                    napis.resize(napis.size() - 7 + tekst.size());
                }
                i = i - 1;
            }
        }
    }
    return napis;
}

string NajwiekszeSlowo(string CaleZdanie){
    string pom = "", maks = "";
    for(int i = 0; i < CaleZdanie.size(); i++){
        if(CaleZdanie[i] != ' ')
            pom = pom + CaleZdanie[i];
        else {
            if(pom > maks)
                maks = pom;
            pom = "";
        }
        if(i == (CaleZdanie.size() - 1)){
            if(pom > maks)
                maks = pom;
        }
    }
    return maks;
}
string NormalizujNapis(string napis) {
    string wynik;
    bool poprzedniaSpacja = false;
    int dlugosc = 0;
    for (int i = 0; i < napis.size(); i++) {
        char aktualnyZnak = napis[i];
        if (aktualnyZnak == ' ') {
            if ((poprzedniaSpacja == false) && dlugosc > 0 && napis[i + 1] != '\0' && napis[i + 1] != ',' && napis[i + 1] != '.') {
                wynik += aktualnyZnak;
                dlugosc++;
            }
            poprzedniaSpacja = true;
        }
        else if (aktualnyZnak == ',' || aktualnyZnak == '.') {
            if (dlugosc > 0 && wynik[dlugosc - 1] == ' ') {
                wynik.resize(dlugosc - 1);
                dlugosc--;
            }
            wynik += aktualnyZnak;
            dlugosc++;
            if (napis[i + 1] != '\0' && napis[i + 1] != ' ') {
                wynik += ' ';
                dlugosc++;
            }
            poprzedniaSpacja = false;
        }
        else {
            wynik += aktualnyZnak;
            dlugosc++;
            poprzedniaSpacja = false;
        }
    }
    if(wynik[wynik.size() - 1] == ' ' && wynik[wynik.size() - 2] != '.')
        wynik.resize(wynik.size() - 1);
    return wynik;
}
string UsunSlowo(string Tekst, int KtoreSlowo){
    string ZdanieCale = Tekst;
    int licznik = 0, flaga = 1;
    if(Tekst == "") return "";
    if(Tekst[0] != ' ')licznik++;
    if(KtoreSlowo == 1){
        int j = 0;
        while (ZdanieCale[j] == ' ') {
            j++;
        }
        int i = j;
        while(ZdanieCale[i] != ' ' and i < Tekst.size()){
            i++;
        }
        i -= j;
        for(; j < ZdanieCale.size() - i; j++){
            ZdanieCale[j] = ZdanieCale[j + i];
        }
        ZdanieCale.resize(ZdanieCale.size() - i);
    }
    else {
        for (int i = 0; i < ZdanieCale.size() - 1; i++) {
            if(ZdanieCale == "") return "";
            if ((ZdanieCale[i] == ' ') && (ZdanieCale[i + 1] != ' '))
                licznik++;
            if (licznik == KtoreSlowo && flaga == 1) {
                flaga = 0;
                int j = i + 1;
                int ileliterusunac = 0;
                while ((ZdanieCale[j] != ' ') && (j != (ZdanieCale.size() - 1))) {
                    ileliterusunac++;
                    j++;
                }
                if (j == (ZdanieCale.size() - 1))
                    ileliterusunac++;
                for (int k = i + 1; k < ZdanieCale.size() - ileliterusunac; k++) {
                    ZdanieCale[k] = ZdanieCale[k + ileliterusunac];
                }
                ZdanieCale.resize(ZdanieCale.size() - ileliterusunac);
                return ZdanieCale;
            }
        }
    }
    return ZdanieCale;
}
