#include <cstdio>
#include <iostream>
using namespace std;
#ifndef TABLICA_H
#define TABLICA_H
class Tablica
{
    int m_tab_i[3];
    int* m_tab{};
public:
    Tablica();
    ~Tablica();
    Tablica(int* tab,int);
    void  get_tab_i(int*);
    int *get_tab_i();
    int *get_tab();
};
#endif