//Mateusz Paszynski
struct wsp
{
    wsp* next;
    wsp* prev;
    int wspolczynnik;
    long long licznik;
    long long mianownik;
    wsp()
    {
        next = NULL;
        prev = NULL;
        wspolczynnik = 0;
        licznik = 0;
        mianownik = 1;

    }
};
class POLYNOMIAL
{
public :
    wsp* head;
    wsp * tail;
    int stopien;
    static int overloaded;
    POLYNOMIAL(int,...);
    POLYNOMIAL(const POLYNOMIAL&);
    POLYNOMIAL();
    ~POLYNOMIAL();
    friend void normalizuj(POLYNOMIAL&);
    POLYNOMIAL(unsigned int x);
    POLYNOMIAL bez_skracania( const POLYNOMIAL& );
    POLYNOMIAL operator+(const POLYNOMIAL&);
    POLYNOMIAL operator-();
    POLYNOMIAL operator-(const POLYNOMIAL&);
    POLYNOMIAL operator*(const POLYNOMIAL& );
    POLYNOMIAL operator/(const POLYNOMIAL& );
    POLYNOMIAL operator%(const POLYNOMIAL&);

    POLYNOMIAL& operator=(const POLYNOMIAL& other);
    POLYNOMIAL& operator+=(const POLYNOMIAL& second);
    POLYNOMIAL& operator-=(const POLYNOMIAL& second);
    POLYNOMIAL& operator*=( const POLYNOMIAL& second);
    POLYNOMIAL& operator/=( const POLYNOMIAL& second);
    POLYNOMIAL& operator%=(const POLYNOMIAL& second);


    POLYNOMIAL& operator++();
    POLYNOMIAL operator++(int);
    POLYNOMIAL& operator--();
    POLYNOMIAL operator--(int);

    POLYNOMIAL operator<<(int a);
    POLYNOMIAL operator>>(int a);
    POLYNOMIAL& operator<<=(int a);
    POLYNOMIAL& operator>>=( int a);
    void* operator new(size_t);
    void operator delete(void *);
    friend std::ostream& operator<<(std::ostream& stream, const POLYNOMIAL& wielomian);
    friend std::istream& operator>>(std::istream& stream, POLYNOMIAL& wielomian);


};
void* POLYNOMIAL::operator new(size_t size) {
    overloaded++;
    return ::operator new(size);
}
void POLYNOMIAL::operator delete(void *p) {
    overloaded--;
    ::operator delete(p);
}
int NWD(int a, int b)
{
    if ( a < 0 ) a = 0-a;
    if ( b< 0 ) b = 0-b;
    if ( a == 0 || b == 0)
    {
        if ( a == 0 && b == 0)
            return 0;
        return (a > b) ? a : b;
    }

    while (a!=b)
    {
        if ( b > a) b -=a;
        else a-=b;
    }
    if ( a == 0)
    {return 0;}

    if ( a < 0)a = 0 - a;
    return a;
}
int NWW(int a, int b)
{
    int temp = a * b;
    if ( temp < 0 ) temp = -temp;
    if ( NWD(a,b)!= 0 )return (temp / NWD(a, b));
    else return 0;
}
void wypisz (POLYNOMIAL & p)
{
    wsp * f = p.tail;
    while (f)
    {
        cout<<"("<<f->licznik<<" / "<<f->mianownik<<") ";
        f = f->prev;
    }
}
void skroc(POLYNOMIAL& p);
void normalizuj(POLYNOMIAL& p)
{
    if ( p.stopien == 0)
    {
        return;
    }
    while (p.tail && p.tail->wspolczynnik == 0)
    {
        if ( p.tail->prev == NULL)
        {
            p.head = p.tail;
            return;
        }
        wsp * todel = p.tail;
        p.tail = p.tail->prev;
        p.tail -> next = NULL;

        p.stopien--;
        delete todel;
    }
}
void wpisz(POLYNOMIAL& p)
{
    wsp * f = p.head;
    while (f)
    {
        f->licznik = f->wspolczynnik;
        f->mianownik = 1;
        f = f->next;
    }
}
void skroc(POLYNOMIAL& p)
{
    if ( p.stopien == 0)
    {

        if ( p.head->wspolczynnik > 0)p.head->wspolczynnik = 1;
        if ( p.head->wspolczynnik < 0)p.head->wspolczynnik =-1;
        return;
    }
    wsp * curr = p.head;
    int a = curr->wspolczynnik;
    curr = curr->next;
    int b = curr->wspolczynnik;
    int temp = NWD(a,b);
    curr = curr->next;
    while ( curr )
    {
        temp = NWD(temp,curr->wspolczynnik);
        curr = curr->next;
    }
    if ( temp == 1)
    {
        return;
    }
    curr = p.head;

    while (curr)
    {
        curr->wspolczynnik /= temp;
        curr -> licznik = curr->wspolczynnik;
        curr->mianownik = 1;
        curr = curr->next;
    }
}

ostream& operator <<(ostream& stream, const POLYNOMIAL& wielomian)
{
    stream <<"( ";
    wsp * curr = wielomian.head;
    for ( int i =0; i<=wielomian.stopien;i++)
    {
        stream<<curr->wspolczynnik;
        if (( i ) != wielomian.stopien )stream<<", ";
        curr = curr->next;

    }
    stream<<" )";
    return stream;
}
istream& operator >>(istream& stream, POLYNOMIAL& wielomian)
{
    POLYNOMIAL temp;
    int st;
    stream >> st;
    temp.stopien = st;
    if (st >= 0)
    {
        delete temp.head;

        temp.head = new wsp();
        stream >> temp.head->wspolczynnik;

        wsp* prev = temp.head;
        for (int i = 1; i <= st; i++)
        {
            wsp* curr = new wsp();
            stream >> curr->wspolczynnik;
            prev->next = curr;
            curr->prev = prev;
            prev = curr;
        }
        temp.tail = prev;
    }

    normalizuj(temp);
    skroc(temp);

    wielomian = temp;

    return stream;
}

POLYNOMIAL POLYNOMIAL ::bez_skracania (const POLYNOMIAL &second)
{
    unsigned int x = (second.stopien < this->stopien) ? this->stopien : second.stopien;
    POLYNOMIAL  result(x);
    wsp *f = this->head;
    wsp *s = second.head;
    wsp * curr = result.head;
    for ( unsigned int i = 0;i <= x;i++)
    {
        if ( f != NULL)
        {
            curr->wspolczynnik += f->wspolczynnik;
            f = f->next;
        }
        if ( s != NULL)
        {
            curr->wspolczynnik += s->wspolczynnik;
            s = s->next;
        }
        curr = curr->next;
    }

    normalizuj(result);
    return result;
}
POLYNOMIAL POLYNOMIAL ::operator+ (const POLYNOMIAL &second)
{
    unsigned int x = (second.stopien < this->stopien) ? this->stopien : second.stopien;
    POLYNOMIAL  result(x);
     wsp *f = this->head;
    wsp *s = second.head;
     wsp * curr = result.head;
    for ( unsigned int i = 0;i <= x;i++)
    {
        if ( f != NULL)
        {
            curr->wspolczynnik += f->wspolczynnik;
            f = f->next;
        }
        if ( s != NULL)
        {
            curr->wspolczynnik += s->wspolczynnik;
            s = s->next;
        }
        curr = curr->next;
    }
    normalizuj(result);
    skroc(result);
    return result;
}
POLYNOMIAL POLYNOMIAL :: operator-()
{
    unsigned int rozmiar = this->stopien;
    POLYNOMIAL result(rozmiar);
    wsp * curr = this->head;
    wsp * r_curr = result.head;
    for ( int i = 0;i<=this->stopien;i++ )
    {
        r_curr->wspolczynnik = 0 - curr->wspolczynnik;
        if ( curr->mianownik > 0 && curr->licznik > 0)
        {
            r_curr->licznik = 0 - curr->licznik;
            r_curr->mianownik = curr->mianownik;
        }
        else if ( curr->mianownik < 0 && curr->licznik > 0)
        {
            r_curr->licznik = curr->licznik;
            r_curr->mianownik = 0-curr->mianownik;
        }
        else if (curr->mianownik < 0 && curr->licznik < 0)
        {
            r_curr->licznik = curr->licznik;
            r_curr->mianownik = 0-curr->mianownik;
        }
        else
        {
            r_curr->licznik = 0 - curr->licznik;
            r_curr->mianownik =curr->mianownik;
        }

        r_curr = r_curr->next;
        curr = curr->next;

    }

    return result;
}

POLYNOMIAL POLYNOMIAL ::operator- (const POLYNOMIAL& second)
{
    unsigned int x = (this->stopien > second.stopien) ? this->stopien : second.stopien;
    POLYNOMIAL  result(x);
    wsp *f = this->head;
    wsp *s = second.head;
    wsp * curr = result.head;
    for (unsigned int i = 0;i <= x;i++)
    {
        if ( f != NULL)
        {
            curr->wspolczynnik = f->wspolczynnik;
            f = f->next;
        }
        if ( s != NULL)
        {
            curr->wspolczynnik -= s->wspolczynnik;
            s = s->next;
        }
        curr = curr->next;
    }
    normalizuj(result);
    skroc(result);
    return result;
}
POLYNOMIAL POLYNOMIAL ::operator*(const POLYNOMIAL& second)
{
    unsigned int rozmiar = this->stopien + second.stopien;
    POLYNOMIAL result(rozmiar);
    wsp * f = this->head;
    for (int i = 0;i<=this->stopien;i++)
    {
        POLYNOMIAL temp1(rozmiar);
        wsp * temp_w = temp1.head;
        wsp* s = second.head;

        for ( int c = 0;c<i;c++)
        {
            temp_w = temp_w->next;
        }
        int a = f->wspolczynnik;
        if ( a != 0){
            for ( int j = 0;j<=second.stopien;j++)
            {
                temp_w->wspolczynnik = (s->wspolczynnik) * a;
                s = s->next;
                temp_w = temp_w->next;
            }
        result = result.bez_skracania(temp1);
    }
        f = f->next;
    }
    normalizuj(result);
    skroc(result);
    return result;
}

POLYNOMIAL& POLYNOMIAL :: operator= (const POLYNOMIAL &other)
    {
    if ( this == &other)
    {
        return *this;
    }
    wsp* current = this->head;
    while (current != NULL) {
        wsp* next_node = current->next;
        delete current;
        current = next_node;
    }

    if ( other.head == NULL)
    {
        this->head = new wsp();
        this->stopien = 0;
        this->tail = this->head;
        return *this;
    }
    this->stopien = other.stopien;
    this->head = new wsp();
     wsp * prev = head;
     wsp * other_h = other.head;
    this->head->wspolczynnik = other_h->wspolczynnik;
    this->head->licznik = other_h->licznik;
    this->head->mianownik = other_h->mianownik;
    other_h = other_h->next;
    while (other_h)
     {
         wsp* curr = new wsp();
         curr->wspolczynnik = other_h->wspolczynnik;
         curr->licznik = other_h->licznik;
         curr->mianownik = other_h->mianownik;
         prev->next = curr;
         curr->prev = prev;
         prev = curr;
         other_h = other_h->next;
     }
    this->tail = prev;
    return *this;
    }
POLYNOMIAL& POLYNOMIAL ::operator +=(const POLYNOMIAL & second)
{
   *this= *this + second;
    return *this;
}
POLYNOMIAL& POLYNOMIAL :: operator-=(const POLYNOMIAL & second)
{
   *this= (*this) - second;
    return (*this);
}
POLYNOMIAL& POLYNOMIAL ::operator*=( const POLYNOMIAL & second)
{
    *this = (*this)* second;
    return (*this);
}
POLYNOMIAL& POLYNOMIAL ::operator /=(const POLYNOMIAL & second)
{
    *this = (*this)/ second;
    return *this;
}
POLYNOMIAL& POLYNOMIAL ::operator %=(const POLYNOMIAL & second)
{
    *this = (*this)% second;
    return (*this);
}


POLYNOMIAL :: ~POLYNOMIAL()
{
    wsp * curr = head;
    while (curr)
    {
        wsp * next = curr->next;
        delete curr;
        curr = next;
    }
}
POLYNOMIAL::POLYNOMIAL(int x, ...)
{
    va_list args;
    va_start(args, x);
    stopien = x;
    if ( x >= 0)
    {
        head = new wsp();
        head->wspolczynnik = va_arg(args, int);

        wsp * prev= head;
        for(int i=0;i<x;i++)
        {
            wsp * curr = new wsp();
            curr->wspolczynnik = va_arg(args,int);
            curr->licznik = curr->wspolczynnik;
            curr->mianownik = 1;
            prev->next = curr;
            curr->prev = prev;
            prev = curr;
        }
        tail = prev;
        va_end(args);
        normalizuj(*this);
        skroc(*this);
    }
}
POLYNOMIAL::POLYNOMIAL(unsigned int x)
{
    stopien = x ;
    head = new wsp();
    wsp * prev = head;
    for ( unsigned int i = 0;i<x;i++ )
    {
        wsp * curr = new wsp();
        prev->next = curr;
        curr->prev = prev;
        prev = curr;
    }
    tail = prev;
}
POLYNOMIAL :: POLYNOMIAL()
{

    stopien = 0;
    head = new wsp();
    tail = head;

}
POLYNOMIAL::POLYNOMIAL(const POLYNOMIAL& other)
{

    if ( other.head == NULL)
    {
        head = new wsp();
        tail = head;
        stopien = 0;
        return;
    }
    stopien  = other.stopien;
    head = new wsp();
    head->wspolczynnik = other.head->wspolczynnik;
    head->licznik = head->wspolczynnik;
    head->mianownik = other.head->mianownik;
    wsp * prev = head;
    wsp * f = other.head->next;
    for ( int i = 0;i<stopien;i++ )
    {
        wsp * curr = new wsp();
        curr->wspolczynnik = f->wspolczynnik;
        curr->licznik = f->wspolczynnik;
        curr->mianownik = f->mianownik;
        f = f->next;
        prev->next = curr;
        curr->prev = prev;
        prev = curr;
    }
    tail = prev;
    normalizuj(*this);
    skroc(*this);
}
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

int NWW_m(POLYNOMIAL& p)
{
    if ( p.stopien == 0)
    {
        if ( p.head->mianownik < 0 ) return ( 0 - p.head->mianownik);
        return p.head->mianownik;
    }
    wsp * curr = p.head;
    int a = curr->mianownik;
    curr = curr->next;
    int b = curr->mianownik;
    int temp = NWW(a,b);
    curr = curr->next;
    while ( curr )
    {
        if ( curr->mianownik < 0 )
        {
            curr->licznik = 0 - curr->licznik;
         curr->mianownik = 0 - curr->mianownik;
    }
        temp = NWW(temp,curr->mianownik);
        curr = curr->next;
    }
    if ( temp < 0 )
    {
        return -temp;
    }
    return temp;
}
POLYNOMIAL dodaj ( POLYNOMIAL &second,POLYNOMIAL &first)
{

    unsigned int x = (second.stopien < first.stopien) ? first.stopien : second.stopien;
    POLYNOMIAL  result(x );
    wsp *f = first.head;
    wsp *s = second.head;
    wsp * curr = result.head;
    int w1= NWW_m(second);
    int w2= NWW_m(first);
    //cout<<w1<<" "<<w2<<endl;
    int wspolny_mianownik = NWW(w1,w2);


   while (curr)
    {
        curr->licznik = 0;

        if ( f != NULL)
        {
            int dziele = wspolny_mianownik;
            if ( f->mianownik != 0 )dziele/= f->mianownik;
            curr->licznik += f->licznik * (dziele);
            f = f->next;
        }
        if ( s != NULL)
        {
            int dziele = wspolny_mianownik;
            if ( s->mianownik != 0 )dziele/= s->mianownik;
            curr->licznik += s->licznik * (dziele);
            s = s->next;
        }
        curr->mianownik = wspolny_mianownik;
        curr = curr->next;

    }
   // cout<<"wsp : "<<wspolny_mianownik<<endl;
   // wypisz(result);
   // cout<<endl;
    //normalizuj(result);
    return result;
}

POLYNOMIAL POLYNOMIAL ::operator %(const POLYNOMIAL & second)
{

    wsp * c = this->head;
    while (c)
    {
        c->licznik = c->wspolczynnik;
        c ->mianownik = 1;
        c = c->next;
    }
    c = second.head;
    while (c)
    {
        c->licznik = c->wspolczynnik;
        c ->mianownik = 1;
        c = c->next;
    }

    if (second.stopien == 0 && (second.head == NULL || second.head->wspolczynnik == 0))
    {
        return *this;
    }
    if ((this)->stopien < second.stopien)
    {

        return *this;
    }
    if ( * this == second)
    {
        return POLYNOMIAL();
    }
    unsigned int rozmiar = this->stopien -  second.stopien;
    POLYNOMIAL result(rozmiar);
    POLYNOMIAL rest (*this);
    wsp * res = result.tail;
    int dziel = second.tail->wspolczynnik;

    for ( unsigned int i = 0; (i <= rozmiar && res); i++ )
    {
        wsp * f = rest.tail;
        for ( unsigned int j = 0;j<i;j++)
        {
            f = f->prev;
        }

        res->licznik = f->licznik;
        res->mianownik = f->mianownik * dziel;

        //cout<<endl<<f->licznik<<" "<<f->mianownik<<endl;
        //cout<<res->licznik<<"/"<<res->mianownik<<endl;
        wsp* s = second.tail;
        if ( s == NULL)return POLYNOMIAL();
        unsigned int rozmiar_temp = this->stopien - i;
        POLYNOMIAL temp(rozmiar_temp);
        wsp * tmp = temp.tail;
       while (s && tmp && res){

            tmp->licznik = res->licznik * s->wspolczynnik;
            tmp->mianownik = res->mianownik;
            s = s->prev;
            tmp = tmp->prev;
        }

        tmp = temp.tail;


        int wspolny_mianownik = NWW_m(temp);

        while (tmp) // przepisz na ludzkie
        {
            tmp->wspolczynnik = tmp->licznik * wspolny_mianownik;
            if (tmp->mianownik!=0)tmp->wspolczynnik/=tmp->mianownik;
            tmp = tmp->prev;

        }//przeksztalc licznik/mianownik na wspolczynniki

        temp =  -temp;

         //wypisz(rest);cout<<" + ";wypisz(temp);cout<<" = ";
        POLYNOMIAL new_rest(dodaj(rest,temp));
        rest = new_rest;


        //wypisz(rest);
         //cout<<"\n";

        res = res->prev;

    }

    int w_mianownik = NWW_m(rest);
    wsp * h = rest.tail;

    while (h)
    {
       if (h->mianownik < 0 && h->licznik < 0)
        {
            h->licznik = 0 - h->licznik;
            h->mianownik = 0-h->mianownik;
        }
        h->wspolczynnik = h->licznik * w_mianownik;
        if ( h->mianownik != 0 )h->wspolczynnik/=h->mianownik;
        h= h->prev;
    }

    normalizuj(rest);
    skroc(rest);
    return rest;
}
POLYNOMIAL POLYNOMIAL ::operator/ (const POLYNOMIAL& second)
{
    if (this->stopien < second.stopien) return POLYNOMIAL(0, 0);
    if (second.stopien == 0 && second.head->wspolczynnik > 0) return *this;
    if (second.stopien == 0 && second.head->wspolczynnik < 0) return (*this) * POLYNOMIAL(0, -1);
    if (second.stopien == 0 && second.head->wspolczynnik == 0) return POLYNOMIAL(0, 0);
    wsp * c = this->head;
    while (c)
    {
        c->licznik = c->wspolczynnik;
        c ->mianownik = 1;
        c = c->next;
    }
    c = second.head;
    while (c)
    {
        c->licznik = c->wspolczynnik;
        c ->mianownik = 1;
        c = c->next;
    }

    unsigned int rozmiar = this->stopien -  second.stopien;
    POLYNOMIAL result(rozmiar);
    POLYNOMIAL rest (*this);
    wsp * res = result.tail;
    int dziel = second.tail->wspolczynnik;

    for (unsigned  int i = 0; (i <= rozmiar && res ) ; i++ )
    {
        wsp * f = rest.tail;
        for (unsigned int j = 0;j<i;j++)
        {
            f = f->prev;
        }
        res->licznik = f->licznik;
        res->mianownik = f->mianownik * dziel;

        // cout<<endl<<f->licznik<<" "<<f->mianownik<<endl;
        // cout<<res->licznik<<"/"<<res->mianownik<<endl;
        wsp* s = second.tail;
        unsigned int rozmiar_temp = this->stopien - i;
        POLYNOMIAL temp(rozmiar_temp);
        wsp * tmp = temp.tail;
        while (s && tmp && res) {

            tmp->licznik = res->licznik * s->wspolczynnik;
            tmp->mianownik = res->mianownik;
            s = s->prev;
            tmp = tmp->prev;
        }

        tmp = temp.tail;

        int wspolny_mianownik = NWW_m(temp);

        while (tmp) // przepisz na ludzkie
        {
            tmp->wspolczynnik = tmp->licznik * wspolny_mianownik;
            if (tmp->mianownik!=0)tmp->wspolczynnik/=tmp->mianownik;
            tmp = tmp->prev;

        }//przeksztalc licznik/mianownik na wspolczynniki

        temp =  -temp;

        // wypisz(rest);cout<<" + ";wypisz(temp);cout<<" = ";
       POLYNOMIAL new_rest = (dodaj(rest,temp));
        rest = new_rest;
        // wypisz(rest);
       // cout<<"\n";
        res = res->prev;
    }
    int w_mianownik = NWW_m(result);
    if ( w_mianownik < 0 ) w_mianownik = 0 - w_mianownik;
    wsp * h = result.tail;
    while (h)
    {

       if (h->mianownik < 0 && h->licznik < 0)
        {
            h->licznik = 0 - h->licznik;
            h->mianownik = 0-h->mianownik;
        }
        h->wspolczynnik = h->licznik * w_mianownik;
        if ( h->mianownik != 0 )h->wspolczynnik/=h->mianownik;
        h= h->prev;
    }
    normalizuj(result);
    skroc(result);
    return result;
}
// int POLYNOMIAL::overloaded = 0;
// int main()
// {
//     POLYNOMIAL p,q;
//     POLYNOMIAL s(3,1,3,4,-1),t(2,6,8,-7);
//     cin>>p>>q;
//     cout<<p/q;
//
// }