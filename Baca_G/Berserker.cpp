class BERSERKER_CLASS :public HUMAN_CLASS,public BEAST_CLASS
{

protected:
    void die();
public :
    unsigned int getDefence();
    friend class HUMAN_CLASS;
    friend class BEAST_CLASS;
    string get_name();
    void applyWinnerReward();
    void cure();
    BERSERKER_CLASS(string,string);
    unsigned int getDamage();
    void takeDamage(unsigned int);
    unsigned int getAgility();
    void printParams();
    unsigned int getRemainingHealth();

    unsigned int health();
    friend bool cmp(PLAYER_CLASS*,PLAYER_CLASS*);

};
unsigned int BERSERKER_CLASS::getDefence()
{
    return defense;
}
string BERSERKER_CLASS::get_name()
{
    if (getRemainingHealth() <25)
    {
        return BEAST_CLASS::name;
    }
    return HUMAN_CLASS::name;
}
unsigned int BERSERKER_CLASS::health()
{
    return hp;
}
BERSERKER_CLASS::BERSERKER_CLASS(string human,string beast): HUMAN_CLASS(human), BEAST_CLASS(beast)
{
    alive = true;
    defense = 15;
    agility = 5;
    hp = 200;
    max_hp = 200;
    attack_power = 35;

}
void BERSERKER_CLASS::cure()
{
    hp = max_hp;
}
void BERSERKER_CLASS::applyWinnerReward()
{
    agility+=2;
    attack_power+=2;
}

void BERSERKER_CLASS::die()
{
    HUMAN_CLASS::die();
}
void BERSERKER_CLASS::takeDamage(unsigned int damage)
{
    if (getRemainingHealth()>=25)
    {
        HUMAN_CLASS::takeDamage(damage);
    }
    else
    {
        BEAST_CLASS::takeDamage(damage);
    }
}
unsigned int BERSERKER_CLASS::getDamage()
{
    if (getRemainingHealth()>=25) return HUMAN_CLASS::getDamage();
    return BEAST_CLASS::getDamage();

}
unsigned int BERSERKER_CLASS::getAgility()
{
    if (getRemainingHealth()>=25)return HUMAN_CLASS::getAgility();
    return BEAST_CLASS::getAgility();
}

void BERSERKER_CLASS::printParams()
{

    if (getRemainingHealth()>=25 || isAlive() ==false)return HUMAN_CLASS::printParams();
    return BEAST_CLASS::printParams();
}
unsigned int BERSERKER_CLASS::getRemainingHealth()
{
    return 100 * hp/max_hp;
}