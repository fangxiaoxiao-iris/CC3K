#include <string>
#include <cmath>
#include "Potion.h"
using namespace std;

Potion::Potion(int row, int col, char sym, char prev, GameBoard* theBoard, 
	string type): Item(row, col, sym, prev, theBoard){
	setItemType(type);
}

Potion::~Potion(){}

void Potion::used(PC &p) {
	string itemType = getItemType();
	string type = p.gettype();
	int p_cur_hp = p.gethp();
	int p_cur_atk = p.getatk();
	int p_cur_def = p.getdef();
	int p_max_hp = p.getmaxhp();
	int p_update_hp, p_update_atk, p_update_def;

	if (p.gettype() == "drow") {
		if (itemType == "RH") {
			p_update_hp = ((p_cur_hp + 10*1.5) <= p_max_hp) ? 
			(p_cur_hp + 10*1.5) : p_max_hp;
			p.sethp(p_update_hp);
			cout << "Your HP increases or already at maximum." << endl;
		} else if (itemType == "BA") {
			p_update_atk = ceil(p_cur_atk + 5*1.5);
			p.setatk(p_update_atk);
			cout << "Your Attack increases." << endl;
		} else if (itemType == "BD") {
			p_update_def = ceil(p_cur_def + 5*1.5);
			p.setdef(p_update_def);
			cout << "Your Defense increases." << endl;
		} else if (itemType == "PH") {
			p_update_hp = ((p_cur_hp - 10*1.5) >= 0) ? 
			(p_cur_hp - 10*1.5) : 0;
			p.sethp(p_update_hp);
			cout << "Your HP decreases." << endl;
		} else if (itemType == "WA") {
			p_update_atk = (ceil(p_cur_atk - 5*1.5) >= 0) ? 
			ceil(p_cur_atk - 5*1.5) : 0;
			p.setatk(p_update_atk);
			cout << "Your Attack decreases." << endl;
		} else if (itemType == "WD") {
			p_update_def = (ceil(p_cur_def - 5*1.5) >= 0) ? 
			ceil(p_cur_def - 5*1.5) : 0;
			p.setdef(p_update_def);
			cout << "Your Defense decreases." << endl;
		}
	} else {
		if (itemType == "RH") {
			p_update_hp = ((p_cur_hp + 10) <= p_max_hp) ? (p_cur_hp + 10) 
			: p_max_hp;
			p.sethp(p_update_hp);
			cout << "Your HP increases or already at maximum." << endl;
		} else if (itemType == "BA") {
			p_update_atk = p_cur_atk + 5;
			p.setatk(p_update_atk);
			cout << "Your Attack increases." << endl;
		} else if (itemType == "BD") {
			p_update_def = p_cur_def + 5;
			p.setdef(p_update_def);
			cout << "Your Defense increases." << endl;
		} else if (itemType == "PH") {
			p_update_hp = ((p_cur_hp - 10) >= 0) ? (p_cur_hp - 10) : 0;
			p.sethp(p_update_hp);
			cout << "Your HP decreases." << endl;
		} else if (itemType == "WA") {
			p_update_atk = ((p_cur_atk - 5) >= 0) ? (p_cur_atk - 5) : 0;
			p.setatk(p_update_atk);
			cout << "Your Attack decreases." << endl;
		} else if (itemType == "WD") {
			p_update_def = ((p_cur_def - 5) >= 0) ? (p_cur_def - 5) : 0;
			p.setdef(p_update_def);
			cout << "Your Defense decreases." << endl;
		}
	}

	setSym('.');
	notifyBoard();
}
