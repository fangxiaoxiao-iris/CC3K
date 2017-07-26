#include "human.h"
#include <cmath>

using namespace std;

Human::Human(int row, int col, char sym, char prev, GameBoard* theBoard): 
	Enemy(row, col, sym, prev, theBoard) {
	sethp(140);
	setatk(20);
	setdef(20);
	setmaxhp(140);
	setgold(0);
	settype("Human");
}

Human::~Human() {}

void Human::attack(PC &defender){
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
	
void Human::beAttacked(Shade &shade) {
	int human_hp = this->gethp();
	int human_def = this->getdef();
	int attacker_atk = shade.getatk();
	// human is the defender
	float d = (float)(100 * attacker_atk ) / (float)(100 + human_def);
	int damagetaken = ceil(d);

	int human_newhp = human_hp - damagetaken;
	if(human_newhp <= 0){
		this->sethp(0);
		this->dead();
		int cur_gold = shade.getgold();
		shade.setgold(cur_gold+4);
		} else {
		this->sethp(human_newhp);
		cout << "Enemy: " << this->gettype() << " has " << this->gethp() << " HP now." << endl;
	}
}

void Human::beAttacked(Drow &drow) {
	int human_hp = this->gethp();
	int human_def = this->getdef();
	int attacker_atk = drow.getatk();
	// human is the defender
	float d = (float)(100 * attacker_atk ) / (float)(100 + human_def);
	int damagetaken = ceil(d);

	int human_newhp = human_hp - damagetaken;
	if(human_newhp <= 0){
		this->sethp(0);
		this->dead();
		int cur_gold = drow.getgold();
		drow.setgold(cur_gold+4);
		} else {
		this->sethp(human_newhp);
		cout << this->gettype() << " has " << this->gethp() << " HP now." << endl;
	}
}


void Human::beAttacked(Vampire &vampire) {
	int human_hp = this->gethp();
	int human_def = this->getdef();
	int attacker_atk = vampire.getatk();
	// human is the defender
	float d = (float)(100 * attacker_atk ) / (float)(100 + human_def);
	int damagetaken = ceil(d);

	int human_newhp = human_hp - damagetaken;
	// vampire gains 5 hp every successful attack
	int hp_gained = 5;
	vampire.sethp(vampire.gethp() + hp_gained);
	if(human_newhp <= 0){
		this->sethp(0);
		this->dead();
		int cur_gold = vampire.getgold();
		vampire.setgold(cur_gold+4);
		} else {
		this->sethp(human_newhp);
		cout << this->gettype() << " has " << this->gethp() << " HP now." << endl;
	}
}

void Human::beAttacked(Troll &troll){
	int human_hp = this->gethp();
	int human_def = this->getdef();
	int attacker_atk = troll.getatk();
	// human is the defender
	float d = (float)(100 * attacker_atk ) / (float)(100 + human_def);
	int damagetaken = ceil(d);

	int human_newhp = human_hp - damagetaken;
	if(human_newhp <= 0){
		this->sethp(0);
		this->dead();
		int cur_gold = troll.getgold();
		troll.setgold(cur_gold+4);
		} else {
		this->sethp(human_newhp);
		cout << this->gettype() << " has " << this->gethp() << " HP now." << endl;
	}
}

void Human::beAttacked(Goblin &goblin){
	int human_hp = this->gethp();
	int human_def = this->getdef();
	int attacker_atk = goblin.getatk();
	// human is the defender
	float d = (float)(100 * attacker_atk ) / (float)(100 + human_def);
	int damagetaken = ceil(d);

	int human_newhp = human_hp - damagetaken;
	if(human_newhp <= 0){
		// goblin steals 5 gold from every slain enemy
		int goblin_goldgain = 5;
		goblin.setgold(goblin.getgold() + goblin_goldgain);
		this->sethp(0);
		this->dead();
		int cur_gold = goblin.getgold();
		goblin.setgold(cur_gold+4);
		} else {
		this->sethp(human_newhp);
		cout << this->gettype() << " has " << this->gethp() << " HP now." << endl;
	}
}

// when human dies, it drops 2 normal pules of gold
void Human::beAttacked(Fairy &fairy) {
	int human_hp = this->gethp();
	int human_def = this->getdef();
	int attacker_atk = fairy.getatk();
	// human is the defender
	float d = (float)(100 * attacker_atk ) / (float)(100 + human_def);
	int damagetaken = ceil(d);

	int human_newhp = human_hp - damagetaken;
	if(human_newhp <= 0){
		this->sethp(0);
		this->dead();
		int cur_gold = fairy.getgold();
		fairy.setgold(cur_gold+4);
		} else {
		this->sethp(human_newhp);
		cout << this->gettype() << " has " << this->gethp() << " HP now." << endl;
	}
}
