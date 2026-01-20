//Pawel Jandula
#include<iostream>
using namespace std;

int main(){
    int n, m = 0, wartosc_poczatkowa = 0;
    int indeks_1 = 0;
    int dlugosc = 0, przesuniecie = 0;
    int wskaznik = 0;
    int pom = 0, pom1 = 0, pom2 = 0;
    int licznikwejsc = 0, j = 0, k = 0, wartownik = 0;
    char c;
    cin >> n;
    licznikwejsc = n;
    while(licznikwejsc > 0){
        cin >> m;
        int Tab[m];
        j = 0;
        int z = m - 1;
    while(z >= 0){
        Tab[z] = 0;
        z = z - 1;
    }
        while( j < m){
            cin >> Tab[j];
            j = j + 1;
        }
        j = 0;
        while(j < m){
            cout << Tab[j] << " ";
            j = j + 1;
        }
        cout<<endl;
        j = 0;
    while( wartownik == 0){
            cin >> c;
        if(c == 'R'){
                cin >> wartosc_poczatkowa >> dlugosc;
                if( dlugosc != 0){
                if(wartosc_poczatkowa < 0){
                    while(wartosc_poczatkowa < 0)wartosc_poczatkowa = wartosc_poczatkowa + m;
                }
                wartosc_poczatkowa = wartosc_poczatkowa % m;
                int k = m / dlugosc;
                int licznik = 0;
                while(k > 0){
                    int h = 0;
                    while(h < (dlugosc / 2)){
                            pom1 = ((wartosc_poczatkowa+h) + (licznik * dlugosc)) % m, pom2 = ((wartosc_poczatkowa + dlugosc-h-1) + (licznik * dlugosc)) % m;
                             pom = Tab[pom1];
                            Tab[pom1] = Tab[pom2];
                            Tab[pom2] = pom;
                h = h + 1;
                }
                licznik = licznik + 1;
                k = k - 1;
                }


                }
        }
        if(c == 'M'){
            cin >> wartosc_poczatkowa >> dlugosc >> przesuniecie;
            if(dlugosc != 0){
            if(wartosc_poczatkowa < 0){
                while(wartosc_poczatkowa < 0)wartosc_poczatkowa = wartosc_poczatkowa + m;}
            wartosc_poczatkowa = wartosc_poczatkowa % m;\
            przesuniecie = przesuniecie % dlugosc;
            int licznik = 0, liczba = 0;
            int k = m / dlugosc;
            int petla = dlugosc;
                while(k > 0){
                    if(przesuniecie > 0){
                            int zmien = 1;
                        int pom1 = Tab[(wartosc_poczatkowa + (liczba * dlugosc)) % m ];
                        while(przesuniecie > 0){
                                while(petla > 0){
                              int pom2 = Tab[(wartosc_poczatkowa + zmien + (liczba * dlugosc)) % m ];
                              Tab[(wartosc_poczatkowa + zmien + (liczba * dlugosc)) % m] = pom1;
                              pom1 = pom2;

                              zmien = zmien + 1;
                              if(wartosc_poczatkowa + zmien + (liczba * dlugosc) % m > wartosc_poczatkowa + dlugosc + (liczba * dlugosc))zmien = 0;
                                petla = petla - 1;
                                }
                        przesuniecie = przesuniecie - 1;
                        liczba = liczba + 1;
                        }
                    }

                    if(przesuniecie < 0){
                        przesuniecie = -przesuniecie;
                        while(przesuniecie > 0){
                                while(licznik < dlugosc){



                                    licznik = licznik + 1;
                                }




                        przesuniecie = przesuniecie - 1;
                        }


                        }
                        k = k - 1;
                        liczba = liczba + 1;

                }
            }
        }
        if(c == 'C'){
            cin >> wartosc_poczatkowa >> dlugosc;
            if(dlugosc != 0){
            if(wartosc_poczatkowa < 0){
                    while(wartosc_poczatkowa < 0)wartosc_poczatkowa = wartosc_poczatkowa + m;
            }
                wartosc_poczatkowa = wartosc_poczatkowa % m;
            int k = (m / dlugosc) / 2;
            int petla = dlugosc;
            int licznikskokow = 0;
            while (k > 0){
                    petla = dlugosc;
                    while(petla > 0){
                            pom = Tab[(wartosc_poczatkowa + petla - 1 + (licznikskokow * dlugosc)) % m];
                        Tab[(wartosc_poczatkowa + petla - 1 + (licznikskokow * dlugosc)) % m] = Tab[(wartosc_poczatkowa + dlugosc + petla - 1 + (licznikskokow * dlugosc)) % m];
                        Tab[(wartosc_poczatkowa + dlugosc + petla - 1 + (licznikskokow * dlugosc)) % m] = pom;



                       petla = petla - 1;
                    }

                licznikskokow = licznikskokow + 2;
                k = k - 1;
            }
            }

        }
        if(c == 'S'){
                cin >> wartosc_poczatkowa >> dlugosc;
                if(dlugosc != 0){
                if(wartosc_poczatkowa < 0){
                    while(wartosc_poczatkowa < 0)wartosc_poczatkowa = wartosc_poczatkowa + m;
                }
                wartosc_poczatkowa = wartosc_poczatkowa % m;
                int k;
                if(dlugosc > 0) k = m / dlugosc;
                if(dlugosc < 0) k = (-m) / dlugosc;
                int zmienna = 0;
                int pomk = k;
                int licznik = 0;
                if(dlugosc > 0){
                        if(dlugosc >= m){
                            int indeks1 = 0, indeks2 = 1, pomindeks = 0;
                            while(indeks1 < m){
                                while(indeks2 < m){
                                    if(Tab[(wartosc_poczatkowa + indeks1) % m] > Tab[(wartosc_poczatkowa + indeks2) % m]){
                                        pomindeks = Tab[(wartosc_poczatkowa + indeks1) % m];
                                        Tab[(wartosc_poczatkowa + indeks1) % m] = Tab[(wartosc_poczatkowa + indeks2) % m];
                                        Tab[(wartosc_poczatkowa + indeks2) % m] = pomindeks;
                                    }

                                    indeks2 = indeks2 + 1;
                                }
                                indeks2 = indeks1 + 2;
                                indeks1 = indeks1 + 1;
                            }
                        }
                        if(dlugosc < m){
                        while(zmienna < pomk){
                            int z = 0, x = 0, pomsort = 0;
                            while(z < dlugosc){
                                while(x < dlugosc - 1){
                                    if(Tab[(wartosc_poczatkowa + x + 1 + (licznik*dlugosc)) % m] < Tab[(wartosc_poczatkowa + x + (licznik*dlugosc)) % m]){
                                        pomsort = Tab[(wartosc_poczatkowa + x + (licznik*dlugosc)) % m];
                                        Tab[(wartosc_poczatkowa + x + (licznik*dlugosc)) % m] = Tab[(wartosc_poczatkowa + x + 1 + (licznik*dlugosc)) % m];
                                        Tab[(wartosc_poczatkowa + x + 1 + (licznik*dlugosc)) % m] = pomsort;
                                    }
                                    x = x + 1;
                                }
                                x = 0;
                                z = z + 1;
                            }


                            zmienna = zmienna + 1;
                            licznik = licznik + 1;
                        }
                        if(m != zmienna * k){
                                int ipom = 0, pom12_sort = 0;
                            while(ipom < (m - (dlugosc * k)) - 1){
                                if(Tab[(wartosc_poczatkowa + ipom + (dlugosc * licznik)) % m] > Tab[(wartosc_poczatkowa + ipom + 1 + (dlugosc * licznik))% m]){
                                    pom12_sort = Tab[(wartosc_poczatkowa + ipom + (dlugosc * licznik)) % m];
                                    Tab[(wartosc_poczatkowa + ipom + (dlugosc * licznik)) % m] = Tab[(wartosc_poczatkowa + ipom + 1 + (dlugosc * licznik))% m];
                                    Tab[(wartosc_poczatkowa + ipom + 1 + (dlugosc * licznik))% m] = pom12_sort;
                                }
                                ipom = ipom + 1;
                            }
                        }

                        }
                }
                if(dlugosc < 0){
                        int dodatnia_dlugosc = -dlugosc;
                        if(dodatnia_dlugosc >= m){
                            int indeks1 = 0, indeks2 = 1, pomindeks = 0;
                            while(indeks1 < m){
                                while(indeks2 < m){
                                    if(Tab[(wartosc_poczatkowa + indeks1) % m] < Tab[(wartosc_poczatkowa + indeks2) % m]){
                                        pomindeks = Tab[(wartosc_poczatkowa + indeks1) % m];
                                        Tab[(wartosc_poczatkowa + indeks1) % m] = Tab[(wartosc_poczatkowa + indeks2) % m];
                                        Tab[(wartosc_poczatkowa + indeks2) % m] = pomindeks;
                                    }

                                    indeks2 = indeks2 + 1;
                                }
                                indeks2 = indeks1 + 2;
                                indeks1 = indeks1 + 1;
                            }



                        }
                        if(dodatnia_dlugosc < m){
                        while(zmienna < pomk){
                            int z = 0, x = 0, pomsort = 0;
                            while(z < dodatnia_dlugosc ){
                                while(x < dodatnia_dlugosc - 1 ){
                                    if(Tab[(wartosc_poczatkowa + x + 1 + (licznik*dodatnia_dlugosc)) % m] > Tab[(wartosc_poczatkowa + x + (licznik*dodatnia_dlugosc)) % m]){
                                        pomsort = Tab[(wartosc_poczatkowa + x + (licznik*dodatnia_dlugosc)) % m];
                                        Tab[(wartosc_poczatkowa + x + (licznik*dodatnia_dlugosc)) % m] = Tab[(wartosc_poczatkowa + x + 1 + (licznik*dodatnia_dlugosc)) % m];
                                        Tab[(wartosc_poczatkowa + x + 1 + (licznik*dodatnia_dlugosc)) % m] = pomsort;
                                    }
                                    x = x + 1;
                                }
                                x = 0;
                                z = z + 1;
                            }


                            zmienna = zmienna + 1;
                            licznik = licznik + 1;
                        }

                        if(m != zmienna * k){
                                int ipom = 0, pom12_sort = 0;
                            while(ipom < (m - (dodatnia_dlugosc * k) - 1)){
                                if(Tab[(wartosc_poczatkowa + ipom + (dodatnia_dlugosc * licznik)) % m] < Tab[(wartosc_poczatkowa + ipom + 1 + (dodatnia_dlugosc * licznik))% m]){
                                    pom12_sort = Tab[(wartosc_poczatkowa + ipom + (dodatnia_dlugosc * licznik)) % m];
                                    Tab[(wartosc_poczatkowa + ipom + (dodatnia_dlugosc * licznik)) % m] = Tab[(wartosc_poczatkowa + ipom + 1 + (dodatnia_dlugosc * licznik))% m];
                                    Tab[(wartosc_poczatkowa + ipom + 1 + (dodatnia_dlugosc * licznik))% m] = pom12_sort;
                                }
                                ipom = ipom + 1;
                            }
                        }


        }
                }
                }
        }
if(c == 'F')wartownik = 1;
    }
    int w = 0;
    while( w < m ){
        cout << Tab[w] << " ";
        w = w + 1;
    }
    cout << endl;


        licznikwejsc = licznikwejsc - 1;
        wartownik = 0;
    }

    return 0;
}
