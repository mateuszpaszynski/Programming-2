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
