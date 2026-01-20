//Pawel Jandula
#include<iostream>
using namespace std;
int wb = 0, rb = 0, sb = 0, pe = 0, we = 0, re = 0, se = 0, oldpe = 0, nowa = 0;
int w = 0, r = 0, s = 0, p = 0, a = 0 , P = 0, S = 0, A = 0, W = 0, stara = 0;
long long int sumatowarow = 0;
char d1 = ' ', d2 = ' ';
struct Towar
{
    unsigned short int ilosc; // ilosc towaru w miejscu na towar
    unsigned char etykieta[2];
};

struct Polka
{
    int plimit; //ilosc miejsc na towar- int char ?
    Towar towary[128];
};

struct Regal
{
    int rlimit; // ilosc polek
    Polka polki[128];
};

struct Magazyn
{
    int mlimit; // ilosc regalow
    Regal regaly[128];
    Polka pomocnik;
};

struct Sklad
{
    int slimit; // ilosc magazynow
    Magazyn magazyny[128];
    Polka pomocnikpolkaskladu;
    Regal pregal;
};

Sklad sklad;


char c[23];
int i = 0, wartownik = 1;

void SET_AP(int wb, int rb, int sb, int pe){
    if( wb < 0 || rb < 0 || sb < 0 || pe < 0 || wb > 127 || rb > 127 || sb > 127 || pe > 128 || sklad.slimit <= wb || sklad.magazyny[wb].mlimit <= rb || sklad.magazyny[wb].regaly[rb].rlimit <= sb){
        cout << "error" << endl;
    }
    else {
        oldpe = sklad.magazyny[wb].regaly[rb].polki[sb].plimit;
        sklad.magazyny[wb].regaly[rb].polki[sb].plimit = pe;
        for(int i = oldpe ; i < pe; i++){
            sklad.magazyny[wb].regaly[rb].polki[sb].towary[i].ilosc = 0;
            sklad.magazyny[wb].regaly[rb].polki[sb].towary[i].etykieta[0] = '-';
            sklad.magazyny[wb].regaly[rb].polki[sb].towary[i].etykieta[1] = '-';
        }
        for(int i = pe; i < oldpe; i++){
            sumatowarow -= sklad.magazyny[wb].regaly[rb].polki[sb].towary[i].ilosc;
            sklad.magazyny[wb].regaly[rb].polki[sb].towary[i].ilosc = 0;
            sklad.magazyny[wb].regaly[rb].polki[sb].towary[i].etykieta[0] = '-';
            sklad.magazyny[wb].regaly[rb].polki[sb].towary[i].etykieta[1] = '-';
        }

    }
}

void SET_AP_HR( int sb, int pe){
        oldpe = sklad.pregal.polki[sb].plimit;
        sklad.pregal.polki[sb].plimit = pe;
        for(int i = oldpe ; i < pe; i++){
            sklad.pregal.polki[sb].towary[i].ilosc = 0;
            sklad.pregal.polki[sb].towary[i].etykieta[0] = '-';
            sklad.pregal.polki[sb].towary[i].etykieta[1] = '-';
        }
        for(int i = pe; i < oldpe; i++){
            sumatowarow -= sklad.pregal.polki[sb].towary[i].ilosc;
            sklad.pregal.polki[sb].towary[i].ilosc = 0;
            sklad.pregal.polki[sb].towary[i].etykieta[0] = '-';
            sklad.pregal.polki[sb].towary[i].etykieta[1] = '-';
        }

}

void SET_AS(int wb, int rb, int se, int pe) {
    if (wb > 127 ||  rb > 127 ||  se > 128 ||  pe > 128 || sklad.slimit <= wb || sklad.magazyny[wb].mlimit <= rb || wb < 0 || rb < 0 || se < 0 || pe < 0) {
        cout << "error" << endl;
    } else {
        if (se < sklad.magazyny[wb].regaly[rb].rlimit) {

            for (int i = se; i < sklad.magazyny[wb].regaly[rb].rlimit; i++) {
                for (int j = 0; j < sklad.magazyny[w].regaly[rb].polki[i].plimit; j++) {
                    sumatowarow -= sklad.magazyny[w].regaly[rb].polki[i].towary[j].ilosc;
                    sklad.magazyny[w].regaly[rb].polki[i].towary[j].ilosc = 0;
                    sklad.magazyny[w].regaly[rb].polki[i].towary[j].etykieta[0] = '-';
                    sklad.magazyny[w].regaly[rb].polki[i].towary[j].etykieta[1] = '-';
                }

            }
            sklad.magazyny[wb].regaly[rb].rlimit = se;

        }
        else {
            for (int i = sklad.magazyny[wb].regaly[rb].rlimit; i < se; i++) {
                for (int j = 0; j < sklad.magazyny[w].regaly[rb].polki[i].plimit; j++) {
                    sumatowarow -= sklad.magazyny[w].regaly[rb].polki[i].towary[j].ilosc;
                    sklad.magazyny[w].regaly[rb].polki[i].towary[j].etykieta[0] = '-';
                    sklad.magazyny[w].regaly[rb].polki[i].towary[j].etykieta[1] = '-';

                }
                sklad.magazyny[w].regaly[rb].polki[i].plimit = re;
            }
            sklad.magazyny[wb].regaly[rb].rlimit = se;
        }
        if (sklad.magazyny[wb].regaly[rb].rlimit > se) {
            for (int i = 0; i < se; i++) {
                SET_AP(wb, rb, i, pe);
            }
        } else {
            for (int i = 0; i < sklad.magazyny[wb].regaly[rb].rlimit; i++) {
                SET_AP(wb, rb, i, pe);
            }
        }
    }
}



void SET_AR(int wb, int re, int se, int pe)
{
    if (wb < 0 || re < 0 || se < 0 || pe < 0 || re > 128 || se > 128 || pe > 128 ||  sklad.slimit <= wb  )
    {
        cout << "error" << endl;
    }
    else
    {
        stara = sklad.magazyny[wb].mlimit;
        sklad.magazyny[wb].mlimit = re;
        if (stara > re)
        {
            for (int i = re; i < stara; i++)
            {
                for (int j = 0; j < sklad.magazyny[wb].regaly[i].rlimit; j++)
                {
                    for (int k = 0; k < sklad.magazyny[wb].regaly[i].polki[j].plimit; k++)
                    {
                        sumatowarow -= sklad.magazyny[wb].regaly[i].polki[j].towary[k].ilosc;
                        sklad.magazyny[wb].regaly[i].polki[j].towary[k].ilosc = 0;
                        sklad.magazyny[wb].regaly[i].polki[j].towary[k].etykieta[0] = '-';
                        sklad.magazyny[wb].regaly[i].polki[j].towary[k].etykieta[1] = '-';
                    }
                    sklad.magazyny[wb].regaly[i].polki[j].plimit = 0;
                }
                sklad.magazyny[wb].regaly[i].rlimit = 0;
            }
        }
        else
        {
            for (int i = stara; i < re; i++)
            {

                for (int j = 0; j < se; j++)
                {
                    for (int k = 0; k < sklad.magazyny[wb].regaly[i].polki[j].plimit; k++)
                    {
                        sumatowarow -= sklad.magazyny[wb].regaly[i].polki[j].towary[k].ilosc;
                        sklad.magazyny[wb].regaly[i].polki[j].towary[k].ilosc = 0;
                        sklad.magazyny[wb].regaly[i].polki[j].towary[k].etykieta[0] = '-';
                        sklad.magazyny[wb].regaly[i].polki[j].towary[k].etykieta[1] = '-';
                    }
                    sklad.magazyny[wb].regaly[i].polki[j].plimit = pe;
                }
                sklad.magazyny[wb].regaly[i].rlimit = se;

            }
        }
        if (stara > re)
        {
            for (int i = 0; i < re; i++)
            {
                SET_AS(wb, i, se, pe);
            }
        }
        else
        {
            for (int i = 0; i < stara; i++)
            {
                SET_AS(wb, i, se, pe);
            }
        }
    }
}

void SET_AW(int we, int re, int se, int pe){
    if(we > 128 || re > 128 || se > 128 || pe > 128 || we < 0 || re < 0 || se < 0 || pe < 0){
        cout << "error" << endl;
    }
    else {
        nowa = sklad.slimit;
        sklad.slimit = we;
        if (we > nowa) {
            for (int i = nowa; i < we; i++) {
                sklad.magazyny[i].mlimit = re;
                for (int j = 0; j < re; j++) {
                    sklad.magazyny[i].regaly[j].rlimit = se;
                    for (int k = 0; k < se; k++) {
                        sklad.magazyny[i].regaly[j].polki[k].plimit = pe;
                        for(int l = 0; l < pe; l ++){
                            sklad.magazyny[i].regaly[j].polki[k].towary[l].ilosc = 0;
                            sklad.magazyny[i].regaly[j].polki[k].towary[l].etykieta[0] = '-';
                            sklad.magazyny[i].regaly[j].polki[k].towary[l].etykieta[1] = '-';
                        }
                    }
                }
            }
            for (int i = 0; i < nowa; i++) {
                SET_AR(i, re, se, pe);
            }
        }
        else {
            for (int i = 0; i < we; i++) {
                SET_AR(i, re, se, pe);
            }

            for(int i = we; i < nowa; i++){
                sklad.magazyny[i].mlimit = re;
                for (int j = 0; j < re; j++) {
                    sklad.magazyny[i].regaly[j].rlimit = se;
                    for (int k = 0; k < se; k++) {
                        sklad.magazyny[i].regaly[j].polki[k].plimit = pe;
                        for(int l = 0; l < pe; l ++){
                            sumatowarow -= sklad.magazyny[i].regaly[j].polki[k].towary[l].ilosc;
                            sklad.magazyny[i].regaly[j].polki[k].towary[l].ilosc = 0;
                            sklad.magazyny[i].regaly[j].polki[k].towary[l].etykieta[0] = '-';
                            sklad.magazyny[i].regaly[j].polki[k].towary[l].etykieta[1] = '-';
                        }
                    }
                }
            }
        }
    }
}

void SET_HW(int w, int P){
    if( w > 127 || P > 128 || P < 0 || W < 0|| sklad.slimit <= w){
        cout << "error" << endl;
    }
    else {
        int zmienna = sklad.magazyny[w].pomocnik.plimit;
        sklad.magazyny[w].pomocnik.plimit = P;
        if( P > zmienna){
            for(int i = zmienna; i < P; i++){
                sklad.magazyny[w].pomocnik.towary[i].ilosc = 0;
                sklad.magazyny[w].pomocnik.towary[i].etykieta[0] = '-';
                sklad.magazyny[w].pomocnik.towary[i].etykieta[1] = '-';
            }

        }
        if( P <= zmienna){
            for(int i = P; i < zmienna; i++){
                sumatowarow -= sklad.magazyny[w].pomocnik.towary[i].ilosc;
                sklad.magazyny[w].pomocnik.towary[i].ilosc = 0;
                sklad.magazyny[w].pomocnik.towary[i].etykieta[0] = '-';
                sklad.magazyny[w].pomocnik.towary[i].etykieta[1] = '-';
            }
        }
    }
}

void SET_HR(int S, int P){
    if( S > 128 || P > 128 || P < 0 || S < 0){
        cout << "error" << endl;
    }
    else {

        if (S > sklad.pregal.rlimit) {
            for (int i = sklad.pregal.rlimit; i < S; i++) {
                sklad.pregal.polki[i].plimit = P;
                for (int j = 0; j < P; j++) {
                    sklad.pregal.polki[i].towary[j].ilosc = 0;
                    sklad.pregal.polki[i].towary[j].etykieta[0] = '-';
                    sklad.pregal.polki[i].towary[j].etykieta[1] = '-';
                }
            }


            for (int i = 0; i < sklad.pregal.rlimit; i++) {
                SET_AP_HR(i, P);
            }

        }
        else {
            for(int i = S; i < sklad.pregal.rlimit; i++){
                for(int j = 0; j < sklad.pregal.polki[i].plimit; j++) {
                    sumatowarow -= sklad.pregal.polki[i].towary[j].ilosc;
                    sklad.pregal.polki[i].towary[j].ilosc = 0;
                    sklad.pregal.polki[i].towary[j].etykieta[0] = '-';
                    sklad.pregal.polki[i].towary[j].etykieta[1] = '-';
                }
            }
            for (int i = 0; i < sklad.pregal.rlimit; i++) {

                SET_AP_HR(i, P);
            }
        }
        sklad.pregal.rlimit = S;
    }

}

void SET_HS(int P){
    if( P > 128 || P < 0){
        cout << "error" << endl;
    }
    else {
        nowa = sklad.pomocnikpolkaskladu.plimit;
        sklad.pomocnikpolkaskladu.plimit = P;
        if (P > nowa) {
            for (int i = nowa; i < P; i++) {
                sklad.pomocnikpolkaskladu.towary[i].ilosc = 0;
                sklad.pomocnikpolkaskladu.towary[i].etykieta[0] = '-';
                sklad.pomocnikpolkaskladu.towary[i].etykieta[1] = '-';
            }
        }
        if(P <= nowa){
            for(int i = P; i < nowa; i++){
                sumatowarow -= sklad.pomocnikpolkaskladu.towary[i].ilosc;
                sklad.pomocnikpolkaskladu.towary[i].ilosc = 0;
                sklad.pomocnikpolkaskladu.towary[i].etykieta[0] = '-';
                sklad.pomocnikpolkaskladu.towary[i].etykieta[1] = '-';

            }
        }
    }
}

void POP_W(int w, int r, int s, int p, int A){
    if(sklad.slimit > w && sklad.magazyny[w].mlimit > r && sklad.magazyny[w].regaly[r].rlimit > s && sklad.magazyny[w].regaly[r].polki[s].plimit > p && p >= 0 && s >= 0 && r >= 0 && w >= 0){
        if(sklad.magazyny[w].regaly[r].polki[s].towary[p].ilosc < A){
            nowa = sklad.magazyny[w].regaly[r].polki[s].towary[p].ilosc;
            sklad.magazyny[w].regaly[r].polki[s].towary[p].ilosc = 0;
            sumatowarow -= (nowa);
        }
        else {
            sklad.magazyny[w].regaly[r].polki[s].towary[p].ilosc -= A;
            sumatowarow -= A;
        }
    }
    else cout << "error" << endl;
}
void POP_H(int w, int p, int A){
    if( w >= 0 && p >= 0 && sklad.slimit > w && sklad.magazyny[w].pomocnik.plimit > p ){
        if(sklad.magazyny[w].pomocnik.towary[p].ilosc < A){
            nowa = sklad.magazyny[w].pomocnik.towary[p].ilosc;
            sklad.magazyny[w].pomocnik.towary[p].ilosc = 0;
            sumatowarow -= (nowa);
        }
        else {
            sklad.magazyny[w].pomocnik.towary[p].ilosc -= A;
            sumatowarow -= A;
        }
    }
    else cout << "error" << endl;
}

void POP_R(int s, int p, int A){
    if(s >= 0 && p >= 0 && sklad.pregal.rlimit > s && sklad.pregal.polki[s].plimit > p) {
        if (sklad.pregal.polki[s].towary[p].ilosc < A) {
            nowa = sklad.pregal.polki[s].towary[p].ilosc;
            sklad.pregal.polki[s].towary[p].ilosc = 0;
            sumatowarow -= ( nowa);
        } else {
            sklad.pregal.polki[s].towary[p].ilosc -= A;
            sumatowarow -= A;
        }
    }
    else cout << "error" << endl;
}
void POP_S(int p, int A){
    if(p >= 0 && sklad.pomocnikpolkaskladu.plimit > p){
        if(sklad.pomocnikpolkaskladu.towary[p].ilosc < A){
            nowa = sklad.pomocnikpolkaskladu.towary[p].ilosc;
            sklad.pomocnikpolkaskladu.towary[p].ilosc = 0;
            sumatowarow -= ( nowa);
        }
        else {
            sklad.pomocnikpolkaskladu.towary[p].ilosc -= A;
            sumatowarow -= A;
        }
    }
    else cout <<"error" << endl;
}


void PUT_W(int w, int r, int s, int p, int A){
    if(w >= 0 && r >= 0 && s >= 0 && p >= 0 && sklad.slimit > w && sklad.magazyny[w].mlimit > r && sklad.magazyny[w].regaly[r].rlimit > s && sklad.magazyny[w].regaly[r].polki[s].plimit > p) {
        if (sklad.magazyny[w].regaly[r].polki[s].towary[p].ilosc > 65535 - A) {
            nowa = sklad.magazyny[w].regaly[r].polki[s].towary[p].ilosc;
            sklad.magazyny[w].regaly[r].polki[s].towary[p].ilosc = 65535;
            sumatowarow += (65535 - nowa);
        } else {
            sklad.magazyny[w].regaly[r].polki[s].towary[p].ilosc += A;
            sumatowarow += A;
        }
    }
    else cout << "error" << endl;
}
void PUT_H(int w, int p, int A){
    if( w >= 0 && p >= 0 && sklad.slimit > w && sklad.magazyny[w].pomocnik.plimit > p ){
        if(sklad.magazyny[w].pomocnik.towary[p].ilosc > 65535 - A){
            nowa = sklad.magazyny[w].pomocnik.towary[p].ilosc;
            sklad.magazyny[w].pomocnik.towary[p].ilosc = 65535;
            sumatowarow += (65535 - nowa);
        }
        else {
            sklad.magazyny[w].pomocnik.towary[p].ilosc += A;
            sumatowarow += A;
        }
    }
    else cout << "error" << endl;
}
void PUT_R(int s, int p, int A){
    if(s >= 0 && p >= 0 && sklad.pregal.rlimit > s && sklad.pregal.polki[s].plimit > p) {
        if (sklad.pregal.polki[s].towary[p].ilosc > 65535 - A) {
            nowa = sklad.pregal.polki[s].towary[p].ilosc;
            sklad.pregal.polki[s].towary[p].ilosc = 65535;
            sumatowarow += (65535 - nowa);
        } else {
            sklad.pregal.polki[s].towary[p].ilosc += A;
            sumatowarow += A;
        }
    }
    else cout << "error" << endl;
}
void PUT_S(int p, int A){
    if(p >= 0 && sklad.pomocnikpolkaskladu.plimit> p){
        if (sklad.pomocnikpolkaskladu.towary[p].ilosc > 65535 - A) {
            nowa = sklad.pomocnikpolkaskladu.towary[p].ilosc;
            sklad.pomocnikpolkaskladu.towary[p].ilosc = 65535;
            sumatowarow += (65535 - nowa);
        } else {
            sklad.pomocnikpolkaskladu.towary[p].ilosc += A;
            sumatowarow += A;
        }
    }
    else cout << "error" << endl;

}

void SET_LW(int w, int r, int s, int p, char d1, char d2){
    if(w >= 0 && w < sklad.slimit && r >= 0 && r < sklad.magazyny[w].mlimit && s >= 0 && s < sklad.magazyny[w].regaly[r].rlimit && p >= 0 && p < sklad.magazyny[w].regaly[r].polki[s].plimit && d1 >= '0' && d1 <='9' && d2 >='0' && d2 <='9'){
        sklad.magazyny[w].regaly[r].polki[s].towary[p].etykieta[0] = d1;
        sklad.magazyny[w].regaly[r].polki[s].towary[p].etykieta[1] = d2;
    }
    else cout << "error" << endl;
}
void SET_LH (int w, int p, char d1, char d2){
    if(w >= 0 && w < sklad.slimit && p >= 0 && p < sklad.magazyny[w].pomocnik.plimit && d1 >= '0' && d1 <='9' && d2 >='0' && d2 <='9') {
        sklad.magazyny[w].pomocnik.towary[p].etykieta[0] = d1;
        sklad.magazyny[w].pomocnik.towary[p].etykieta[1] = d2;
    }
    else cout << "error" << endl;
}
void SET_LR(int s, int p, char d1, char d2){
    if(s >= 0 && s < sklad.pregal.rlimit && p >= 0 && p < sklad.pregal.polki[s].plimit && d1 >= '0' && d1 <='9' && d2 >='0' && d2 <='9') {
        sklad.pregal.polki[s].towary[p].etykieta[0] = d1;
        sklad.pregal.polki[s].towary[p].etykieta[1] = d2;
    }
    else cout << "error" << endl;
}
void SET_LS(int p, char d1, char d2){
    if(p < sklad.pomocnikpolkaskladu.plimit && p >= 0 && d1 >= '0' && d1 <='9' && d2 >='0' && d2 <='9') {
        sklad.pomocnikpolkaskladu.towary[p].etykieta[0] = d1;
        sklad.pomocnikpolkaskladu.towary[p].etykieta[1] = d2;
    }
    else {
        cout << "error" << endl;
    }
}






void FILL(long long int W, long long int R, long long int S, long long int P, long long int A) {
    sumatowarow = 0;
    if (W > 128 || R > 128 || S > 128 || P > 128 || A > 65535 || W < 0 || R < 0 || S < 0 || P < 0 || A < 0)
        cout << "error" << endl;
    else {
        for (int i = W; i < 128; i++) {
            sklad.magazyny[i].mlimit = 0;
            for (int j = R; j < 128; j++) {
                sklad.magazyny[i].regaly[j].rlimit = 0;
                for (int k = S; k < 128; k++) {
                    sklad.magazyny[i].regaly[j].polki[k].plimit = 0;
                    for (int l = P; l < 128; l++) {
                        sklad.magazyny[i].regaly[j].polki[k].towary[l].ilosc = 0;
                        sklad.magazyny[i].regaly[j].polki[k].towary[l].etykieta[0] = '-';
                        sklad.magazyny[i].regaly[j].polki[k].towary[l].etykieta[1] = '-';
                    }
                }
            }
            sklad.magazyny[i].pomocnik.plimit = 0;
            for (int m = P; m < 128; m++) {
                sklad.magazyny[i].pomocnik.towary[m].ilosc = 0;
                sklad.magazyny[i].pomocnik.towary[m].etykieta[0] = '-';
                sklad.magazyny[i].pomocnik.towary[m].etykieta[1] = '-';
            }
        }
        sklad.pomocnikpolkaskladu.plimit = 0;
        for (int m = P; m < 128; m++) {
            sklad.pomocnikpolkaskladu.towary[m].ilosc = 0;
            sklad.pomocnikpolkaskladu.towary[m].etykieta[0] = '-';
            sklad.pomocnikpolkaskladu.towary[m].etykieta[1] = '-';
        }
        sklad.pregal.rlimit = 0;
        for (int m = S; m < 128; m++) {
            sklad.pregal.polki[m].plimit = 0;
            for (int n = P; n < 128; n++) {
                sklad.pregal.polki[m].towary[n].ilosc = 0;
                sklad.pregal.polki[m].towary[n].etykieta[0] = '-';
                sklad.pregal.polki[m].towary[n].etykieta[1] = '-';
            }
        }
        sumatowarow = W * R * S * P * A + W * P * A + S * P * A + P * A;
        sklad.slimit = W;
        for (int i = 0; i < W; i++) {
            sklad.magazyny[i].mlimit = R;
            for (int j = 0; j < R; j++) {
                sklad.magazyny[i].regaly[j].rlimit = S;
                for (int k = 0; k < S; k++) {
                    sklad.magazyny[i].regaly[j].polki[k].plimit = P;
                    for (int l = 0; l < P; l++) {
                        sklad.magazyny[i].regaly[j].polki[k].towary[l].ilosc = A;
                        sklad.magazyny[i].regaly[j].polki[k].towary[l].etykieta[0] = '-';
                        sklad.magazyny[i].regaly[j].polki[k].towary[l].etykieta[1] = '-';
                    }
                }
            }
            sklad.magazyny[i].pomocnik.plimit = P;
            for (int m = 0; m <= P; m++) {
                sklad.magazyny[i].pomocnik.towary[m].ilosc = A;
                sklad.magazyny[i].pomocnik.towary[m].etykieta[0] = '-';
                sklad.magazyny[i].pomocnik.towary[m].etykieta[1] = '-';
            }
        }
        sklad.pomocnikpolkaskladu.plimit = P;
        for (int m = 0; m < P; m++) {
            sklad.pomocnikpolkaskladu.towary[m].ilosc = A;
            sklad.pomocnikpolkaskladu.towary[m].etykieta[0] = '-';
            sklad.pomocnikpolkaskladu.towary[m].etykieta[1] = '-';
        }
        sklad.pregal.rlimit = S;
        for (int m = 0; m < S; m++) {
            sklad.pregal.polki[m].plimit = P;
            for (int n = 0; n < P; n++) {
                sklad.pregal.polki[m].towary[n].ilosc = A;
                sklad.pregal.polki[m].towary[n].etykieta[0] = '-';
                sklad.pregal.polki[m].towary[n].etykieta[1] = '-';
            }
        }
    }



}
void GET_E(){ // dziala
    cout << sumatowarow << endl;
}
void GET_S(){ // dziala
    long long int suma = 0;
    for(int i = 0; i < sklad.pomocnikpolkaskladu.plimit; i++){
        suma += sklad.pomocnikpolkaskladu.towary[i].ilosc;
    }
    cout << suma << endl;
}
void GET_W(int W){ // dobrze
    long long int suma = 0;
    if(W < 0 || W >= sklad.slimit){
        cout << "error" << endl;
    }
    else {
        for(int i = 0; i < sklad.magazyny[W].mlimit; i++){
            for(int j = 0; j < sklad.magazyny[W].regaly[i].rlimit; j++){
                for(int k = 0; k < sklad.magazyny[W].regaly[i].polki[j].plimit; k++){
                    suma += sklad.magazyny[W].regaly[i].polki[j].towary[k].ilosc;
                }
            }
        }
        for( int i = 0; i < sklad.magazyny[W].pomocnik.plimit; i++) {
            suma += sklad.magazyny[W].pomocnik.towary[i].ilosc;
        }
        cout << suma << endl;
    }

}


void GET_RW(int w, int r){
    if(w < 0 || r < 0 || w >= sklad.slimit || r >= sklad.magazyny[w].mlimit)cout << "error" << endl;
    else {
        long long int suma = 0;
        for (int i = 0; i < sklad.magazyny[w].regaly[r].rlimit; i++) {// ilosc polek
            for (int j = 0; j < sklad.magazyny[w].regaly[r].polki[i].plimit; j++) {// ilosc miejsc
                suma += sklad.magazyny[w].regaly[r].polki[i].towary[j].ilosc;
            }

        }
        cout << suma << endl;
    }
}

void GET_RH(){//dziala

    long long int suma = 0;
    for (int i = 0; i < sklad.pregal.rlimit; i++) {
        for (int j = 0; j < sklad.pregal.polki[i].plimit; j++) {
            suma += sklad.pregal.polki[i].towary[j].ilosc;
        }
    }
    cout << suma << endl;
}

void GET_SW(int w, int r, int s){//dziala
    if(w < 0 || r < 0 || s < 0 ||  w >= sklad.slimit || r >= sklad.magazyny[w].mlimit || s >= sklad.magazyny[w].regaly[r].rlimit )cout << "error" << endl;
    else {
        long long int suma = 0;
        for (int i = 0; i < sklad.magazyny[w].regaly[r].polki[s].plimit; i++){
            suma += sklad.magazyny[w].regaly[r].polki[s].towary[i].ilosc;}
        cout << suma << endl;
    }
}

void GET_SR(int s){// dziala
    if(s < 0 || s >= sklad.pregal.rlimit)cout << "error" << endl;
    else {
        long long int suma = 0;
        for (int i = 0; i < sklad.pregal.polki[s].plimit; i++) {
            suma += sklad.pregal.polki[s].towary[i].ilosc;
        }
        cout << suma << endl;
    }
}

void GET_SH(int w){// dobrze
    if(w < 0 || w >= sklad.slimit)cout << "error" << endl;
    else {
        long long int suma = 0;
        for (int i = 0; i < sklad.magazyny[w].pomocnik.plimit; i++) {
            suma += sklad.magazyny[w].pomocnik.towary[i].ilosc;
        }
        cout << suma << endl;
    }
}



void GET_LW(int w, int r, int s, int p){
    if(p >= 0 && w >= 0 && w < sklad.slimit && r >= 0 && r < sklad.magazyny[w].mlimit && s >= 0 && s < sklad.magazyny[w].regaly[r].rlimit && p < sklad.magazyny[w].regaly[r].polki[s].plimit){
        if( sklad.magazyny[w].regaly[r].polki[s].towary[p].etykieta[0] != '-' && sklad.magazyny[w].regaly[r].polki[s].towary[p].etykieta[1] != '-'){
            cout << sklad.magazyny[w].regaly[r].polki[s].towary[p].etykieta[0] << sklad.magazyny[w].regaly[r].polki[s].towary[p].etykieta[1] << endl;
        }
        else cout << "--" << endl;
    }
    else cout <<"error"<<endl;

}
void GET_LH(int w, int p){
    if(w >= 0 && p >= 0 && w < sklad.slimit && p < sklad.magazyny[w].pomocnik.plimit) {
        if (sklad.magazyny[w].pomocnik.towary[p].etykieta[0] != '-' && sklad.magazyny[w].pomocnik.towary[p].etykieta[1] != '-')
            cout << sklad.magazyny[w].pomocnik.towary[p].etykieta[0] << sklad.magazyny[w].pomocnik.towary[p].etykieta[1]<< endl;
        else
            cout << "--" << endl;

    }
    else
        cout << "error" << endl;

}
void GET_LR(int s, int p){

    if(s >=0 && p >= 0 && sklad.pregal.rlimit > s && p < sklad.pregal.polki[s].plimit){
        if(sklad.pregal.polki[s].towary[p].etykieta[0] != '-' && sklad.pregal.polki[s].towary[p].etykieta[1] != '-'){
            cout << sklad.pregal.polki[s].towary[p].etykieta[0] << sklad.pregal.polki[s].towary[p].etykieta[1] << endl;
        }
        else
            cout << "--" << endl;
    }
    else {
        cout << "error" << endl;
    }
}
void GET_LS(int p){
    if(p >=0 && sklad.pomocnikpolkaskladu.plimit > p){
        if(sklad.pomocnikpolkaskladu.towary[p].etykieta[0] != '-' && sklad.pomocnikpolkaskladu.towary[p].etykieta[1] != '-'){
            cout << sklad.pomocnikpolkaskladu.towary[p].etykieta[0] << sklad.pomocnikpolkaskladu.towary[p].etykieta[1] << endl;
        }
        else
            cout << "--" << endl;
    }
    else {
        cout << "error" << endl;
    }
}

void MOV_W(int wb, int rb, int sb, int we, int re, int se, int p, long long A){
    if(wb < 0 || rb < 0 || sb < 0|| we < 0 || re < 0 || se < 0 || p < 0 || A < 0 || A > 65535 || wb >= sklad.slimit || rb >= sklad.magazyny[wb].mlimit || sb >= sklad.magazyny[wb].regaly[rb].rlimit || we >= sklad.slimit || re >= sklad.magazyny[we].mlimit || se >= sklad.magazyny[we].regaly[re].rlimit||p>=sklad.magazyny[we].regaly[re].polki[se].plimit||p>=sklad.magazyny[wb].regaly[rb].polki[sb].plimit){
        cout <<"error" << endl;
    }
    else {
        if(sklad.magazyny[wb].regaly[rb].polki[sb].towary[p].ilosc < A)
        {
            A = sklad.magazyny[wb].regaly[rb].polki[sb].towary[p].ilosc;
        }
        if(sklad.magazyny[we].regaly[re].polki[se].towary[p].ilosc > 65535 - A){
            A = 65535 - sklad.magazyny[we].regaly[re].polki[se].towary[p].ilosc;
        }
        POP_W(wb, rb, sb, p, A);
        PUT_W(we, re, se, p, A);


    }


}
void MOV_H(int w, int r, int s, int p, int A){
    if(w < 0 || r < 0 || s < 0 || p < 0 || A < 0 || A > 65535 || w >= sklad.slimit || r >= sklad.magazyny[w].mlimit || s >= sklad.magazyny[w].regaly[r].rlimit || p >= sklad.magazyny[w].regaly[r].polki[s].plimit || p >= sklad.magazyny[w].pomocnik.plimit ) {
        cout <<"error" << endl;
    }
    else {
        if (sklad.magazyny[w].regaly[r].polki[s].towary[p].ilosc < A) {
            A = sklad.magazyny[w].regaly[r].polki[s].towary[p].ilosc;
        }
        if (sklad.magazyny[w].pomocnik.towary[p].ilosc > 65535 - A) {
            A = 65535 - sklad.magazyny[w].pomocnik.towary[p].ilosc;
        }
        POP_W(w, r, s, p, A);
        PUT_H(w, p, A);
    }


}
void MOV_R(int w, int r, int sb, int se, int p, int A) {
    if (w < 0 || r < 0 || sb < 0 || se < 0 || p < 0 || A < 0 || A > 65535 || w >= sklad.slimit || r >= sklad.magazyny[w].mlimit || sb >= sklad.magazyny[w].regaly[r].rlimit || se >= sklad.pregal.rlimit || p >= sklad.magazyny[w].regaly[r].polki[sb].plimit || p >= sklad.pregal.polki[se].plimit) {
        cout << "error" << endl;
    }
    else {
        if(sklad.magazyny[w].regaly[r].polki[sb].towary[p].ilosc < A){
            A = sklad.magazyny[w].regaly[r].polki[sb].towary[p].ilosc;
        }
        if(sklad.pregal.polki[se].towary[p].ilosc > 65535 - A){
            A = 65535 - sklad.pregal.polki[se].towary[p].ilosc;
        }
        POP_W(w,r, sb, p, A);
        PUT_R( se, p, A);
    }
}
void MOV_S(int s, int p, int A){
    if( s < 0 || p < 0 || A < 0 || A > 65535 || s >= sklad.pregal.rlimit || p >= sklad.pomocnikpolkaskladu.plimit || p >= sklad.pregal.polki[s].plimit){
        cout << "error" << endl;
    }
    else {
        if(sklad.pregal.polki[s].towary[p].ilosc < A){
            A = sklad.pregal.polki[s].towary[p].ilosc;
        }
        if(sklad.pomocnikpolkaskladu.towary[p].ilosc > 65535 - A){
            A = 65535 - sklad.pomocnikpolkaskladu.towary[p].ilosc;
        }
        PUT_S(p, A);
        POP_R(s, p, A);
    }
}







int main(){

    while(wartownik == 1) {
        cin >> c;
        if (c[0] == 'S') {//SET
            if(c[4] == 'A' && c[5] == 'P'){
                cin >> wb >> rb >> sb >> pe;
                SET_AP(wb, rb, sb, pe);
            }

            else if(c[4] == 'A'  && c[5] == 'S'){
                cin >> wb >> rb >> se >> pe;
                SET_AS(wb, rb, se, pe);

            }
            else if(c[4] == 'A'  && c[5] == 'R'){
                cin >> wb >> re >> se >> pe;
                SET_AR(wb, re, se, pe);
            }
            else if(c[4] == 'A' && c[5] == 'W'){
                cin >> we >> re >> se >> pe;
                SET_AW(we, re, se , pe);
            }



            else if(c[4] == 'H'  && c[5] == 'W'){
                cin >> w >> P;
                SET_HW(w, P);

            }
            else if(c[4] == 'H' && c[5] == 'R'){
                cin >> S >> P;
                SET_HR(S , P);
            }
            else if(c[4] == 'H' && c[5] == 'S'){
                cin >> P;
                SET_HS(P);
            }



            else if(c[4] == 'L'  && c[5] == 'W'){
                cin >> w >> r >> s >> p >> d1 >> d2;
                SET_LW(w, r, s, p, d1 , d2);
            }
            else if(c[4] == 'L' && c[5] == 'H'){
                cin >> w >> p >> d1 >> d2;
                SET_LH(w, p, d1, d2);
            }
            else if(c[4] == 'L'  && c[5] == 'R'){
                cin >> s >> p >> d1 >> d2;
                SET_LR(s, p, d1, d2);
            }
            else if(c[4] == 'L'  && c[5] == 'S'){
                cin >> p >> d1 >> d2;
                SET_LS(p, d1, d2);
            }


        }


        else if (c[0] == 'P' && c[1] == 'U') {//PUT
            if(c[4] == 'W'){
                cin >> w >> r >> s >> p >> A;
                PUT_W(w, r, s, p ,A);

            }
            else if(c[4] == 'H'){
                cin >> w >> p >> A;
                PUT_H(w, p , A);
            }
            else if(c[4] == 'R'){
                cin >> s >> p >> A;
                PUT_R(s, p, A);
            }
            else if(c[4] == 'S'){
                cin >> p >> A;
                PUT_S(p, A);
            }
        }
        else if (c[0] == 'P' && c[1] == 'O') {//POP
            if(c[4] == 'W'){
                cin >> w >> r >> s >> p >> A;
                POP_W(w, r, s, p, A);
            }
            else if(c[4] == 'H'){
                cin >> w >> p >> A;
                POP_H(w, p, A);
            }
            else if(c[4] == 'R'){
                cin >> s >> p >> A;
                POP_R(s, p, A);
            }
            else if(c[4] == 'S'){
                cin >> p >> A;
                POP_S(p, A);
            }
        }
        else if (c[0] == 'F') {//FILL
            cin >> w >> r >> s >> p >> a;
            FILL(w, r, s, p, a);
        }
        else if (c[0] == 'M') {//MOV
            if(c[4] == 'W'){
                cin >> wb >> rb >> sb >> we >> re >> se >> p >> A;
                MOV_W(wb, rb, sb, we, re, se, p, A);
            }
            else if(c[4] == 'H'){
                cin >> w >> r >> s >> p >> A;
                MOV_H(w, r, s, p, A);
            }
            else if(c[4] == 'R'){
                cin >> w >> r >> sb >> se >> p >> A;
                MOV_R(w, r, sb, se, p, A);
            }
            else if(c[4] == 'S'){
                cin >> s >> p >> A;
                MOV_S(s, p, A);
            }
        }
        else if (c[0] == 'G') {//GET
            if(c[4] == 'E'){
                GET_E();
            }
            else if(c[4] == 'W'){
                cin >> W;
                GET_W(W);
            }
            else if(c[4] == 'R' && c[5] == 'W'){
                cin >> w >> r;
                GET_RW(w, r);
            }
            else if(c[4] == 'R' && c[5] == 'H'){
                GET_RH();
            }
            else if(c[4] == 'S' && c[5] == 'W'){
                cin >> w >> r >> s;
                GET_SW(w, r, s);
            }
            else if(c[4] == 'S' && c[5] == 'H'){
                cin >> w;
                GET_SH(w);
            }
            else if(c[4] == 'S' && c[5] == 'R'){
                cin >> s;
                GET_SR(s);
            }
            else if(c[4] == 'L' && c[5] == 'W'){
                cin >> w >> r >> s >> p;
                GET_LW(w, r, s, p);
            }
            else if(c[4] == 'L' && c[5] == 'H'){
                cin >> w >> p;
                GET_LH(w, p);
            }
            else if(c[4] == 'L' && c[5] == 'R'){
                cin >> s >> p;
                GET_LR(s, p);
            }
            else if(c[4] == 'L' && c[5] == 'S'){
                cin >> p;
                GET_LS(p);
            }
            else if(c[4] == 'S'){
                GET_S();
            }
        }
        else if (c[0] == 'E') {//END
            wartownik = 0;
        }
    }
    return 0;

}
