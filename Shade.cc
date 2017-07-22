#include <string>
#include <cmath>
#include "Shade.h"

Shade::Shade(int row, int col, char sym, char prev, GameBoard* theBoard): 
PC(row, col, sym, prev, theBoard) {
	sethp(125);
	setatk(25);
	setdef(25);
	setmaxhp(125);
	settype("Shade");
}

Shade::~Shade(){}

void Shade::attack(Enemy &e) override {
	e.beAttacked(*this);
}

void Shade::beAttacked(Human &hu) override {
	int s_cur_hp = gethp();
	int s_def = getdef();
	int hu_atk = hu.getatk()
	int damage = ceil((100/(100+s_def))*hu_atk);
	int s_updated_hp = ((s_cur_hp - damage) > 0) ? (s_cur_hp - damage) : 0;
	sethp(s_updated_hp);
	if (s_updated_hp == 0) {
		dead();
	}
}

void Shade::beAttacked(Dwarf &dw) override {
	int s_cur_hp = gethp();
	int s_def = getdef();
	int dw_atk = dw.getatk()
	int damage = ceil((100/(100+s_def))*dw_atk);
	int s_updated_hp = ((s_cur_hp - damage) > 0) ? (s_cur_hp - damage) : 0;
	sethp(s_updated_hp);
	if (s_updated_hp == 0) {
		dead();
	}
}

void Shade::beAttacked(Elf &el) override {
	int s_cur_hp = gethp();
	int s_def = getdef();
	int el_atk = el.getatk()
	int damage = ceil((100/(100+s_def))*el_atk);
	int s_updated_hp = ((s_cur_hp - 2*damage) > 0) ? (s_cur_hp - 2*damage) : 0;
	sethp(s_updated_hp);
	if (s_updated_hp == 0) {
		dead();
	}
}

void Shade::beAttacked(Orcs &o) override {
	int s_cur_hp = gethp();
	int s_def = getdef();
	int o_atk = o.getatk()
	int damage = ceil((100/(100+s_def))*o_atk);
	int s_updated_hp = ((s_cur_hp - damage) > 0) ? (s_cur_hp - damage) : 0;
	sethp(s_updated_hp);
	if (s_updated_hp == 0) {
		dead();
	}
}

void Shade::beAttacked(Merchant &m) override {
	int s_cur_hp = gethp();
	int s_def = getdef();
	int m_atk = m.getatk()
	int damage = ceil((100/(100+s_def))*m_atk);
	int s_updated_hp = ((s_cur_hp - damage) > 0) ? (s_cur_hp - damage) : 0;
	sethp(s_updated_hp);
	if (s_updated_hp == 0) {
		dead();
	}
}

void Shade::beAttacked(Dragon &dr) override {
	int s_cur_hp = gethp();
	int s_def = getdef();
	int dr_atk = dr.getatk()
	int damage = ceil((100/(100+s_def))*dr_atk);
	int s_updated_hp = ((s_cur_hp - damage) > 0) ? (s_cur_hp - damage) : 0;
	sethp(s_updated_hp);
	if (s_updated_hp == 0) {
		dead();
	}
}

void Shade::beAttacked(Halfling &ha) override {
	int s_cur_hp = gethp();
	int s_def = getdef();
	int ha_atk = ha.getatk()
	int damage = ceil((100/(100+s_def))*ha_atk);
	int s_updated_hp = ((s_cur_hp - damage) > 0) ? (s_cur_hp - damage) : 0;
	sethp(s_updated_hp);
	if (s_updated_hp == 0) {
		dead();
	}
}
