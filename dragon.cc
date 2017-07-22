#include "dragon.h"
#include <cmath>

using namespace std;

Dragon::Dragon(): Enemy() {
	sethp(150);
	setatk(20);
	setdef(20);
	setmaxhp(150);
	setgold(0);
	settype("Dragon")
}

Dragon::~Dragon() {}

void Dragon::attack(PC &defender){
	int tmp = rand() % 2;
	if(tmp == 0) {
	defender.beAttacked(*this);
}
}
	
void Dragon::beAttacked(Shade &shade) {
	int Dragon_hp = this->gethp();
	int Dragon_def = this->getdef();
	int attacker_atk = shade.getatk();
	// Dragon is the defender
	int damagetaken = ceil((100/(100+Dragon_def)) * attacker_atk);
	int Dragon_newhp = Dragon_hp - damagetaken;
	if(Dragon_newhp <= 0){
		this->sethp(0);
		this->dead();
		hoard.setavailable(true);
		} else {
		this->setup(Dragon_newhp);
	}
}

void Dragon::beAttacked(Drow &drow) {
	int Dragon_hp = this->gethp();
	int Dragon_def = this->getdef();
	int attacker_atk = drow.getatk();
	// Dragon is the defender
	int damagetaken = ceil((100/(100+Dragon_def)) * attacker_atk);
	int Dragon_newhp = Dragon_hp - damagetaken;
	if(Dragon_newhp <= 0){
		this->sethp(0);
		this->dead();
		hoard.setavailable(true);
		} else {
		this->setup(Dragon_newhp);
	}
}


void Dragon::beAttacked(Vampire &vampire) {
	int Dragon_hp = this->gethp();
	int Dragon_def = this->getdef();
	int vampire_atk = vampire.getatk();
	// Dragon is the defender
	int damagetaken = ceil((100/(100+Dragon_def)) * attacker_atk);
	int Dragon_newhp = Dragon_hp - damagetaken;
	// vampire gains 5 hp every successful attack
	int hp_gained = 5;
	vampire.sethp(vampire.hp + hp_gained);
	if(Dragon_newhp <= 0){
		this->sethp(0);
		this->dead();
		hoard.setavailable(true);
		} else {
		this->setup(Dragon_newhp);
	}
}

void Dragon::beAttacked(Troll &troll){
	int Dragon_hp = this->gethp();
	int Dragon_def = this->getdef();
	int attacker_atk = troll.getatk();
	// Dragon is the defender
	int damagetaken = ceil((100/(100+Dragon_def)) * attacker_atk);
	int Dragon_newhp = Dragon_hp - damagetaken;
	int hp_regain = 5;
	int troll_newhp = (troll.hp + hp_regain) > troll.maxhp ? troll.maxhp : troll.hp + hp_regain;
	if(Dragon_newhp <= 0){
		this->sethp(0);
		this->dead();
		hoard.setavailable(true);
		} else {
		this->setup(Dragon_newhp);
	}
}

void Dragon::beAttacked(Goblin &goblin){
	int Dragon_hp = this->gethp();
	int Dragon_def = this->getdef();
	int attacker_atk = goblin.getatk();
	// Dragon is the defender
	int damagetaken = ceil((100/(100+Dragon_def)) * attacker_atk);
	int Dragon_newhp = Dragon_hp - damagetaken;
	if(Dragon_newhp <= 0){
		// goblin steals 5 gold from every slain enemy
		int goblin_goldgain = 5;
		goblin.setgold(goblin.getgold += goblin_goldgain);
		this->sethp(0);
		this->dead();
		hoard.setavailable(true);
		} else {
		this->setup(Dragon_newhp);
	}
}

void Dragon::move() {
	bool attacked = false;

	for(auto n: neighbors) {
		if(n->get_sym() == '@') {
			attack(*n);
			attacked = true;
		}
	}
	for(auto m: hoard->neighbors) {
		if(m->get_sym() == '@') {
			if(attacked == false) {
			attack(*n);
			attacked = true;
		}
		}
	}
}