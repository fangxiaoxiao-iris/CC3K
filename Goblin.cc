#include <string>
#include <cmath>
#include "Goblin.h"

Goblin::Goblin(): PC() {
	sethp(110);
	setatk(15);
	setdef(20);
	setmaxhp(110);
	settype("Goblin");
}

Goblin::~Goblin(){}

void Goblin::attack(Enemy &e) override {
	e.beAttacked(*this);
}

void Goblin::beAttacked(Human &hu) override {
	int g_cur_hp = gethp();
	int g_def = getdef();
	int hu_atk = hu.getatk()
	int damage = ceil((100/(100+g_def))*hu_atk);
	int g_updated_hp = ((g_cur_hp - damage) > 0) ? (g_cur_hp - damage) : 0;
	sethp(g_updated_hp);
	if (g_updated_hp == 0) {
		dead();
	}
}

void Goblin::beAttacked(Dwarf &dw) override {
	int g_cur_hp = gethp();
	int g_def = getdef();
	int dw_atk = dw.getatk()
	int damage = ceil((100/(100+g_def))*dw_atk);
	int g_updated_hp = ((g_cur_hp - damage) > 0) ? (g_cur_hp - damage) : 0;
	sethp(g_updated_hp);
	if (g_updated_hp == 0) {
		dead();
	}
}

void Goblin::beAttacked(Elf &el) override {
	int g_cur_hp = gethp();
	int g_def = getdef();
	int el_atk = el.getatk()
	int damage = ceil((100/(100+g_def))*el_atk);
	int g_updated_hp = ((g_cur_hp - 2*damage) > 0) ? (g_cur_hp - damage) : 0;
	sethp(g_updated_hp);
	if (g_updated_hp == 0) {
		dead();
	}
}

void Goblin::beAttacked(Orcs &o) override {
	int g_cur_hp = gethp();
	int g_def = getdef();
	int o_atk = o.getatk()
	int damage = ceil((100/(100+g_def))*o_atk)*1.5;
	int g_updated_hp = ((g_cur_hp - damage) > 0) ? (g_cur_hp - damage) : 0;
	sethp(g_updated_hp);
	if (g_updated_hp == 0) {
		dead();
	}
}

void Goblin::beAttacked(Merchant &m) override {
	int g_cur_hp = gethp();
	int g_def = getdef();
	int m_atk = m.getatk()
	int damage = ceil((100/(100+g_def))*m_atk);
	int g_updated_hp = ((g_cur_hp - damage) > 0) ? (g_cur_hp - damage) : 0;
	sethp(g_updated_hp);
	if (g_updated_hp == 0) {
		dead();
	}
}

void Goblin::beAttacked(Dragon &dr) override {
	int g_cur_hp = gethp();
	int g_def = getdef();
	int dr_atk = dr.getatk()
	int damage = ceil((100/(100+g_def))*dr_atk);
	int g_updated_hp = ((g_cur_hp - damage) > 0) ? (g_cur_hp - damage) : 0;
	sethp(g_updated_hp);
	if (g_updated_hp == 0) {
		dead();
	}
}

void Goblin::beAttacked(Halfling &ha) override {
	int g_cur_hp = gethp();
	int g_def = getdef();
	int ha_atk = ha.getatk()
	int damage = ceil((100/(100+g_def))*ha_atk);
	int g_updated_hp = ((g_cur_hp - damage) > 0) ? (g_cur_hp - damage) : 0;
	sethp(g_updated_hp);
	if (g_updated_hp == 0) {
		dead();
	}
}
