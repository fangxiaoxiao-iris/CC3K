#include <string>
#include <cmath>
#include "Shade.h"
using namespace std;

Shade::Shade(int row, int col, char sym, char prev, GameBoard* theBoard): 
PC(row, col, sym, prev, theBoard) {
	sethp(125);
	setatk(25);
	setdef(25);
	setmaxhp(125);
	settype("Shade");
}

Shade::~Shade(){}

void Shade::attack(Enemy &e) {
	e.beAttacked(*this);
}

void Shade::beAttacked(Human &hu) {
	int s_cur_hp = gethp();
	int s_def = getdef();
	int hu_atk = hu.getatk();
	float damage = (float)(100*hu_atk)/(float)(100+s_def);
	int d = ceil(damage);
	int s_updated_hp = ((s_cur_hp - d) > 0) ? (s_cur_hp - d) : 0;
	sethp(s_updated_hp);
	cout << hu.gettype() << " deals " << d << " damage on Shade." << endl;
}

void Shade::beAttacked(Dwarf &dw) {
	int s_cur_hp = gethp();
	int s_def = getdef();
	int dw_atk = dw.getatk();
	float damage = (float)(100*dw_atk)/(float)(100+s_def);
	int d = ceil(damage);
	int s_updated_hp = ((s_cur_hp - d) > 0) ? (s_cur_hp - d) : 0;
	sethp(s_updated_hp);
	cout << dw.gettype() << " deals " << d << " damage on Shade." << endl;
}

void Shade::beAttacked(Elf &el) {
	int s_cur_hp = gethp();
	int s_def = getdef();
	int el_atk = el.getatk();
	float damage = (float)(100*el_atk)/(float)(100+s_def);
	int d = ceil(damage);
	int s_updated_hp = ((s_cur_hp - 2*d) > 0) ? (s_cur_hp - 2*d) : 0;
	sethp(s_updated_hp);
	cout << el.gettype() << " deals " << d << " damage on Shade." << endl;
}

void Shade::beAttacked(Orcs &o) {
	int s_cur_hp = gethp();
	int s_def = getdef();
	int o_atk = o.getatk();
	float damage = (float)(100*o_atk)/(float)(100+s_def);
	int d = ceil(damage);
	int s_updated_hp = ((s_cur_hp - d) > 0) ? (s_cur_hp - d) : 0;
	sethp(s_updated_hp);
	cout << o.gettype() << " deals " << d << " damage on Shade." << endl;
}

void Shade::beAttacked(Merchant &m) {
	int s_cur_hp = gethp();
	int s_def = getdef();
	int m_atk = m.getatk();
	float damage = (float)(100*m_atk)/(float)(100+s_def);
	int d = ceil(damage);
	int s_updated_hp = ((s_cur_hp - d) > 0) ? (s_cur_hp - d) : 0;
	sethp(s_updated_hp);
	cout << m.gettype() << " deals " << d << " damage on Shade." << endl;
}

void Shade::beAttacked(Dragon &dr) {
	int s_cur_hp = gethp();
	int s_def = getdef();
	int dr_atk = dr.getatk();
	float damage = (float)(100*dr_atk)/(float)(100+s_def);
	int d = ceil(damage);
	int s_updated_hp = ((s_cur_hp - d) > 0) ? (s_cur_hp - d) : 0;
	sethp(s_updated_hp);
	cout << dr.gettype() << " deals " << d << " damage on Shade." << endl;
}

void Shade::beAttacked(Halfling &ha) {
	int s_cur_hp = gethp();
	int s_def = getdef();
	int ha_atk = ha.getatk();
	float damage = (float)(100*ha_atk)/(float)(100+s_def);
	int d = ceil(damage);
	int s_updated_hp = ((s_cur_hp - d) > 0) ? (s_cur_hp - d) : 0;
	sethp(s_updated_hp);
	cout << ha.gettype() << " deals " << d << " damage on Shade." << endl;
}
