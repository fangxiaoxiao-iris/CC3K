#include <string>
#include <cmath>
#include "Troll.h"
using namespace std;

Troll::Troll(int row, int col, char sym, char prev, GameBoard* theBoard): 
PC(row, col, sym, prev, theBoard){
	sethp(120);
	setatk(25);
	setdef(15);
	setmaxhp(120);
	settype("Troll");
}

Troll::~Troll(){}

void Troll::attack(Enemy &e) {
	int t_cur_hp = gethp();
	int t_updated_hp = ((t_cur_hp + 5) < 120) ? (t_cur_hp + 5) : 120;
	sethp(t_updated_hp);
	e.beAttacked(*this);
}

void Troll::beAttacked(Human &hu) {
	int t_cur_hp = gethp();
	int t_def = getdef();
	int hu_atk = hu.getatk();
	float damage = (float)(100*hu_atk)/(float)(100+t_def);
	int d = ceil(damage);
	int t_updated_hp = ((t_cur_hp - d) > 0) ? (t_cur_hp - d) : 0;
	sethp(t_updated_hp);
	cout << hu.gettype() << " deals " << d << " damage on Shade." << endl;
}

void Troll::beAttacked(Dwarf &dw) {
	int t_cur_hp = gethp();
	int t_def = getdef();
	int dw_atk = dw.getatk();
	float damage = (float)(100*dw_atk)/(float)(100+t_def);
	int d = ceil(damage);
	int t_updated_hp = ((t_cur_hp - d) > 0) ? (t_cur_hp - d) : 0;
	sethp(t_updated_hp);
	cout << dw.gettype() << " deals " << d << " damage on Shade." << endl;
}

void Troll::beAttacked(Elf &el) {
	int t_cur_hp = gethp();
	int t_def = getdef();
	int el_atk = el.getatk();
	float damage = (float)(100*el_atk)/(float)(100+t_def);
	int d = ceil(damage);
	int t_updated_hp = ((t_cur_hp - 2*d) > 0) ? (t_cur_hp - 2*d) : 0;
	sethp(t_updated_hp);
	cout << el.gettype() << " deals " << d << " damage on Shade." << endl;
}

void Troll::beAttacked(Orcs &o) {
	int t_cur_hp = gethp();
	int t_def = getdef();
	int o_atk = o.getatk();
	float damage = (float)(100*o_atk)/(float)(100+t_def);
	int d = ceil(damage);
	int t_updated_hp = ((t_cur_hp - d) > 0) ? (t_cur_hp - d) : 0;
	sethp(t_updated_hp);
	cout << o.gettype() << " deals " << d << " damage on Shade." << endl;
}

void Troll::beAttacked(Merchant &m) {
	int t_cur_hp = gethp();
	int t_def = getdef();
	int m_atk = m.getatk();
	float damage = (float)(100*m_atk)/(float)(100+t_def);
	int d = ceil(damage);
	int t_updated_hp = ((t_cur_hp - d) > 0) ? (t_cur_hp - d) : 0;
	sethp(t_updated_hp);
	cout << m.gettype() << " deals " << d << " damage on Shade." << endl;
}

void Troll::beAttacked(Dragon &dr) {
	int t_cur_hp = gethp();
	int t_def = getdef();
	int dr_atk = dr.getatk();
	float damage = (float)(100*dr_atk)/(float)(100+t_def);
	int d = ceil(damage);
	int t_updated_hp = ((t_cur_hp - d) > 0) ? (t_cur_hp - d) : 0;
	sethp(t_updated_hp);
	cout << dr.gettype() << " deals " << d << " damage on Shade." << endl;
}

void Troll::beAttacked(Halfling &ha) {
	int t_cur_hp = gethp();
	int t_def = getdef();
	int ha_atk = ha.getatk();
	float damage = (float)(100*ha_atk)/(float)(100+t_def);
	int d = ceil(damage);
	int t_updated_hp = ((t_cur_hp - d) > 0) ? (t_cur_hp - d) : 0;
	sethp(t_updated_hp);
	cout << ha.gettype() << " deals " << d << " damage on Shade." << endl;
}
