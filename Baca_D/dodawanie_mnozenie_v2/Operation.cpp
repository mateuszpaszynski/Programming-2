//Pawel Jandula
#include<string>
#include<cstdarg>
using namespace std;
void Operate( string* destination, va_list& source, int licznik, int warunek) {
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
	va_end(lista);
return funkcja ( liczba, napis );
}
void Operation ( string *wynik, string (*funkcja) (int, const string*), int liczba, const string* napis ) {
	*wynik = funkcja ( liczba, napis );
}
void Operation ( string *wynik, string (*funkcja) (int, const string*), int liczba, ... ) {
	va_list lista;
	va_start ( lista, liczba );
	string *napis = new string[liczba];
	Operate ( napis, lista, 0, liczba );
	va_end(lista);
	*wynik = funkcja ( liczba, napis );
}
void Operation ( string& wynik, void (*funkcja) (string*, int, const string*), int liczba, const string* napis ) {
	funkcja(&wynik, liczba, napis );
}
void Operation ( string &wynik, string (*funkcja) (string*, int, const string*), int liczba, ... ) {
    if(liczba <= 0){
        wynik = "0";
        return;
    }
	va_list lista;
	va_start ( lista, liczba );
	string *napis = new string[liczba];
	Operate ( napis, lista, 0, liczba );
	wynik = funkcja (&wynik, liczba, napis );
	va_end(lista);
}
