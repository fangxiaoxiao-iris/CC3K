#ifndef ITEM_H
#define ITEM_H
#include <string>
#include "square.h"

class Item: public Square {
	std::string itemType;
	int itemValue;
public:
	Item(int row, int col, char sym, char prev, GameBoard* theBoard);
	~Item();

	// getters:
	std::string getItemType() override;
	int getItemValue();

	//mutators:
	void setItemType(std::string type);
	void setItemValue(int value);
};

#endif
