#include<vector>
#include<utility>
#include<string>
#include<map>

class Monopoly {
public:
	Monopoly();
	Monopoly(int x, int y);
	void set_decks();
	void set_record();

protected:
	int chance_drawn;
	int community_drawn;
	std::vector<std::pair<int, std::string>> chance_deck;
	std::vector<std::pair<int, std::string>> community_deck;
	std::map<int, std::pair<std::string, int>> game_record;

};