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
	settype("Halfling");
}

Halfling::~Halfling() {}

void Halfling::attack(PC &defender){
	for(auto n: getNeigh()) {
		if (n.second->get_sym() == '@') {
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

// halfling has a 50% chance to cause the pc to miss in combat
void Halfling::beAttacked(Shade &shade) {
	int tmp = rand() % 2;
	if(tmp == 0) {
	int Halfling_hp = this->gethp();
	int Halfling_def = this->getdef();
	int attacker_atk = shade.getatk();
	// Halfling is the defender
	float d = (float)(100 * attacker_atk ) / (float)(100 + Halfling_def);
	int damagetaken = ceil(d);

	int Halfling_newhp = Halfling_hp - damagetaken;
	if(Halfling_newhp <= 0){
		this->sethp(0);
		this->dead();
		int goldnum;
		goldnum = rand() % 2;
		++goldnum;
		shade.setgold(shade.getgold() + goldnum);
		} else {
		this->sethp(Halfling_newhp);
		cout << this->gettype() << " has " << this->gethp() << " HP now." << endl;
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
	float d = (float)(100 * attacker_atk ) / (float)(100 + Halfling_def);
	int damagetaken = ceil(d);

	int Halfling_newhp = Halfling_hp - damagetaken;
	if(Halfling_newhp <= 0){
		this->sethp(0);
		this->dead();
		int goldnum;
		goldnum = rand() % 2;
		++goldnum;
		drow.setgold(drow.getgold() + goldnum);
		} else {
		this->sethp(Halfling_newhp);
		cout << this->gettype() << " has " << this->gethp() << " HP now." << endl;
	}
}
}


void Halfling::beAttacked(Vampire &vampire) {
	int tmp = rand() % 2;
	if(tmp == 0) {
	int Halfling_hp = this->gethp();
	int Halfling_def = this->getdef();
	int attacker_atk = vampire.getatk();
	// Halfling is the defender
	float d = (float)(100 * attacker_atk ) / (float)(100 + Halfling_def);
	int damagetaken = ceil(d);

	int Halfling_newhp = Halfling_hp - damagetaken;
	// vampire gains 5 hp every successful attack
	int hp_gained = 5;
	vampire.sethp(vampire.gethp() + hp_gained);
	if(Halfling_newhp <= 0){
		this->sethp(0);
		this->dead();
		int goldnum;
		goldnum = rand() % 2;
		++goldnum;
		vampire.setgold(vampire.getgold() + goldnum);
		} else {
		this->sethp(Halfling_newhp);
		cout << this->gettype() << " has " << this->gethp() << " HP now." << endl;
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
	float d = (float)(100 * attacker_atk ) / (float)(100 + Halfling_def);
	int damagetaken = ceil(d);
	
	int Halfling_newhp = Halfling_hp - damagetaken;
	if(Halfling_newhp <= 0){
		this->sethp(0);
		this->dead();
		int goldnum;
		goldnum = rand() % 2;
		++goldnum;
		troll.setgold(troll.getgold() + goldnum);
		} else {
		this->sethp(Halfling_newhp);
		cout << this->gettype() << " has " << this->gethp() << " HP now." << endl;
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
		goblin.setgold(goblin.getgold() + goblin_goldgain);
		this->sethp(0);
		this->dead();
		int goldnum;
		goldnum = rand() % 2;
		++goldnum;
		goblin.setgold(goblin.getgold() + goldnum);
		} else {
		this->sethp(Halfling_newhp);
		cout << this->gettype() << " has " << this->gethp() << " HP now." << endl;
	}
}
}

void Halfling::beAttacked(Fairy &fairy) {
	int tmp = rand() % 2;
	if(tmp == 0) {
	int Halfling_hp = this->gethp();
	int Halfling_def = this->getdef();
	int attacker_atk = fairy.getatk();
	// Halfling is the defender
	float d = (float)(100 * attacker_atk ) / (float)(100 + Halfling_def);
	int damagetaken = ceil(d);

	int Halfling_newhp = Halfling_hp - damagetaken;
	if(Halfling_newhp <= 0){
		this->sethp(0);
		this->dead();
		int goldnum;
		goldnum = rand() % 2;
		++goldnum;
		fairy.setgold(fairy.getgold() + goldnum);
		} else {
		this->sethp(Halfling_newhp);
		cout << this->gettype() << " has " << this->gethp() << " HP now." << endl;
	}
}
}
