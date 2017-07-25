#include <string>
#include "Gold.h"
using namespace std;

Gold::Gold(int row, int col, char sym, char prev, GameBoard* theBoard, 
	string type, int value, bool available):
Item(row, col, sym, prev, theBoard), available(available){
	setItemType(type);
	setItemValue(value);
}

Gold::~Gold(){}

void Gold::picked(PC &p) {
	int value = getItemValue();
	int p_cur_gold = p.getgold();
	int p_update_gold = p_cur_gold + value;
	p.setgold(p_update_gold);
	setSym('.');
	notifyBoard();
	cout << "You have picked up " << value << " piles of Gold!" << endl;
}

bool Gold::getavailable() {
	return available;
}

void Gold::setavailable(bool available) {
	this->available = available;
}
