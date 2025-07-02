#include "Kapitan.h"
size_t Kapitan::count = 0;
Kapitan::Kapitan():experience(0)
{
    printf("Im born\n");
    Kapitan::count++;
}
Kapitan::Kapitan(string name,string surname,int experience,bool alive):name(name),surname(surname),experience(experience),alive(alive)
{
    Kapitan::count++;
}
Kapitan::~Kapitan()
{
    printf("Im dying\n");
   Kapitan:: count--;
}
pair<string,string> Kapitan::getName()
{
    auto dane = make_pair(this->name,this->surname);
    return dane;
}
int Kapitan::getExp()
{
    return experience;
}
void Kapitan::setExp(int experience)
{
    this->experience = experience;
}
void Kapitan::setName(string name,string surname)
{
    this->name = name;
    this->surname = surname;
}
void Kapitan::setAlive(bool alive)
{
    this->alive = alive;
}
int main()
{

    Kapitan *kapitan =  new Kapitan("Matesz","Paszynski",10,true);
    delete kapitan;
    Kapitan mati("Mateusz","paszynski",10,true);
    Kapitan mati2("Mateusz","paszynski",10,true);
    cout<<Kapitan::count<<endl;

}



