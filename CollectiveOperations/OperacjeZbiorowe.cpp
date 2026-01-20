//Pawel Jandula
void Print(int n , char* c){
    if(n == 0){
        *c = 'e';
        *(c + 1) = 'm';
        *(c + 2) = 'p';
        *(c + 3) = 't';
        *(c + 4) = 'y';
        *(c + 5) = '\0';
        return;
    }
    else {
        static int zmienna = 31;
        if(zmienna < 0){
            zmienna = 31;
            *c = '\0';
            return;
        }
        if(n & (1 << zmienna) ){
            if(zmienna & (1 << 4))
                *c = '1';
            else
                *c = '0';
            if(zmienna & (1 << 3))
                *(c + 1) = '1';
            else
                *(c + 1) = '0';
            if(zmienna & (1 << 2))
                *(c + 2) = '1';
            else
                *(c + 2) = '0';
            if(zmienna & (1 << 1))
                *(c + 3) = '1';
            else
                *(c + 3) = '0';
            if(zmienna & (1 << 0))
                *(c + 4) = '1';
            else
                *(c + 4) = '0';

            *(c + 5) = ' ';
            zmienna--;
            Print(n, c + 6);
        }
        else {
            zmienna--;
            Print(n, c);
        }
    }
}


void Insert(char* c, int* a){
    if(*c == '\0') return;
    if(*c == ' '){
        Insert(c + 1, a);
    }
    else {
        int licznik = ((*(c) - '0') * 16)
                      + ((*(c + 1) - '0') * 8)
                      + ((*(c + 2) - '0') * 4)
                      + ((*(c + 3) - '0') * 2)
                      + (*(c + 4) - '0');
        *a = ((*a) | (1 << licznik));
        Insert(c + 5, a);
    }
}


void Emplace(char* c, int* a){
    *a = 0;
    Insert(c, a);
}


void Erase(char* c, int* a){
    if(*c == '\0') return;
    int licznik = 0;
    if(*c == ' '){
        Erase(c + 1, a);
    }
    else {
        licznik = (*(c) - '0') * 16 + (*(c + 1) - '0') * 8 + (*(c + 2) - '0') * 4 + (*(c + 3) - '0') * 2 + (*(c + 4) - '0');
        *a &= ~(1 << licznik);
        Erase(c + 5, a);
    }

}


bool Member(char* c, int a){
    if(*c == '\0') return 0;
    if(*c == ' '){
        Member(c + 1, a);
    }
    else {
        int licznik = ((*(c) - '0') * 16) + ((*(c + 1) - '0') * 8) + ((*(c + 2) - '0') * 4) + ((*(c + 3) - '0') * 2) + (*(c + 4) - '0');
        int zmienna = ((a) & (1 << licznik));
        if(zmienna){
            return 1;
        }
        else
            return 0;
    }


}


int Cardinality(int n){
    static int a = 31;
    static int moc = 0;
    if(a < 0){
        int b = moc;
        moc = 0;
        a = 31;
        return b;
    }
    else if(((n >> a) & 1) == 1){
        moc += 1;
        a--;
        return Cardinality(n);
    }
    a--;
    return Cardinality(n);


}


bool Disjoint(int x, int y){
    if((x & y) == 0)
    {
        return 1;
    }
    return 0;
}

bool Conjunctive(int x, int y){
    if((x & y) == 0)
    {
        return 0;
    }
    return 1;
}


bool Emptiness(int a){
    if(a == 0)
        return 1;

    return 0;

}

bool Nonempty(int a){
    if(a == 0)
        return 0;

    return 1;
}


bool Inclusion(int x, int y){
    if(( x | y ) == y){
        return 1;
    }
    else
        return 0;
}

bool Equality(int x, int y){
    if( x == y ){
        return 1;
    }
    else
        return 0;

}


void Union(int z1,int z2,int* z3){
    *z3 = (z1 | z2);
}
void Intersection(int z1, int z2, int* z3){
    *z3 = (z1 & z2);
}
void Symmetric(int z1, int z2, int* z3){
    *z3 = (z1 ^ z2);
}
void Difference(int z1, int z2, int* z3){
    *z3 = (z1 & ~z2);
}
void Complement(int z1, int* z2){
    *z2 = ~z1;
}

bool LessThan(int a, int b){
    if (Cardinality(a) < Cardinality(b))
    {
        return 1;
    }
    if (Cardinality(a) == Cardinality(b))
    {
        return (unsigned int)a < (unsigned int)b;
    }
    return 0;

}
bool GreatThan(int a, int b)
{
    if (Cardinality(a) > Cardinality(b))
    {
        return 1;
    }
    if (Cardinality(a) == Cardinality(b))
    {
        return (unsigned int)a > (unsigned int)b;
    }
    return 0;
}
bool LessEqual(int a, int b){
    return (!GreatThan(a, b));
}
bool GreatEqual(int a, int b){
    return(!LessThan(a, b));
}




