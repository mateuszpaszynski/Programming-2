//Pawel Jandula
#include<string>
#include<cstdarg>
using namespace std;
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
    if(rozmiar > 0){
        *(tab+rozmiar) += przeniesienie;
        przeniesienie = (*(tab + rozmiar)) /10;
        *(tab + rozmiar)%= 10;
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