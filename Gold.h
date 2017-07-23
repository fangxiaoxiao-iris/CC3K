#ifndef GOLD_H
#define GOLD_H
#include <string>

class Gold: public Item {
public:
	Gold(int row, int col, char sym, char prev, GameBoard* theBoard,
		std::string type, int value);
	~Gold();
	void picked(PC &P);
}

#endif
