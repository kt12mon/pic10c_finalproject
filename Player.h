#include <unordered_map>
#include <string>
#include <utility>
#include "Dice.h"

class Player{
public:
	Player();
	bool get_jail_status();
	int get_position();
	void init_record(); //initaites a clear record
	void move_n(int n); //moving function
	bool in_jail_rules(Dice_roll roll);
	bool roll_doubles_check(Dice_roll roll);
	void update_record(); //updates space tracking
	void print_table();
	void export_table();

private:
	//private functions
	void landed_chance(); //function for landing on chance
	void landed_community(); //function for landing community

//variables
	int position; //goes from 0 to 39
	bool in_jail;
	int double_count;
	int doubles_attempted;
	std::unordered_map<int, std::pair<std::string, int>> game_record;
};