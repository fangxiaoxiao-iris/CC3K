#include "orcs.h"
#include <cmath>

using namespace std;

Orcs::Orcs(int row, int col, char sym, char prev, GameBoard* theBoard):
	 Enemy(row, col, sym, prev, theBoard) {
	sethp(180);
	setatk(30);
	setdef(25);
	setmaxhp(180);
	setgold(0);
	settype("Orcs");
}

Orcs::~Orcs() {}

void Orcs::attack(PC &defender){
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
	
void Orcs::beAttacked(Shade &shade) {
	int Orcs_hp = this->gethp();
	int Orcs_def = this->getdef();
	int attacker_atk = shade.getatk();
	// Orcs is the defender
	float d = (float)(100 * attacker_atk ) / (float)(100 + Orcs_def);
	int damagetaken = ceil(d);

	int Orcs_newhp = Orcs_hp - damagetaken;
	if(Orcs_newhp <= 0){
		this->sethp(0);
		this->dead();
		int goldnum;
		goldnum = rand() % 2;
		++goldnum;
		shade.setgold(shade.getgold() + goldnum);
		} else {
		this->sethp(Orcs_newhp);
		cout << this->gettype() << " has " << this->gethp() << " HP now." << endl;
	}
}

void Orcs::beAttacked(Drow &drow) {
	int Orcs_hp = this->gethp();
	int Orcs_def = this->getdef();
	int attacker_atk = drow.getatk();
	// Orcs is the defender
	float d = (float)(100 * attacker_atk ) / (float)(100 + Orcs_def);
	int damagetaken = ceil(d);

	int Orcs_newhp = Orcs_hp - damagetaken;
	if(Orcs_newhp <= 0){
		this->sethp(0);
		this->dead();
		int goldnum;
		goldnum = rand() % 2;
		++goldnum;
		drow.setgold(drow.getgold() + goldnum);
		} else {
		this->sethp(Orcs_newhp);
		cout << this->gettype() << " has " << this->gethp() << " HP now." << endl;
	}
}


void Orcs::beAttacked(Vampire &vampire) {
	int Orcs_hp = this->gethp();
	int Orcs_def = this->getdef();
	int attacker_atk = vampire.getatk();
	// Orcs is the defender
	float d = (float)(100 * attacker_atk ) / (float)(100 + Orcs_def);
	int damagetaken = ceil(d);

	int Orcs_newhp = Orcs_hp - damagetaken;
	// vampire gains 5 hp every successful attack
	int hp_gained = 5;
	vampire.sethp(vampire.gethp() + hp_gained);
	if(Orcs_newhp <= 0){
		this->sethp(0);
		this->dead();
		int goldnum;
		goldnum = rand() % 2;
		++goldnum;
		vampire.setgold(vampire.getgold() + goldnum);
		} else {
		this->sethp(Orcs_newhp);
		cout << this->gettype() << " has " << this->gethp() << " HP now." << endl;
	}
}

void Orcs::beAttacked(Troll &troll){
	int Orcs_hp = this->gethp();
	int Orcs_def = this->getdef();
	int attacker_atk = troll.getatk();
	// Orcs is the defender
	float d = (float)(100 * attacker_atk ) / (float)(100 + Orcs_def);
	int damagetaken = ceil(d);

	int Orcs_newhp = Orcs_hp - damagetaken;
	if(Orcs_newhp <= 0){
		this->sethp(0);
		this->dead();
		int goldnum;
		goldnum = rand() % 2;
		++goldnum;
		troll.setgold(troll.getgold() + goldnum);
		} else {
		this->sethp(Orcs_newhp);
		cout << this->gettype() << " has " << this->gethp() << " HP now." << endl;
	}
}

void Orcs::beAttacked(Goblin &goblin){
	int Orcs_hp = this->gethp();
	int Orcs_def = this->getdef();
	int attacker_atk = goblin.getatk();
	// Orcs is the defender
	float d = (float)(100 * attacker_atk ) / (float)(100 + Orcs_def);
	int damagetaken = ceil(d);
	
	int Orcs_newhp = Orcs_hp - damagetaken;
	if(Orcs_newhp <= 0){
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
		this->sethp(Orcs_newhp);
		cout << this->gettype() << " has " << this->gethp() << " HP now." << endl;
	}
}

void Orcs::beAttacked(Fairy &fairy) {
	int Orcs_hp = this->gethp();
	int Orcs_def = this->getdef();
	int attacker_atk = fairy.getatk();
	// Orcs is the defender
	float d = (float)(100 * attacker_atk ) / (float)(100 + Orcs_def);
	int damagetaken = ceil(d);

	int Orcs_newhp = Orcs_hp - damagetaken;
	if(Orcs_newhp <= 0){
		this->sethp(0);
		this->dead();
		int goldnum;
		goldnum = rand() % 2;
		++goldnum;
		fairy.setgold(fairy.getgold() + goldnum);
		} else {
		this->sethp(Orcs_newhp);
		cout << this->gettype() << " has " << this->gethp() << " HP now." << endl;
	}
}
