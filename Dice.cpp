#include "Dice.h"
#include <cstdlib>
#include <ctime>

Dice_roll::Dice_roll() {
	total_roll = 0;
	doubles_rolled = false;
}

void Dice_roll::roll() {
	int D1 = rand() % 7;
	int D2 = rand() % 7;
	total_roll = D1 + D2;
	doubles_rolled = (D1 == D2);
}

int Dice_roll::get_total() {
	return total_roll;
}

bool Dice_roll::get_doubles_status(){
	return doubles_rolled;
}