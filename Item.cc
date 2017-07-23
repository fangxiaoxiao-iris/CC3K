#include <string>
#include "Item.h"
using namespace std;

Item::Item(int row, int col, char sym, char prev, GameBoard* theBoard): 
Square(row, col, sym, prev, theBoard), itemType(""), itemValue(0){}

Item::~Item(){}

string Item::getItemType() {
	return itemType;
}

int Item::getItemValue() {
	return itemValue;
}

void Item::setItemType(string type) {
	itemType = type;
}

void Item::setItemValue(int value) {
	itemValue = value;
}
