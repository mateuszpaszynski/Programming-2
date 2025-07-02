#ifndef WEKTOR3_H
#define WEKTOR3_H

#include <iostream>
#include <cmath>
#include <iomanip>

#define tmp template <typename T1, int rozmiar>
#define W3 Wektor3<T1, rozmiar>

tmp
class Wektor3 {
private:
    T1* dane;

public:
    W3();                                 // konstruktor domyślny
    W3(T1 x);                             // konstruktor z jedną wartością
    W3(T1 x, T1 y, T1 z);                 // konstruktor z 3 wartościami
    W3(T1* daneIn);                       // konstruktor z tablicy
    ~W3();                                // destruktor
    T1 getX() const;
    T1 getY() const;
    T1 getZ() const;
    friend std::ostream& operator<<(std::ostream & wyjscie,const Wektor3& wektor);
    friend Wektor3 operator*(const Wektor3&,const Wektor3&);
    friend std::istream&operator>>(std::istream& wejscie, const Wektor3& wektor);
    bool operator<(const Wektor3<T1,rozmiar>& wektor2);
    Wektor3 operator++(int);
    Wektor3& operator++();

    void kopiuj(T1* inny);
    void dodaj(T1* inny);
    void odejmij(T1* inny);
    void pomnoz(T1 skalar);
    void wypisz() const;

    void setX(T1 x);
    void setY(T1 y);
    void setZ(T1 z);

    T1* getDane() const;

    void normalizuj();
    T1 dlugosc() const;
    T1 skalarny(T1* inny) const;
    W3 wektorowy(T1* inny) const;
};

// === IMPLEMENTACJE ===

tmp
W3::Wektor(Wektor3<T1,rozmiar>other )
{
    for ( int i = 0;i<rozmiar;i++)
    {
        this->dane[i] = other.dane[i];
    }
}
tmp
W3::Wektor3() {
    dane = new T1[rozmiar]{};
    for ( int i = 0;i<rozmiar;i++)dane[i] = 0;
}

tmp
W3::Wektor3(T1 x) {
    dane = new T1[rozmiar]{x, 0, 0};
}

tmp
W3::Wektor3(T1 x, T1 y, T1 z) {
    dane = new T1[rozmiar]{x, y, z};
}

tmp
W3::Wektor3(T1* daneIn) {
    dane = new T1[rozmiar];
    for (int i = 0; i < rozmiar; i++) {
        dane[i] = daneIn[i];
    }
}

tmp
W3::~Wektor3() {
    delete[] dane;
}

tmp
void W3::kopiuj(T1* inny) {
    for (int i = 0; i < rozmiar; i++) {
        dane[i] = inny[i];
    }
}

tmp
void W3::dodaj(T1* inny) {
    for (int i = 0; i < rozmiar; i++) {
        dane[i] += inny[i];
    }
}

tmp
void W3::odejmij(T1* inny) {
    for (int i = 0; i < rozmiar; i++) {
        dane[i] -= inny[i];
    }
}


// void W3::pomnoz(int skalar) {
//     for (int i = 0; i < rozmiar; i++) {
//         dane[i] *= skalar;
//     }
// }

tmp
void W3::wypisz() const {
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "(";
    for (int i = 0; i < rozmiar; ++i) {
        std::cout << dane[i];
        if (i < rozmiar - 1) std::cout << ", ";
    }
    std::cout << ")" << std::endl;
}

tmp
void W3::setX(T1 x) { dane[0] = x; }
tmp
void W3::setY(T1 y) { dane[1] = y; }
tmp
void W3::setZ(T1 z) { dane[2] = z; }

tmp
T1 W3::getX() const { return dane[0]; }
tmp
T1 W3::getY() const { return dane[1]; }
tmp
T1 W3::getZ() const { return dane[2]; }

tmp
T1* W3::getDane() const {
    return dane;
}

tmp
void W3::normalizuj() {
    T1 len = dlugosc();
    if (len != 0) {
        for (int i = 0; i < rozmiar; i++) {
            dane[i] /= len;
        }
    }
}

tmp
T1 W3::dlugosc() const {
    T1 suma = 0;
    for (int i = 0; i < rozmiar; i++) {
        suma += dane[i] * dane[i];
    }
    return std::sqrt(suma);
}

tmp
T1 W3::skalarny(T1* inny) const {
    T1 suma = 0;
    for (int i = 0; i < rozmiar; i++) {
        suma += dane[i] * inny[i];
    }
    return suma;
}

tmp
W3 W3::wektorowy(T1* inny) const {
    T1 x = dane[1] * inny[2] - dane[2] * inny[1];
    T1 y = dane[2] * inny[0] - dane[0] * inny[2];
    T1 z = dane[0] * inny[1] - dane[1] * inny[0];
    return W3(x, y, z);
}

#endif // WEKTOR3_H
