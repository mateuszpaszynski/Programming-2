//Mateusz Paszynski
#include <iostream>
using namespace std;
void Insert (char* tab, int* wsk) {
    int temp = 0;
    if (*tab == '\0') {
        return;
    }
    if ( *tab == ' ') {
        tab++;
        Insert (tab, wsk);
    }

    else {
        if (*tab=='1') {
            temp+=1;
        }
        temp=temp<<1;
        tab++;
        if (*tab=='1') {
            temp+=1;
        }
        temp=temp<<1;
        tab++;
        if (*tab=='1') {
            temp+=1;
        }
        temp=temp<<1;
        tab++;
        if (*tab=='1') {
            temp+=1;
        }
        temp=temp<<1;
        tab++;
        if (*tab=='1') {
            temp+=1;
        }
        tab++;
        if ( *tab == ' ')tab++;
        int help = *wsk>>temp;
        if ( help%2 == 0) {
            temp = 1<<temp;
            *wsk+=temp;
        }
        Insert(tab, wsk);
    }
}
void Emplace (char* tab, int* wsk ) {
    *wsk = 0;
    Insert(tab,wsk);
}
void Erase(char* tab, int* wsk) {
    int temp = 0;
    if (* tab == '\0') {
        return;
    }
    if ( *tab == ' ') {
        tab++;
        Erase (tab, wsk);
    }
    else {
        if (*tab=='1') {
            temp+=1;
        }
        temp=temp<<1;
        tab++;
        if (*tab=='1') {
            temp+=1;
        }
        temp=temp<<1;
        tab++;
        if (*tab=='1') {
            temp+=1;
        }
        temp=temp<<1;
        tab++;
        if (*tab=='1') {
            temp+=1;
        }
        temp=temp<<1;
        tab++;
        if (*tab=='1') {
            temp+=1;
        }
        tab++;
        if ( *tab == ' ')tab++;
        int help = *wsk>>temp;

        if ( help%2 == 1 || help%2 == -1) {
            temp = 1<<temp;
            *wsk-=temp;
        }
        Erase(tab, wsk);
    }
}
bool Emptiness(int x) {
    if ( x == 0 ) return true;
    else return false;
}
bool Nonempty ( int x) {
    if ( x != 0 ) return true;
    else return false;
}
void Print(int zbior,char * tab) {
    if ( zbior == 0 ) {
        *tab = 'e';
        tab++;
        *tab = 'm';
        tab++;
        *tab = 'p';
        tab++;
        *tab = 't';
        tab++;
        *tab = 'y';
        tab++;
        *tab = '\0';
        return;
    }
    if ( zbior < 0 ) {
        *tab = '1';
        tab++;
        *tab = '1';
        tab++;
        *tab = '1';
        tab++;
        *tab = '1';
        tab++;
        *tab = '1';
        tab++;
        *tab = ' ';
        tab++;
    }//31
    zbior = zbior<<1;
    if ( zbior < 0 ) {
        *tab = '1';
        tab++;
        *tab = '1';
        tab++;
        *tab = '1';
        tab++;
        *tab = '1';
        tab++;
        *tab = '0';
        tab++;
        *tab = ' ';
        tab++;
    }//30
    zbior = zbior<<1;
    if ( zbior < 0 ) {
        *tab = '1';
        tab++;
        *tab = '1';
        tab++;
        *tab = '1';
        tab++;
        *tab = '0';
        tab++;
        *tab = '1';
        tab++;
        *tab = ' ';
        tab++;
    }//29
    zbior = zbior<<1;
    if ( zbior < 0 ) {
        *tab = '1';
        tab++;
        *tab = '1';
        tab++;
        *tab = '1';
        tab++;
        *tab = '0';
        tab++;
        *tab = '0';
        tab++;
        *tab = ' ';
        tab++;
    }//28
    zbior = zbior<<1;
    if ( zbior < 0 ) {
        *tab = '1';
        tab++;
        *tab = '1';
        tab++;
        *tab = '0';
        tab++;
        *tab = '1';
        tab++;
        *tab = '1';
        tab++;
        *tab = ' ';
        tab++;
    }//27
    zbior = zbior<<1;
    if ( zbior < 0 ) {
        *tab = '1';
        tab++;
        *tab = '1';
        tab++;
        *tab = '0';
        tab++;
        *tab = '1';
        tab++;
        *tab = '0';
        tab++;
        *tab = ' ';
        tab++;
    }//26
    zbior = zbior<<1;
    if ( zbior < 0 ) {
        *tab = '1';
        tab++;
        *tab = '1';
        tab++;
        *tab = '0';
        tab++;
        *tab = '0';
        tab++;
        *tab = '1';
        tab++;
        *tab = ' ';
        tab++;
    }//25
    zbior = zbior<<1;
    if ( zbior < 0 ) {
        *tab = '1';
        tab++;
        *tab = '1';
        tab++;
        *tab = '0';
        tab++;
        *tab = '0';
        tab++;
        *tab = '0';
        tab++;
        *tab = ' ';
        tab++;
    }//24
    zbior = zbior<<1;
    if (zbior < 0) {
        *tab = '1'; tab++;
        *tab = '0'; tab++;
        *tab = '1'; tab++;
        *tab = '1'; tab++;
        *tab = '1'; tab++;
        *tab = ' '; tab++;
    } // 23
    zbior = zbior << 1;
    if (zbior < 0) {
        *tab = '1'; tab++;
        *tab = '0'; tab++;
        *tab = '1'; tab++;
        *tab = '1'; tab++;
        *tab = '0'; tab++;
        *tab = ' '; tab++;
    } // 22
    zbior = zbior << 1;
    if (zbior < 0) {
        *tab = '1'; tab++;
        *tab = '0'; tab++;
        *tab = '1'; tab++;
        *tab = '0'; tab++;
        *tab = '1'; tab++;
        *tab = ' '; tab++;
    } // 21
    zbior = zbior << 1;
    if (zbior < 0) {
        *tab = '1'; tab++;
        *tab = '0'; tab++;
        *tab = '1'; tab++;
        *tab = '0'; tab++;
        *tab = '0'; tab++;
        *tab = ' '; tab++;
    } // 20
    zbior = zbior << 1;
    if (zbior < 0) {
        *tab = '1'; tab++;
        *tab = '0'; tab++;
        *tab = '0'; tab++;
        *tab = '1'; tab++;
        *tab = '1'; tab++;
        *tab = ' '; tab++;
    } // 19
    zbior = zbior << 1;
    if (zbior < 0) {
        *tab = '1'; tab++;
        *tab = '0'; tab++;
        *tab = '0'; tab++;
        *tab = '1'; tab++;
        *tab = '0'; tab++;
        *tab = ' '; tab++;
    } // 18
    zbior = zbior << 1;
    if (zbior < 0) {
        *tab = '1'; tab++;
        *tab = '0'; tab++;
        *tab = '0'; tab++;
        *tab = '0'; tab++;
        *tab = '1'; tab++;
        *tab = ' '; tab++;
    } // 17
    zbior = zbior << 1;
    if (zbior < 0) {
        *tab = '1'; tab++;
        *tab = '0'; tab++;
        *tab = '0'; tab++;
        *tab = '0'; tab++;
        *tab = '0'; tab++;
        *tab = ' '; tab++;
    } // 16
    zbior = zbior << 1;
    if (zbior < 0) {
        *tab = '0'; tab++;
        *tab = '1'; tab++;
        *tab = '1'; tab++;
        *tab = '1'; tab++;
        *tab = '1'; tab++;
        *tab = ' '; tab++;
    } // 15
    zbior = zbior << 1;
    if (zbior < 0) {
        *tab = '0'; tab++;
        *tab = '1'; tab++;
        *tab = '1'; tab++;
        *tab = '1'; tab++;
        *tab = '0'; tab++;
        *tab = ' '; tab++;
    } // 14
    zbior = zbior << 1;
    if (zbior < 0) {
        *tab = '0'; tab++;
        *tab = '1'; tab++;
        *tab = '1'; tab++;
        *tab = '0'; tab++;
        *tab = '1'; tab++;
        *tab = ' '; tab++;
    } // 13
    zbior = zbior << 1;
    if (zbior < 0) {
        *tab = '0'; tab++;
        *tab = '1'; tab++;
        *tab = '1'; tab++;
        *tab = '0'; tab++;
        *tab = '0'; tab++;
        *tab = ' '; tab++;
    } // 12
    zbior = zbior << 1;
    if (zbior < 0) {
        *tab = '0'; tab++;
        *tab = '1'; tab++;
        *tab = '0'; tab++;
        *tab = '1'; tab++;
        *tab = '1'; tab++;
        *tab = ' '; tab++;
    } // 11
    zbior = zbior << 1;
    if (zbior < 0) {
        *tab = '0'; tab++;
        *tab = '1'; tab++;
        *tab = '0'; tab++;
        *tab = '1'; tab++;
        *tab = '0'; tab++;
        *tab = ' '; tab++;
    } // 10
    zbior = zbior << 1;
    if (zbior < 0) {
        *tab = '0'; tab++;
        *tab = '1'; tab++;
        *tab = '0'; tab++;
        *tab = '0'; tab++;
        *tab = '1'; tab++;
        *tab = ' '; tab++;
    } // 9
    zbior = zbior << 1;
    if (zbior < 0) {
        *tab = '0'; tab++;
        *tab = '1'; tab++;
        *tab = '0'; tab++;
        *tab = '0'; tab++;
        *tab = '0'; tab++;
        *tab = ' '; tab++;
    } // 8
    zbior = zbior << 1;
    if (zbior < 0) {
        *tab = '0'; tab++;
        *tab = '0'; tab++;
        *tab = '1'; tab++;
        *tab = '1'; tab++;
        *tab = '1'; tab++;
        *tab = ' '; tab++;
    } // 7
    zbior = zbior << 1;
    if (zbior < 0) {
        *tab = '0'; tab++;
        *tab = '0'; tab++;
        *tab = '1'; tab++;
        *tab = '1'; tab++;
        *tab = '0'; tab++;
        *tab = ' '; tab++;
    } // 6
    zbior = zbior << 1;
    if (zbior < 0) {
        *tab = '0'; tab++;
        *tab = '0'; tab++;
        *tab = '1'; tab++;
        *tab = '0'; tab++;
        *tab = '1'; tab++;
        *tab = ' '; tab++;
    } // 5
    zbior = zbior << 1;
    if (zbior < 0) {
        *tab = '0'; tab++;
        *tab = '0'; tab++;
        *tab = '1'; tab++;
        *tab = '0'; tab++;
        *tab = '0'; tab++;
        *tab = ' '; tab++;
    } // 4
    zbior = zbior << 1;
    if (zbior < 0) {
        *tab = '0'; tab++;
        *tab = '0'; tab++;
        *tab = '0'; tab++;
        *tab = '1'; tab++;
        *tab = '1'; tab++;
        *tab = ' '; tab++;
    } // 3
    zbior = zbior << 1;
    if (zbior < 0) {
        *tab = '0'; tab++;
        *tab = '0'; tab++;
        *tab = '0'; tab++;
        *tab = '1'; tab++;
        *tab = '0'; tab++;
        *tab = ' '; tab++;
    } // 2
    zbior = zbior << 1;
    if (zbior < 0) {
        *tab = '0'; tab++;
        *tab = '0'; tab++;
        *tab = '0'; tab++;
        *tab = '0'; tab++;
        *tab = '1'; tab++;
        *tab = ' '; tab++;
    } // 1
    zbior = zbior << 1;
    if (zbior < 0) {
        *tab = '0'; tab++;
        *tab = '0'; tab++;
        *tab = '0'; tab++;
        *tab = '0'; tab++;
        *tab = '0'; tab++;
        *tab = ' '; tab++;
    } // 0
    tab--;
    *tab = '\0';
}
bool Member ( char * tab,int zbior) {
    if ( *tab == ' ') {
        return Member(++tab,zbior);
    }
    int temp = 0;
    if (*tab=='1') {
        temp+=1;
    }
    temp=temp<<1;
    tab++;
    if (*tab=='1') {
        temp+=1;
    }
    temp=temp<<1;
    tab++;
    if (*tab=='1') {
        temp+=1;
    }
    temp=temp<<1;
    tab++;
    if (*tab=='1') {
        temp+=1;
    }
    temp=temp<<1;
    tab++;
    if (*tab=='1') {
        temp+=1;
    }
    tab++;
    int help = zbior>>temp;
    if ( help%2 ==1 || help%2 == -1) {
        return true;
    }
    else return false;
}
int Cardinality( int zbior) {
    if ( zbior == 0 )return 0;
    if ( zbior < 0) {
        return Cardinality(zbior<<1) + 1;
    }
    else return Cardinality(zbior<<1) ;
}
void Complement(int zbior, int * wsk) {
    *wsk = (~zbior);
}
int wiekszyB(int a, int b, int c ) {
    if ( c == 0) {
        return 0;
    }
    if (a < 0 && b >=0) {
        return -1;
    }
    if ( b < 0 && a >= 0) {
        return 1;
    }
    a = a << 1;
    b = b << 1;
    return wiekszyB( a, b, c-1 );
}
bool LessEqual( int a,int b) {
    int mocA=Cardinality(a),mocB=Cardinality(b);
    if ( mocA < mocB ) {
        return true;
    }
    if ( mocA == mocB) {
            if (wiekszyB(a,b,31) >= 0) {
                return true;
            }
    }
    return false;
}
bool LessThan(int a,int b) {
    int mocA=Cardinality(a),mocB=Cardinality(b);
    if ( mocA < mocB ) {
        return true;
    }
    if ( mocA == mocB) {
            if ( wiekszyB(a,b,31) > 0) {
                return true;
            }
    }
    return false;
}
bool GreatThan(int a, int b) {
    return 1 - LessEqual(a,b);
}
bool GreatEqual(int a, int b) {
    return 1 - LessThan(a,b);
}
void Difference ( int a,int b,int* wsk) {
   *wsk = a & (~b);
}
bool Equality(int a,int b) {
    if (a == b)return true;
    return false;
}
bool Inclusion(int a,int b) {
    if ( a == (b & a)) return true;
    return false;
}
void Union(int a,int b,int * wsk) {
    *wsk = (a | b);
}
void Intersection(int a,int b,int * wsk) {
    * wsk = (a & b);
}
bool Conjunctive(int a,int b) {
    if (( a & b )!=0)return true;
    else return false;
}
bool Disjoint(int a, int b) {
    return 1 - Conjunctive(a,b);
}
void Symmetric( int a, int b, int* wsk) {
    *wsk = (a ^ b);
}
int main(){
    int a = 0;
    int b = 0;
    int* wsk = &a;
    int* ptr = &b;
    Emplace("11111",wsk);
    Emplace("01111",ptr);
    cout<<a<<" "<<b<<endl;
    cout<<LessThan(a,b)<<endl;
    cout<<GreatThan(a,b)<<endl;
    cout<<GreatEqual(a,b)<<endl;
    cout<<LessEqual(a,b)<<endl;
}