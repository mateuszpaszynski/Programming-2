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

bool isAlive()
{
    return alive;
}
    virtual string get_name()
    {
        return "";
    }
    virtual unsigned int getDefence()
    {
        return 0;
    }
    unsigned int get_max_hp()
    {
        return max_hp;
    }
    unsigned int get_hp()
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
ARENA_CLASS::ARENA_CLASS(CAESAR_CLASS *caesar){
    this->caesar = *caesar;
}
void ARENA_CLASS::fight(PLAYER_CLASS* player1, PLAYER_CLASS*player2)
{

    if ( player1->isAlive() && player2->isAlive()){

        if (player1->getAgility()<player2->getAgility())
        {
            PLAYER_CLASS* temp = player2;
            player2 = player1;
            player1 = temp;
        }
        attacks_count = 0;
    player1->printParams();
    player2->printParams();
    int counter = 1;
    while (player1->getRemainingHealth() >= 10 && player2->getRemainingHealth() >= 10 )
    {
        //printf("turn: %d\n",counter);
        counter++;
        if ( ! player1->isAlive())break;
        player2->takeDamage(player1->getDamage());
        attacks_count++;
        player2->printParams();
        if (player2->getRemainingHealth() < 10)break;
        if (! player2->isAlive())break;
        player1->takeDamage(player2->getDamage());
        attacks_count++;
        player1->printParams();
        if ( player1->getRemainingHealth() < 10 || player2->getRemainingHealth() < 10 || attacks_count>=40)break;
    }
    if ( player1->isAlive())
    {
        player1->printParams();
        caesar.judgeDeathOrLife(player1);
    }

    if (player2->isAlive())
    {
        player2->printParams();
        caesar.judgeDeathOrLife(player2);

    }
    if ( player1->isAlive())
    {
        player1->applyWinnerReward();
        player1->cure();
    }
    if (player2->isAlive())
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
class CREEPER_CLASS : public PLAYER_CLASS {
private:
    std::string _name;

    unsigned int _health;
    unsigned int _max_health;
    unsigned int _attack;
    unsigned int _agility;

    bool _alive;

    static unsigned int _creepers_alive;

protected:
    void die();

public:
    CREEPER_CLASS(const std::string& player_name);
    virtual ~CREEPER_CLASS();

    unsigned int getRemainingHealth();
    unsigned int getDamage();
    unsigned int getAgility();

    void takeDamage(unsigned int damage_to_take);

    void applyWinnerReward();
    void cure();

    void printParams();

    //additional public methods
    virtual bool is_alive();

    //additional methods used for sorting
    virtual std::string get_name();
    virtual unsigned int get_health();
    virtual unsigned int get_max_health();
    virtual unsigned int get_defense();
};
unsigned int CREEPER_CLASS::_creepers_alive = 0;

CREEPER_CLASS::CREEPER_CLASS(const std::string& player_name) {
    this -> _name = player_name;

    this -> _health = 50;
    this -> _max_health = 50;
    this -> _attack = 10;
    this -> _agility = 10;

    this -> _alive = true;

    CREEPER_CLASS::_creepers_alive += 1;
}

CREEPER_CLASS::~CREEPER_CLASS() {
    this -> die();
}

unsigned int CREEPER_CLASS::getRemainingHealth() {
    return 100 * this -> _health / this -> _max_health;
}

unsigned int CREEPER_CLASS::getDamage() {
    return this -> _attack + CREEPER_CLASS::_creepers_alive;
}

unsigned int CREEPER_CLASS::getAgility() {
    return this -> _agility;
}

void CREEPER_CLASS::takeDamage(unsigned int damage_to_take) {
    if(damage_to_take < this -> _health) {
        this -> _health -= damage_to_take;
        return;
    }

    this -> _health = 0;
    this -> die();
}

void CREEPER_CLASS::applyWinnerReward() {
    this -> _attack += 2;
    this -> _agility += 2;
}

void CREEPER_CLASS::cure() {
    if(!(this -> _alive))
        return;

    this -> _health = this -> _max_health;
}

void CREEPER_CLASS::die() {
    if(!(this -> _alive))
        return; //already dead

    this -> _alive = false;
    this -> _health = 0;

    CREEPER_CLASS::_creepers_alive -= 1;
}

void CREEPER_CLASS::printParams() {
    if(!(this -> _alive)) {
        std::cout << this -> _name << ":R.I.P." << std::endl;

        return;
    }

    std::cout << this -> _name << ":" << this -> _max_health << ":" << this -> _health << ":" << this -> getRemainingHealth() << "%:" << this -> getDamage() << ":" << this -> getAgility() << ":" << CREEPER_CLASS::_creepers_alive << std::endl;
}

bool CREEPER_CLASS::is_alive() {
    return this -> _alive;
}

std::string CREEPER_CLASS::get_name() {
    return this -> _name;
}

unsigned int CREEPER_CLASS::get_health() {
    return this -> _health;
}

unsigned int CREEPER_CLASS::get_max_health() {
    return this -> _max_health;
}
unsigned int CREEPER_CLASS::get_defense() {
    return 0;
}