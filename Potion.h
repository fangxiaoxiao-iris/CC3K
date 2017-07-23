#ifndef POTION_H
#define POTION_H
#include <string>
#include "Item.h"
#include "PC.h"

class Potion: public Item {
public:
	Potion(int row, int col, char sym, char prev, GameBoard* theBoard, 
		std::string type);
	~Potion();
	void used(PC &P);
};

#endif
