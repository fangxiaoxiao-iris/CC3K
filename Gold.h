#ifndef GOLD_H
#define GOLD_H
#include <string>
#include "Item.h"
#include "PC.h"

class Gold: public Item {
	bool available;
public:
	Gold(int row, int col, char sym, char prev, GameBoard* theBoard,
		std::string type, int value, bool available);
	~Gold();
	void picked(PC &P);
	bool getavailable();
	void setavailable(bool available) override;
};

#endif
