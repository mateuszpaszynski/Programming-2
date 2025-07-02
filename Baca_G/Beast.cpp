class BEAST_CLASS : public virtual PLAYER_CLASS
{
protected:
    string name;
    void die();
public:
    string get_name();
    void applyWinnerReward();
    void cure();
    BEAST_CLASS(string);
    void printParams();
    unsigned int getAgility();
    unsigned int getDamage();
    void takeDamage(unsigned int);
    unsigned int getRemainingHealth();
    unsigned int health();
    friend bool cmp(PLAYER_CLASS*,PLAYER_CLASS*);
};
string BEAST_CLASS::get_name()
{
    return name;
}
unsigned int BEAST_CLASS::health()
{
    return hp;
}
BEAST_CLASS::BEAST_CLASS(string name)
{
    alive = true;
    this->name = name;
    max_hp = 150;
    hp = 150;
    attack_power = 40;
    agility = 20;

}
void BEAST_CLASS::die()
{
    hp = 0;
    alive = false;
}
unsigned int BEAST_CLASS::getRemainingHealth()
{
    return 100*hp/max_hp;
}
unsigned int BEAST_CLASS::getAgility()
{
    return agility;
}
void BEAST_CLASS::cure()
{
    hp = max_hp;
}
void BEAST_CLASS::applyWinnerReward()
{
    agility+=2;
    attack_power+=2;
}

unsigned int BEAST_CLASS::getDamage()
{
    if ( getRemainingHealth() < 25)return attack_power*2;
    return attack_power;
}
void BEAST_CLASS::takeDamage(unsigned int damage)
{
    damage = ((damage > int(agility/2) ) )? damage - agility/2 : 0;
    if ( hp>damage)hp -= damage;
    else hp = 0;
    if (hp ==0)this->die();
}
void BEAST_CLASS::printParams()
{
    if (hp == 0)
    {
        cout<<name.c_str()<<":R.I.P.\n";
        return;
    }
    unsigned int health = 100 * hp /max_hp;
    cout<<name.c_str()<<":"<<max_hp<<":"<<hp<<":"<<health<<"%:"<<getDamage()<<":"<<agility<<endl;
}