//Mateusz Paszynski
#include <iostream>
#include <string>
using namespace std;
class PLAYER_CLASS
{
protected:
    unsigned int max_hp;
    unsigned int hp;
    unsigned int attack_power;
    unsigned int agility;
    virtual void die() =0;
    bool alive;
public :

    virtual string get_name()
    {
        return "";
    }
    virtual unsigned int getDefence()
    {
        return 0;
    }
    virtual unsigned int get_max_hp()
    {
        return max_hp;
    }
    virtual unsigned int get_hp()
    {
        return hp;
    }
    virtual unsigned int getRemainingHealth() =0;
    virtual unsigned int getDamage() =0;
    virtual unsigned int getAgility() =0;
    virtual void takeDamage(unsigned int) =0;
    virtual void applyWinnerReward() =0;
    virtual void cure() =0;
    virtual void printParams() =0;

    friend class CAESAR_CLASS;
    friend bool cmp(PLAYER_CLASS*,PLAYER_CLASS*);
};

class CAESAR_CLASS
{
    public :
    static unsigned int th_man;
    void judgeDeathOrLife(PLAYER_CLASS*);
};
class ARENA_CLASS
{
    CAESAR_CLASS caesar;
    public:
    static int attacks_count;

    ARENA_CLASS(CAESAR_CLASS*);
    void fight(PLAYER_CLASS*,PLAYER_CLASS*);
};
ARENA_CLASS::ARENA_CLASS(CAESAR_CLASS *ptr){
    this->caesar = *ptr;
}
void ARENA_CLASS::fight(PLAYER_CLASS* player1, PLAYER_CLASS*player2)
{
    if ( player1->getRemainingHealth() > 0  && player2->getRemainingHealth() > 0){

        if (player1->getAgility()<player2->getAgility())
        {
            PLAYER_CLASS* temp = player2;
            player2 = player1;
            player1 = temp;
        }
        attacks_count = 0;
    player1->printParams();
    player2->printParams();
    while (player1->getRemainingHealth() >= 10 && player2->getRemainingHealth() >= 10 )
    {
        player2->takeDamage(player1->getDamage());
        attacks_count++;
        player2->printParams();
        if (player2->getRemainingHealth() < 10)break;
        player1->takeDamage(player2->getDamage());
        attacks_count++;
        player1->printParams();
        if ( player1->getRemainingHealth() < 10 || player2->getRemainingHealth() < 10 || attacks_count>=40)break;
    }
    if ( player1->getRemainingHealth() > 0)
    {
        caesar.judgeDeathOrLife(player1);
        player1->printParams();
    }

    if (player2->getRemainingHealth() > 0)
    {

        caesar.judgeDeathOrLife(player2);
        player2->printParams();

    }
    if ( player1->getRemainingHealth() > 0)
    {
        player1->applyWinnerReward();
        player1->cure();
    }
    if (player2->getRemainingHealth() > 0)
    {
        player2->applyWinnerReward();
        player2->cure();
    }
    //printf("END OF THE FIGHT\n");
    player1->printParams();
    player2->printParams();
}
}
void CAESAR_CLASS::judgeDeathOrLife(PLAYER_CLASS* player)
{
    // printf("ATTACKS_COUNT: %d\n",ARENA_CLASS::attacks_count);
    th_man++;
    //printf("th_man: %d\n",th_man);
    if ( ARENA_CLASS::attacks_count % 2 == 0)
    {
        if ( th_man % 3 == 0)
        {
            // printf("\nCAESAR SENTENCED TO DEATH!!\n");
            player->die();
        }
    }
}
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
HUMAN_CLASS::HUMAN_CLASS(string n)
{
    alive = true;
    this->name = n;
    max_hp = 200;
    hp = max_hp;
    attack_power = 30;
    agility = 10;
    defense = 10;
}
unsigned int HUMAN_CLASS::getRemainingHealth()
{
    return (100*hp)/max_hp;
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
    unsigned int health = (100 * hp) /max_hp;
    cout<<name.c_str()<<":"<<max_hp<<":"<<hp<<":"<<health<<"%:"<<getDamage()<<":"<<agility<<":"<<defense<<endl;
}
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
    unsigned int getDefence();
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
BEAST_CLASS::BEAST_CLASS(string n)
{
    alive = true;
    this->name = n;
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
    return (100*hp)/max_hp;
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
    damage = ((damage > (agility/2) ) )? damage - agility/2 : 0;
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
    unsigned int health = (100 * hp )/max_hp;
    cout<<name.c_str()<<":"<<max_hp<<":"<<hp<<":"<<health<<"%:"<<getDamage()<<":"<<agility<<endl;
}
unsigned int BEAST_CLASS::getDefence()
{
    return 0;
}
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
    if ( getRemainingHealth() >= 25)
    {
        return HUMAN_CLASS::getDefence();
    }

    return BEAST_CLASS::getDefence();
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

    if (getRemainingHealth()>=25 ||getRemainingHealth() == 0 )return HUMAN_CLASS::printParams();
    return BEAST_CLASS::printParams();
}
unsigned int BERSERKER_CLASS::getRemainingHealth()
{
    return (100 * hp)/max_hp;
}
class SQUAD_CLASS : public PLAYER_CLASS
{
protected:
    string name;
    unsigned int player_count;
    void die();
public:
    struct Member
    {
        PLAYER_CLASS* player;
        Member* next_member;
    };
    Member* members;
    ~SQUAD_CLASS()
    {
        Member* current = members;
        while (current)
        {
            Member* next = current;
            current=current->next_member;
            delete next;
        }
    }
    string get_name();
    void addPlayer(PLAYER_CLASS*);
    unsigned int getAgility();
    unsigned int getDamage();
    void takeDamage(unsigned int);
    void printParams();
    SQUAD_CLASS(string);
    void cure();
    void applyWinnerReward();
    unsigned int getRemainingHealth();
    unsigned int health();
    void sortm(Member *&,unsigned int);
     bool cmp(Member*,Member*);
    unsigned int getPlayerCount();
};
unsigned int SQUAD_CLASS::getPlayerCount()
{
    unsigned int undead = 0;
    Member * p = members;
    Member * prev = NULL;
    Member * usun = NULL;
    for ( unsigned int i = 0; (i < player_count) &&(p) ; i++ )
    {
        if ( p->player->getRemainingHealth() > 0)
        {
            undead++;
            prev = p;
            usun = NULL;
        }
        else
        {
            if ( prev == NULL)
            {
                members = p->next_member;
            }
            else
            {
                prev->next_member = p->next_member;

            }
            usun = p;
        }
        p = p->next_member;
       if ( usun != NULL) delete usun;
    }
    player_count = undead;
    if ( undead == 0)alive = false;
    return undead;
}
string SQUAD_CLASS::get_name()
{
    return name;
}
SQUAD_CLASS::SQUAD_CLASS(string n)
{
    this->name = n;
    members = NULL;
    player_count = 0;
    attack_power = 0;
    alive = true;
    hp = 10e6;
}
unsigned int SQUAD_CLASS::getAgility()
{
    getPlayerCount();
    sortm(members,player_count);
    Member * curr = members;
    if ( members == NULL)
    {
        return 0;
    }
    unsigned int minn = curr->player->getAgility();
    for ( unsigned int i = 0; (i<player_count) && curr ;i++ )
    {
        PLAYER_CLASS* mem = curr->player;
        if (mem && (mem->getAgility() < minn))minn = mem->getAgility();
        curr = curr->next_member;
    }
    return minn;
}
unsigned int SQUAD_CLASS::getDamage()
{
    getPlayerCount();
    sortm(members,player_count);
    Member * curr = members;
    unsigned int power = 0;
    for ( unsigned int i = 0;(i<player_count) && curr;i++ )
    {
        if ( curr->player) power+=curr->player->getDamage();
        curr = curr->next_member;
    }
    return power;
}
void SQUAD_CLASS::takeDamage(unsigned int damage)
{
    getPlayerCount();
    sortm(members,player_count);
    Member * curr = members;
    Member * prev = NULL;
    unsigned int dead = 0;
    for (unsigned  int i = 0;(i<player_count) && curr;i++ )
    {
        PLAYER_CLASS * player = curr->player;

        player->takeDamage(damage/player_count);

        prev = curr;
        curr = curr->next_member;
    }
    getPlayerCount();

}
bool SQUAD_CLASS::cmp(Member* f,Member * s)
{
    PLAYER_CLASS * first = f->player;
    PLAYER_CLASS * second = s->player;

    if (first->get_name() > second->get_name())return true;
    if ( first->get_name() < second->get_name())return false;

    if ( first->get_max_hp() > second->get_max_hp())return true;
    if (first->get_max_hp() < second->get_max_hp())return false;

    if (first->get_hp() > second->get_hp())return true;
    if (first->get_hp() < second->get_hp())return false;

    if ( first->getRemainingHealth() > second->getRemainingHealth()) return true;
    if (first->getRemainingHealth() < second->getRemainingHealth()) return false;

    if ( first->getDamage() > second->getDamage() )return true;
    if ( first->getDamage()  < second->getDamage() )return false;

    if ( first->getAgility() > second->getAgility())return true;
    if (first->getAgility() < second->getAgility())return false;

    if (first->getDefence() > second->getDefence()) return true;
    if ( first->getDefence() < second->getDefence()) return false;

    return false;

}
void SQUAD_CLASS::sortm(Member *& first_player, unsigned int count)
{
    Member * curr = first_player;
    Member * prev = NULL;
    for ( unsigned int i = 0;i<count;i++ )
    {
        PLAYER_CLASS* p = curr->player;
        while (p && curr->next_member) {
            Member * next = curr->next_member;
            if (cmp(curr,next)  ) {
                if (prev == NULL) {
                    members = next;
                    }
                else {
                    prev->next_member = next;
                }
                curr->next_member = next->next_member;
                next->next_member = curr;

                prev = next;
            }
            else {
                prev = curr;
                curr = curr->next_member;
            }
        }
    }
}
void SQUAD_CLASS::printParams()
{
    if ( getPlayerCount() == 0 || members == NULL)
    {
        cout<<name<<":nemo\n";
        alive = false;
        return;
    }
    sortm(members,player_count);
    cout<<name<<":"<<player_count<<":"<<getRemainingHealth()<<"%:"<<getDamage()<<":"<<getAgility()<<"\n";

    Member * curr = members;
    while (curr)
    {
        curr->player->printParams();
        curr = curr->next_member;
    }
}
void SQUAD_CLASS::addPlayer(PLAYER_CLASS* p)
{
    getPlayerCount();
    sortm(members,player_count);
    if ( p->getRemainingHealth() >0)
    {
        if ( player_count == 0)
        {
            alive = true;
            members = new Member();
            members ->player = p;
            members -> next_member = NULL;
            player_count++;
            return;
        }

        Member * curr = members;
        Member * prev = NULL;
        while (curr)
        {
            if ( curr->player == p)
            {
                return;
            }
            prev = curr;
            curr = curr->next_member;
        }
        if ( prev)
        {
            prev->next_member = new Member();
            prev->next_member->player = p;
            prev->next_member->next_member = NULL;
        }
        player_count++;
    }
}
unsigned int SQUAD_CLASS::getRemainingHealth()
{
    getPlayerCount();
    sortm(members,player_count);
    Member * curr = members;
    unsigned int remaining_health = 0;
    while ( curr)
    {
        PLAYER_CLASS* p = curr->player;
        if ( p ->getRemainingHealth() > remaining_health)remaining_health = p ->getRemainingHealth();

        curr = curr->next_member;
    }
    return remaining_health;

}
void SQUAD_CLASS::cure()
{
    getPlayerCount();
    sortm(members,player_count);
    Member * curr = members;
    while (curr)
    {
        PLAYER_CLASS* p = curr->player;
        p->cure();
        curr = curr->next_member;
    }

}
void SQUAD_CLASS::die()
{
    getPlayerCount();
    sortm(members,player_count);
    Member * curr = members;
    while (curr)
    {
        PLAYER_CLASS* p = curr->player;
        p->takeDamage(4294967295u);
        curr = curr->next_member;
    }
    player_count = 0;
    alive = false;
}
void SQUAD_CLASS::applyWinnerReward()
{
    getPlayerCount();
    sortm(members,player_count);
    Member * curr = members;
    while (curr)
    {
        PLAYER_CLASS* p = curr->player;
        p->applyWinnerReward();
        curr = curr->next_member;
    }
}
unsigned int CAESAR_CLASS::th_man = 0;
int ARENA_CLASS::attacks_count = 0;
int main() {
    CAESAR_CLASS caesar;
    ARENA_CLASS arena(&caesar);

    HUMAN_CLASS h1("Herkulio");
    HUMAN_CLASS h2("POTTER");
    HUMAN_CLASS h3( "GRANGER");
    HUMAN_CLASS h4("WEASLEY");
    HUMAN_CLASS h5("LOVEGOOD");
    HUMAN_CLASS h6("MOODY");
    HUMAN_CLASS h7("HAGRID");
    HUMAN_CLASS h8("GINNY");
    HUMAN_CLASS h9("SNAPE");

    SQUAD_CLASS hogwart("HarrySquad");
    BEAST_CLASS beast ("rudnik8888");
    caesar.judgeDeathOrLife(&beast);
    caesar.judgeDeathOrLife(&beast);

    hogwart.addPlayer(&h1);
    hogwart.addPlayer(&h2);
    hogwart.addPlayer(&h3);
    hogwart.addPlayer(&h4);
    hogwart.addPlayer(&h5);
    hogwart.addPlayer(&h6);
    hogwart.addPlayer(&h7);
    hogwart.addPlayer(&h8);
    hogwart.addPlayer(&h9);
    caesar.judgeDeathOrLife(&hogwart);
    hogwart.printParams();

}