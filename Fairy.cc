#include <string>
#include <cmath>
#include "Fairy.h"
using namespace std;

Fairy::Fairy(int row, int col, char sym, char prev, GameBoard* theBoard): 
PC(row, col, sym, prev, theBoard) {
	sethp(130);
	setatk(15);
	setdef(30);
	setmaxhp(130);
	settype("Fairy");
}

Fairy::~Fairy(){}

void Fairy::attack(Enemy &e) {
	e.beAttacked(*this);
}

void Fairy::beAttacked(Human &hu) {
	int s_cur_hp = gethp();
	int s_def = getdef();
	int hu_atk = hu.getatk();
	float damage = (float)(100*hu_atk)/(float)(100+s_def);
	int d = ceil(damage);
	int s_updated_hp = ((s_cur_hp - d) > 0) ? (s_cur_hp - d) : 0;
	sethp(s_updated_hp);
	cout << "Human dealt " << d << " damage on Fairy." << endl;
}

void Fairy::beAttacked(Dwarf &dw) {
	int s_cur_hp = gethp();
	int s_def = getdef();
	int dw_atk = dw.getatk();
	float damage = (float)(100*dw_atk)/(float)(100+s_def);
	int d = ceil(damage);
	int s_updated_hp = ((s_cur_hp - d) > 0) ? (s_cur_hp - d) : 0;
	sethp(s_updated_hp);
	cout << "Dwarf dealt " << d << " damage on Fairy." << endl;
}

void Fairy::beAttacked(Elf &el) {
	int s_cur_hp = gethp();
	int s_def = getdef();
	int el_atk = el.getatk();
	float damage = (float)(100*el_atk)/(float)(100+s_def);
	int d = ceil(damage);
	int s_updated_hp = ((s_cur_hp - 2*d) > 0) ? (s_cur_hp - 2*d) : 0;
	sethp(s_updated_hp);
	cout << "Elf dealt " << d << " damage on Fairy." << endl;
}

void Fairy::beAttacked(Orcs &o) {
	int s_cur_hp = gethp();
	int s_def = getdef();
	int o_atk = o.getatk();
	float damage = (float)(100*o_atk)/(float)(100+s_def);
	int d = ceil(damage);
	int s_updated_hp = ((s_cur_hp - d) > 0) ? (s_cur_hp - d) : 0;
	sethp(s_updated_hp);
	cout << "Orcs dealt " << d << " damage on Fairy." << endl;
}

void Fairy::beAttacked(Merchant &m) {
	int s_cur_hp = gethp();
	int s_def = getdef();
	int m_atk = m.getatk();
	float damage = (float)(100*m_atk)/(float)(100+s_def);
	int d = ceil(damage);
	int s_updated_hp = ((s_cur_hp - d) > 0) ? (s_cur_hp - d) : 0;
	sethp(s_updated_hp);
	cout << "Merchant dealt " << d << " damage on Fairy." << endl;
}

void Fairy::beAttacked(Dragon &dr) {
	int s_cur_hp = gethp();
	int s_def = getdef();
	int dr_atk = dr.getatk();
	float damage = (float)(100*dr_atk)/(float)(100+s_def);
	int d = ceil(damage);
	int s_updated_hp = ((s_cur_hp - d) > 0) ? (s_cur_hp - d) : 0;
	sethp(s_updated_hp);
	cout << "Dragon dealt " << d << " damage on Fairy." << endl;
}

void Fairy::beAttacked(Halfling &ha) {
	int s_cur_hp = gethp();
	int s_def = getdef();
	int ha_atk = ha.getatk();
	float damage = (float)(100*ha_atk)/(float)(100+s_def);
	int d = ceil(damage);
	int s_updated_hp = ((s_cur_hp - d) > 0) ? (s_cur_hp - d) : 0;
	sethp(s_updated_hp);
	cout << "Halfling dealt " << d << " damage on Fairy." << endl;
}
