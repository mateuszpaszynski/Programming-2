#ifndef DZIALA_H
#define DZIALA_H

bool operator ==(const POLYNOMIAL& first, const POLYNOMIAL& second){
    if ( first.stopien != second.stopien)
    {
        return false;
    }
    wsp * f  = first.head;
    wsp * s  = second.head;
    for ( int i = 0;i<=first.stopien;i++)
    {
        if ( f->wspolczynnik != s->wspolczynnik)
            return false;
        f = f->next;
        s = s->next;
    }
    return true;
}
bool operator<(const POLYNOMIAL& first, const POLYNOMIAL& second)
{
    if ( first.stopien != second.stopien)
    {
        return first.stopien < second.stopien;
    }

    wsp * f = first.tail;
    wsp * s = second.tail;
    for ( int i = 0;i <=first.stopien;i++)
    {
        if ( f->wspolczynnik != s->wspolczynnik)
        {
            return f->wspolczynnik < s->wspolczynnik;
        }
        f = f->prev;
        s = s->prev;
    }
    return false;
}
bool operator<=(const POLYNOMIAL& first, const POLYNOMIAL& second)
{

    if ( first.stopien != second.stopien)
    {
        return first.stopien < second.stopien;
    }
    wsp * f = first.tail;
    wsp * s = second.tail;
    for ( int i = 0;i <=first.stopien;i++)
    {

        if ( f->wspolczynnik != s->wspolczynnik)
        {
            return f->wspolczynnik < s->wspolczynnik;
        }
        f = f->prev;
        s = s->prev;
    }
    return true;
}
bool  operator >(const POLYNOMIAL& first, const POLYNOMIAL& second)
{
    return !(first <= second);
}
bool  operator >=(const POLYNOMIAL& first, const POLYNOMIAL& second)
{
    return !(first<second);
}
bool  operator != (const POLYNOMIAL & first, const POLYNOMIAL & second)
{
    return !(first==second);
}
POLYNOMIAL& POLYNOMIAL ::operator++() {

    wsp* current = this->head;
    for ( int i = 0; i<=stopien;i++){
        current->wspolczynnik++;
        current = current->next;
    }
    normalizuj(*this);
    skroc(*this);
    return *this;
}
POLYNOMIAL POLYNOMIAL ::operator++(int) {

    POLYNOMIAL temp = *this;
    ++(*this);
    normalizuj(*this);
    skroc(*this);
    return temp;
}
POLYNOMIAL& POLYNOMIAL ::operator--() {

    wsp* current = this->head;
    for ( int i = 0; i<=stopien;i++){
        current->wspolczynnik--;
        current = current->next;
    }
    normalizuj(*this);
    skroc(*this);
    return *this;
}
POLYNOMIAL POLYNOMIAL :: operator--(int) {

    POLYNOMIAL temp = *this;
    --(*this);
    normalizuj(*this);
    skroc(*this);
    return temp;

}

POLYNOMIAL POLYNOMIAL ::operator >>( int a)
{
    if ( a < 0)
    {
        unsigned int x = 0;
        POLYNOMIAL result(x);
        return result;
    }
    unsigned int rozmiar = a ;
    POLYNOMIAL  result(rozmiar + this->stopien );
    wsp * curr= result.head;
    wsp * f = this->head;
    for (unsigned int i = 0; i <= rozmiar+this->stopien;i++)
    {
        if ( i  >= rozmiar)
        {
            curr->wspolczynnik = f->wspolczynnik;
            f = f->next;
        }
        else
        {
            curr->wspolczynnik = 0;
        }
        curr = curr->next;
    }
    normalizuj(result);
    return result;
}
POLYNOMIAL POLYNOMIAL ::operator <<(int a)
{
    if ( a < 0)
    {
        unsigned int x = 0;
        POLYNOMIAL result(x);
        return result;
    }
    unsigned int rozmiar = (this->stopien > a ) ? this->stopien - a : 0;
    POLYNOMIAL result(rozmiar );

    wsp * curr= result.head;
    wsp * f = this->head;
    for ( int i = 0; i <= this->stopien ;i++)
    {
        if ( i >= a)
        {
            curr->wspolczynnik = f->wspolczynnik;
            curr = curr->next;
        }
        f = f->next;
    }
    normalizuj(result);
    return result;
}
POLYNOMIAL& POLYNOMIAL ::operator<<=(int a)
{
    *this = (*this) << a;
    return *this;
}
POLYNOMIAL& POLYNOMIAL ::operator>>=(int a)
{
    *this = (*this)>> a;
    return *this;
}

#endif //DZIALA_H
