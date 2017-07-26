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
	bool attacked = false;
	for(auto n: getNeigh()) {
		if (n.second->get_sym() == '@') {
			int tmp = rand() % 2;
			if (tmp == 0) {
				defender.beAttacked(*this);
			}
			attacked = true;	
		}
	}
	for(auto m: getNeigh()) {
		if (m.second->getItemType() == "dragon_h") {
			for (auto i: m.second->getNeigh()) {
				if (i.second->get_sym() == '@' && attacked != true) {
					int tmp = rand() % 2;
					if (tmp == 0) {
						defender.beAttacked(*this);
					}
					if(tmp == 1) {
						cout << "Oops! " << "Enemy: " << this->gettype() << " misses his attack!" << endl;
					}
				}	
			}		
		}
	}
}
	
void Dragon::beAttacked(Shade &shade) {
	int Dragon_hp = this->gethp();
	int Dragon_def = this->getdef();
	int attacker_atk = shade.getatk();
	// Dragon is the defender
	float d = (float)(100 * attacker_atk ) / (float)(100 + Dragon_def);
	int damagetaken = ceil(d);

	int Dragon_newhp = Dragon_hp - damagetaken;
	if(Dragon_newhp <= 0){
		this->sethp(0);
		this->dead();
		for(auto m: getNeigh()) {
			if (m.second->getItemType() == "dragon_h") {
				m.second->setavailable(true);		
			}
		}
	} else {
		this->sethp(Dragon_newhp);
		cout << this->gettype() << " has " << this->gethp() << " HP now." << endl;
	}
}

void Dragon::beAttacked(Drow &drow) {
	int Dragon_hp = this->gethp();
	int Dragon_def = this->getdef();
	int attacker_atk = drow.getatk();
	// Dragon is the defender
	float d = (float)(100 * attacker_atk ) / (float)(100 + Dragon_def);
	int damagetaken = ceil(d);

	int Dragon_newhp = Dragon_hp - damagetaken;
	if(Dragon_newhp <= 0){
		this->sethp(0);
		this->dead();
		for(auto m: getNeigh()) {
			if (m.second->getItemType() == "dragon_h") {
				m.second->setavailable(true);		
			}
		}
	} else {
		this->sethp(Dragon_newhp);
		cout << this->gettype() << " has " << this->gethp() << " HP now." << endl;
	}
}


void Dragon::beAttacked(Vampire &vampire) {
	int Dragon_hp = this->gethp();
	int Dragon_def = this->getdef();
	int attacker_atk = vampire.getatk();
	// Dragon is the defender
	float d = (float)(100 * attacker_atk ) / (float)(100 + Dragon_def);
	int damagetaken = ceil(d);

	int Dragon_newhp = Dragon_hp - damagetaken;
	// vampire gains 5 hp every successful attack
	int hp_gained = 5;
	vampire.sethp(vampire.gethp() + hp_gained);
	if(Dragon_newhp <= 0){
		this->sethp(0);
		this->dead();
		for(auto m: getNeigh()) {
			if (m.second->getItemType() == "dragon_h") {
				m.second->setavailable(true);		
			}
		}
	} else {
		this->sethp(Dragon_newhp);
		cout << this->gettype() << " has " << this->gethp() << " HP now." << endl;
	}
}

void Dragon::beAttacked(Troll &troll){
	int Dragon_hp = this->gethp();
	int Dragon_def = this->getdef();
	int attacker_atk = troll.getatk();
	// Dragon is the defender
	float d = (float)(100 * attacker_atk ) / (float)(100 + Dragon_def);
	int damagetaken = ceil(d);

	int Dragon_newhp = Dragon_hp - damagetaken;
	if(Dragon_newhp <= 0){
		this->sethp(0);
		this->dead();
		for(auto m: getNeigh()) {
			if (m.second->getItemType() == "dragon_h") {
				m.second->setavailable(true);		
			}
		}
	} else {
		this->sethp(Dragon_newhp);
		cout << this->gettype() << " has " << this->gethp() << " HP now." << endl;
	}
}

void Dragon::beAttacked(Goblin &goblin){
	int Dragon_hp = this->gethp();
	int Dragon_def = this->getdef();
	int attacker_atk = goblin.getatk();
	// Dragon is the defender
	float d = (float)(100 * attacker_atk ) / (float)(100 + Dragon_def);
	int damagetaken = ceil(d);
	
	int Dragon_newhp = Dragon_hp - damagetaken;
	if(Dragon_newhp <= 0){
		// goblin steals 5 gold from every slain enemy
		int goblin_goldgain = 5;
		goblin.setgold(goblin.getgold() + goblin_goldgain);
		this->sethp(0);
		this->dead();
		for(auto m: getNeigh()) {
			if (m.second->getItemType() == "dragon_h") {
				m.second->setavailable(true);		
			}
		}
	} else {
		this->sethp(Dragon_newhp);
		cout << this->gettype() << " has " << this->gethp() << " HP now." << endl;
	}
}

void Dragon::beAttacked(Fairy &fairy) {
	int Dragon_hp = this->gethp();
	int Dragon_def = this->getdef();
	int attacker_atk = fairy.getatk();
	// Dragon is the defender
	float d = (float)(100 * attacker_atk ) / (float)(100 + Dragon_def);
	int damagetaken = ceil(d);

	int Dragon_newhp = Dragon_hp - damagetaken;
	if(Dragon_newhp <= 0){
		this->sethp(0);
		this->dead();
		for(auto m: getNeigh()) {
			if (m.second->getItemType() == "dragon_h") {
				m.second->setavailable(true);		
			}
		}
	} else {
		this->sethp(Dragon_newhp);
		cout << this->gettype() << " has " << this->gethp() << " HP now." << endl;
	}
}

void Dragon::move() {}
