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
	settype("Merchant");
}

Merchant::~Merchant() {}

void Merchant::attack(PC &defender){
	for(auto n: getNeigh()) {
		if (n.second->get_sym() == '@') {
			int tmp = rand() % 2;
			if (tmp == 0 && this->isHostile == true) {
				defender.beAttacked(*this);
			}
			if(tmp == 1 && this->isHostile == true) {
						cout << "Oops! " << "Enemy: " << this->gettype() << " misses his attack!" << endl;
					}	
		}
	}
	/*
	int tmp = rand() % 2;
	// when merchant is hostile it will attack pc
	if(tmp == 0 && this->isHostile == true) {
	defender.beAttacked(*this);
}*/
}

// once merchant was attacked, set time filed isHostile to true	
void Merchant::beAttacked(Shade &shade) {
	int Merchant_hp = this->gethp();
	int Merchant_def = this->getdef();
	int attacker_atk = shade.getatk();
	// Merchant is the defender
	float d = (float)(100 * attacker_atk ) / (float)(100 + Merchant_def);
	int damagetaken = ceil(d);

	int Merchant_newhp = Merchant_hp - damagetaken;
	this->isHostile = true;
	if(Merchant_newhp <= 0){
		this->sethp(0);
		this->dead();
		} else {
		this->sethp(Merchant_newhp);
		cout << this->gettype() << " has " << this->gethp() << " HP now." << endl;
	}
}

void Merchant::beAttacked(Drow &drow) {
	int Merchant_hp = this->gethp();
	int Merchant_def = this->getdef();
	int attacker_atk = drow.getatk();
	// Merchant is the defender
	float d = (float)(100 * attacker_atk ) / (float)(100 + Merchant_def);
	int damagetaken = ceil(d);

	int Merchant_newhp = Merchant_hp - damagetaken;
	this->isHostile = true;
	if(Merchant_newhp <= 0){
		this->sethp(0);
		this->dead();
		} else {
		this->sethp(Merchant_newhp);
		cout << this->gettype() << " has " << this->gethp() << " HP now." << endl;
	}
}


void Merchant::beAttacked(Vampire &vampire) {
	int Merchant_hp = this->gethp();
	int Merchant_def = this->getdef();
	int attacker_atk = vampire.getatk();
	// Merchant is the defender
	float d = (float)(100 * attacker_atk ) / (float)(100 + Merchant_def);
	int damagetaken = ceil(d);

	int Merchant_newhp = Merchant_hp - damagetaken;
	// vampire gains 5 hp every successful attack
	int hp_gained = 5;
	vampire.sethp(vampire.gethp() + hp_gained);
	this->isHostile = true;
	if(Merchant_newhp <= 0){
		this->sethp(0);
		this->dead();
		} else {
		this->sethp(Merchant_newhp);
		cout << this->gettype() << " has " << this->gethp() << " HP now." << endl;
	}
}

void Merchant::beAttacked(Troll &troll){
	int Merchant_hp = this->gethp();
	int Merchant_def = this->getdef();
	int attacker_atk = troll.getatk();
	// Merchant is the defender
	float d = (float)(100 * attacker_atk ) / (float)(100 + Merchant_def);
	int damagetaken = ceil(d);

	int Merchant_newhp = Merchant_hp - damagetaken;
	this->isHostile = true;
	if(Merchant_newhp <= 0){
		this->sethp(0);
		this->dead();
		} else {
		this->sethp(Merchant_newhp);
		cout << this->gettype() << " has " << this->gethp() << " HP now." << endl;
	}
}

void Merchant::beAttacked(Goblin &goblin){
	int Merchant_hp = this->gethp();
	int Merchant_def = this->getdef();
	int attacker_atk = goblin.getatk();
	// Merchant is the defender
	float d = (float)(100 * attacker_atk ) / (float)(100 + Merchant_def);
	int damagetaken = ceil(d);
	
	int Merchant_newhp = Merchant_hp - damagetaken;
	this->isHostile = true;
	if(Merchant_newhp <= 0){
		// goblin steals 5 gold from every slain enemy
		int goblin_goldgain = 5;
		goblin.setgold(goblin.getgold() + goblin_goldgain);
		this->sethp(0);
		this->dead();
		} else {
		this->sethp(Merchant_newhp);
		cout << this->gettype() << " has " << this->gethp() << " HP now." << endl;
	}
}

void Merchant::beAttacked(Fairy &fairy) {
	int Merchant_hp = this->gethp();
	int Merchant_def = this->getdef();
	int attacker_atk = fairy.getatk();
	// Merchant is the defender
	float d = (float)(100 * attacker_atk ) / (float)(100 + Merchant_def);
	int damagetaken = ceil(d);

	int Merchant_newhp = Merchant_hp - damagetaken;
	this->isHostile = true;
	if(Merchant_newhp <= 0){
		this->sethp(0);
		this->dead();
		} else {
		this->sethp(Merchant_newhp);
		cout << this->gettype() << " has " << this->gethp() << " HP now." << endl;
	}
}
