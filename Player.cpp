#include "Player.h"
#include <fstream>
#include <iostream>

Player::Player()
	:position(0), in_jail(false), double_count(0), doubles_attempted(0), Monopoly(0,0) {}

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

void Player::update_record() {
	game_record[position].second = game_record[position].second+1;
}

void Player::landed_chance() {   //hard coding this cause it's easier
	if (position == 7 || position == 22 || position == 36) {
		std::pair<int, std::string> card_drawn = chance_deck[chance_drawn];
		chance_drawn++;
		if (chance_drawn > 16)
			chance_drawn = 0;
		if (card_drawn.first == 1) {
			position = 0;
			return;
		}
		if (card_drawn.first == 2) {
			position = 24;
			return;
		}
		if (card_drawn.first == 3) {
			position = 11;
			return;
		}
		if (card_drawn.first == 4) {
			if (position == 8 || position == 37)
				position = 12;
			if (position == 23)
				position = 28;
			return;
		}
		if (card_drawn.first == 5 || card_drawn.first == 16) {
			if (position == 8)
				position = 15;
			if (position == 23)
				position = 25;
			if (position == 37)
				position = 5;
			return;
		}
		if (card_drawn.first == 6) {
			position = 5;
			return;
		}
		if (card_drawn.first == 7) {
			position = 39;
			return;
		}
		if (card_drawn.first == 8) {
			position = 10;
			in_jail = true;
			return;
		}
		if (card_drawn.first == 9) {
			position -= 3;
			return;
		}
	}
	}

void Player::landed_community() {
	if(position== 2 || position == 17 || position == 33){
		std::pair<int, std::string> card_drawn = community_deck[community_drawn];
		community_drawn++;
		if (community_drawn > 16)
			community_drawn = 0;
		if (card_drawn.first == 1) {
			position = 0;
			return;
		}
		if (card_drawn.first == 2) {
			position = 10;
			in_jail = true;
			return;
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
	for (auto it = game_record.begin(); it != game_record.end(); ++it) {
		std::cout << it->first+1 << ". " << it->second.first << " was landed on " << it->second.second << " times." << std::endl;
	}
	std::cout << game_record.begin()->first << " " << game_record.begin()->second.second;
}

void Player::export_table() {
	std::ofstream fout;
	fout.open("Data.txt");
	fout << "SpotNum" << "\t" << "SpotName" << "\t" << "TimesLand" << std::endl;
	
	for (auto it = game_record.begin(); it != game_record.end(); ++it)
		fout << it->first +1<< "\t" << it->second.first << "\t" << it->second.second << std::endl;
	fout.close();
}