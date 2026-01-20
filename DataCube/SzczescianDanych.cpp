//Pawel Jandula
#include<iostream>
using namespace std;
long long int Tab[32][32][32];
 long long int Indeks[32][32];
int n = 0;
int wartownik = 1;
int maks = 1000000, zmienna1 = 0, zmienna2 = 0, zmienna3 = 0;
void FunkcjaC(int l, int v, int p, int h, int w, int d){
    int suma = 0;

            if(l >= (n / 2) && v >= (n / 2) && p >= (n / 2))
            {
                for(int i = l - h; i <= l; i++)
                {
                    if(i >= 0 && i < n)
                    {
                        for(int j = v - w; j <= v; j++ )
                        {
                            if(j >= 0 && j < n)
                            {
                                for(int k = p - d; k <= p; k++)
                                {
                                    if(k >= 0 && k < n)
                                    {
                                        suma+=Tab[i][k][j];
                                    }
                                }
                            }
                        }
                    }
                }
            }

            if(l < (n / 2) && v >= (n / 2) && p < (n / 2))
            {
                for(int i = l ; i <= l + d; i++)
                {
                    if(i >= 0 && i < n)
                    {
                        for(int j = v - w; j <= v; j++ )
                        {
                            if(j >= 0 && j < n)
                            {
                                for(int k = p; k <= p + d; k++)
                                {
                                    if(k >= 0 && k < n)
                                    {
                                        suma+=Tab[i][k][j];
                                    }
                                }
                            }
                        }
                    }
                }
            }


            if(l >= (n / 2) && v < (n / 2) && p < (n / 2))
            {
                for(int i = l - h; i <= l; i++)
                {
                    if(i >= 0 && i < n)
                    {
                        for(int j = v; j <= v + w; j++ )
                        {
                            if(j >= 0 && j < n)
                            {
                                for(int k = p; k <= p + d; k++)
                                {
                                    if(k >= 0 && k < n)
                                    {
                                        suma+=Tab[i][k][j];
                                    }
                                }
                            }
                        }
                    }
                }
            }

            if(l < (n / 2) && v < (n / 2) && p < (n / 2))
            {
                for(int i = l; i <= l + h; i++)
                {
                    if(i >= 0 && i < n)
                    {
                        for(int j = v; j <= v + w; j++ )
                        {
                            if(j >= 0 && j < n)
                            {
                                for(int k = p; k <= p + d; k++)
                                {
                                    if(k >= 0 && k < n)
                                    {
                                        suma+=Tab[i][k][j];
                                    }
                                }
                            }
                        }
                    }
                }
            }

            if(l < (n / 2) && v < (n / 2) && p >= (n / 2))
            {
                for(int i = l; i <= l + h; i++)
                {
                    if(i >= 0 && i < n)
                    {
                        for(int j = v; j <= v + w; j++ )
                        {
                            if(j >= 0 && j < n)
                            {
                                for(int k = p - d; k <= p; k++)
                                {
                                    if(k >= 0 && k < n)
                                    {
                                        suma+=Tab[i][k][j];
                                    }
                                }
                            }
                        }
                    }
                }
            }

            if(l < (n / 2) && v >= (n / 2) && p >= (n / 2))
            {
                for(int i = l; i <= l + h; i++)
                {
                    if(i >= 0 && i < n)
                    {
                        for(int j = v - w; j <= v; j++ )
                        {
                            if(j >= 0 && j < n)
                            {
                                for(int k = p - d; k <= p; k++)
                                {
                                    if(k >= 0 && k < n)
                                    {
                                        suma+=Tab[i][k][j];
                                    }
                                }
                            }
                        }
                    }
                }
            }

            if(l >= (n / 2) && v < (n / 2) && p >= (n / 2))
            {
                for(int i = l - h; i <= l; i++)
                {
                    if(i >= 0 && i < n)
                    {
                        for(int j = v; j <= v + w; j++ )
                        {
                            if(j >= 0 && j < n)
                            {
                                for(int k = p - d; k <= p; k++)
                                {
                                    if(k >= 0 && k < n)
                                    {
                                        suma+=Tab[i][k][j];
                                    }
                                }
                            }
                        }
                    }
                }
            }

            if(l >= (n / 2) && v >= (n / 2) && p < (n / 2))
            {
                for(int i = l - h; i <= l; i++)
                {
                    if(i >= 0 && i < n)
                    {
                        for(int j = v - w; j <= v; j++ )
                        {
                            if(j >= 0 && j < n)
                            {
                                for(int k = p; k <= p + d; k++)
                                {
                                    if(k >= 0 && k < n)
                                    {
                                        suma+=Tab[i][k][j];
                                    }
                                }
                            }
                        }
                    }
                }
            }


            cout << suma << endl;
            suma = 0;
}
void FunkcjaO(int l, int v, int p, int r){
    int suma = 0;
            if(l < (n / 2) && v < (n / 2) && p < (n / 2))
            {
            for(int i = l; i <= l + r; i++){
                if(i >= 0 && i < n){
                for(int j = v; j <= v + r; j++){
                        if(j >= 0 && j < n){
                    for(int k = p; k <= p + r; k++){
                        if( k >= 0 && k < n){
                        if((l - i)*(l - i) + (v - j) * (v - j) + (p - k) * (p - k) <= r * r)suma += Tab[i][j][k];
                    }
                }
            }
            }}}}

            if(l < (n / 2) && v >= (n / 2) && p < (n / 2))
            {
                for(int i = l ; i <= l + r; i++)
                {
                    if(i >= 0 && i < n)
                    {
                        for(int j = v - r; j <= v; j++ )
                        {
                            if(j >= 0 && j < n)
                            {
                                for(int k = p; k <= p + r; k++)
                                {
                                    if(k >= 0 && k < n)
                                    {
                                    if((l - i)*(l - i) + (v - j) * (v - j) + (p - k) * (p - k) <= r * r)suma += Tab[i][j][k];
                                    }
                                }
                            }
                        }
                    }
                }
            }


            if(l >= (n / 2) && v < (n / 2) && p < (n / 2))
            {
                for(int i = l - r; i <= l ; i++)
                {
                    if(i >= 0 && i < n)
                    {
                        for(int j = v; j <= v + r; j++ )
                        {
                            if(j >= 0 && j < n)
                            {
                                for(int k = p; k <= p + r; k++)
                                {
                                    if(k >= 0 && k < n)
                                    {
                                    if((l - i)*(l - i) + (v - j) * (v - j) + (p - k) * (p - k) <= r * r)suma += Tab[i][j][k];
                                    }
                                }
                            }
                        }
                    }
                }
            }

            if(l >= (n / 2) && v >= (n / 2) && p >= (n / 2))
            {
                for(int i = l - r; i <= l ; i++)
                {
                    if(i >= 0 && i < n)
                    {
                        for(int j = v - r; j <= v ; j++ )
                        {
                            if(j >= 0 && j < n)
                            {
                                for(int k = p - r; k <= p ; k++)
                                {
                                    if(k >= 0 && k < n)
                                    {
                                    if((l - i)*(l - i) + (v - j) * (v - j) + (p - k) * (p - k) <= r * r)suma += Tab[i][j][k];
                                    }
                                }
                            }
                        }
                    }
                }
            }

            if(l < (n / 2) && v < (n / 2) && p >= (n / 2))
            {
                for(int i = l; i <= l + r; i++)
                {
                    if(i >= 0 && i < n)
                    {
                        for(int j = v; j <= v + r; j++ )
                        {
                            if(j >= 0 && j < n)
                            {
                                for(int k = p - r; k <= p; k++)
                                {
                                    if(k >= 0 && k < n)
                                    {
                                    if((l - i)*(l - i) + (v - j) * (v - j) + (p - k) * (p - k) <= r * r)suma += Tab[i][j][k];
                                    }
                                }
                            }
                        }
                    }
                }
            }

            if(l < (n / 2) && v >= (n / 2) && p >= (n / 2))
            {
                for(int i = l; i <= l + r; i++)
                {
                    if(i >= 0 && i < n)
                    {
                        for(int j = v - r; j <= v; j++ )
                        {
                            if(j >= 0 && j < n)
                            {
                                for(int k = p - r; k <= p; k++)
                                {
                                    if(k >= 0 && k < n)
                                    {
                                    if((l - i)*(l - i) + (v - j) * (v - j) + (p - k) * (p - k) <= r * r)suma += Tab[i][j][k];
                                    }
                                }
                            }
                        }
                    }
                }
            }

            if(l >= (n / 2) && v < (n / 2) && p >= (n / 2))
            {
                for(int i = l - r; i <= l; i++)
                {
                    if(i >= 0 && i < n)
                    {
                        for(int j = v; j <= v + r; j++ )
                        {
                            if(j >= 0 && j < n)
                            {
                                for(int k = p - r; k <= p; k++)
                                {
                                    if(k >= 0 && k < n)
                                    {
                                    if((l - i)*(l - i) + (v - j) * (v - j) + (k - p) * (k - p) <= r * r)suma += Tab[i][j][k];
                                    }
                                }
                            }
                        }
                    }
                }
            }

            if(l >= (n / 2) && v >= (n / 2) && p < (n / 2))
            {
                for(int i = l - r; i <= l; i++)
                {
                    if(i >= 0 && i < n)
                    {
                        for(int j = v - r; j <= v; j++ )
                        {
                            if(j >= 0 && j < n)
                            {
                                for(int k = p; k <= p + r; k++)
                                {
                                    if(k >= 0 && k < n)
                                    {
                                    if((l - i)*(l - i) + (v - j) * (v - j) + (p - k) * (p - k) <= r * r)suma += Tab[i][j][k];
                                    }
                                }
                            }
                        }
                    }
                }
            }
            cout << suma << endl;
            suma = 0;
}
void FunkcjaT(int l, int v, int p, int e){
             int suma = 0;
            if(l < (n / 2) && v < (n / 2) && p < (n / 2))
            {
            for(int i = l; i <= l + e; i++){
                if(i >= 0 && i < n){
                for(int j = v; j <= v + e; j++){
                        if(j >= 0 && j < n){
                    for(int k = p; k <= p + e; k++){
                        if( k >= 0 && k < n){
                        if(((i - l) + (j - v) + (k - p)) <= e )suma += Tab[i][j][k];
                    }
                }
            }
            }}}}

            if(l < (n / 2) && v >= (n / 2) && p < (n / 2))
            {
                for(int i = l ; i <= l + e; i++)
                {
                    if(i >= 0 && i < n)
                    {
                        for(int j = v - e; j <= v; j++ )
                        {
                            if(j >= 0 && j < n)
                            {
                                for(int k = p; k <= p + e; k++)
                                {
                                    if(k >= 0 && k < n)
                                    {
                                    if(((i - l) + (v - j) + (k - p)) <= e )suma += Tab[i][j][k];
                                    }
                                }
                            }
                        }
                    }
                }
            }


            if(l >= (n / 2) && v < (n / 2) && p < (n / 2))
            {
                for(int i = l - e; i <= l ; i++)
                {
                    if(i >= 0 && i < n)
                    {
                        for(int j = v; j <= v + e; j++ )
                        {
                            if(j >= 0 && j < n)
                            {
                                for(int k = p; k <= p + e; k++)
                                {
                                    if(k >= 0 && k < n)
                                    {
                                    if(((l - i) + (j -  v) + (k - p)) <= e )suma += Tab[i][j][k];
                                    }
                                }
                            }
                        }
                    }
                }
            }

            if(l >= (n / 2) && v >= (n / 2) && p >= (n / 2))
            {
                for(int i = l - e; i <= l ; i++)
                {
                    if(i >= 0 && i < n)
                    {
                        for(int j = v - e; j <= v ; j++ )
                        {
                            if(j >= 0 && j < n)
                            {
                                for(int k = p - e; k <= p ; k++)
                                {
                                    if(k >= 0 && k < n)
                                    {
                                    if(((l - i) + (v - j) + (p - k)) <= e )suma += Tab[i][j][k];
                                    }
                                }
                            }
                        }
                    }
                }
            }

            if(l < (n / 2) && v < (n / 2) && p >= (n / 2))
            {
                for(int i = l; i <= l + e; i++)
                {
                    if(i >= 0 && i < n)
                    {
                        for(int j = v; j <= v + e; j++ )
                        {
                            if(j >= 0 && j < n)
                            {
                                for(int k = p - e; k <= p; k++)
                                {
                                    if(k >= 0 && k < n)
                                    {
                                    if(((i - l) + (j - v) + (p - k)) <= e )suma += Tab[i][j][k];
                                    }
                                }
                            }
                        }
                    }
                }
            }

            if(l < (n / 2) && v >= (n / 2) && p >= (n / 2))
            {
                for(int i = l; i <= l + e; i++)
                {
                    if(i >= 0 && i < n)
                    {
                        for(int j = v - e; j <= v; j++ )
                        {
                            if(j >= 0 && j < n)
                            {
                                for(int k = p - e; k <= p; k++)
                                {
                                    if(k >= 0 && k < n)
                                    {
                                    if(((i - l) + (v - j) + (p - k)) <= e )suma += Tab[i][j][k];
                                    }
                                }
                            }
                        }
                    }
                }
            }

            if(l >= (n / 2) && v < (n / 2) && p >= (n / 2))
            {
                for(int i = l - e; i <= l; i++)
                {
                    if(i >= 0 && i < n)
                    {
                        for(int j = v; j <= v + e; j++ )
                        {
                            if(j >= 0 && j < n)
                            {
                                for(int k = p - e; k <= p; k++)
                                {
                                    if(k >= 0 && k < n)
                                    {
                                    if(((l - i) + (j - v) + (p - k)) <= e )suma += Tab[i][j][k];
                                    }
                                }
                            }
                        }
                    }
                }
            }

            if(l >= (n / 2) && v >= (n / 2) && p < (n / 2))
            {
                for(int i = l - e; i <= l; i++)
                {
                    if(i >= 0 && i < n)
                    {
                        for(int j = v - e; j <= v; j++ )
                        {
                            if(j >= 0 && j < n)
                            {
                                for(int k = p; k <= p + e; k++)
                                {
                                    if(k >= 0 && k < n)
                                    {
                                    if(((l - i) + (v - j) + (k - p)) <= e )suma += Tab[i][j][k];
                                    }
                                }
                            }
                        }
                    }
                }
            }
            cout << suma << endl;
            suma = 0;




}

long long int getDeterminantBareiss(int n) {
    long long dim = n ;
    long long pom = 0;

    if(dim <= 0) {
        return 0;
    }

    int sign = 1;

    for(int k = 0; k < dim - 1; k++) {

        if(Indeks[k][k] == 0) {
            int m = 0;
            for(m = k + 1; m < dim; m++) {
                if(Indeks[m][k] != 0) {
                    for(int i = 0; i < dim; i++){
                      pom = Indeks[m][i];
                      Indeks[m][i] = Indeks[k][i];
                      Indeks[k][i] = pom;
                      }
                      sign = -sign;
                    break;
                }
            }
            if(m == dim) {
                return 0;
            }
        }

        for (int i = k + 1; i < dim; i++) {
            for (int j = k + 1; j < dim; j++) {
                Indeks[i][j] = Indeks[k][k] * Indeks[i][j] - Indeks[i][k] * Indeks[k][j];
                if(k != 0) {
                    Indeks[i][j] /= Indeks[k-1][k-1];
                }
            }
        }
    }

    return sign * Indeks[dim-1][dim-1];
}


void FunkcjaD(char k, int i){
             if( k == 'l'){//poziom wiersz
                for(int j = 0 ; j < n; j++){
                    for(int k = 0; k < n ; k++){
                        Indeks[j][k] = Tab[i][j][k];
                    }
                }
             }
             if( k == 'v'){//pion
                for(int j = 0; j < n; j++){
                    for(int k = 0; k < n; k++){
                        Indeks[j][k] = Tab[j][k][i];
                    }

                }
             }
             if( k == 'p'){//panel
                for(int j = 0; j < n; j++){
                    for(int k = 0; k < n; k++){
                        Indeks[j][k] = Tab[j][i][k];
                    }
                }
             }
            // cout << endl;
         /*/    for(int j = 0; j < n; j++ ){
                for(int k = 0; k < n; k++){
                    cout << Indeks[j][k] << " ";
                }
                cout << endl;
             }
/*/
            cout << getDeterminantBareiss(n);
            cout << endl;
}


int main()
{
    int l = 0, v = 0, p = 0, h = 0, w = 0, d = 0;
    int r = 0, e = 0, s = 0;
    char k = ' ';
    cin >> n;

    for(int i = 0; i < n; i++) //width - poziom
    {
        for(int j = 0; j < n; j++) //height - pion
        {
            for(int k = 0; k < n; k++) //depth - panel
            {
                cin >> Tab[j][i][k];
            }
        }
    }
    //cout << Tab[1][2][3] <<endl;
    char c = ' ';
    while(wartownik > 0 && c != 'E')
    {
        cin >> c;

        if(c == 'C')
        {
            cin >> l >> v >> p >> h >> w >> d;
            FunkcjaC(l, v, p, h, w, d);
        }

        if(c == 'O')
        {
           cin >> l >> v >> p >> r;
           FunkcjaO(l, p, v, r);
        }

        if(c == 'T'){
            cin >> l >> v >> p >> e;
            FunkcjaT(l, p, v, e);
        }
        if(c == 'D'){
            cin >> k >> s;
            FunkcjaD(k, s);
        }

        if(c == 'E')
        {
            wartownik == 0;
        }
    }
    return 0;
}
