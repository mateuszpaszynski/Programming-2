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
