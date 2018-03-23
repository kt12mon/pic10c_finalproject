
class Dice_roll {
public:
	Dice_roll();
	void roll();
	int get_total();
	bool get_doubles_status();

private:
	int total_roll;
	bool doubles_rolled;
};
