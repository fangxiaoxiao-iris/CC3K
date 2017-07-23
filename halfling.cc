#include "halfling.h"
#include <cmath>

using namespace std;

Halfling::Halfling(int row, int col, char sym, char prev, GameBoard* theBoard):
	Enemy(row, col, sym, prev, theBoard) {
	sethp(100);
	setatk(15);
	setdef(20);
	setmaxhp(100);
	setgold(0);
	settype("Halfling")
}

Halfling::~Halfling() {}

void Halfling::attack(PC &defender){
	int tmp = rand() % 2;
	if(tmp == 0) {
	defender.beAttacked(*this);
}
}

// halfling has a 50% chance to cause the pc to miss in combat
void Halfling::beAttacked(Shade &shade) {
	int tmp = rand() % 2;
	if(tmp == 0) {
	int Halfling_hp = this->gethp();
	int Halfling_def = this->getdef();
	int attacker_atk = shade.getatk();
	// Halfling is the defender
	int damagetaken = ceil((100/(100+Halfling_def)) * attacker_atk);
	int Halfling_newhp = Halfling_hp - damagetaken;
	if(Halfling_newhp <= 0){
		this->sethp(0);
		this->dead();
		this->setsym('.');
		} else {
		this->setup(Halfling_newhp);
	}
}
}

void Halfling::beAttacked(Drow &drow) {
	int tmp = rand() % 2;
	if(tmp == 0) {
	int Halfling_hp = this->gethp();
	int Halfling_def = this->getdef();
	int attacker_atk = drow.getatk();
	// Halfling is the defender
	int damagetaken = ceil((100/(100+Halfling_def)) * attacker_atk);
	int Halfling_newhp = Halfling_hp - damagetaken;
	if(Halfling_newhp <= 0){
		this->sethp(0);
		this->dead();
		this->setsym('.');
		} else {
		this->setup(Halfling_newhp);
	}
}
}


void Halfling::beAttacked(Vampire &vampire) {
	int tmp = rand() % 2;
	if(tmp == 0) {
	int Halfling_hp = this->gethp();
	int Halfling_def = this->getdef();
	int vampire_atk = vampire.getatk();
	// Halfling is the defender
	int damagetaken = ceil((100/(100+Halfling_def)) * attacker_atk);
	int Halfling_newhp = Halfling_hp - damagetaken;
	// vampire gains 5 hp every successful attack
	int hp_gained = 5;
	vampire.sethp(vampire.hp + hp_gained);
	if(Halfling_newhp <= 0){
		this->sethp(0);
		this->dead();
		this->setsym('.');
		} else {
		this->setup(Halfling_newhp);
	}
}
}

void Halfling::beAttacked(Troll &troll){
	int tmp = rand() % 2;
	if(tmp == 0) {
	int Halfling_hp = this->gethp();
	int Halfling_def = this->getdef();
	int attacker_atk = troll.getatk();
	// Halfling is the defender
	int damagetaken = ceil((100/(100+Halfling_def)) * attacker_atk);
	int Halfling_newhp = Halfling_hp - damagetaken;
	int hp_regain = 5;
	int troll_newhp = (troll.hp + hp_regain) > troll.maxhp ? troll.maxhp : troll.hp + hp_regain;
	if(Halfling_newhp <= 0){
		this->sethp(0);
		this->dead();
		this->setsym('.');
		} else {
		this->setup(Halfling_newhp);
	}
}
}

void Halfling::beAttacked(Goblin &goblin){
	int tmp = rand() % 2;
	if(tmp == 0) {
	int Halfling_hp = this->gethp();
	int Halfling_def = this->getdef();
	int attacker_atk = goblin.getatk();
	// Halfling is the defender
	int damagetaken = ceil((100/(100+Halfling_def)) * attacker_atk);
	int Halfling_newhp = Halfling_hp - damagetaken;
	if(Halfling_newhp <= 0){
		// goblin steals 5 gold from every slain enemy
		int goblin_goldgain = 5;
		goblin.setgold(goblin.getgold += goblin_goldgain);
		this->sethp(0);
		this->dead();
		this->setsym('.');
		} else {
		this->setup(Halfling_newhp);
	}
}
}

