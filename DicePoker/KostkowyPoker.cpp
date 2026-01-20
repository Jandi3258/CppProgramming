//Pawel Jandula
#include<iostream>
using namespace std;
int main(){
int liczba_graczy;
char index_gracza1, index_gracza2;
int wynik11 , wynik21, wynik31, wynik41;
int wynik12 , wynik22, wynik32, wynik42;
int licznikjedynek1 = 0, licznikdwojek1 = 0, liczniktrojek1 = 0, licznikczworek1 = 0;
int licznikjedynek2 = 0, licznikdwojek2 = 0, liczniktrojek2 = 0, licznikczworek2 = 0;
int liczba_par_1 = 0, liczba_par_2 = 0, brak_powtorzen_1 = 0, brak_powtorzen_2 = 0, jednakowe_1 = 0, jednakowe_2 = 0;
int max_jednakowe_1 = 0, max_jednakowe_2 = 0, jednakowe_liczba_1 = 0, jednakowe_liczba_2 = 0;
int trojka_1 = 0, trojka_2 = 0, max_trojkowe_1 = 0, max_trojkowe_2 = 0, inna_zm_w_3_1 = 0, inna_zm_w_3_2 = 0;
float licznik_a = 0, licznik_b = 0, licznik_c = 0, licznik_d = 0, licznik_e = 0, wygrane_a = 0, wygrane_b = 0, wygrane_c = 0, wygrane_d = 0, wygrane_e = 0;
float przegrane_a = 0, przegrane_b = 0, przegrane_c = 0, przegrane_d = 0, przegrane_e = 0, remisy_a = 0, remisy_b = 0, remisy_c = 0, remisy_d = 0, remisy_e = 0;
int dwojka_wieksza_1 = 0, dwojka_wieksza_2 = 0;
int dwojka_mniejsza_1 = 0, dwojka_mniejsza_2 = 0, reszta_z_dwojek_1 = 0, reszta_z_dwojek_2 = 0;
int suma1 = 0, suma2 = 0;
cin >> liczba_graczy;
int zmienna = liczba_graczy;
while(zmienna > 0){
    cin >> index_gracza1;
    cin >> wynik11;
if(wynik11 == 1) licznikjedynek1 = licznikjedynek1 + 1;
if(wynik11 == 2) licznikdwojek1 = licznikdwojek1 + 1;
if(wynik11 == 3) liczniktrojek1 = liczniktrojek1 + 1;
if(wynik11 == 4) licznikczworek1 = licznikczworek1 + 1;
  cin >> wynik21;
if(wynik21 == 1) licznikjedynek1 = licznikjedynek1 + 1;
if(wynik21 == 2) licznikdwojek1 = licznikdwojek1 + 1;
if(wynik21 == 3) liczniktrojek1 = liczniktrojek1 + 1;
if(wynik21 == 4) licznikczworek1 = licznikczworek1 + 1;
  cin >> wynik31;
if(wynik31 == 1) licznikjedynek1 = licznikjedynek1 + 1;
if(wynik31 == 2) licznikdwojek1 = licznikdwojek1 + 1;
if(wynik31 == 3) liczniktrojek1 = liczniktrojek1 + 1;
if(wynik31 == 4) licznikczworek1 = licznikczworek1 + 1;
  cin >> wynik41;
if(wynik41 == 1) licznikjedynek1 = licznikjedynek1 + 1;
if(wynik41 == 2) licznikdwojek1 = licznikdwojek1 + 1;
if(wynik41 == 3) liczniktrojek1 = liczniktrojek1 + 1;
if(wynik41 == 4) licznikczworek1 = licznikczworek1 + 1;
if(licznikjedynek1 == 1 && licznikdwojek1 == 1 && liczniktrojek1 == 1 && licznikczworek1 == 1)brak_powtorzen_1 = 1;
if(licznikjedynek1 == 4 || licznikdwojek1 == 4 || liczniktrojek1 == 4 || licznikczworek1 == 4){
        jednakowe_1 = 1;
        if(licznikjedynek1 > max_jednakowe_1) {
                max_jednakowe_1 = licznikjedynek1;
                jednakowe_liczba_1 = 1;
                }
        if(licznikdwojek1 > max_jednakowe_1) {
                max_jednakowe_1 = licznikdwojek1;
                jednakowe_liczba_1 = 2;
                }
        if(liczniktrojek1 > max_jednakowe_1) {
                max_jednakowe_1 = liczniktrojek1;
                jednakowe_liczba_1 = 3;
                }
        if(licznikczworek1 > max_jednakowe_1) {
                max_jednakowe_1 = licznikczworek1;
                jednakowe_liczba_1 = 4;
                }
}
if(licznikjedynek1 == 3 || licznikdwojek1 == 3 || liczniktrojek1 == 3 || licznikczworek1 == 3){
    trojka_1 = 1;
if(licznikjedynek1 == 3)max_trojkowe_1 = 1;
if(licznikdwojek1 == 3)max_trojkowe_1 = 2;
if(liczniktrojek1 == 3)max_trojkowe_1 = 3;
if(licznikczworek1 == 3)max_trojkowe_1 = 4;
if(licznikjedynek1 == 1)inna_zm_w_3_1 = 1;
if(licznikdwojek1 == 1)inna_zm_w_3_1 = 2;
if(liczniktrojek1 == 1)inna_zm_w_3_1 = 3;
if(licznikczworek1 == 1)inna_zm_w_3_1 = 4;
}
if((licznikjedynek1 == 2 && licznikdwojek1 == 2) || (licznikjedynek1 == 2 && liczniktrojek1 == 2) || (licznikjedynek1 == 2 && licznikczworek1 == 2) || (licznikdwojek1 == 2 && liczniktrojek1 ==2) || (liczniktrojek1 == 2 && licznikczworek1 == 2) || (licznikdwojek1 == 2 && licznikczworek1 == 2)){
  if(licznikjedynek1 == 2 && licznikdwojek1 == 2){
        dwojka_wieksza_1 = 2;
        dwojka_mniejsza_1 = 1;
  }
    if(licznikjedynek1 == 2 && liczniktrojek1 == 2){
        dwojka_wieksza_1 = 3;
        dwojka_mniejsza_1 = 1;
    }
    if(licznikjedynek1 == 2 && licznikczworek1 == 2){
            dwojka_wieksza_1 = 4;
            dwojka_mniejsza_1 = 1;
    }
    if(licznikdwojek1 == 2 && liczniktrojek1 ==2){
        dwojka_wieksza_1 = 3;
        dwojka_mniejsza_1 = 2;
    }
    if(liczniktrojek1 == 2 && licznikczworek1 == 2){
            dwojka_wieksza_1 = 4;
            dwojka_mniejsza_1 = 3;
    }
    if(licznikdwojek1 == 2 && licznikczworek1 == 2){
            dwojka_wieksza_1 = 4;
            dwojka_mniejsza_1 = 2;
    }
}
 suma1 = wynik11 + wynik21 + wynik31 + wynik41;


   cin >> index_gracza2;
   cin>> wynik12;
if(wynik12 == 1) licznikjedynek2 = licznikjedynek2 + 1;
if(wynik12 == 2) licznikdwojek2 = licznikdwojek2 + 1;
if(wynik12 == 3) liczniktrojek2 = liczniktrojek2 + 1;
if(wynik12 == 4) licznikczworek2 = licznikczworek2 + 1;
   cin >> wynik22;
if(wynik22 == 1) licznikjedynek2 = licznikjedynek2 + 1;
if(wynik22 == 2) licznikdwojek2 = licznikdwojek2 + 1;
if(wynik22 == 3) liczniktrojek2 = liczniktrojek2 + 1;
if(wynik22 == 4) licznikczworek2 = licznikczworek2 + 1;
   cin >> wynik32;
if(wynik32 == 1) licznikjedynek2 = licznikjedynek2 + 1;
if(wynik32 == 2) licznikdwojek2 = licznikdwojek2 + 1;
if(wynik32 == 3) liczniktrojek2 = liczniktrojek2 + 1;
if(wynik32 == 4) licznikczworek2 = licznikczworek2 + 1;
   cin >> wynik42;
if(wynik42 == 1) licznikjedynek2 = licznikjedynek2 + 1;
if(wynik42 == 2) licznikdwojek2 = licznikdwojek2 + 1;
if(wynik42 == 3) liczniktrojek2 = liczniktrojek2 + 1;
if(wynik42 == 4) licznikczworek2 = licznikczworek2 + 1;

if(licznikjedynek2 == 1 && licznikdwojek2 == 1 && liczniktrojek2 == 1 && licznikczworek2 == 1) brak_powtorzen_2 = 1;
if(licznikjedynek2 == 4 || licznikdwojek2 == 4 || liczniktrojek2 == 4 || licznikczworek2 == 4){
        jednakowe_2 = 1;
        if(licznikjedynek2 > max_jednakowe_2) {
                max_jednakowe_2 = licznikjedynek2;
                jednakowe_liczba_2 = 1;
                }
        if(licznikdwojek2 > max_jednakowe_2) {
                max_jednakowe_2 = licznikdwojek2;
                jednakowe_liczba_2 = 2;
                }
        if(liczniktrojek2 > max_jednakowe_2) {
                max_jednakowe_2 = liczniktrojek2;
                jednakowe_liczba_2 = 3;
                }
        if(licznikczworek2 > max_jednakowe_2) {
                max_jednakowe_2 = licznikczworek2;
                jednakowe_liczba_2 = 4;
                }
}
if(licznikjedynek2 == 3 || licznikdwojek2 == 3 || liczniktrojek2 == 3 || licznikczworek2 == 3){
    trojka_2 = 1;
if(licznikjedynek2 == 3)max_trojkowe_2 = 1;
if(licznikdwojek2 == 3)max_trojkowe_2 = 2;
if(liczniktrojek2 == 3)max_trojkowe_2 = 3;
if(licznikczworek2 == 3)max_trojkowe_2 = 4;
if(licznikjedynek2 == 1)inna_zm_w_3_2 = 1;
if(licznikdwojek2 == 1)inna_zm_w_3_2 = 2;
if(liczniktrojek2 == 1)inna_zm_w_3_2 = 3;
if(licznikczworek2 == 1)inna_zm_w_3_2 = 4;
}
if((licznikjedynek2 == 2 && licznikdwojek2 == 2) || (licznikjedynek2 == 2 && liczniktrojek2 == 2) || (licznikjedynek2 == 2 && licznikczworek2 == 2) || (licznikdwojek2 == 2 && liczniktrojek2 == 2) || (liczniktrojek2 == 2 && licznikczworek2 == 2) || (licznikdwojek2 == 2 && licznikczworek2 == 2)){
    if(licznikjedynek2 == 2 && licznikdwojek2 == 2) {
            dwojka_wieksza_2 = 2;
            dwojka_mniejsza_2 = 1;
    }
    if(licznikjedynek2 == 2 && liczniktrojek2 == 2){
        dwojka_wieksza_2 = 3;
        dwojka_mniejsza_2 = 1;
    }
    if(licznikjedynek2 == 2 && licznikczworek2 == 2){
        dwojka_wieksza_2 = 4;
        dwojka_mniejsza_2 = 1;
    }
    if(licznikdwojek2 == 2 && liczniktrojek2 ==2){
            dwojka_wieksza_2 = 3;
            dwojka_mniejsza_2 = 2;
    }
    if(liczniktrojek2 == 2 && licznikczworek2 == 2){
            dwojka_wieksza_2 = 4;
            dwojka_mniejsza_2 = 3;
    }
    if(licznikdwojek2 == 2 && licznikczworek2 == 2){
            dwojka_wieksza_2 = 4;
            dwojka_mniejsza_2 = 2;
    }
}

suma2 = wynik12 + wynik22 + wynik32 + wynik42;


 if(jednakowe_1 == 1 && jednakowe_2 == 1){
if(jednakowe_liczba_1 > jednakowe_liczba_2){
 if(index_gracza1 == 'a') wygrane_a = wygrane_a + 1;
 if(index_gracza1 == 'b') wygrane_b = wygrane_b + 1;
 if(index_gracza1 == 'c') wygrane_c = wygrane_c + 1;
 if(index_gracza1 == 'd') wygrane_d = wygrane_d + 1;
 if(index_gracza1 == 'e') wygrane_e = wygrane_e + 1;
 if(index_gracza2 == 'a') przegrane_a = przegrane_a + 1;
 if(index_gracza2 == 'b') przegrane_b = przegrane_b + 1;
 if(index_gracza2 == 'c') przegrane_c = przegrane_c + 1;
 if(index_gracza2 == 'd') przegrane_d = przegrane_d + 1;
 if(index_gracza2 == 'e') przegrane_e = przegrane_e + 1;
}

else
    if(jednakowe_liczba_1 < jednakowe_liczba_2){
    if(index_gracza1 == 'a') przegrane_a = przegrane_a + 1;
 if(index_gracza1 == 'b') przegrane_b = przegrane_b + 1;
 if(index_gracza1 == 'c') przegrane_c = przegrane_c + 1;
 if(index_gracza1 == 'd') przegrane_d = przegrane_d + 1;
 if(index_gracza1 == 'e') przegrane_e = przegrane_e + 1;
 if(index_gracza2 == 'a') wygrane_a = wygrane_a + 1;
 if(index_gracza2 == 'b') wygrane_b = wygrane_b + 1;
 if(index_gracza2 == 'c') wygrane_c = wygrane_c + 1;
 if(index_gracza2 == 'd') wygrane_d = wygrane_d + 1;
 if(index_gracza2 == 'e') wygrane_e = wygrane_e + 1;
}
else
    if(jednakowe_liczba_1 == jednakowe_liczba_2){
    if(index_gracza1 == 'a') remisy_a = remisy_a + 1;
 if(index_gracza1 == 'b') remisy_b = remisy_b + 1;
 if(index_gracza1 == 'c') remisy_c = remisy_c + 1;
 if(index_gracza1 == 'd') remisy_d = remisy_d + 1;
 if(index_gracza1 == 'e') remisy_e = remisy_e + 1;
 if(index_gracza2 == 'a') remisy_a = remisy_a + 1;
 if(index_gracza2 == 'b') remisy_b = remisy_b + 1;
 if(index_gracza2 == 'c') remisy_c = remisy_c + 1;
 if(index_gracza2 == 'd') remisy_d = remisy_d + 1;
 if(index_gracza2 == 'e') remisy_e = remisy_e + 1;
}}
else
    if(jednakowe_1 == 1 && jednakowe_2 == 0){
   if(index_gracza1 == 'a') wygrane_a = wygrane_a + 1;
 if(index_gracza1 == 'b') wygrane_b = wygrane_b + 1;
 if(index_gracza1 == 'c') wygrane_c = wygrane_c + 1;
 if(index_gracza1 == 'd') wygrane_d = wygrane_d + 1;
 if(index_gracza1 == 'e') wygrane_e = wygrane_e + 1;
 if(index_gracza2 == 'a') przegrane_a = przegrane_a + 1;
 if(index_gracza2 == 'b') przegrane_b = przegrane_b + 1;
 if(index_gracza2 == 'c') przegrane_c = przegrane_c + 1;
 if(index_gracza2 == 'd') przegrane_d = przegrane_d + 1;
 if(index_gracza2 == 'e') przegrane_e = przegrane_e + 1;
}


else
    if(jednakowe_1 == 0 && jednakowe_2 == 1){
     if(index_gracza1 == 'a') przegrane_a = przegrane_a + 1;
 if(index_gracza1 == 'b') przegrane_b = przegrane_b + 1;
 if(index_gracza1 == 'c') przegrane_c = przegrane_c + 1;
 if(index_gracza1 == 'd') przegrane_d = przegrane_d + 1;
 if(index_gracza1 == 'e') przegrane_e = przegrane_e + 1;
 if(index_gracza2 == 'a') wygrane_a = wygrane_a + 1;
 if(index_gracza2 == 'b') wygrane_b = wygrane_b + 1;
 if(index_gracza2 == 'c') wygrane_c = wygrane_c + 1;
 if(index_gracza2 == 'd') wygrane_d = wygrane_d + 1;
 if(index_gracza2 == 'e') wygrane_e = wygrane_e + 1;
}
else
    if(brak_powtorzen_1 == 1 && brak_powtorzen_2 == 0){
    if(index_gracza1 == 'a') wygrane_a = wygrane_a + 1;
 if(index_gracza1 == 'b') wygrane_b = wygrane_b + 1;
 if(index_gracza1 == 'c') wygrane_c = wygrane_c + 1;
 if(index_gracza1 == 'd') wygrane_d = wygrane_d + 1;
 if(index_gracza1 == 'e') wygrane_e = wygrane_e + 1;
 if(index_gracza2 == 'a') przegrane_a = przegrane_a + 1;
 if(index_gracza2 == 'b') przegrane_b = przegrane_b + 1;
 if(index_gracza2 == 'c') przegrane_c = przegrane_c + 1;
 if(index_gracza2 == 'd') przegrane_d = przegrane_d + 1;
 if(index_gracza2 == 'e') przegrane_e = przegrane_e + 1;
}


else
    if(brak_powtorzen_1 == 0 && brak_powtorzen_2 == 1){
    if(index_gracza1 == 'a') przegrane_a = przegrane_a + 1;
 if(index_gracza1 == 'b') przegrane_b = przegrane_b + 1;
 if(index_gracza1 == 'c') przegrane_c = przegrane_c + 1;
 if(index_gracza1 == 'd') przegrane_d = przegrane_d + 1;
 if(index_gracza1 == 'e') przegrane_e = przegrane_e + 1;
 if(index_gracza2 == 'a') wygrane_a = wygrane_a + 1;
 if(index_gracza2 == 'b') wygrane_b = wygrane_b + 1;
 if(index_gracza2 == 'c') wygrane_c = wygrane_c + 1;
 if(index_gracza2 == 'd') wygrane_d = wygrane_d + 1;
 if(index_gracza2 == 'e') wygrane_e = wygrane_e + 1;
}


else
    if(brak_powtorzen_1 == 1 && brak_powtorzen_2 == 1){
if(index_gracza1 == 'a')remisy_a = remisy_a + 1;
if(index_gracza1 == 'b')remisy_b = remisy_b + 1;
if(index_gracza1 == 'c')remisy_c = remisy_c + 1;
if(index_gracza1 == 'd')remisy_d = remisy_d + 1;
if(index_gracza1 == 'e')remisy_e = remisy_e + 1;
if(index_gracza2 == 'a')remisy_a = remisy_a + 1;
if(index_gracza2 == 'b')remisy_b = remisy_b + 1;
if(index_gracza2 == 'c')remisy_c = remisy_c + 1;
if(index_gracza2 == 'd')remisy_d = remisy_d + 1;
if(index_gracza2 == 'e')remisy_e = remisy_e + 1;
}


 else  if(dwojka_wieksza_1 > dwojka_wieksza_2){
    if(index_gracza1 == 'a') wygrane_a = wygrane_a + 1;
 if(index_gracza1 == 'b') wygrane_b = wygrane_b + 1;
 if(index_gracza1 == 'c') wygrane_c = wygrane_c + 1;
 if(index_gracza1 == 'd') wygrane_d = wygrane_d + 1;
 if(index_gracza1 == 'e') wygrane_e = wygrane_e + 1;
 if(index_gracza2 == 'a') przegrane_a = przegrane_a + 1;
 if(index_gracza2 == 'b') przegrane_b = przegrane_b + 1;
 if(index_gracza2 == 'c') przegrane_c = przegrane_c + 1;
 if(index_gracza2 == 'd') przegrane_d = przegrane_d + 1;
 if(index_gracza2 == 'e') przegrane_e = przegrane_e + 1;
}
 else if(dwojka_wieksza_1 < dwojka_wieksza_2){
    if(index_gracza1 == 'a') przegrane_a = przegrane_a + 1;
if(index_gracza1 == 'b') przegrane_b = przegrane_b + 1;
 if(index_gracza1 == 'c') przegrane_c = przegrane_c + 1;
 if(index_gracza1 == 'd') przegrane_d = przegrane_d + 1;
 if(index_gracza1 == 'e') przegrane_e = przegrane_e + 1;
 if(index_gracza2 == 'a') wygrane_a = wygrane_a + 1;
 if(index_gracza2 == 'b') wygrane_b = wygrane_b + 1;
 if(index_gracza2 == 'c') wygrane_c = wygrane_c + 1;
 if(index_gracza2 == 'd') wygrane_d = wygrane_d + 1;
 if(index_gracza2 == 'e') wygrane_e = wygrane_e + 1;
  }
else if((dwojka_wieksza_1 == dwojka_wieksza_2) && (dwojka_wieksza_1 > 0) && (dwojka_wieksza_2 > 0) && (dwojka_mniejsza_1 > 0) && (dwojka_mniejsza_2 > 0)){
    if(dwojka_mniejsza_1 > dwojka_mniejsza_2){
        if(index_gracza1 == 'a') wygrane_a = wygrane_a + 1;
 if(index_gracza1 == 'b') wygrane_b = wygrane_b + 1;
 if(index_gracza1 == 'c') wygrane_c = wygrane_c + 1;
 if(index_gracza1 == 'd') wygrane_d = wygrane_d + 1;
 if(index_gracza1 == 'e') wygrane_e = wygrane_e + 1;
 if(index_gracza2 == 'a') przegrane_a = przegrane_a + 1;
 if(index_gracza2 == 'b') przegrane_b = przegrane_b + 1;
 if(index_gracza2 == 'c') przegrane_c = przegrane_c + 1;
 if(index_gracza2 == 'd') przegrane_d = przegrane_d + 1;
 if(index_gracza2 == 'e') przegrane_e = przegrane_e + 1;
    }
    if(dwojka_mniejsza_1 < dwojka_mniejsza_2){
        if(index_gracza1 == 'a') przegrane_a = przegrane_a + 1;
if(index_gracza1 == 'b') przegrane_b = przegrane_b + 1;
 if(index_gracza1 == 'c') przegrane_c = przegrane_c + 1;
 if(index_gracza1 == 'd') przegrane_d = przegrane_d + 1;
 if(index_gracza1 == 'e') przegrane_e = przegrane_e + 1;
 if(index_gracza2 == 'a') wygrane_a = wygrane_a + 1;
 if(index_gracza2 == 'b') wygrane_b = wygrane_b + 1;
 if(index_gracza2 == 'c') wygrane_c = wygrane_c + 1;
 if(index_gracza2 == 'd') wygrane_d = wygrane_d + 1;
 if(index_gracza2 == 'e') wygrane_e = wygrane_e + 1;
    }
    if(dwojka_mniejsza_1 == dwojka_mniejsza_2 && dwojka_mniejsza_1 != 0 && dwojka_mniejsza_2 != 0 ){
         if(index_gracza1 == 'a') remisy_a = remisy_a + 1;
 if(index_gracza1 == 'b') remisy_b = remisy_b + 1;
 if(index_gracza1 == 'c') remisy_c = remisy_c + 1;
 if(index_gracza1 == 'd') remisy_d = remisy_d + 1;
 if(index_gracza1 == 'e') remisy_e = remisy_e + 1;
 if(index_gracza2 == 'a') remisy_a = remisy_a + 1;
 if(index_gracza2 == 'b') remisy_b = remisy_b + 1;
 if(index_gracza2 == 'c') remisy_c = remisy_c + 1;
 if(index_gracza2 == 'd') remisy_d = remisy_d + 1;
 if(index_gracza2 == 'e') remisy_e = remisy_e + 1;
    }
  }



else if((max_trojkowe_1 > max_trojkowe_2 ) && trojka_1 != 0){
     if(index_gracza1 == 'a') wygrane_a = wygrane_a + 1;
 if(index_gracza1 == 'b') wygrane_b = wygrane_b + 1;
 if(index_gracza1 == 'c') wygrane_c = wygrane_c + 1;
 if(index_gracza1 == 'd') wygrane_d = wygrane_d + 1;
 if(index_gracza1 == 'e') wygrane_e = wygrane_e + 1;
 if(index_gracza2 == 'a') przegrane_a = przegrane_a + 1;
 if(index_gracza2 == 'b') przegrane_b = przegrane_b + 1;
 if(index_gracza2 == 'c') przegrane_c = przegrane_c + 1;
 if(index_gracza2 == 'd') przegrane_d = przegrane_d + 1;
 if(index_gracza2 == 'e') przegrane_e = przegrane_e + 1;

}
else if((max_trojkowe_1 < max_trojkowe_2) && trojka_2 != 0){
    if(index_gracza1 == 'a') przegrane_a = przegrane_a + 1;
if(index_gracza1 == 'b') przegrane_b = przegrane_b + 1;
 if(index_gracza1 == 'c') przegrane_c = przegrane_c + 1;
 if(index_gracza1 == 'd') przegrane_d = przegrane_d + 1;
 if(index_gracza1 == 'e') przegrane_e = przegrane_e + 1;
 if(index_gracza2 == 'a') wygrane_a = wygrane_a + 1;
 if(index_gracza2 == 'b') wygrane_b = wygrane_b + 1;
 if(index_gracza2 == 'c') wygrane_c = wygrane_c + 1;
 if(index_gracza2 == 'd') wygrane_d = wygrane_d + 1;
 if(index_gracza2 == 'e') wygrane_e = wygrane_e + 1;
}
else
    if(max_trojkowe_1 == max_trojkowe_2 && trojka_1 != 0 && trojka_2 != 0){
    if(inna_zm_w_3_1 > inna_zm_w_3_2){
       if(index_gracza1 == 'a') wygrane_a = wygrane_a + 1;
 if(index_gracza1 == 'b') wygrane_b = wygrane_b + 1;
 if(index_gracza1 == 'c') wygrane_c = wygrane_c + 1;
 if(index_gracza1 == 'd') wygrane_d = wygrane_d + 1;
 if(index_gracza1 == 'e') wygrane_e = wygrane_e + 1;
 if(index_gracza2 == 'a') przegrane_a = przegrane_a + 1;
 if(index_gracza2 == 'b') przegrane_b = przegrane_b + 1;
 if(index_gracza2 == 'c') przegrane_c = przegrane_c + 1;
 if(index_gracza2 == 'd') przegrane_d = przegrane_d + 1;
 if(index_gracza2 == 'e') przegrane_e = przegrane_e + 1;
    }
    if(inna_zm_w_3_1 < inna_zm_w_3_2){
        if(index_gracza1 == 'a') przegrane_a = przegrane_a + 1;
if(index_gracza1 == 'b') przegrane_b = przegrane_b + 1;
 if(index_gracza1 == 'c') przegrane_c = przegrane_c + 1;
 if(index_gracza1 == 'd') przegrane_d = przegrane_d + 1;
 if(index_gracza1 == 'e') przegrane_e = przegrane_e + 1;
 if(index_gracza2 == 'a') wygrane_a = wygrane_a + 1;
 if(index_gracza2 == 'b') wygrane_b = wygrane_b + 1;
 if(index_gracza2 == 'c') wygrane_c = wygrane_c + 1;
 if(index_gracza2 == 'd') wygrane_d = wygrane_d + 1;
 if(index_gracza2 == 'e') wygrane_e = wygrane_e + 1;
    }
    if(inna_zm_w_3_1 == inna_zm_w_3_2){
        if(index_gracza1 == 'a') remisy_a = remisy_a + 1;
 if(index_gracza1 == 'b') remisy_b = remisy_b + 1;
 if(index_gracza1 == 'c') remisy_c = remisy_c + 1;
 if(index_gracza1 == 'd') remisy_d = remisy_d + 1;
 if(index_gracza1 == 'e') remisy_e = remisy_e + 1;
 if(index_gracza2 == 'a') remisy_a = remisy_a + 1;
 if(index_gracza2 == 'b') remisy_b = remisy_b + 1;
 if(index_gracza2 == 'c') remisy_c = remisy_c + 1;
 if(index_gracza2 == 'd') remisy_d = remisy_d + 1;
 if(index_gracza2 == 'e') remisy_e = remisy_e + 1;
    }
}
else
if((licznikjedynek1 == 2 || licznikdwojek1 == 2) && ( liczniktrojek2 == 2 || licznikczworek2 == 2)){
    if(index_gracza1 == 'a') przegrane_a = przegrane_a + 1;
if(index_gracza1 == 'b') przegrane_b = przegrane_b + 1;
 if(index_gracza1 == 'c') przegrane_c = przegrane_c + 1;
 if(index_gracza1 == 'd') przegrane_d = przegrane_d + 1;
 if(index_gracza1 == 'e') przegrane_e = przegrane_e + 1;
 if(index_gracza2 == 'a') wygrane_a = wygrane_a + 1;
 if(index_gracza2 == 'b') wygrane_b = wygrane_b + 1;
 if(index_gracza2 == 'c') wygrane_c = wygrane_c + 1;
 if(index_gracza2 == 'd') wygrane_d = wygrane_d + 1;
 if(index_gracza2 == 'e') wygrane_e = wygrane_e + 1;
}
else if((liczniktrojek1 == 2 || licznikczworek1 == 2) && (licznikjedynek2 == 2 || licznikdwojek2 == 2)){
    if(index_gracza1 == 'a') wygrane_a = wygrane_a + 1;
 if(index_gracza1 == 'b') wygrane_b = wygrane_b + 1;
 if(index_gracza1 == 'c') wygrane_c = wygrane_c + 1;
 if(index_gracza1 == 'd') wygrane_d = wygrane_d + 1;
 if(index_gracza1 == 'e') wygrane_e = wygrane_e + 1;
 if(index_gracza2 == 'a') przegrane_a = przegrane_a + 1;
 if(index_gracza2 == 'b') przegrane_b = przegrane_b + 1;
 if(index_gracza2 == 'c') przegrane_c = przegrane_c + 1;
 if(index_gracza2 == 'd') przegrane_d = przegrane_d + 1;
 if(index_gracza2 == 'e') przegrane_e = przegrane_e + 1;
}
else if(licznikjedynek1 == 2 && licznikdwojek2 == 2){
     if(index_gracza1 == 'a') przegrane_a = przegrane_a + 1;
if(index_gracza1 == 'b') przegrane_b = przegrane_b + 1;
 if(index_gracza1 == 'c') przegrane_c = przegrane_c + 1;
 if(index_gracza1 == 'd') przegrane_d = przegrane_d + 1;
 if(index_gracza1 == 'e') przegrane_e = przegrane_e + 1;
 if(index_gracza2 == 'a') wygrane_a = wygrane_a + 1;
 if(index_gracza2 == 'b') wygrane_b = wygrane_b + 1;
 if(index_gracza2 == 'c') wygrane_c = wygrane_c + 1;
 if(index_gracza2 == 'd') wygrane_d = wygrane_d + 1;
 if(index_gracza2 == 'e') wygrane_e = wygrane_e + 1;
}
  else  if(licznikjedynek2 == 2 && licznikdwojek1 == 2){
        if(index_gracza1 == 'a') wygrane_a = wygrane_a + 1;
 if(index_gracza1 == 'b') wygrane_b = wygrane_b + 1;
 if(index_gracza1 == 'c') wygrane_c = wygrane_c + 1;
 if(index_gracza1 == 'd') wygrane_d = wygrane_d + 1;
 if(index_gracza1 == 'e') wygrane_e = wygrane_e + 1;
 if(index_gracza2 == 'a') przegrane_a = przegrane_a + 1;
 if(index_gracza2 == 'b') przegrane_b = przegrane_b + 1;
 if(index_gracza2 == 'c') przegrane_c = przegrane_c + 1;
 if(index_gracza2 == 'd') przegrane_d = przegrane_d + 1;
 if(index_gracza2 == 'e') przegrane_e = przegrane_e + 1;
    }
else
    if(suma1 > suma2){
        if(index_gracza1 == 'a') wygrane_a = wygrane_a + 1;
 if(index_gracza1 == 'b') wygrane_b = wygrane_b + 1;
 if(index_gracza1 == 'c') wygrane_c = wygrane_c + 1;
 if(index_gracza1 == 'd') wygrane_d = wygrane_d + 1;
 if(index_gracza1 == 'e') wygrane_e = wygrane_e + 1;
 if(index_gracza2 == 'a') przegrane_a = przegrane_a + 1;
 if(index_gracza2 == 'b') przegrane_b = przegrane_b + 1;
 if(index_gracza2 == 'c') przegrane_c = przegrane_c + 1;
 if(index_gracza2 == 'd') przegrane_d = przegrane_d + 1;
 if(index_gracza2 == 'e') przegrane_e = przegrane_e + 1;
    }
 else   if(suma1 < suma2){
        if(index_gracza1 == 'a') przegrane_a = przegrane_a + 1;
if(index_gracza1 == 'b') przegrane_b = przegrane_b + 1;
 if(index_gracza1 == 'c') przegrane_c = przegrane_c + 1;
 if(index_gracza1 == 'd') przegrane_d = przegrane_d + 1;
 if(index_gracza1 == 'e') przegrane_e = przegrane_e + 1;
 if(index_gracza2 == 'a') wygrane_a = wygrane_a + 1;
 if(index_gracza2 == 'b') wygrane_b = wygrane_b + 1;
 if(index_gracza2 == 'c') wygrane_c = wygrane_c + 1;
 if(index_gracza2 == 'd') wygrane_d = wygrane_d + 1;
 if(index_gracza2 == 'e') wygrane_e = wygrane_e + 1;
    }
else    if(suma1 == suma2){
       if(index_gracza1 == 'a') remisy_a = remisy_a + 1;
 if(index_gracza1 == 'b') remisy_b = remisy_b + 1;
 if(index_gracza1 == 'c') remisy_c = remisy_c + 1;
 if(index_gracza1 == 'd') remisy_d = remisy_d + 1;
 if(index_gracza1 == 'e') remisy_e = remisy_e + 1;
 if(index_gracza2 == 'a') remisy_a = remisy_a + 1;
 if(index_gracza2 == 'b') remisy_b = remisy_b + 1;
 if(index_gracza2 == 'c') remisy_c = remisy_c + 1;
 if(index_gracza2 == 'd') remisy_d = remisy_d + 1;
 if(index_gracza2 == 'e') remisy_e = remisy_e + 1;
    }


brak_powtorzen_1 = 0;
brak_powtorzen_2 = 0;
jednakowe_1 = 0;
jednakowe_2 = 0;
max_jednakowe_1 = 0;
max_jednakowe_2 = 0;
licznikjedynek1 = 0, licznikdwojek1 = 0, liczniktrojek1 = 0, licznikczworek1 = 0, licznikjedynek2 = 0, licznikdwojek2 = 0, liczniktrojek2 = 0, licznikczworek2 = 0;
trojka_1 = 0, trojka_2 = 0, max_trojkowe_1 = 0, max_trojkowe_2 = 0, inna_zm_w_3_1 = 0, inna_zm_w_3_2 = 0, dwojka_wieksza_1 = 0, dwojka_wieksza_2 = 0, dwojka_mniejsza_1 = 0, dwojka_mniejsza_2 = 0, reszta_z_dwojek_1 = 0, reszta_z_dwojek_2 = 0, suma1 = 0, suma2 = 0;
zmienna--;
}

if(wygrane_a + remisy_a + przegrane_a != 0){
        cout << "gracz a" << endl;
     if(wygrane_a != 0)cout << "    wygrane: " << (wygrane_a / (wygrane_a + remisy_a + przegrane_a)) * 100 << "%" << endl;
     if(remisy_a != 0)cout <<  "    remisy: " << (remisy_a / (wygrane_a + remisy_a + przegrane_a)) * 100 << "%" << endl;
     if(przegrane_a != 0) cout << "    przegrane: " << (przegrane_a / (wygrane_a + remisy_a + przegrane_a)) * 100 << "%" << endl;
     cout << endl;}
if(wygrane_b + remisy_b + przegrane_b != 0){
        cout << "gracz b" << endl;
    if(wygrane_b != 0)cout << "    wygrane: " << (wygrane_b / (wygrane_b + remisy_b + przegrane_b)) * 100 << "%" << endl;
     if(remisy_b != 0)cout <<  "    remisy: " << (remisy_b / (wygrane_b + remisy_b + przegrane_b)) * 100 << "%" << endl;
     if(przegrane_b != 0) cout << "    przegrane: " << (przegrane_b / (wygrane_b + remisy_b + przegrane_b)) * 100 << "%" << endl;
     cout << endl;}
if(wygrane_c + remisy_c + przegrane_c != 0){
        cout << "gracz c" << endl;
     if(wygrane_c != 0)cout << "    wygrane: " << (wygrane_c / (wygrane_c + remisy_c + przegrane_c)) * 100 << "%" << endl;
     if(remisy_c != 0)cout <<  "    remisy: " << (remisy_c / (wygrane_c + remisy_c + przegrane_c)) * 100 << "%" << endl;
     if(przegrane_c != 0) cout << "    przegrane: " << (przegrane_c / (wygrane_c + remisy_c + przegrane_c)) * 100 << "%" << endl;
     cout << endl;}
if(wygrane_d + remisy_d + przegrane_d != 0){
    cout << "gracz d" << endl;
        if(wygrane_d != 0)cout << "    wygrane: " << (wygrane_d / (wygrane_d + remisy_d + przegrane_d)) * 100 << "%" << endl;
     if(remisy_d != 0)cout <<  "    remisy: " << (remisy_d / (wygrane_d + remisy_d + przegrane_d)) * 100 << "%" << endl;
     if(przegrane_d != 0) cout << "    przegrane: " << (przegrane_d / (wygrane_d + remisy_d + przegrane_d)) * 100 << "%" << endl;
     cout << endl;}
if(wygrane_e + remisy_e + przegrane_e != 0){
    cout << "gracz e" << endl;
        if(wygrane_e != 0)cout << "    wygrane: " << (wygrane_e / (wygrane_e + remisy_e + przegrane_e)) * 100 << "%" << endl;
     if(remisy_e != 0)cout <<  "    remisy: " << (remisy_e / (wygrane_e + remisy_e + przegrane_e)) * 100 << "%" << endl;
     if(przegrane_e != 0) cout << "    przegrane: " << (przegrane_e / (wygrane_e + remisy_e + przegrane_e)) * 100 << "%" << endl;
     cout << endl;}
return 0;
}
