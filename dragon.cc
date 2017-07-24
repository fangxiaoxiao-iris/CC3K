#include "dragon.h"
#include <cmath>

using namespace std;

Dragon::Dragon(int row, int col, char sym, char prev, GameBoard* theBoard):
	Enemy(row, col, sym, prev, theBoard) {
	sethp(150);
	setatk(20);
	setdef(20);
	setmaxhp(150);
	setgold(0);
	settype("Dragon");
}

Dragon::~Dragon() {}

// need to implement neighbor exclusive.
void Dragon::attack(PC &defender) {
	for(auto n: neighbors) {
		if (n.second->get_sym() == '@') {
			int tmp = rand() % 2;
			if (tmp == 0) {
				defender.beAttacked(*this);
			}	
		}
	}/*
	for(auto m: hoard->getNeigh()) {
		if (m.second->get_sym() == '@') {
			int tmp = rand() % 2;
			if (tmp == 0) {
				defender.beAttacked(*this);
			}	
		}
	}*/
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
		hoard->setavailable(true);
		} else {
		this->sethp(Dragon_newhp);
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
		hoard->setavailable(true);
		} else {
		this->sethp(Dragon_newhp);
	}
}


void Dragon::beAttacked(Vampire &vampire) {
	int Dragon_hp = this->gethp();
	int Dragon_def = this->getdef();
	int vampire_atk = vampire.getatk();
	// Dragon is the defender
	int damagetaken = ceil((100/(100+Dragon_def)) * vampire_atk);
	int Dragon_newhp = Dragon_hp - damagetaken;
	// vampire gains 5 hp every successful attack
	int hp_gained = 5;
	vampire.sethp(vampire.gethp() + hp_gained);
	if(Dragon_newhp <= 0){
		this->sethp(0);
		this->dead();
		hoard->setavailable(true);
		} else {
		this->sethp(Dragon_newhp);
	}
}

void Dragon::beAttacked(Troll &troll){
	int Dragon_hp = this->gethp();
	int Dragon_def = this->getdef();
	int attacker_atk = troll.getatk();
	// Dragon is the defender
	int damagetaken = ceil((100/(100+Dragon_def)) * attacker_atk);
	int Dragon_newhp = Dragon_hp - damagetaken;
	if(Dragon_newhp <= 0){
		this->sethp(0);
		this->dead();
		hoard->setavailable(true);
		} else {
		this->sethp(Dragon_newhp);
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
		goblin.setgold(goblin.getgold() + goblin_goldgain);
		this->sethp(0);
		this->dead();
		hoard->setavailable(true);
		} else {
		this->sethp(Dragon_newhp);
	}
}

/*void Dragon::move() {
	bool attacked = false;

	for(auto n: neighbors) {
		if(n.second->get_sym() == '@') {
			n.second->beAttacked(*this);
			attacked = true;
		}
	}
	for(auto m: hoard->neighbors) {
		if(m.second->get_sym() == '@') {
			if(attacked == false) {
			n.second->beAttacked(*this);
			attacked = true;
		}
		}
	}
}*/
