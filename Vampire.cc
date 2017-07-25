#include <string>
#include <cmath>
#include "Vampire.h"
using namespace std;

Vampire::Vampire(int row, int col, char sym, char prev, GameBoard* theBoard): 
PC(row, col, sym, prev, theBoard){
	sethp(50);
	setatk(25);
	setdef(25);
	setmaxhp(-1);
	settype("Vampire");
}

Vampire::~Vampire(){}

void Vampire::attack(Enemy &e) {
	e.beAttacked(*this);
}

void Vampire::beAttacked(Human &hu) {
	int v_cur_hp = gethp();
	int v_def = getdef();
	int hu_atk = hu.getatk();
	float damage = (float)(100*hu_atk)/(float)(100+v_def);
	int d = ceil(damage);
	int v_updated_hp = ((v_cur_hp - d) > 0) ? (v_cur_hp - d) : 0;
	sethp(v_updated_hp);
	cout << hu.gettype() << " deals " << d << " damage on Shade." << endl;
}

void Vampire::beAttacked(Dwarf &dw) {
	int v_cur_hp = gethp();
	int v_def = getdef();
	int dw_atk = dw.getatk();
	float damage = (float)(100*dw_atk)/(float)(100+v_def);
	int d = ceil(damage);
	int v_updated_hp = ((v_cur_hp - d) > 0) ? (v_cur_hp - d) : 0;
	sethp(v_updated_hp);
	cout << dw.gettype() << " deals " << d << " damage on Shade." << endl;
}

void Vampire::beAttacked(Elf &el) {
	int v_cur_hp = gethp();
	int v_def = getdef();
	int el_atk = el.getatk();
	float damage = (float)(100*el_atk)/(float)(100+v_def);
	int d = ceil(damage);
	int v_updated_hp = ((v_cur_hp - 2*d) > 0) ? (v_cur_hp - 2*d) : 0;
	sethp(v_updated_hp);
	cout << el.gettype() << " deals " << d << " damage on Shade." << endl;
}

void Vampire::beAttacked(Orcs &o) {
	int v_cur_hp = gethp();
	int v_def = getdef();
	int o_atk = o.getatk();
	float damage = (float)(100*o_atk)/(float)(100+v_def);
	int d = ceil(damage);
	int v_updated_hp = ((v_cur_hp - d) > 0) ? (v_cur_hp - d) : 0;
	sethp(v_updated_hp);
	cout << o.gettype() << " deals " << d << " damage on Shade." << endl;
}

void Vampire::beAttacked(Merchant &m) {
	int v_cur_hp = gethp();
	int v_def = getdef();
	int m_atk = m.getatk();
	float damage = (float)(100*m_atk)/(float)(100+v_def);
	int d = ceil(damage);
	int v_updated_hp = ((v_cur_hp - d) > 0) ? (v_cur_hp - d) : 0;
	sethp(v_updated_hp);
	cout << m.gettype() << " deals " << d << " damage on Shade." << endl;
}

void Vampire::beAttacked(Dragon &dr) {
	int v_cur_hp = gethp();
	int v_def = getdef();
	int dr_atk = dr.getatk();
	float damage = (float)(100*dr_atk)/(float)(100+v_def);
	int d = ceil(damage);
	int v_updated_hp = ((v_cur_hp - d) > 0) ? (v_cur_hp - d) : 0;
	sethp(v_updated_hp);
	cout << dr.gettype() << " deals " << d << " damage on Shade." << endl;
}

void Vampire::beAttacked(Halfling &ha) {
	int v_cur_hp = gethp();
	int v_def = getdef();
	int ha_atk = ha.getatk();
	float damage = (float)(100*ha_atk)/(float)(100+v_def);
	int d = ceil(damage);
	int v_updated_hp = ((v_cur_hp - d) > 0) ? (v_cur_hp - d) : 0;
	sethp(v_updated_hp);
	cout << ha.gettype() << " deals " << d << " damage on Shade." << endl;
}
