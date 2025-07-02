class HUMAN_CLASS : public virtual PLAYER_CLASS
{
protected:
    string name;
    void die();
public:
    unsigned int getDefence();
    string get_name();
    unsigned int defense;
    HUMAN_CLASS(string);
    unsigned int getRemainingHealth();
    unsigned int getDamage();
    unsigned int getAgility();
    void takeDamage(unsigned int);
    void applyWinnerReward();
    void cure();
    void printParams();
    unsigned int health();
    friend bool cmp(PLAYER_CLASS*,PLAYER_CLASS*);
};
unsigned int HUMAN_CLASS::getDefence()
{
    return defense;
}
string HUMAN_CLASS::get_name()
{
    return name;
}
unsigned int HUMAN_CLASS::health()
{
    return hp;
}
HUMAN_CLASS::HUMAN_CLASS(string name)
{
    alive = true;
    this->name = name;
    max_hp = 200;
    hp = max_hp;
    attack_power = 30;
    agility = 10;
    defense = 10;
}
unsigned int HUMAN_CLASS::getRemainingHealth()
{
    return 100*hp/max_hp;
}
unsigned int HUMAN_CLASS::getAgility()
{
    return agility;
}
unsigned int HUMAN_CLASS::getDamage()
{
    return attack_power;
}
void HUMAN_CLASS::cure()
{
    hp = max_hp;
}
void HUMAN_CLASS::applyWinnerReward()
{
    agility+=2;
    attack_power+=2;
}
void HUMAN_CLASS::die()
{
    hp = 0;
    alive = false;
}
void HUMAN_CLASS::takeDamage(unsigned int damage)
{
    //cout<<damage-agility-defense<<endl;
    damage = ((damage > agility + defense ) )? (damage - agility - defense) : 0;

    if ( hp > damage )hp -=damage;
    else hp = 0;
    if (hp ==0)this->die();
}
void HUMAN_CLASS::printParams()
{
    if (hp == 0)
    {
        cout<<name.c_str()<<":R.I.P.\n";
        //printf("%s:R.I.P.\n",name.c_str());
        return;
    }
    unsigned int health = 100 * hp /max_hp;
    cout<<name.c_str()<<":"<<max_hp<<":"<<hp<<":"<<health<<"%:"<<getDamage()<<":"<<agility<<":"<<defense<<endl;
}
