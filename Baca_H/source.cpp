//Mateusz Paszynski
#include <iostream>
#include <cstdarg>
long long NWD(long long a, long long b) {
    if (a < 0) a = 0 - a;
    if (b < 0) b = 0 - b;
    if (a == 0 || b == 0) {
        if (a > b) return a;
        else return b;
    }
    while (a != b) {
        if (b > a) b = b - a;
        else a = a - b;
    }
    return a;
}

long long NWW(long long a, long long b) {
    if (a == 0 || b == 0) return 0;
    long long temp = a * b;
    if (temp < 0) temp = 0 - temp;
    long long dzielnik = NWD(a,b);
    if (dzielnik != 0) return (temp / dzielnik);
    return 0;
}

struct Ułamek {
    long long licznik;
    long long mianownik;
};

class POLYNOMIAL {
public:
    int stopien;
    int* wspolczynniki;
    static int overloaded;

    POLYNOMIAL();
    POLYNOMIAL(int stopien, ...);
    ~POLYNOMIAL();
    POLYNOMIAL(const POLYNOMIAL& other);
    POLYNOMIAL& operator=(const POLYNOMIAL& other);

    POLYNOMIAL operator+(const POLYNOMIAL& other) const;
    POLYNOMIAL operator-() const;
    POLYNOMIAL operator-(const POLYNOMIAL& other) const;
    POLYNOMIAL operator*(const POLYNOMIAL& other) const;
    POLYNOMIAL operator/(const POLYNOMIAL& other) const;
    POLYNOMIAL operator%(const POLYNOMIAL& other) const;

    POLYNOMIAL& operator+=(const POLYNOMIAL& second);
    POLYNOMIAL& operator-=(const POLYNOMIAL& second);
    POLYNOMIAL& operator*=(const POLYNOMIAL& second);
    POLYNOMIAL& operator/=(const POLYNOMIAL& second);
    POLYNOMIAL& operator%=(const POLYNOMIAL& second);

    POLYNOMIAL& operator++();
    POLYNOMIAL operator++(int);
    POLYNOMIAL& operator--();
    POLYNOMIAL operator--(int);

    POLYNOMIAL operator<<(int a) const;
    POLYNOMIAL operator>>(int a) const;
    POLYNOMIAL& operator<<=(int a);
    POLYNOMIAL& operator>>=(int a);

    void* operator new(size_t size);
    void operator delete(void* p);

private:
    void normalizuj();
    void skroc();
    void dziel_z_reszta(const POLYNOMIAL& other, POLYNOMIAL& iloraz, POLYNOMIAL& reszta) const;
};

int POLYNOMIAL::overloaded = 0;

void POLYNOMIAL::normalizuj() {
    int nowy_stopien = stopien;
    while (nowy_stopien > 0 && wspolczynniki[nowy_stopien] == 0) {
        nowy_stopien--;
    }
    if (nowy_stopien != stopien) {
        int* nowa_tablica = new int[nowy_stopien + 1];
        for (int i = 0; i <= nowy_stopien; ++i) {
            nowa_tablica[i] = wspolczynniki[i];
        }
        delete[] wspolczynniki;
        wspolczynniki = nowa_tablica;
        stopien = nowy_stopien;
    }
}

void POLYNOMIAL::skroc() {
    if (stopien == 0 && wspolczynniki[0] == 0) return;
    int dzielnik = 0;
    for (int i = 0; i <= stopien; ++i) {
        if (wspolczynniki[i] != 0) {
            int temp_wsp = wspolczynniki[i];
            if (temp_wsp < 0) temp_wsp = 0 - temp_wsp;
            if (dzielnik == 0) {
                dzielnik = temp_wsp;
            } else {
                dzielnik = NWD(dzielnik, temp_wsp);
            }
        }
    }
    if (dzielnik > 1) {
        for (int i = 0; i <= stopien; ++i) wspolczynniki[i] /= dzielnik;
    }
}

void POLYNOMIAL::dziel_z_reszta(const POLYNOMIAL& other, POLYNOMIAL& iloraz_out, POLYNOMIAL& reszta_out) const {
    iloraz_out = POLYNOMIAL();
    reszta_out = *this;

    if (reszta_out.stopien < other.stopien) {
        return;
    }

    int iloraz_stopien = reszta_out.stopien - other.stopien;
    delete[] iloraz_out.wspolczynniki;
    iloraz_out.stopien = iloraz_stopien;
    iloraz_out.wspolczynniki = new int[iloraz_stopien + 1];
    for (int i = 0; i <= iloraz_stopien; ++i) iloraz_out.wspolczynniki[i] = 0;

    std::vector<Ułamek> reszta_wsp_ul(reszta_out.stopien + 1);
    for (int i = 0; i <= reszta_out.stopien; ++i) {
        reszta_wsp_ul[i] = { (long long)reszta_out.wspolczynniki[i], 1 };
    }
    std::vector<Ułamek> iloraz_wsp_ul(iloraz_stopien + 1);

    long long dzielnik_wiodacy = other.wspolczynniki[other.stopien];

    for (int i = reszta_out.stopien; i >= other.stopien; --i) {
        Ułamek czynnik = { reszta_wsp_ul[i].licznik, reszta_wsp_ul[i].mianownik * dzielnik_wiodacy };
        iloraz_wsp_ul[i - other.stopien] = czynnik;
        for (int j = 0; j <= other.stopien; ++j) {
            long long l_do_odjecia = czynnik.licznik * other.wspolczynniki[j];
            long long m_do_odjecia = czynnik.mianownik;
            long long nowy_l = reszta_wsp_ul[i - j].licznik * m_do_odjecia - l_do_odjecia * reszta_wsp_ul[i - j].mianownik;
            long long nowy_m = reszta_wsp_ul[i - j].mianownik * m_do_odjecia;
            reszta_wsp_ul[i - j] = { nowy_l, nowy_m };
        }
    }

    long long iloraz_lcm = 1;
    for(int i = 0; i <= iloraz_stopien; ++i) iloraz_lcm = NWW(iloraz_lcm, iloraz_wsp_ul[i].mianownik);
    for(int i = 0; i <= iloraz_stopien; ++i) {
        if (iloraz_wsp_ul[i].mianownik != 0) {
            iloraz_out.wspolczynniki[i] = (iloraz_wsp_ul[i].licznik * iloraz_lcm) / iloraz_wsp_ul[i].mianownik;
        } else {
             iloraz_out.wspolczynniki[i] = 0;
        }
    }

    int max_reszta_stopien = (other.stopien > 0) ? other.stopien - 1 : 0;
    long long reszta_lcm = 1;
    for (int i = 0; i <= max_reszta_stopien; ++i) reszta_lcm = NWW(reszta_lcm, reszta_wsp_ul[i].mianownik);

    delete[] reszta_out.wspolczynniki;
    reszta_out.stopien = max_reszta_stopien;
    reszta_out.wspolczynniki = new int[max_reszta_stopien + 1];

    for (int i = 0; i <= max_reszta_stopien; ++i) {
        if (reszta_wsp_ul[i].mianownik != 0) {
            reszta_out.wspolczynniki[i] = (reszta_wsp_ul[i].licznik * reszta_lcm) / reszta_wsp_ul[i].mianownik;
        } else {
            reszta_out.wspolczynniki[i] = 0;
        }
    }

    iloraz_out.normalizuj(); iloraz_out.skroc();
    reszta_out.normalizuj(); reszta_out.skroc();
}

POLYNOMIAL POLYNOMIAL::operator/(const POLYNOMIAL& other) const {
    if ((other.stopien == 0 && other.wspolczynniki[0] == 0)) return POLYNOMIAL();
    POLYNOMIAL iloraz;
    POLYNOMIAL reszta;
    this->dziel_z_reszta(other, iloraz, reszta);
    return iloraz;
}

POLYNOMIAL POLYNOMIAL::operator%(const POLYNOMIAL& other) const {
    if ((other.stopien == 0 && other.wspolczynniki[0] == 0)) return *this;
    POLYNOMIAL iloraz;
    POLYNOMIAL reszta;
    this->dziel_z_reszta(other, iloraz, reszta);
    return reszta;
}

POLYNOMIAL::POLYNOMIAL() : stopien(0) {
    wspolczynniki = new int[1];
    wspolczynniki[0] = 0;
}
POLYNOMIAL::~POLYNOMIAL() { delete[] wspolczynniki; }
POLYNOMIAL::POLYNOMIAL(int st, ...) : stopien(st < 0 ? 0 : st) {
    wspolczynniki = new int[stopien + 1];
    if (st < 0) { wspolczynniki[0] = 0; return; }
    va_list args;
    va_start(args, st);
    for (int i = 0; i <= stopien; ++i) wspolczynniki[i] = va_arg(args, int);
    va_end(args);
    this->normalizuj(); this->skroc();
}
POLYNOMIAL::POLYNOMIAL(const POLYNOMIAL& other) : stopien(other.stopien) {
    wspolczynniki = new int[stopien + 1];
    for (int i = 0; i <= stopien; ++i) wspolczynniki[i] = other.wspolczynniki[i];
}
POLYNOMIAL& POLYNOMIAL::operator=(const POLYNOMIAL& other) {
    if (this != &other) {
        delete[] wspolczynniki; stopien = other.stopien;
        wspolczynniki = new int[stopien + 1];
        for (int i = 0; i <= stopien; ++i) wspolczynniki[i] = other.wspolczynniki[i];
    }
    return *this;
}

POLYNOMIAL POLYNOMIAL::operator-() const {
    POLYNOMIAL result(*this);
    for (int i = 0; i <= result.stopien; ++i) result.wspolczynniki[i] = 0 - result.wspolczynniki[i];
    return result;
}
POLYNOMIAL POLYNOMIAL::operator+(const POLYNOMIAL& other) const {
    int max_stopien;
    if (this->stopien > other.stopien) max_stopien = this->stopien; else max_stopien = other.stopien;

    POLYNOMIAL result;
    delete[] result.wspolczynniki; result.stopien = max_stopien;
    result.wspolczynniki = new int[max_stopien + 1];
    for (int i = 0; i <= max_stopien; ++i) result.wspolczynniki[i] = 0;

    for (int i = 0; i <= this->stopien; ++i) result.wspolczynniki[i] += this->wspolczynniki[i];
    for (int i = 0; i <= other.stopien; ++i) result.wspolczynniki[i] += other.wspolczynniki[i];

    result.normalizuj(); result.skroc();
    return result;
}
POLYNOMIAL POLYNOMIAL::operator-(const POLYNOMIAL& other) const { return *this + (-other); }
POLYNOMIAL POLYNOMIAL::operator*(const POLYNOMIAL& other) const {
    if ((this->stopien == 0 && this->wspolczynniki[0] == 0) || (other.stopien == 0 && other.wspolczynniki[0] == 0))
        return POLYNOMIAL();
    int res_stopien = this->stopien + other.stopien;
    POLYNOMIAL result;
    delete[] result.wspolczynniki; result.stopien = res_stopien;
    result.wspolczynniki = new int[res_stopien + 1];
    for (int i = 0; i <= res_stopien; ++i) result.wspolczynniki[i] = 0;

    for (int i = 0; i <= this->stopien; ++i) {
        for (int j = 0; j <= other.stopien; ++j) {
            result.wspolczynniki[i + j] += this->wspolczynniki[i] * other.wspolczynniki[j];
        }
    }
    result.normalizuj(); result.skroc();
    return result;
}

POLYNOMIAL& POLYNOMIAL::operator+=(const POLYNOMIAL& second) { *this = *this + second; return *this; }
POLYNOMIAL& POLYNOMIAL::operator-=(const POLYNOMIAL& second) { *this = *this - second; return *this; }
POLYNOMIAL& POLYNOMIAL::operator*=(const POLYNOMIAL& second) { *this = *this * second; return *this; }
POLYNOMIAL& POLYNOMIAL::operator/=(const POLYNOMIAL& second) { *this = *this / second; return *this; }
POLYNOMIAL& POLYNOMIAL::operator%=(const POLYNOMIAL& second) { *this = *this % second; return *this; }

POLYNOMIAL& POLYNOMIAL::operator++() { for (int i = 0; i <= stopien; ++i) this->wspolczynniki[i]++; this->normalizuj(); this->skroc(); return *this; }
POLYNOMIAL POLYNOMIAL::operator++(int) { POLYNOMIAL temp(*this); ++(*this); return temp; }
POLYNOMIAL& POLYNOMIAL::operator--() { for (int i = 0; i <= stopien; ++i) this->wspolczynniki[i]--; this->normalizuj(); this->skroc(); return *this; }
POLYNOMIAL POLYNOMIAL::operator--(int) { POLYNOMIAL temp(*this); --(*this); return temp; }

POLYNOMIAL POLYNOMIAL::operator>>(int a) const {
    if (a < 0) return POLYNOMIAL();
    POLYNOMIAL result;
    delete[] result.wspolczynniki; result.stopien = this->stopien + a;
    result.wspolczynniki = new int[result.stopien + 1];
    for(int i = 0; i <= result.stopien; ++i) result.wspolczynniki[i] = 0;
    for (int i = 0; i <= this->stopien; ++i) result.wspolczynniki[i + a] = this->wspolczynniki[i];
    return result;
}
POLYNOMIAL POLYNOMIAL::operator<<(int a) const {
    if (a < 0 || a > this->stopien) return POLYNOMIAL();
    POLYNOMIAL result;
    delete[] result.wspolczynniki; result.stopien = this->stopien - a;
    result.wspolczynniki = new int[result.stopien + 1];
    for (int i = 0; i <= result.stopien; ++i) result.wspolczynniki[i] = this->wspolczynniki[i + a];
    result.normalizuj();
    return result;
}
POLYNOMIAL& POLYNOMIAL::operator<<=(int a) { *this = *this << a; return *this; }
POLYNOMIAL& POLYNOMIAL::operator>>=(int a) { *this = *this >> a; return *this; }

void* POLYNOMIAL::operator new(size_t size) { overloaded++; return ::operator new(size); }
void POLYNOMIAL::operator delete(void* p) { overloaded--; ::operator delete(p); }

std::ostream& operator<<(std::ostream& stream, const POLYNOMIAL& wielomian) {
    stream << "( ";
    for (int i = 0; i <= wielomian.stopien; ++i) {
        stream << wielomian.wspolczynniki[i];
        if (i < wielomian.stopien) stream << ", ";
    }
    stream << " )";
    return stream;
}
std::istream& operator>>(std::istream& stream, POLYNOMIAL& wielomian) {
    int st;
    stream >> st;
    POLYNOMIAL temp;
    delete[] temp.wspolczynniki; temp.stopien = st;
    temp.wspolczynniki = new int[st + 1];
    for (int i = 0; i <= st; ++i) stream >> temp.wspolczynniki[i];
    temp.normalizuj(); temp.skroc();
    wielomian = temp;
    return stream;
}

bool operator==(const POLYNOMIAL& a, const POLYNOMIAL& b) {
    if (a.stopien != b.stopien) return false;
    for (int i = 0; i <= a.stopien; ++i) if (a.wspolczynniki[i] != b.wspolczynniki[i]) return false;
    return true;
}
bool operator!=(const POLYNOMIAL& a, const POLYNOMIAL& b) { return !(a == b); }
bool operator<(const POLYNOMIAL& a, const POLYNOMIAL& b) {
    if (a.stopien != b.stopien) return a.stopien < b.stopien;
    for (int i = a.stopien; i >= 0; --i) {
        if (a.wspolczynniki[i] != b.wspolczynniki[i]) return a.wspolczynniki[i] < b.wspolczynniki[i];
    }
    return false;
}
bool operator>(const POLYNOMIAL& a, const POLYNOMIAL& b) { return b < a; }
bool operator<=(const POLYNOMIAL& a, const POLYNOMIAL& b) { return !(a > b); }
bool operator>=(const POLYNOMIAL& a, const POLYNOMIAL& b) { return !(a < b); }
