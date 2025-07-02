class SQUAD_CLASS : public PLAYER_CLASS
{
protected:
    string name;
    unsigned int remaining_health;
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
        Member* next;
        while (current)
        {
            next = current->next_member;
            delete current;
            current = next;
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
    for ( unsigned int i = 0; (i < player_count) &&(p) ; i++ )
    {
        if ( p->player->get_hp() > 0)
        {
            undead++;
            prev = p;
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
        }
        p = p->next_member;

    }
    player_count = undead;
    if ( undead == 0)alive = false;
    return undead;
}
string SQUAD_CLASS::get_name()
{
    return name;
}
SQUAD_CLASS::SQUAD_CLASS(string name)
{
    this->name = name;
    members = NULL;
    remaining_health = 0;
    player_count = 0;
    attack_power = 0;
    alive = true;
    hp = 10e6;
}
unsigned int SQUAD_CLASS::getAgility()
{
    getPlayerCount();
    Member * curr = members;
    if ( members == NULL)
    {
        return 0;
    }
    unsigned int minn = curr->player->getAgility();
    for ( unsigned int i = 0; (i<player_count) && curr ;i++ )
    {
        PLAYER_CLASS* mem = curr->player;
        if (mem && mem->getAgility() < minn)minn = mem->getAgility();
        curr = curr->next_member;
    }
    return minn;
}
unsigned int SQUAD_CLASS::getDamage()
{
    getPlayerCount();
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
    Member * curr = members;
    Member * prev = NULL;
    unsigned int dead = 0;
    for (unsigned  int i = 0;(i<player_count) && curr;i++ )
    {
        PLAYER_CLASS * player = curr->player;
        if ( !player)return;
        player->takeDamage(damage/player_count);

        if (! player->isAlive())
        {
            if ( prev == NULL )
            {
                members= curr->next_member;

            }
            else
            {
                prev->next_member = curr->next_member;
            }

            dead++;
        }
        prev = curr;
        curr = curr->next_member;
    }
    player_count -= dead;

}
bool SQUAD_CLASS::cmp(Member* f,Member * s)
{
    PLAYER_CLASS * first = f->player;
    PLAYER_CLASS * second = s->player;

    if (first->get_name() > second->get_name())return true;
    if ( first->get_name() < second->get_name())return false;

    if ( first->get_max_hp() > second->get_max_hp())return true;
    if (first->get_max_hp() > second->get_max_hp())return false;

    if (first->get_hp() > second->get_hp())return true;
    if (first->get_hp() < second->get_hp())return false;

    if ( first->getRemainingHealth() > second->getRemainingHealth()) return true;
    if (first->getRemainingHealth() < second->getRemainingHealth()) return false;

    if ( first->getDamage() > second->getDamage() )return true;
    if ( first->getDamage()  < second->getDamage() )return false;

    if ( first->getAgility() > second->getAgility())return true;
    if (first->getAgility() < second->getAgility())return false;

    if ( first->getDefence() > second->getDefence() )return true;
    if ( first->getDefence() < second->getDefence() )return false;

    return false;

}
void SQUAD_CLASS::sortm(Member *& first_player, unsigned int player_count)
{
    Member * curr = first_player;
    Member * prev = NULL;
    for ( unsigned int i = 0;i<player_count;i++ )
    {
        PLAYER_CLASS* p = curr->player;
        while (p && curr->next_member) {
            //cout<<curr->next_player->get_name()<<endl;
            Member * next = curr->next_member;
            if (cmp(curr,next)  ) {
                if (prev == NULL) {
                    members = next;
                    //cout<<first_player->next_player->get_name()<<endl;
                    //return;
                }
                else {
                    prev->next_member = next;
                }
                curr->next_member = next->next_member;
                next->next_member = curr;


                // Po zamianie, prev wskazuje na next
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
    if ( player_count == 0 || members == NULL)
    {
        cout<<name<<":nemo\n";
        return;
    }
    cout<<name<<":"<<player_count<<":"<<getRemainingHealth()<<"%:"<<getDamage()<<":"<<getAgility()<<"\n";
    sortm(members,player_count);
    Member * curr = members;
    while (curr)
    {
        curr->player->printParams();
        curr = curr->next_member;
    }
}
void SQUAD_CLASS::addPlayer(PLAYER_CLASS* p)
{
    if ( p->get_hp()>0)
    {
        if ( player_count == 0)
        {
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
                return ;
            }
            prev = curr;
            curr = curr->next_member;
        }
        prev->next_member = new Member();
        prev->next_member->player = p;
        prev->next_member->next_member = NULL;

        player_count++;

    }

}
unsigned int SQUAD_CLASS::getRemainingHealth()
{
    getPlayerCount();
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
    Member * curr = members;
    while (curr)
    {
        PLAYER_CLASS* p = curr->player;
        p->applyWinnerReward();
        curr = curr->next_member;
    }
}
unsigned int SQUAD_CLASS::health()
{
    return hp;
}