//
// Created by mpaszynski on 23.05.25.
//
#include <iostream>
using namespace std;
#ifndef KAPITAN_H
#define KAPITAN_H

class Kapitan
{
public:
    static size_t count;
    Kapitan();
    ~Kapitan();
    string name;
    string surname;
    int experience;
    bool alive;
    Kapitan(string,string,int,bool);
private:

    pair<string,string> getName();
    int getExp();
    bool isAlive();
    void setName(string,string);
    void setExp(int);
    void setAlive(bool);
};
#endif //KAPITAN_H
