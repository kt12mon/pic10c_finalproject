#include "Dice.h"
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

Dice_roll::Dice_roll() {
	total_roll = 0;
	doubles_rolled = false;
}

void Dice_roll::roll() {
	std::vector<int> faces = { 1,1,2,2,3,3,4,4,5,5,6,6 };
	std::random_shuffle(faces.begin(), faces.end());
	int D1 = faces[0];
	int D2 = faces[1];
	total_roll = D1 + D2;
	doubles_rolled = (D1 == D2);
}

int Dice_roll::get_total() {
	return total_roll;
}

bool Dice_roll::get_doubles_status(){
	return doubles_rolled;
}