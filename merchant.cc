#include "merchant.h"
#include <cmath>

using namespace std;

Merchant::Merchant(int row, int col, char sym, char prev, GameBoard* theBoard): 
	Enemy(row, col, sym, prev, theBoard), isHostile(false) {
	sethp(30);
	setatk(70);
	setdef(5);
	setmaxhp(30);
	setgold(0);
	settype("Merchant")
}

Merchant::~Merchant() {}

void Merchant::attack(PC &defender){
	int tmp = rand() % 2;
	// when merchant is hostile it will attack pc
	if(tmp == 0 && this->isHostile == true) {
	defender.beAttacked(*this);
}
}

// once merchant was attacked, set time filed isHostile to true	
void Merchant::beAttacked(Shade &shade) {
	int Merchant_hp = this->gethp();
	int Merchant_def = this->getdef();
	int attacker_atk = shade.getatk();
	// Merchant is the defender
	int damagetaken = ceil((100/(100+Merchant_def)) * attacker_atk);
	int Merchant_newhp = Merchant_hp - damagetaken;
	this->isHostile = true;
	if(Merchant_newhp <= 0){
		this->sethp(0);
		this->dead();
		} else {
		this->sethp(Merchant_newhp);
	}
}

void Merchant::beAttacked(Drow &drow) {
	int Merchant_hp = this->gethp();
	int Merchant_def = this->getdef();
	int attacker_atk = drow.getatk();
	// Merchant is the defender
	int damagetaken = ceil((100/(100+Merchant_def)) * attacker_atk);
	int Merchant_newhp = Merchant_hp - damagetaken;
	this->isHostile = true;
	if(Merchant_newhp <= 0){
		this->sethp(0);
		this->dead();
		} else {
		this->sethp(Merchant_newhp);
	}
}


void Merchant::beAttacked(Vampire &vampire) {
	int Merchant_hp = this->gethp();
	int Merchant_def = this->getdef();
	int vampire_atk = vampire.getatk();
	// Merchant is the defender
	int damagetaken = ceil((100/(100+Merchant_def)) * attacker_atk);
	int Merchant_newhp = Merchant_hp - damagetaken;
	// vampire gains 5 hp every successful attack
	int hp_gained = 5;
	vampire.sethp(vampire.hp + hp_gained);
	this->isHostile = true;
	if(Merchant_newhp <= 0){
		this->sethp(0);
		this->dead();
		} else {
		this->sethp(Merchant_newhp);
	}
}

void Merchant::beAttacked(Troll &troll){
	int Merchant_hp = this->gethp();
	int Merchant_def = this->getdef();
	int attacker_atk = troll.getatk();
	// Merchant is the defender
	int damagetaken = ceil((100/(100+Merchant_def)) * attacker_atk);
	int Merchant_newhp = Merchant_hp - damagetaken;
	int hp_regain = 5;
	int troll_newhp = (troll.hp + hp_regain) > troll.maxhp ? troll.maxhp : troll.hp + hp_regain;
	this->isHostile = true;
	if(Merchant_newhp <= 0){
		this->sethp(0);
		this->dead();
		} else {
		this->sethp(Merchant_newhp);
	}
}

void Merchant::beAttacked(Goblin &goblin){
	int Merchant_hp = this->gethp();
	int Merchant_def = this->getdef();
	int attacker_atk = goblin.getatk();
	// Merchant is the defender
	int damagetaken = ceil((100/(100+Merchant_def)) * attacker_atk);
	int Merchant_newhp = Merchant_hp - damagetaken;
	this->isHostile = true;
	if(Merchant_newhp <= 0){
		// goblin steals 5 gold from every slain enemy
		int goblin_goldgain = 5;
		goblin.setgold(goblin.getgold += goblin_goldgain);
		this->sethp(0);
		this->dead();
		} else {
		this->sethp(Merchant_newhp);
	}
}
