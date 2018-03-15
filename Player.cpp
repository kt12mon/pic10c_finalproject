#include "Player.h"
#include <fstream>
#include <iostream>

Player::Player()
	:position(0), in_jail(0), double_count(0), doubles_attempted(0) {}

void Player::move_n(int n) {
	position += n;
	if (position > 39) //restarts cycle past index 39
		position -= 40;
	if (position == 30) //lands on go to jail (go_to_jail should never have a count)
	{
		position = 10;
		in_jail = true;
	}
	this->landed_chance();
	this->landed_community();
}

int Player::get_position() {
	return position;
}

bool Player::get_jail_status() {
	return in_jail;
}

void Player::init_record() {
	std::ifstream fin;
	std::string spots;
	int i(0);

	fin.open("monopolyboard.txt");
	while (!fin.eof()) {
		fin >> spots;
		std::pair<std::string, int> a;
		a.first = spots;
		a.second = 0;
		game_record.insert({ i, a });
		i++;
	}
}

void Player::update_record() {
	game_record[position].second = game_record[position].second+1;
}

void Player::landed_chance() {   //hard coding this cause it's easier
	if (position == 7 || position == 2 || position == 36) {
		int card_drawn = rand() % 16;
		if (card_drawn == 1)
			position = 0;
		if (card_drawn == 2)
			position = 24;
		if (card_drawn == 3)
			position = 11;
		if (card_drawn == 4) {
			if (position == 8 || position == 37)
				position = 12;
			if (position == 23)
				position = 28;
		}
		if (card_drawn == 5) {
			if (position == 8)
				position = 15;
			if (position == 23)
				position = 25;
			if (position == 37)
				position = 5;
		}
		if (card_drawn == 6)
			position = 5;
		if (card_drawn == 7)
			position = 39;
		if (card_drawn == 8) {
			position = 10;
			in_jail = true;
		}
		if (card_drawn == 9)
			position -= 3;
	}
}

void Player::landed_community() {
	if(position== 2 || position == 17 || position == 33){
		int card_drawn = rand() % 17;
		if (card_drawn == 1)
			position = 0;
		if (card_drawn == 2) {
			position = 10;
			in_jail = true;
		}
	}
}

bool Player::roll_doubles_check(Dice_roll roll) {
	if (roll.get_doubles_status()) {
		double_count++;
		if (double_count == 3) {
			position = 10;
			in_jail = true;
			double_count = 0;
			return true;
		}
		else
			return false;
	}
	else {
		double_count = 0;
		return false;
	}
}

bool Player::in_jail_rules(Dice_roll roll) {
	if (roll.get_doubles_status()) {
		in_jail = false;
		doubles_attempted = 0;
		return true;
	}
	else if (doubles_attempted == 2) {
		in_jail = false;
		doubles_attempted = 0;
		return true;
	}
	else {
		doubles_attempted++;
		return false;
	}
}

void Player::print_table() {
	for (int i = 0; i < 40; i++) {
		std::cout << i+1 << ". " << game_record[i].first << " was landed on " << game_record[i].second << " times." << std::endl;
	}
}

void Player::export_table() {
	std::ofstream fout;
	fout.open("Data.txt");
	fout << "SpotNum" << "\t" << "SpotName" << "\t" << "TimesLand" << std::endl;
	for (int i = 0; i < 40; i++)
		fout << i + 1 << "\t" << game_record[i].first << "\t" << game_record[i].second << std::endl;
	fout.close();
}