#include "macierze.h"
#include "wektory.h"
#include <algorithm>
std::ostream& operator<<(std::ostream & wyjscie,const Wektor3<int,3>& wektor)
{
    wyjscie<<"[x="<<wektor.dane[0]<<", y="<<wektor.dane[1]<<", z="<<wektor.dane[2]<<"]"<<endl;
    return wyjscie;

}
Wektor3<int,3> operator*(const Wektor3<int,3>& wektor1,const Wektor3<int,3>&wektor2)
{
        Wektor3<int,3> wektor_wynik;
        wektor_wynik.dane[0] = wektor1.dane[1]*wektor2.dane[2] -wektor1.dane[2]*wektor2.dane[1] ;
        wektor_wynik.dane[1] = wektor1.dane[2]*wektor2.dane[0] - wektor1.dane[0]*wektor2.dane[2];
        wektor_wynik.dane[2] = wektor1.dane[0]*wektor2.dane[1] - wektor1.dane[1]*wektor2.dane[0];
        return wektor_wynik;
}
std::istream& operator>>(std::istream & wejscie,const Wektor3<int,3>& wektor)
{
   // cout<<"Podaj x : ";
    wejscie>>wektor.dane[0]
    ;
   // cout<<"Podaj y : ";

    wejscie>>wektor.dane[1];
    //cout<<"Podaj z : ";
    wejscie>>wektor.dane[2];
    return wejscie;
}
template <typename T1, int rozmiar>
bool Wektor3<T1, rozmiar>::operator<(const Wektor3<T1,rozmiar>& wektor1)
{
    return this->dlugosc()<wektor1.dlugosc();
}
tmp
Wektor3<T1,rozmiar>& Wektor3<T1,rozmiar>::operator++()
{
    for ( int i = 0;i <rozmiar ;i++)
    {
        this->dane[i]+=1;
    }
    return *this;
}
tmp
Wektor3<T1,rozmiar> Wektor3<T1,rozmiar> ::operator++(int)
{
    Wektor3 przed_inkr = *this;
    for ( int i = 0;i < rozmiar;i++)
    {
        this->dane[i]+=1;
    }
    return przed_inkr;
}
int main()
{


   Wektor3<int,3> wektory(3,4,5);
    //cin>>wektory;
    cout<<wektory++;
   // cout<<wektory;

   //sort(wektory[0],wektory[2]);


    return 0;
}
