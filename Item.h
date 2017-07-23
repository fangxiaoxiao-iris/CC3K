#ifndef ITEM_H
#define ITEM_H
#include <string>

class Item: public Square {
	std::string itemType;
	std::int itemValue;
public:
	Item();
	~Item();

	// getters:
	std::string getItemType();
	int getItemValue();

	//mutators:
	void setItemType(std::string type);
	void setItemValue(int value);
}

#endif