#include "orcs.h"
#include <cmath>

using namespace std;

Orcs::Orcs(): Enemy() {
	sethp(180);
	setatk(30);
	setdef(25);
	setmaxhp(180);
	setgold(0);
	settype("Orcs")
}

Orcs::~Orcs() {}

void Orcs::attack(PC &defender){
	int tmp = rand() % 2;
	if(tmp == 0) {
	defender.beAttacked(*this);
}
}
	
void Orcs::beAttacked(Shade &shade) {
	int Orcs_hp = this->gethp();
	int Orcs_def = this->getdef();
	int attacker_atk = shade.getatk();
	// Orcs is the defender
	int damagetaken = ceil((100/(100+Orcs_def)) * attacker_atk);
	int Orcs_newhp = Orcs_hp - damagetaken;
	if(Orcs_newhp <= 0){
		this->sethp(0);
		this->dead();
		} else {
		this->setup(Orcs_newhp);
	}
}

void Orcs::beAttacked(Drow &drow) {
	int Orcs_hp = this->gethp();
	int Orcs_def = this->getdef();
	int attacker_atk = drow.getatk();
	// Orcs is the defender
	int damagetaken = ceil((100/(100+Orcs_def)) * attacker_atk);
	int Orcs_newhp = Orcs_hp - damagetaken;
	if(Orcs_newhp <= 0){
		this->sethp(0);
		this->dead();
		} else {
		this->setup(Orcs_newhp);
	}
}


void Orcs::beAttacked(Vampire &vampire) {
	int Orcs_hp = this->gethp();
	int Orcs_def = this->getdef();
	int vampire_atk = vampire.getatk();
	// Orcs is the defender
	int damagetaken = ceil((100/(100+Orcs_def)) * attacker_atk);
	int Orcs_newhp = Orcs_hp - damagetaken;
	// vampire gains 5 hp every successful attack
	int hp_gained = 5;
	vampire.sethp(vampire.hp + hp_gained);
	if(Orcs_newhp <= 0){
		this->sethp(0);
		this->dead();
		} else {
		this->setup(Orcs_newhp);
	}
}

void Orcs::beAttacked(Troll &troll){
	int Orcs_hp = this->gethp();
	int Orcs_def = this->getdef();
	int attacker_atk = troll.getatk();
	// Orcs is the defender
	int damagetaken = ceil((100/(100+Orcs_def)) * attacker_atk);
	int Orcs_newhp = Orcs_hp - damagetaken;
	int hp_regain = 5;
	int troll_newhp = (troll.hp + hp_regain) > troll.maxhp ? troll.maxhp : troll.hp + hp_regain;
	if(Orcs_newhp <= 0){
		this->sethp(0);
		this->dead();
		} else {
		this->setup(Orcs_newhp);
	}
}

void Orcs::beAttacked(Goblin &goblin){
	int Orcs_hp = this->gethp();
	int Orcs_def = this->getdef();
	int attacker_atk = goblin.getatk();
	// Orcs is the defender
	int damagetaken = ceil((100/(100+Orcs_def)) * attacker_atk);
	int Orcs_newhp = Orcs_hp - damagetaken;
	if(Orcs_newhp <= 0){
		// goblin steals 5 gold from every slain enemy
		int goblin_goldgain = 5;
		goblin.setgold(goblin.getgold += goblin_goldgain);
		this->sethp(0);
		this->dead();
		} else {
		this->setup(Orcs_newhp);
	}
}

// when Orcs dies, it drops 2 normal pules of gold
void Orcs::dead();