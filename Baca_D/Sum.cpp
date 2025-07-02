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
