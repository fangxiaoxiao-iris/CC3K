#include <string>
#include <cmath>
#include "Troll.h"

Troll::Troll(int row, int col, char sym, char prev, GameBoard* theBoard): 
PC(row, col, sym, prev, theBoard){
	sethp(120);
	setatk(25);
	setdef(15);
	setmaxhp(120);
	settype("Troll");
}

Troll::~Troll(){}

void Troll::attack(Enemy &e) override {
	e.beAttacked(*this);
	int t_cur_hp = gethp();
	int t_updated_hp = ((t_cur_hp + 5) < 120) ? (t_cur_hp) : 120;
	sethp(t_updated_hp);
}

void Troll::beAttacked(Human &hu) override {
	int t_cur_hp = gethp();
	int t_def = getdef();
	int hu_atk = hu.getatk()
	int damage = ceil((100/(100+t_def))*hu_atk);
	int t_updated_hp = ((t_cur_hp - damage) > 0) ? (t_cur_hp - damage) : 0;
	sethp(t_updated_hp);
	if (t_updated_hp == 0) {
		dead();
	}
}

void Troll::beAttacked(Dwarf &dw) override {
	int t_cur_hp = gethp();
	int t_def = getdef();
	int dw_atk = dw.getatk()
	int damage = ceil((100/(100+t_def))*dw_atk);
	int t_updated_hp = ((t_cur_hp - damage) > 0) ? (t_cur_hp - damage) : 0;
	sethp(t_updated_hp);
	if (t_updated_hp == 0) {
		dead();
	}
}

void Troll::beAttacked(Elf &el) override {
	int t_cur_hp = gethp();
	int t_def = getdef();
	int el_atk = el.getatk()
	int damage = ceil((100/(100+t_def))*el_atk);
	int t_updated_hp = ((t_cur_hp - 2*damage) > 0) ? (t_cur_hp - damage) : 0;
	sethp(t_updated_hp);
	if (t_updated_hp == 0) {
		dead();
	}
}

void Troll::beAttacked(Orcs &o) override {
	int t_cur_hp = gethp();
	int t_def = getdef();
	int o_atk = o.getatk()
	int damage = ceil((100/(100+t_def))*o_atk);
	int t_updated_hp = ((t_cur_hp - damage) > 0) ? (t_cur_hp - damage) : 0;
	sethp(t_updated_hp);
	if (t_updated_hp == 0) {
		dead();
	}
}

void Troll::beAttacked(Merchant &m) override {
	int t_cur_hp = gethp();
	int t_def = getdef();
	int m_atk = m.getatk()
	int damage = ceil((100/(100+t_def))*m_atk);
	int t_updated_hp = ((t_cur_hp - damage) > 0) ? (t_cur_hp - damage) : 0;
	sethp(t_updated_hp);
	if (t_updated_hp == 0) {
		dead();
	}
}

void Troll::beAttacked(Dragon &dr) override {
	int t_cur_hp = gethp();
	int t_def = getdef();
	int dr_atk = dr.getatk()
	int damage = ceil((100/(100+t_def))*dr_atk);
	int t_updated_hp = ((t_cur_hp - damage) > 0) ? (t_cur_hp - damage) : 0;
	sethp(t_updated_hp);
	if (t_updated_hp == 0) {
		dead();
	}
}

void Troll::beAttacked(Halfling &ha) override {
	int t_cur_hp = gethp();
	int t_def = getdef();
	int ha_atk = ha.getatk()
	int damage = ceil((100/(100+t_def))*ha_atk);
	int t_updated_hp = ((t_cur_hp - damage) > 0) ? (t_cur_hp - damage) : 0;
	sethp(t_updated_hp);
	if (t_updated_hp == 0) {
		dead();
	}
}
