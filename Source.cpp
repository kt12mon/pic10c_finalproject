#include<iostream>
#include "Player.h"
#include<cstdlib>
#include<ctime>
#include<vector>


//OUR DICE FUNCTION. "ROLLS" TWO NUMBERS 
void taketurn(Player& P1) {
	Dice_roll D1;
	D1.roll();

	bool got_out_of_jail(true);  //declare bool, relevent if in jail
	bool sent_to_jail_from_dbls(false); //declare bool, relevent if rolling doubles

	if (P1.get_jail_status()){ //check in jail
		got_out_of_jail = P1.in_jail_rules(D1); //if in jail checks to see if get to get out

		if (got_out_of_jail) { //if got out, move, update, end turn
			P1.move_n(D1.get_total());
			P1.update_record();

			return;
		}
	}

	else {//if not in jail
		sent_to_jail_from_dbls = P1.roll_doubles_check(D1); //checks to see if roll sends u to jail
		if (sent_to_jail_from_dbls) { //if it does go to jail, update and end turn
			P1.update_record();
			return;
		}
		else { //if does not send to jail
			P1.move_n(D1.get_total()); //move based on roll
			P1.update_record(); //update tracker
			if (D1.get_doubles_status()) //checks to see if it was a double
				taketurn(P1); //if double go again recursively (turn has no ended)
			return;
		}
	}
	
}

int main() {
	srand(time(0));
	int simul_type(0);
	int num_of_turns(0);
	std::string response;
	Player player;

	std::cout << "Monte Carlo-esque simulation of Monopoly by Kevin Tran." << std::endl 
			  << "Limitations and constraints are detailed in README." << std::endl << std::endl;

	std::cout << "A Monte Carlo simulation (in layman terms) is a non-linear and often very difficult to parametrize event." << std::endl << std::endl;


	std::cout << "This is a simulation of the classic game of Monopoly." << std::endl
			  << "For details on rules and implementation of simulation refer to the README." << std::endl;

	std::cout << "What kind of simulation would you like to run:" << std::endl
		      << "1)Average Game 2)Central Limit Theorem (10000 turns) 3)Custom Cases" << std::endl
			  << "(Please select from 1, 2, 3)." << std::endl;

	std::cin >> simul_type;

	if (simul_type == 1)
		for (int i = 0; i < 75; i++)
			taketurn(player);

	if (simul_type == 2)
		for (int i = 0; i < 10000; i++)
			taketurn(player);

	if (simul_type == 3) {
		std::cout << "How many turns would you like to do? ";
		std::cin >> num_of_turns;
		for (int i = 0; i < num_of_turns; i++)
			taketurn(player);

	}

	player.export_table();

	std::cout << "Trials complete!" << std::endl;
	std::cout << "A .txt file has been produced with more detailed analysis." << std::endl
		      << "Would you like to see the stored journal (y/n)?" << std::endl;

	std::cin >> response;

	if (response == "y") {
		player.print_table();
	}

	

	return 0;
}
