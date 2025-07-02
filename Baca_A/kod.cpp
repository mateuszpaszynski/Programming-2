//Mateusz Paszynski
#include <iostream>
#include <string>
using namespace std;
string FormatujNapis(string tab,string s1,string s2,string s3) {
    string wynik="";
    string s;
    string m;
    int us;
    for ( int i = 0;i<tab.size();i++) {

        if ( tab[ i ]  == '{') {
            while (tab[i]!='}') {
                i++;
                s+=tab[i];
            }
            m = s;
            if ( m[0] == 'p') {
                us = m[2]-'0';
                for ( int i = 0;i<us;i++) {
                    wynik+=m[4];
                }
            }
            if ( m[0] == 'U') {
                us = m[2] - '0';
                string pomoc="";
                for ( int i = 0;i < wynik.size()-us;i++) {
                    pomoc += wynik[i];
                }
                wynik = pomoc;
            }
            if ( m[0] == 'u') {
                us = m[2]- '0';
                i = i + us;
            }
            if ( m[0] == 'w') {
                if ( m[2]== '1') {
                    wynik+=s1;
                }
                if (m[2]== '2') {
                    wynik+=s2;
                }
                if (m[2]== '3') {
                    wynik+=s3;
                }

            }
            if ( m[0] == 'W') {
                us = m[2]- '0';
                string o;
                int dlugosc = m[4]-'0';
                for ( int i = 0;i <dlugosc;i++) {
                    if ( us == 1) {
                        if ( i>=s1.size()) {
                            o+=' ';
                        }
                        else
                        o+=s1[i];
                    }
                    if ( us == 2) {
                        if ( i>=s2.size()) {
                            o+=' ';
                        }
                        else
                        o+=s2[i];
                    }
                    if ( us == 3) {
                        if ( i>=s3.size()) {
                            o+=' ';
                        }
                        else
                        o+=s3[i];
                    }

                }
                wynik+=o;
            }
            s="";
        }
        else wynik+=tab[i];

    }
    return wynik;
}
string NormalizujNapis(string tab){
int j = 0;
string wynik="";
    
   for ( int i = 0;i<tab.size()-1;i++) {
       wynik+=tab[i];
       if ( (tab[i]=='.' || tab[i]==',' ) && tab[i+1]!=' ') {
           wynik+=" ";
       }
   }
    wynik+=tab[tab.size()-1];
    string ans = "";
    bool flaga = 0;
    //cout<<wynik<<endl;
    for ( int i = wynik.size()-1;i>=0;i--) {
        ans+=wynik[i];
        flaga = 0;
        if ( wynik[i]=='.' || wynik[i]==',') {
            i--;
            while (wynik[i]==' ' && flaga == 0){
                i--;
                if (i<0) {
                    flaga = 1;
                }
            }
            i++;
        }

    }
    wynik="";
    for ( int i = ans.size()-1;i>=0;i--) {
        wynik+=ans[i];
    }
    ans="";
    ans+=wynik[0];
    for ( int i = 1 ;i<wynik.size();i++) {
        if (wynik[i]==' ' && wynik[i-1]==' ') {

        }
        else ans+=wynik[i];
    }
    //cout<<ans<<endl;
    int m = 0;
    int koniec = 0;
    if ( ans [ 0 ] == ' ') {
        m = 1;
    }
    if ( ans[ans.size()-1]==' ') {
        koniec=1;
    }
    wynik="";
    for ( m ; m<ans.size()-koniec;m++) {
        wynik+=ans[m];
    }
    return wynik;
}
string UsunSlowo(string tab1, int k) {
    string wynik="";
    if ( k == 1) {
        wynik = " ";
    }
    string tab = tab1+' ';
    string s="";
    int cunt = 0;
    bool flaga = 1;

    for ( int i = 0;i<tab.size();i++) {
        flaga = 1;
        if (tab[i] != ' ') {
            cunt++;
            s+=tab[i];
            while (tab[i]!=' ' && flaga == 1) {
                i++;
                if ( i>=tab.size()-1) {
                    flaga=0;
                }
                s+=tab[i];
            }
            if ( cunt != k )
            wynik+=s;
            s="";
        }
        else wynik+=tab[i];
    }
    string wynik1 = wynik;
    wynik="";
    for ( int i = 0;i<wynik1.size()-1;i++) {
        wynik+=wynik1[i];
    }
    return wynik;
}
string NajwiekszeSlowo(string tab) {
    string s;
    string najwiekszy;
    for ( int i = 0 ; i < tab.size();i++) {
        if ( tab[ i ]  == ' ') {
            if ( najwiekszy<s){najwiekszy = s;}
            s="";
        }
        else s+=tab[i];
    }
    if ( najwiekszy<s)
    {return s;}
return najwiekszy;
}
