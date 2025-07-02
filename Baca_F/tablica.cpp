#include "tablica.h"

#include<iostream>
Tablica::Tablica(): m_tab_i{ 1,2,3 }
{

}
Tablica::~Tablica()
{
    delete m_tab;
}
int * Tablica::get_tab_i()
{

    int * wsk = new int[3];
    *(wsk) = m_tab_i[0];
    *(wsk+1) = m_tab_i[1];
    *(wsk+2) = m_tab_i[2];
    return wsk;
}
void  Tablica::get_tab_i(int * tablica)
{
    *tablica = m_tab_i[0];
    *(tablica+1) = m_tab_i[1];
    *(tablica+2) = m_tab_i[2];
}
Tablica::Tablica(int *tab, int size):m_tab_i{ 1,2,3 }
{
    m_tab = new int[size];
    for ( int i = 0;i<size;i++ )
    {
        *(m_tab+i) = *(tab+i);
    }
}
int * Tablica::get_tab()
{
    return m_tab;
}
int main()
{
    int nowa[]={5,6,7};
    Tablica tablica(nowa,3);
    int * wsk = tablica.get_tab_i();
    for ( int i = 0;i<3;i++)
    printf("%d ",*(wsk+i));
    printf("\n");
    int tab[3];
    tablica.get_tab_i(tab);
    for ( auto I : tab)
    {
        printf("%d ",I);
    }
    int* ptr=tablica.get_tab();
    cout<<"\nDynamiczna alokacja\n";
    for ( int i = 0;i<3;i++)
    {
        cout<<*(ptr+i)<<" ";
    }

    return 0;
}