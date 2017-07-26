#include "dwarf.h"
#include <cmath>

using namespace std;

Dwarf::Dwarf(int row, int col, char sym, char prev, GameBoard* theBoard): 
	Enemy(row, col, sym, prev, theBoard) {
	sethp(100);
	setatk(20);
	setdef(30);
	setmaxhp(100);
	setgold(0);
	settype("Dwarf");
}

Dwarf::~Dwarf() {}

void Dwarf::attack(PC &defender){
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
	
void Dwarf::beAttacked(Shade &shade) {
	int Dwarf_hp = this->gethp();
	int Dwarf_def = this->getdef();
	int attacker_atk = shade.getatk();
	// Dwarf is the defender
	float d = (float)(100 * attacker_atk ) / (float)(100 + Dwarf_def);
	int damagetaken = ceil(d);

	int Dwarf_newhp = Dwarf_hp - damagetaken;
	if(Dwarf_newhp <= 0){
		this->sethp(0);
		this->dead();
		int goldnum;
		goldnum = rand() % 2;
		++goldnum;
		shade.setgold(shade.getgold() + goldnum);
		} else {
		this->sethp(Dwarf_newhp);
		cout << this->gettype() << " has " << this->gethp() << " HP now." << endl;
	}
}

void Dwarf::beAttacked(Drow &drow) {
	int Dwarf_hp = this->gethp();
	int Dwarf_def = this->getdef();
	int attacker_atk = drow.getatk();
	// Dwarf is the defender
	float d = (float)(100 * attacker_atk ) / (float)(100 + Dwarf_def);
	int damagetaken = ceil(d);

	int Dwarf_newhp = Dwarf_hp - damagetaken;
	if(Dwarf_newhp <= 0){
		this->sethp(0);
		this->dead();
		int goldnum;
		goldnum = rand() % 2;
		++goldnum;
		drow.setgold(drow.getgold() + goldnum);
		} else {
		this->sethp(Dwarf_newhp);
		cout << this->gettype() << " has " << this->gethp() << " HP now." << endl;
	}
}


void Dwarf::beAttacked(Vampire &vampire) {
	int Dwarf_hp = this->gethp();
	int Dwarf_def = this->getdef();
	int attacker_atk = vampire.getatk();
	// Dwarf is the defender
	float d = (float)(100 * attacker_atk ) / (float)(100 + Dwarf_def);
	int damagetaken = ceil(d);

	int Dwarf_newhp = Dwarf_hp - damagetaken;
	// vampire loses 5 hp every successful attack
	int hp_lost = 5;
	int vam_newhp = vampire.gethp() - hp_lost;

	// after attack changes on dwarf
	if(Dwarf_newhp <= 0){
		this->sethp(0);
		this->dead();
		int goldnum;
		goldnum = rand() % 2;
		++goldnum;
		vampire.setgold(vampire.getgold() + goldnum);
		} else {
		this->sethp(Dwarf_newhp);
		cout << this->gettype() << " has " << this->gethp() << " HP now." << endl;
	}

	// after attack changes on vampire
	if(vam_newhp <= 0) {
		vampire.sethp(0);
	} else {
		vampire.sethp(vam_newhp);
	}
}

void Dwarf::beAttacked(Troll &troll){
	int Dwarf_hp = this->gethp();
	int Dwarf_def = this->getdef();
	int attacker_atk = troll.getatk();
	// Dwarf is the defender
	float d = (float)(100 * attacker_atk ) / (float)(100 + Dwarf_def);
	int damagetaken = ceil(d);

	int Dwarf_newhp = Dwarf_hp - damagetaken;
	int hp_regain = 5;
	int troll_newhp = (troll.gethp() + hp_regain) > troll.getmaxhp() ? troll.getmaxhp() : troll.gethp() + hp_regain;
	if(Dwarf_newhp <= 0){
		this->sethp(0);
		this->dead();
		int goldnum;
		goldnum = rand() % 2;
		++goldnum;
		troll.setgold(troll.getgold() + goldnum);
		} else {
		this->sethp(troll_newhp);
		cout << this->gettype() << " has " << this->gethp() << " HP now." << endl;
	}
}

void Dwarf::beAttacked(Goblin &goblin){
	int Dwarf_hp = this->gethp();
	int Dwarf_def = this->getdef();
	int attacker_atk = goblin.getatk();
	// Dwarf is the defender
	float d = (float)(100 * attacker_atk ) / (float)(100 + Dwarf_def);
	int damagetaken = ceil(d);
	
	int Dwarf_newhp = Dwarf_hp - damagetaken;
	if(Dwarf_newhp <= 0){
		// goblin steals 5 gold from every slain Enemy
		int goblin_goldgain = 5;
		goblin.setgold(goblin.getgold() + goblin_goldgain);
		this->sethp(0);
		this->dead();
		int goldnum;
		goldnum = rand() % 2;
		++goldnum;
		goblin.setgold(goblin.getgold() + goldnum);
		} else {
		this->sethp(Dwarf_newhp);
		cout << this->gettype() << " has " << this->gethp() << " HP now." << endl;
	}
}

void Dwarf::beAttacked(Fairy &fairy) {
	int Dwarf_hp = this->gethp();
	int Dwarf_def = this->getdef();
	int attacker_atk = fairy.getatk();
	// Dwarf is the defender
	float d = (float)(100 * attacker_atk ) / (float)(100 + Dwarf_def);
	int damagetaken = ceil(d);

	int Dwarf_newhp = Dwarf_hp - damagetaken;
	if(Dwarf_newhp <= 0){
		this->sethp(0);
		this->dead();
		int goldnum;
		goldnum = rand() % 2;
		++goldnum;
		fairy.setgold(fairy.getgold() + goldnum);
		} else {
		this->sethp(Dwarf_newhp);
		cout << this->gettype() << " has " << this->gethp() << " HP now." << endl;
	}
}
