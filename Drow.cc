#include <string>
#include <cmath>
#include "Drow.h"

Drow::Drow(): PC() {
	sethp(150);
	setatk(25);
	setdef(15);
	setmaxhp(150);
	settype("Drow");
}

Drow::~Drow(){}

void Drow::attack(Enemy &e) override {
	e.beAttacked(*this);
}

void Drow::beAttacked(Human &hu) override {
	int d_cur_hp = gethp();
	int d_def = getdef();
	int hu_atk = hu.getatk()
	int damage = ceil((100/(100+d_def))*hu_atk);
	int d_updated_hp = ((d_cur_hp - damage) > 0) ? (d_cur_hp - damage) : 0;
	sethp(d_updated_hp);
	if (d_updated_hp == 0) {
		dead();
	}
}

void Drow::beAttacked(Dwarf &dw) override {
	int d_cur_hp = gethp();
	int d_def = getdef();
	int dw_atk = dw.getatk()
	int damage = ceil((100/(100+d_def))*dw_atk);
	int d_updated_hp = ((d_cur_hp - damage) > 0) ? (d_cur_hp - damage) : 0;
	sethp(d_updated_hp);
	if (d_updated_hp == 0) {
		dead();
	}
}

void Drow::beAttacked(Elf &el) override {
	int d_cur_hp = gethp();
	int d_def = getdef();
	int el_atk = el.getatk()
	int damage = ceil((100/(100+d_def))*el_atk);
	int d_updated_hp = ((d_cur_hp - damage) > 0) ? (d_cur_hp - damage) : 0;
	sethp(d_updated_hp);
	if (d_updated_hp == 0) {
		dead();
	}
}

void Drow::beAttacked(Orcs &o) override {
	int d_cur_hp = gethp();
	int d_def = getdef();
	int o_atk = o.getatk()
	int damage = ceil((100/(100+d_def))*o_atk);
	int d_updated_hp = ((d_cur_hp - damage) > 0) ? (d_cur_hp - damage) : 0;
	sethp(d_updated_hp);
	if (d_updated_hp == 0) {
		dead();
	}
}

void Drow::beAttacked(Merchant &m) override {
	int d_cur_hp = gethp();
	int d_def = getdef();
	int m_atk = m.getatk()
	int damage = ceil((100/(100+d_def))*m_atk);
	int d_updated_hp = ((d_cur_hp - damage) > 0) ? (d_cur_hp - damage) : 0;
	sethp(d_updated_hp);
	if (d_updated_hp == 0) {
		dead();
	}
}

void Drow::beAttacked(Dragon &dr) override {
	int d_cur_hp = gethp();
	int d_def = getdef();
	int dr_atk = dr.getatk()
	int damage = ceil((100/(100+d_def))*dr_atk);
	int d_updated_hp = ((d_cur_hp - damage) > 0) ? (d_cur_hp - damage) : 0;
	sethp(d_updated_hp);
	if (d_updated_hp == 0) {
		dead();
	}
}

void Drow::beAttacked(Halfling &ha) override {
	int d_cur_hp = gethp();
	int d_def = getdef();
	int ha_atk = ha.getatk()
	int damage = ceil((100/(100+d_def))*ha_atk);
	int d_updated_hp = ((d_cur_hp - damage) > 0) ? (d_cur_hp - damage) : 0;
	sethp(d_updated_hp);
	if (d_updated_hp == 0) {
		dead();
	}
}
