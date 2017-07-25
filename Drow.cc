#include <string>
#include <cmath>
#include "Drow.h"
using namespace std;

Drow::Drow(int row, int col, char sym, char prev, GameBoard* theBoard): 
PC(row, col, sym, prev, theBoard) {
	sethp(150);
	setatk(25);
	setdef(15);
	setmaxhp(150);
	settype("Drow");
}

Drow::~Drow(){}

void Drow::attack(Enemy &e) {
	e.beAttacked(*this);
}

void Drow::beAttacked(Human &hu) {
	int d_cur_hp = gethp();
	int d_def = getdef();
	int hu_atk = hu.getatk();
	float damage = (float)(100*hu_atk)/(float)(100+d_def);
	int d = ceil(damage);
	int d_updated_hp = ((d_cur_hp - d) > 0) ? (d_cur_hp - d) : 0;
	sethp(d_updated_hp);
	cout << hu.gettype() << " deals " << d << " damage on Shade." << endl;
}

void Drow::beAttacked(Dwarf &dw) {
	int d_cur_hp = gethp();
	int d_def = getdef();
	int dw_atk = dw.getatk();
	float damage = (float)(100*dw_atk)/(float)(100+d_def);
	int d = ceil(damage);
	int d_updated_hp = ((d_cur_hp - d) > 0) ? (d_cur_hp - d) : 0;
	sethp(d_updated_hp);
	cout << dw.gettype() << " deals " << d << " damage on Shade." << endl;
}

void Drow::beAttacked(Elf &el) {
	int d_cur_hp = gethp();
	int d_def = getdef();
	int el_atk = el.getatk();
	float damage = (float)(100*el_atk)/(float)(100+d_def);
	int d = ceil(damage);
	int d_updated_hp = ((d_cur_hp - d) > 0) ? (d_cur_hp - d) : 0;
	sethp(d_updated_hp);
	cout << el.gettype() << " deals " << d << " damage on Shade." << endl;
}

void Drow::beAttacked(Orcs &o) {
	int d_cur_hp = gethp();
	int d_def = getdef();
	int o_atk = o.getatk();
	float damage = (float)(100*o_atk)/(float)(100+d_def);
	int d = ceil(damage);
	int d_updated_hp = ((d_cur_hp - d) > 0) ? (d_cur_hp - d) : 0;
	sethp(d_updated_hp);
	cout << o.gettype() << " deals " << d << " damage on Shade." << endl;
}

void Drow::beAttacked(Merchant &m) {
	int d_cur_hp = gethp();
	int d_def = getdef();
	int m_atk = m.getatk();
	float damage = (float)(100*m_atk)/(float)(100+d_def);
	int d = ceil(damage);
	int d_updated_hp = ((d_cur_hp - d) > 0) ? (d_cur_hp - d) : 0;
	sethp(d_updated_hp);
	cout << m.gettype() << " deals " << d << " damage on Shade." << endl;
}

void Drow::beAttacked(Dragon &dr) {
	int d_cur_hp = gethp();
	int d_def = getdef();
	int dr_atk = dr.getatk();
	float damage = (float)(100*dr_atk)/(float)(100+d_def);
	int d = ceil(damage);
	int d_updated_hp = ((d_cur_hp - d) > 0) ? (d_cur_hp - d) : 0;
	sethp(d_updated_hp);
	cout << dr.gettype() << " deals " << d << " damage on Shade." << endl;
}

void Drow::beAttacked(Halfling &ha) {
	int d_cur_hp = gethp();
	int d_def = getdef();
	int ha_atk = ha.getatk();
	float damage = (float)(100*ha_atk)/(float)(100+d_def);
	int d = ceil(damage);
	int d_updated_hp = ((d_cur_hp - d) > 0) ? (d_cur_hp - d) : 0;
	sethp(d_updated_hp);
	cout << ha.gettype() << " deals " << d << " damage on Shade." << endl;
}
