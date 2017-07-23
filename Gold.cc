#include <string>
#include "Gold.h"
using namespace std;

Gold::Gold(string type, int value):Item(){
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
}
