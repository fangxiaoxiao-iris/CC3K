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
	int damage = ceil((100/(100+v_def))*hu_atk);
	int v_updated_hp = ((v_cur_hp - damage) > 0) ? (v_cur_hp - damage) : 0;
	sethp(v_updated_hp);
}

void Vampire::beAttacked(Dwarf &dw) {
	int v_cur_hp = gethp();
	int v_def = getdef();
	int dw_atk = dw.getatk();
	int damage = ceil((100/(100+v_def))*dw_atk);
	int v_updated_hp = ((v_cur_hp - damage) > 0) ? (v_cur_hp - damage) : 0;
	sethp(v_updated_hp);
}

void Vampire::beAttacked(Elf &el) {
	int v_cur_hp = gethp();
	int v_def = getdef();
	int el_atk = el.getatk();
	int damage = ceil((100/(100+v_def))*el_atk);
	int v_updated_hp = ((v_cur_hp - 2*damage) > 0) ? (v_cur_hp - damage) : 0;
	sethp(v_updated_hp);
}

void Vampire::beAttacked(Orcs &o) {
	int d_cur_hp = gethp();
	int d_def = getdef();
	int o_atk = o.getatk();
	int damage = ceil((100/(100+d_def))*o_atk);
	int d_updated_hp = ((d_cur_hp - damage) > 0) ? (d_cur_hp - damage) : 0;
	sethp(d_updated_hp);
}

void Vampire::beAttacked(Merchant &m) {
	int v_cur_hp = gethp();
	int v_def = getdef();
	int m_atk = m.getatk();
	int damage = ceil((100/(100+v_def))*m_atk);
	int v_updated_hp = ((v_cur_hp - damage) > 0) ? (v_cur_hp - damage) : 0;
	sethp(v_updated_hp);
}

void Vampire::beAttacked(Dragon &dr) {
	int v_cur_hp = gethp();
	int v_def = getdef();
	int dr_atk = dr.getatk();
	int damage = ceil((100/(100+v_def))*dr_atk);
	int v_updated_hp = ((v_cur_hp - damage) > 0) ? (v_cur_hp - damage) : 0;
	sethp(v_updated_hp);
}

void Vampire::beAttacked(Halfling &ha) {
	int v_cur_hp = gethp();
	int v_def = getdef();
	int ha_atk = ha.getatk();
	int damage = ceil((100/(100+v_def))*ha_atk);
	int v_updated_hp = ((v_cur_hp - damage) > 0) ? (v_cur_hp - damage) : 0;
	sethp(v_updated_hp);
}
