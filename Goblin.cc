#include <string>
#include <cmath>
#include "Goblin.h"
using namespace std;

Goblin::Goblin(int row, int col, char sym, char prev, GameBoard* theBoard): 
PC(row, col, sym, prev, theBoard){
	sethp(110);
	setatk(15);
	setdef(20);
	setmaxhp(110);
	settype("Goblin");
}

Goblin::~Goblin(){}

void Goblin::attack(Enemy &e) {
	e.beAttacked(*this);
}

void Goblin::beAttacked(Human &hu) {
	int g_cur_hp = gethp();
	int g_def = getdef();
	int hu_atk = hu.getatk();
	float damage = (float)(100*hu_atk)/(float)(100+g_def);
	int d = ceil(damage);
	int g_updated_hp = ((g_cur_hp - damage) > 0) ? (g_cur_hp - damage) : 0;
	sethp(g_updated_hp);
	cout << hu.gettype() << " deals " << d << " damage on Shade." << endl;
}

void Goblin::beAttacked(Dwarf &dw) {
	int g_cur_hp = gethp();
	int g_def = getdef();
	int dw_atk = dw.getatk();
	float damage = (float)(100*dw_atk)/(float)(100+g_def);
	int d = ceil(damage);
	int g_updated_hp = ((g_cur_hp - damage) > 0) ? (g_cur_hp - damage) : 0;
	sethp(g_updated_hp);
	cout << dw.gettype() << " deals " << d << " damage on Shade." << endl;
}

void Goblin::beAttacked(Elf &el) {
	int g_cur_hp = gethp();
	int g_def = getdef();
	int el_atk = el.getatk();
	float damage = (float)(100*el_atk)/(float)(100+g_def);
	int d = ceil(damage);
	int g_updated_hp = ((g_cur_hp - 2*damage) > 0) ? (g_cur_hp - damage) : 0;
	sethp(g_updated_hp);
	cout << el.gettype() << " deals " << d << " damage on Shade." << endl;
}

void Goblin::beAttacked(Orcs &o) {
	int g_cur_hp = gethp();
	int g_def = getdef();
	int o_atk = o.getatk();
	float damage = (float)(100*o_atk)/(float)(100+g_def);
	int d = ceil(damage);
	int g_updated_hp = ((g_cur_hp - damage) > 0) ? (g_cur_hp - damage) : 0;
	sethp(g_updated_hp);
	cout << o.gettype() << " deals " << d << " damage on Shade." << endl;
}

void Goblin::beAttacked(Merchant &m) {
	int g_cur_hp = gethp();
	int g_def = getdef();
	int m_atk = m.getatk();
	float damage = (float)(100*m_atk)/(float)(100+g_def);
	int d = ceil(damage);
	int g_updated_hp = ((g_cur_hp - damage) > 0) ? (g_cur_hp - damage) : 0;
	sethp(g_updated_hp);
	cout << m.gettype() << " deals " << d << " damage on Shade." << endl;
}

void Goblin::beAttacked(Dragon &dr) {
	int g_cur_hp = gethp();
	int g_def = getdef();
	int dr_atk = dr.getatk();
	float damage = (float)(100*dr_atk)/(float)(100+g_def);
	int d = ceil(damage);
	int g_updated_hp = ((g_cur_hp - damage) > 0) ? (g_cur_hp - damage) : 0;
	sethp(g_updated_hp);
	cout << dr.gettype() << " deals " << d << " damage on Shade." << endl;
}

void Goblin::beAttacked(Halfling &ha) {
	int g_cur_hp = gethp();
	int g_def = getdef();
	int ha_atk = ha.getatk();
	float damage = (float)(100*ha_atk)/(float)(100+g_def);
	int d = ceil(damage);
	int g_updated_hp = ((g_cur_hp - damage) > 0) ? (g_cur_hp - damage) : 0;
	sethp(g_updated_hp);
	cout << ha.gettype() << " deals " << d << " damage on Shade." << endl;
}
