//Pawel Jandula
#include<string>
#include<cstdarg>
using namespace std;
bool porownanieznakow(string napispierwszy, string napisdrugi, int wskaznik, int rozmiar){
    if(wskaznik < rozmiar){
        if(napispierwszy[wskaznik] < napisdrugi[wskaznik]) return 1;
        if(napispierwszy[wskaznik] > napisdrugi[wskaznik]) return 0;
        else return porownanieznakow(napispierwszy, napisdrugi, wskaznik + 1, rozmiar);
    }
    else return 0;
}
bool czymniejsza(string napispierwszy, string napisdrugi){
    if (napispierwszy.length() < napisdrugi.length()){
        return true;
    }
    if (napispierwszy.length() > napisdrugi.length()){
        return false;
    }
    else {
        return porownanieznakow(napispierwszy, napisdrugi, 0, napisdrugi.length());
    }
}

string usunzera(string napis) {
	if ( napis[0] == '0' ){
		napis.erase(0,1);
		return usunzera(napis);
	}
	return napis;
}

void obrocone(string tekscior, string &obrocony, int koniec){
    if(koniec >= 0){
        obrocony += tekscior[koniec];
        obrocone(tekscior, obrocony, koniec - 1);
    }
}
string odwrotnystring(string oryginal){
    string pom = "";
    int licznik = 0;
    obrocone(oryginal, pom, oryginal.length() - 1);
    return pom;
}
string DodanieDwochLiczb(string L1, string L2, string &wynik, int &przeniesienie, int wskaznik, int koniec){
        if(wskaznik < koniec){
            int  suma = (L1[wskaznik] - '0') + (L2[wskaznik] - '0') + przeniesienie;
            wynik += (char)(suma % 10 + '0');
            przeniesienie = suma / 10;

            return DodanieDwochLiczb(L1, L2, wynik, przeniesienie, wskaznik + 1, koniec);
        }
        else
            return wynik;
}

string DodaniezPrzeniesieniem(string L1, string &wynik, int &przeniesienie, int wskaznik, int koniec){
        if(wskaznik < koniec){
            int suma = (L1[wskaznik] - '0') + przeniesienie;
            wynik += (char)(suma % 10 + '0');
            przeniesienie = suma / 10;
            return DodaniezPrzeniesieniem(L1, wynik, przeniesienie, wskaznik + 1, koniec);
        }
        else
            return wynik;
}
string FinaloweDodawanie(string s1, string s2){
    int dlugosc1 = s1.length();
    int dlugosc2 = s2.length();
    if(dlugosc1 > dlugosc2){
        string pom = s1;
        s1 = s2;
        s2 = pom;
        int pomocniczadlugosc = dlugosc1;
        dlugosc1 = dlugosc2;
        dlugosc2 = pomocniczadlugosc;
    }
    string s3 = "";

    s1 = odwrotnystring(s1);
    s2 = odwrotnystring(s2);
    int przeniesienie = 0;
    DodanieDwochLiczb(s1, s2, s3, przeniesienie,0,dlugosc1);
    DodaniezPrzeniesieniem(s2, s3, przeniesienie, dlugosc1, dlugosc2);
    if(przeniesienie == 1) s3 += (char)(przeniesienie + '0');
    s3 = odwrotnystring(s3);

    return s3;
}

string OdejmowanieDwochLiczb(string L1, string L2, string &wynik, int &przeniesienie, int wskaznik, int koniec){
        if(wskaznik < koniec){
            int dif = (L1[wskaznik] - '0') - (L2[wskaznik] - '0') - przeniesienie;
            if(dif < 0){
                dif +=10;
                przeniesienie = 1;
            }
            else przeniesienie = 0;

            wynik += (char)(dif + '0');


            return OdejmowanieDwochLiczb(L1, L2, wynik, przeniesienie, wskaznik + 1, koniec);
        }
        else
            return wynik;
}

string OdejmowaniezPrzeniesieniem(string L1, string &wynik, int &przeniesienie, int wskaznik, int koniec){
        if(wskaznik < koniec){
            int dif = (L1[wskaznik] - '0') - przeniesienie;
            if(dif < 0){
                dif += 10;
                przeniesienie = 1;
            }
            else przeniesienie = 0;
            wynik += (char)(dif + '0');

            return OdejmowaniezPrzeniesieniem(L1, wynik, przeniesienie, wskaznik + 1, koniec);
        }
        else
            return wynik;
}

string FinaloweOdejmowanie(string s1, string s2){
    int dlugosc1 = s1.length();
    int dlugosc2 = s2.length();
    if(czymniejsza(s1, s2)){
        string pom = s1;
        s1 = s2;
        s2 = pom;
        int pomocniczadlugosc = dlugosc1;
        dlugosc1 = dlugosc2;
        dlugosc2 = pomocniczadlugosc;
    }
    string s3 = "";

    s1 = odwrotnystring(s1);
    s2 = odwrotnystring(s2);
    int przeniesienie = 0;
    OdejmowanieDwochLiczb(s1, s2, s3, przeniesienie,0,dlugosc2);
    OdejmowaniezPrzeniesieniem(s1, s3, przeniesienie, dlugosc2, dlugosc1);
    if(przeniesienie == 1) s3 += (char)(przeniesienie + '0');
    s3 = odwrotnystring(s3);

    return s3;
}

string SumMany(const string* elementy, string &wynik, int wskaznik, int koniec){
    if(wskaznik < koniec){
        if(wynik[0] == '-' && elementy[wskaznik][0] == '-'){
            string pom = elementy[wskaznik];
            wynik.erase(0,1);
            pom.erase(0,1);
            wynik = FinaloweDodawanie(wynik, pom);
            wynik = usunzera(wynik);
            wynik = '-' + wynik;

        }
        else if(wynik[0] != '-' && elementy[wskaznik][0] != '-'){
            string pom = elementy[wskaznik];
            if(pom[0] == '+') pom.erase(0, 1);
            wynik = FinaloweDodawanie(wynik,pom);
            wynik = usunzera(wynik);
        }
        else if(wynik[0] == '-' && elementy[wskaznik][0] != '-'){
            string pom = elementy[wskaznik];
            if(pom[0] == '+'){
                pom.erase(0, 1);
            }
            wynik.erase(0, 1);
            if(czymniejsza(wynik,pom)){
                wynik = FinaloweOdejmowanie(wynik, pom);
                wynik = usunzera(wynik);
            }
            else {
                wynik = FinaloweOdejmowanie(wynik, pom);
                wynik = usunzera(wynik);
                wynik = '-' + wynik;
            }

        }
        else if(wynik[0] != '-' && elementy[wskaznik][0] == '-'){
            string pom = elementy[wskaznik];
            pom.erase(0, 1);
            if(czymniejsza(wynik, pom)){
                wynik = FinaloweOdejmowanie(wynik, pom);
                wynik = usunzera(wynik);
                wynik = '-' + wynik;

            }
            else {
                wynik = FinaloweOdejmowanie(wynik, pom);
                wynik = usunzera(wynik);
            }
        }
        if ( wynik == "" || wynik == "-0" || wynik == "-" ) wynik = "0";
        return SumMany(elementy, wynik, wskaznik + 1, koniec);
    }
    else return wynik;
}

string SumVar(va_list lista, string &wynik, int wskaznik, int koniec){
       if(wskaznik < koniec){
        string pom = va_arg(lista, char*);
        if(wynik[0] == '-' && pom[0] == '-'){
            wynik.erase(0,1);
            pom.erase(0,1);
            wynik = FinaloweDodawanie(wynik, pom);
            wynik = usunzera(wynik);
            wynik = '-' + wynik;

        }
        else if(wynik[0] != '-' && pom[0] != '-'){
            if(pom[0] == '+') pom.erase(0, 1);
            wynik = FinaloweDodawanie(wynik,pom);
            wynik = usunzera(wynik);
        }
        else if(wynik[0] == '-' && pom[0] != '-'){
            if(pom[0] == '+'){
                pom.erase(0, 1);
            }
            wynik.erase(0, 1);
            if(czymniejsza(wynik,pom)){
                wynik = FinaloweOdejmowanie(wynik, pom);
                wynik = usunzera(wynik);
            }
            else {
                wynik = FinaloweOdejmowanie(wynik, pom);
                wynik = usunzera(wynik);
                wynik = '-' + wynik;
            }

        }
        else if(wynik[0] != '-' && pom[0] == '-'){
            pom.erase(0, 1);
            if(czymniejsza(wynik, pom)){
                wynik = FinaloweOdejmowanie(wynik, pom);
                wynik = usunzera(wynik);
                wynik = '-' + wynik;

            }
            else {
                wynik = FinaloweOdejmowanie(wynik, pom);
                wynik = usunzera(wynik);
            }
        }
        if ( wynik == "" || wynik == "-0" || wynik == "-" ) wynik = "0";


        return SumVar(lista, wynik, wskaznik + 1, koniec);
    }
    else return wynik;
}


string Sum(int liczba, const string* elementy){
    string wynik = "0";
    return SumMany( elementy, wynik, 0 ,liczba );


}
string Sum(int n, ...){
    string pom = "0";
    va_list lista;
    va_start(lista, n);
    return SumVar(lista, pom, 0, n);
    }
void Sum(string* wynik, int liczba, const string* s){
    *wynik = Sum(liczba, s);

}
void Sum(string* wynik, int zmienna, ...){
    string pom ="0";
    va_list lista;
    va_start(lista, zmienna);
    *wynik = SumVar(lista, pom, 0, zmienna);
}
void Sum(string &wynik, int liczba, const string* s){
    wynik = Sum(liczba, s);
}
void Sum(string& wynik, int zmienna, ...){
string pom ="0";
    va_list lista;
    va_start(lista, zmienna);
    wynik = SumVar(lista, pom, 0, zmienna);
}
void _usunzera(string& napis) {
    if((napis.size() == 1 && napis[0] == '0') || (napis[0] != '0'))
        return;
    napis.erase(0,1);
    _usunzera(napis);
}

void Iter2(string s1, string s2, int s1size, int s2size, int* tab){//wew
    if(s1size >= 0) {
        *(tab + s1size + s2size + 1) += (s1[s1size] - '0') * (s2[s2size] - '0');
        Iter2(s1,s2,s1size - 1,s2size, tab);
    }
}
void Iter1(string s1, string s2, int s1size, int s2size, int* tab) {//zew
    if (s2size >= 0) {
        Iter2(s1, s2, s1size, s2size, tab);
        Iter1(s1, s2, s1size, s2size - 1, tab);
    }
}

void StephenCurry(int* tab, int rozmiar, int przeniesienie){
    *(tab+rozmiar) += przeniesienie;
    przeniesienie = (*(tab + rozmiar)) /10;
    *(tab + rozmiar)%= 10;
    if(rozmiar > 0){
        StephenCurry(tab, rozmiar - 1, przeniesienie);
    }
}
void TabToString(int* tab, string& out, int rozmiar){
    if(rozmiar >= 0){
        out[rozmiar] = (*(tab + rozmiar)) + '0';
        TabToString(tab, out, rozmiar - 1);
    }
}

void WyzerujTablice(int* tab, int rozmiar){
    if(rozmiar >= 0){
        *(tab + rozmiar) = 0;
        WyzerujTablice(tab, rozmiar - 1);
    }
}

string Mult(int liczba, const string* elementy){
    if(liczba > 1) {
        string pom = Mult(liczba - 1, elementy);
        string current = *(elementy + liczba - 1);
        bool czyminus = false;
        if(pom[0] == '-' && current[0] == '-'){
            czyminus = false;
        }
        if(pom[0] != '-' && current[0] == '-'){
            czyminus = true;
        }
        if(pom[0] == '-' && current[0] != '-'){
            czyminus = true;
        }
        if(pom[0] == '-' || pom[0] == '+') pom.erase(0,1);
        if(current[0] == '-' || current[0] == '+') current.erase(0,1);
        int* Tab = new int[pom.size() + current.size()];
        WyzerujTablice(Tab, pom.size() + current.size() - 1);
        Iter1(pom, current, pom.size() - 1, current.size() - 1, Tab);
        StephenCurry(Tab, pom.size() + current.size() - 1, 0);
        string wynik = "";
        wynik.resize(pom.size() + current.size());
        TabToString(Tab, wynik, pom.size() + current.size() - 1);
        delete[] Tab;
        _usunzera(wynik);
        if(wynik == "0"){
            return wynik;
        }
        if(czyminus){
            wynik = '-' + wynik;
        }
        return wynik;
    }
    else {
        return *elementy;
    }
}
void vaEndPom( va_list &arg, int rozmiar, string* n ){
    if (rozmiar > 0) {
        *(n + rozmiar - 1) = (string) va_arg(arg, char*);
        vaEndPom(arg, rozmiar - 1, n);
    }
}
string Mult(int n, ...) {
    string* napisy = new string[n];
    va_list args;
    va_start(args, n);
    string wynik = "1";
    vaEndPom(args, n, napisy);
    va_end(args);
    wynik = Mult(n, napisy);
    delete[] napisy;
    return wynik;
}
void Mult( string* wynik, int liczba, const string* s){
    *wynik = Mult ( liczba, s );
}
void Mult(string* wynik, int n, ...) {
    string* napisy = new string[n];
    va_list args;
    va_start(args, n);
    vaEndPom(args, n, napisy);
    va_end(args);
    *(wynik) = Mult(n, napisy);
    delete[] napisy;
}
void Mult(string& wynik,int liczba,const string* s){
    wynik = Mult ( liczba, s );
}
void Mult(string& wynik, int n, ...) {
    string* napisy = new string[n];
    va_list args;
    va_start(args, n);
    vaEndPom(args, n, napisy);
    va_end(args);
    wynik = Mult(n, napisy);
    delete[] napisy;
}
void Operate( string* destination, va_list source, int licznik, int warunek) {
	if ( licznik < warunek ) {
		destination[licznik] = va_arg(source, char*);
		Operate ( destination, source, licznik + 1, warunek );
	}
}

string Operation ( string (*funkcja) (int, const string*), int liczba, const string* napis ) {
	return funkcja(liczba, napis);
}

string Operation ( string (*funkcja) (int, const string*), int liczba, ... ) {
	va_list lista;
	va_start ( lista, liczba );
	string *napis = new string[liczba];
	Operate ( napis, lista, 0, liczba );
	return funkcja ( liczba, napis );
    va_end(lista);
}

void Operation ( string *wynik, string (*funkcja) (int, const string*), int liczba, const string* napis ) {
	*wynik = funkcja ( liczba, napis );
}

void Operation ( string *wynik, string (*funkcja) (int, const string*), int liczba, ... ) {
	va_list lista;
	va_start ( lista, liczba );
	string *napis = new string[liczba];
	Operate ( napis, lista, 0, liczba );
	*wynik = funkcja ( liczba, napis );
    va_end(lista);
}

void Operation ( string& wynik, void (*funkcja) (string*, int, const string*), int liczba, const string* napis ) {
	funkcja(&wynik, liczba, napis );
}

void Operation ( string &wynik, void (*funkcja) (string*, int, const string*), int liczba, ... ) {
    if(liczba <= 0){
        wynik = "0";
        return;
    }
	va_list lista;
	va_start ( lista, liczba );
	string *napis = new string[liczba];
	Operate ( napis, lista, 0, liczba );
    funkcja (&wynik, liczba, napis );
    va_end(lista);
}
