#ifndef MACIERZE_H
#define MACIERZE_H

#include <iostream>
#include <iomanip>
using namespace std;
#define tmp template <typename T1, int rozmiar>
#define M3 Macierz3<T1, rozmiar>
tmp
class Macierz3 {

    template <typename T2, int rozmiar2>
friend std::ostream& operator <<(std::ostream& stream,const Macierz3<T2,rozmiar2>& M);

    template <typename T2, int rozmiar2>
    friend std::istream& operator >>(std::istream& stream,Macierz3<T2,rozmiar2>& M);


private:
    T1** A;
public:
    static const int size = rozmiar;
    M3();
    M3(T1 val);
    M3(T1** tablica);

    ~Macierz3();

    void kopiuj(T1**);
    void dodaj(T1**);
    void odejmij(T1**);
    void pomnoz(T1**);
    void pomnoz(T1);

    void wypisz() const;

    void setij(T1 val, int i, int j);
    T1 getij(int i, int j) const;
    T1** getDane() const;

    T1** jednostkowa();
    void transponowana();
};
tmp
std::ostream& operator <<(std::ostream& stream,const Macierz3<T1,rozmiar>& M)
{
    for ( int i = 0; i < rozmiar; i++)
    {
        for (int j = 0; j < rozmiar; j++)
        {
            stream << M.getij(i,j) << " ";
        }
        stream << endl;
    }
    return stream;
}
tmp
std::istream& operator >>(std::istream& stream,Macierz3<T1,rozmiar>& M)
{
    for ( int i = 0; i < rozmiar; i++)
    {
        for (int j = 0; j < rozmiar; j++)
        {
            T1 val;
            stream>>val;
            M.setij(val,i,j);
        }

    }
    return stream;
}
tmp
M3::Macierz3() {
    A = new T1*[size];
    for (int i = 0; i < size; i++)
        A[i] = new T1[size] {};
}

tmp
M3::Macierz3(T1 val) {
    A = new T1*[size];
    for (int i = 0; i < size; i++) {
        A[i] = new T1[size];
        for (int j = 0; j < size; j++) {
            A[i][j] = val;
        }
    }
}

tmp
M3::Macierz3(T1** tablica) {
    A = new T1*[size];
    for (int i = 0; i < size; i++) {
        A[i] = new T1[size];
        for (int j = 0; j < size; j++) {
            A[i][j] = tablica[i][j];
        }
    }
}

tmp
M3::~Macierz3() {
    for (int i = 0; i < size; i++)
        delete[] A[i];
    delete[] A;
}

tmp
void M3::kopiuj(T1** tablica) {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            A[i][j] = tablica[i][j];
}

tmp
void M3::dodaj(T1** tablica) {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            A[i][j] += tablica[i][j];
}
tmp
void M3::odejmij(T1** tablica) {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            A[i][j] -= tablica[i][j];
}

tmp
void M3::pomnoz(T1 skalar) {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            A[i][j] *= skalar;
}

tmp
void M3::pomnoz(T1** B) {
    T1** wynik = new T1*[size];
    for (int i = 0; i < size; i++) {
        wynik[i] = new T1[size] {};
        for (int j = 0; j < size; j++) {
            for (int k = 0; k < size; k++) {
                wynik[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    kopiuj(wynik);

    for (int i = 0; i < size; i++) delete[] wynik[i];
    delete[] wynik;
}

tmp
void M3::wypisz() const {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << fixed << setprecision(2)<< A[i][j] << " ";
        }
        cout << endl;
    }
}

tmp
void M3::setij(T1 val, int i, int j) {
    if (i >= 0 && i < size && j >= 0 && j < size)
        A[i][j] = val;
}

tmp
T1 M3::getij(int i, int j) const {
    if (i >= 0 && i < size && j >= 0 && j < size)
        return A[i][j];
    return 0;
}

tmp
T1** M3::getDane() const {
    return A;
}

tmp
T1** M3::jednostkowa() {
    T1** arr = new T1*[size];
    for (int i = 0; i < size; i++) {
        arr[i] = new T1[size];
        for (int j = 0; j < size; j++) {
            arr[i][j] = (i == j) ? 1 : 0;
        }
    }
    return arr;
}

tmp
void M3::transponowana() {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            swap(A[i][j], A[j][i]);
        }
    }
}

#endif // MACIERZE_H
