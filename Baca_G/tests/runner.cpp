#include <iostream>
#include <string>

#include "include/new_delete_overrides.hpp"

#include "source.cpp"

#include "include/memory_manager.hpp"
#include "include/creeper.hpp"
#include "helpers/creeper.cpp"

#include <cstdio>
#include <climits>
#include <map>
#include <iterator>
#include <vector>
#include <sstream>
#include <unistd.h>
#include <cctype>
#include <algorithm>

PLAYER_CLASS* find_player(const std::string& player_name, std::map<std::string, HUMAN_CLASS*>& humans, std::map<std::string, BEAST_CLASS*>& beasts, std::map<std::string, BERSERKER_CLASS*>& berserkers, std::map<std::string, CREEPER_CLASS*>& creepers, std::map<std::string, SQUAD_CLASS*>& squads) {

	if(humans[player_name] != NULL)
		return humans[player_name];

	if(beasts[player_name] != NULL)
		return beasts[player_name];

	if(berserkers[player_name] != NULL)
		return berserkers[player_name];

	if(creepers[player_name] != NULL)
		return creepers[player_name];

	if(squads[player_name] != NULL)
		return squads[player_name];

	return NULL;
}

SQUAD_CLASS* find_squad(const std::string& squad_name, std::map<std::string, SQUAD_CLASS*>& squads) {
	return squads[squad_name];
}

std::vector<std::string> split_words(const std::string& input) {
	std::istringstream iss(input);
	std::vector<std::string> words;
	std::string word;

	while (iss >> word)
		words.push_back(word);

	return words;
}

char to_upper_char(char c) {
	return std::toupper((unsigned char)c);
}

void run() {
	std::map<std::string, HUMAN_CLASS*> humans;
	std::map<std::string, BEAST_CLASS*> beasts;
	std::map<std::string, BERSERKER_CLASS*> berserkers;
	std::map<std::string, CREEPER_CLASS*> creepers;
	std::map<std::string, SQUAD_CLASS*> squads;

	unsigned int human_counter = 0;
	unsigned int beast_counter = 0;
	unsigned int berserker_counter = 0;
	unsigned int creeper_counter = 0;
	unsigned int squad_counter = 0;

	CAESAR_CLASS* caesar = new CAESAR_CLASS();
	ARENA_CLASS* arena = new ARENA_CLASS(caesar);

	const bool is_connected_to_console = isatty(STDIN_FILENO);

	while(true) {
		if(is_connected_to_console)
			std::cout << ">>> ";

		std::string operation = *std::istream_iterator<std::string>(std::cin);

		if(operation[0] == '#') {
			//read comment and skip
			std::string comment;
			std::getline(std::cin, comment);

			if(!is_connected_to_console)
				std::cout << operation << comment << std::endl;

			continue;
		}

		std::transform(operation.begin(), operation.end(), operation.begin(), to_upper_char);

		if(operation == "HUMAN") {
			std::string names;
			std::getline(std::cin, names);

			const std::vector<std::string> human_names = split_words(names);

			for(unsigned int i = 0; i < human_names.size(); i += 1) {
				const std::string& human_name = human_names[i];

				if(humans[human_name] != NULL) {
					std::cout << "HUMAN " << human_name << " ALREADY EXISTS" << std::endl;
					continue;
				}

				HUMAN_CLASS* new_human = new HUMAN_CLASS(human_name);

				humans[human_name] = new_human;
				human_counter += 1;
			}

			continue;
		}

		if(operation == "BEAST") {
			std::string names;
			std::getline(std::cin, names);

			const std::vector<std::string> beast_names = split_words(names);

			for(unsigned int i = 0; i < beast_names.size(); i += 1) {
				const std::string& beast_name = beast_names[i];

				if(beasts[beast_name] != NULL) {
					std::cout << "BEAST " << beast_name << " ALREADY EXISTS" << std::endl;
					continue;
				}

				BEAST_CLASS* new_beast = new BEAST_CLASS(beast_name);

				beasts[beast_name] = new_beast;
				beast_counter += 1;
			}

			continue;
		}

		if(operation == "BERSERKER") {
			std::string names;
			std::getline(std::cin, names);

			const std::vector<std::string> berserker_names = split_words(names);

			for(unsigned int i = 0; i < berserker_names.size() / 2; i += 1) {
				const std::string& human_name = berserker_names[2 * i];
				const std::string& beast_name = berserker_names[2 * i + 1];
				const std::string berserker_name = human_name + "-" + beast_name;

				if(berserkers[berserker_name] != NULL) {
					std::cout << "BERSERKER " << berserker_name << " ALREADY EXISTS" << std::endl;
					continue;
				}

				BERSERKER_CLASS* new_berserker = new BERSERKER_CLASS(human_name, beast_name);

				berserkers[berserker_name] = new_berserker;
				berserker_counter += 1;
			}

			continue;
		}

		if(operation == "CREEPER") {
			std::string names;
			std::getline(std::cin, names);

			const std::vector<std::string> creeper_names = split_words(names);

			for(unsigned int i = 0; i < creeper_names.size(); i += 1) {
				const std::string& creeper_name = creeper_names[i];

				if(creepers[creeper_name] != NULL) {
					std::cout << "CREEPER " << creeper_name << " ALREADY EXISTS" << std::endl;
					continue;
				}

				CREEPER_CLASS* new_creeper = new CREEPER_CLASS(creeper_name);

				creepers[creeper_name] = new_creeper;
				creeper_counter += 1;
			}

			continue;
		}

		if(operation == "SQUAD") {
			std::string names;
			std::getline(std::cin, names);

			const std::vector<std::string> squad_names = split_words(names);

			for(unsigned int i = 0; i < squad_names.size(); i += 1) {
				const std::string& squad_name = squad_names[i];

				if(squads[squad_name] != NULL) {
					std::cout << "SQUAD " << squad_name << " ALREADY EXISTS" << std::endl;
					continue;
				}

				SQUAD_CLASS* new_squad = new SQUAD_CLASS(squad_name);

				squads[squad_name] = new_squad;
				squad_counter += 1;
			}

			continue;
		}

		if(operation == "PRINT") {
			std::string names;
			std::getline(std::cin, names);

			const std::vector<std::string> player_names = split_words(names);

			for(unsigned int i = 0; i < player_names.size(); i += 1) {
				const std::string& player_name = player_names[i];

				PLAYER_CLASS* player = find_player(player_name, humans, beasts, berserkers, creepers, squads);

				if(player == NULL) {
					std::cout << "PLAYER " << player_name << " DOES NOT EXIST" << std::endl;
					continue;
				}

				player -> printParams();
			}

			continue;
		}

		if(operation == "HEALTH") {
			const std::string player_name = *std::istream_iterator<std::string>(std::cin);

			PLAYER_CLASS* player = find_player(player_name, humans, beasts, berserkers, creepers, squads);

			if(player == NULL) {
				std::cout << "PLAYER " << player_name << " DOES NOT EXIST" << std::endl;
				continue;
			}

			std::cout << player_name << ": " << player -> getRemainingHealth() << "% health" << std::endl;

			continue;
		}

		if(operation == "ATTACK") {
			const std::string player_name = *std::istream_iterator<std::string>(std::cin);

			PLAYER_CLASS* player = find_player(player_name, humans, beasts, berserkers, creepers, squads);

			if(player == NULL) {
				std::cout << "PLAYER " << player_name << " DOES NOT EXIST" << std::endl;
				continue;
			}

			std::cout << player_name << ": " << player -> getDamage() << " attack" << std::endl;

			continue;
		}

		if(operation == "AGILITY") {
			const std::string player_name = *std::istream_iterator<std::string>(std::cin);

			PLAYER_CLASS* player = find_player(player_name, humans, beasts, berserkers, creepers, squads);

			if(player == NULL) {
				std::cout << "PLAYER " << player_name << " DOES NOT EXIST" << std::endl;
				continue;
			}

			std::cout << player_name << ": " << player -> getAgility() << " agility" << std::endl;

			continue;
		}

		if(operation == "DAMAGE") {
			const unsigned int damage_to_take = *std::istream_iterator<unsigned int>(std::cin);
			std::string names;
			std::getline(std::cin, names);

			const std::vector<std::string> player_names = split_words(names);

			for(unsigned int i = 0; i < player_names.size(); i += 1) {
				const std::string& player_name = player_names[i];

				PLAYER_CLASS* player = find_player(player_name, humans, beasts, berserkers, creepers, squads);

				if(player == NULL) {
					std::cout << "PLAYER " << player_name << " DOES NOT EXIST" << std::endl;
					continue;
				}

				player -> takeDamage(damage_to_take);
			}

			continue;
		}

		if(operation == "REWARD") {
			const unsigned int multiplier = *std::istream_iterator<unsigned int>(std::cin);
			std::string names;
			std::getline(std::cin, names);

			const std::vector<std::string> player_names = split_words(names);

			for(unsigned int i = 0; i < player_names.size(); i += 1) {
				const std::string& player_name = player_names[i];

				PLAYER_CLASS* player = find_player(player_name, humans, beasts, berserkers, creepers, squads);

				if(player == NULL) {
					std::cout << "PLAYER " << player_name << " DOES NOT EXIST" << std::endl;
					continue;
				}

				for(unsigned int j = 0; j < multiplier; j += 1)
					player -> applyWinnerReward();
			}

			continue;
		}

		if(operation == "CURE") {
			std::string names;
			std::getline(std::cin, names);

			const std::vector<std::string> player_names = split_words(names);

			for(unsigned int i = 0; i < player_names.size(); i += 1) {
				const std::string& player_name = player_names[i];

				PLAYER_CLASS* player = find_player(player_name, humans, beasts, berserkers, creepers, squads);

				if(player == NULL) {
					std::cout << "PLAYER " << player_name << " DOES NOT EXIST" << std::endl;
					continue;
				}

				player -> cure();
			}

			continue;
		}

		if(operation == "KILL") {
			std::string names;
			std::getline(std::cin, names);

			const std::vector<std::string> player_names = split_words(names);

			for(unsigned int i = 0; i < player_names.size(); i += 1) {
				const std::string& player_name = player_names[i];

				PLAYER_CLASS* player = find_player(player_name, humans, beasts, berserkers, creepers, squads);

				if(player == NULL) {
					std::cout << "PLAYER " << player_name << " DOES NOT EXIST" << std::endl;
					continue;
				}

				for(unsigned int j = 0; j < 10000; j += 1)
					player -> takeDamage(UINT_MAX);
			}

			continue;
		}

		if(operation == "JUDGE") {
			std::string names;
			std::getline(std::cin, names);

			const std::vector<std::string> player_names = split_words(names);

			for(unsigned int i = 0; i < player_names.size(); i += 1) {
				const std::string& player_name = player_names[i];

				PLAYER_CLASS* player = find_player(player_name, humans, beasts, berserkers, creepers, squads);

				if(player == NULL) {
					std::cout << "PLAYER " << player_name << " DOES NOT EXIST" << std::endl;
					continue;
				}

				caesar -> judgeDeathOrLife(player);
			}

			continue;
		}

		if(operation == "ADD") {
			const std::string squad_name = *std::istream_iterator<std::string>(std::cin);
			std::string names;
			std::getline(std::cin, names);

			SQUAD_CLASS* squad = find_squad(squad_name, squads);
			if(squad == NULL) {
				std::cout << "SQUAD " << squad_name << " DOES NOT EXIST" << std::endl;
				continue;
			}

			const std::vector<std::string> player_names = split_words(names);

			for(unsigned int i = 0; i < player_names.size(); i += 1) {
				const std::string& player_name = player_names[i];

				PLAYER_CLASS* player = find_player(player_name, humans, beasts, berserkers, creepers, squads);

				if(player == NULL) {
					std::cout << "PLAYER " << player_name << " DOES NOT EXIST" << std::endl;
					continue;
				}

				squad -> addPlayer(player);
			}

			continue;
		}

		if(operation == "FIGHT") {
			const std::string player_one_name = *std::istream_iterator<std::string>(std::cin);
			const std::string player_two_name = *std::istream_iterator<std::string>(std::cin);

			PLAYER_CLASS* player_one = find_player(player_one_name, humans, beasts, berserkers, creepers, squads);
			PLAYER_CLASS* player_two = find_player(player_two_name, humans, beasts, berserkers, creepers, squads);

			if(player_one == NULL) {
				std::cout << "PLAYER " << player_one_name << " DOES NOT EXIST" << std::endl;
				continue;
			}

			if(player_two == NULL) {
				std::cout << "PLAYER " << player_two_name << " DOES NOT EXIST" << std::endl;
				continue;
			}

			std::cout << "BEGIN FIGHT " << player_one_name << " WITH " << player_two_name << std::endl;

			arena -> fight(player_one, player_two);

			continue;
		}

		if(operation == "LIST") {
			if(human_counter > 0) {
				std::cout << "Human(s):" << std::endl;
				for(std::map<std::string, HUMAN_CLASS* >::const_iterator it = humans.begin(); it != humans.end(); it++)
					if(it -> second != NULL)
						std::cout << "  - " << it -> first << std::endl;
			}

			if(beast_counter > 0) {
				std::cout << "Beast(s):" << std::endl;
				for(std::map<std::string, BEAST_CLASS* >::const_iterator it = beasts.begin(); it != beasts.end(); it++)
					if(it -> second != NULL)
						std::cout << "  - " << it -> first << std::endl;
			}

			if(berserker_counter > 0) {
				std::cout << "Berserker(s):" << std::endl;
				for(std::map<std::string, BERSERKER_CLASS* >::const_iterator it = berserkers.begin(); it != berserkers.end(); it++)
					if(it -> second != NULL)
						std::cout << "  - " << it -> first << std::endl;
			}

			if(creeper_counter > 0) {
				std::cout << "Creeper(s):" << std::endl;
				for(std::map<std::string, CREEPER_CLASS* >::const_iterator it = creepers.begin(); it != creepers.end(); it++)
					if(it -> second != NULL)
						std::cout << "  - " << it -> first << std::endl;
			}

			if(squad_counter > 0) {
				std::cout << "Human(s):" << std::endl;
				for(std::map<std::string, SQUAD_CLASS* >::const_iterator it = squads.begin(); it != squads.end(); it++)
					if(it -> second != NULL)
						std::cout << "  - " << it -> first << std::endl;
			}

			continue;
		}

		if(operation == "LARRY") {
			std::cout << "LARRY WILL FIND YOU IN YOUR SLEEP" << std::endl;
			continue;
		}

		if(operation == "HELP") {
			std::cout << "Available operations:" << std::endl;
			std::cout << std::endl;
			std::cout << "  Declare new entities:" << std::endl;
			std::cout << "   - HUMAN <name1> <name2> ... - declare new human(s)" << std::endl;
			std::cout << "   - BEAST <name1> <name2> ... - declare new beast(s)" << std::endl;
			std::cout << "   - CREEPER <name1> <name2> ... - declare new creeper(s)" << std::endl;
			std::cout << "   - SQUAD <name1> <name2> ... - declare new squad(s)" << std::endl;
			std::cout << "   - BERSERKER <human name 1> <beast name 1> <human name 2> <beast name 2> ... - declare new berserker(s)" << std::endl;
			std::cout << std::endl;
			std::cout << "  Berserker name specified for operations is <human name>-<beast name>, so to print berserker with human name 'harold' and beast name 'bunny' type 'PRINT harold-bunny'" << std::endl;
			std::cout << std::endl;
			std::cout << "  Properties getters:" << std::endl;
			std::cout << "   - HEALTH <player name> - calls getRemainingHealth() on the player" << std::endl;
			std::cout << "   - AGILITY <player name> - calls getAgility() on the player" << std::endl;
			std::cout << "   - ATTACK <player name> - calls getDamage() on the player" << std::endl;
			std::cout << "   - PRINT <player name 1> <player name 2> ... - calls printParams() on the player(s)" << std::endl;
			std::cout << std::endl;
			std::cout << "  Player actions:" << std::endl;
			std::cout << "   - DAMAGE [int] <player1> <player2> ... - calls takeDamage(int) on every player specified" << std::endl;
			std::cout << "   - REWARD [int] <player1> <player2> ... - calls applyWinnerReward() on every player specified int times" << std::endl;
			std::cout << "   - CURE <player1> <player2> ... - calls cure() on every player specified" << std::endl;
			std::cout << "   - KILL <player1> <player2> ... - kills every player specified" << std::endl;
			std::cout << "   - JUDGE <player1> <player2> ... - calls caesar.judgeDeathOrLife(PLAYER) on every player specified sequentially" << std::endl;
			std::cout << std::endl;
			std::cout << "  Squad actions:" << std::endl;
			std::cout << "   - ADD [squad name] <player1> <player2> ... - on the specified squad calls addPlayer(PLAYER) sequentially" << std::endl;
			std::cout << std::endl;
			std::cout << "  Arena actions:" << std::endl;
			std::cout << "   - FIGHT <player1> <player2> - begin fight between player1 and player2" << std::endl;
			std::cout << std::endl;
			std::cout << "  Program action:" << std::endl;
			std::cout << "   - LIST - lists all entities" << std::endl;
			std::cout << "   - HELP - prints this message" << std::endl;
			std::cout << "   - EXIT - frees all memory allocated to objects and exits" << std::endl;
			std::cout << std::endl;
			continue;
		}

		if(operation == "QUIT" || operation == "EXIT" || operation == "END") {
			for(std::map<std::string, SQUAD_CLASS* >::const_iterator it = squads.begin(); it != squads.end(); it++)
				delete it -> second;

			for(std::map<std::string, HUMAN_CLASS* >::const_iterator it = humans.begin(); it != humans.end(); it++)
				delete it -> second;

			for(std::map<std::string, BEAST_CLASS* >::const_iterator it = beasts.begin(); it != beasts.end(); it++)
				delete it -> second;

			for(std::map<std::string, BERSERKER_CLASS* >::const_iterator it = berserkers.begin(); it != berserkers.end(); it++)
				delete it -> second;

			for(std::map<std::string, CREEPER_CLASS* >::const_iterator it = creepers.begin(); it != creepers.end(); it++)
				delete it -> second;

			delete arena;
			delete caesar;

			return;
		}

		std::cout << "ERROR UNKNOWN OPERATION" << std::endl << "TYPE HELP TO GET AVAILABLE OPERTAIONS" << std::endl;
		getline(std::cin, operation);
	}
}

int main() {
	run(); //so that objects allocated on stack in run() will be freed and report_leaks won't falsly claim leaks

	return memory_manager::report_leaks();
}
