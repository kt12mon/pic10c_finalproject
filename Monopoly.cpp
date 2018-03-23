#include "Monopoly.h"
#include <algorithm>
#include <fstream>

Monopoly::Monopoly()
:chance_drawn(0), community_drawn(0) {}

Monopoly::Monopoly(int x, int y)
:chance_drawn(0), community_drawn(0) {
	set_record();
	set_decks();
	std::random_shuffle(chance_deck.begin(), chance_deck.end());
	std::random_shuffle(community_deck.begin(), community_deck.end());
}

void Monopoly::set_decks(){
	std::ifstream fin;
	std::string card;
	int j(1);

	fin.open("chance.txt");
	while (!fin.eof()) {
		fin >> card;
		std::pair<int, std::string> a;
		a.first = j;
		a.second = card;
		chance_deck.push_back(a);
		j++;
	}
	fin.close();

	j = 1;

	fin.open("community.txt");
	while (!fin.eof()) {
		fin >> card;
		std::pair<int, std::string> a;
		a.first = j;
		a.second = card;
		community_deck.push_back(a);
		j++;
	}
	fin.close();
}

void Monopoly::set_record() {
	std::ifstream fin;
	std::string spots;
	int j(0);

	fin.open("monopolyboard.txt");
	while (!fin.eof()) {
		fin >> spots;
		std::pair<std::string, int> a;
		a.first = spots;
		a.second = 0;
		game_record.insert({ j, a });
		j++;
	}
}
