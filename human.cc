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
	for(auto n: neighbors) {
		if (n.second->get_sym() == '@') {
			int tmp = rand() % 2;
			if (tmp == 0) {
				defender.beAttacked(*this);
			}	
		}
	}
}
	
void Human::beAttacked(Shade &shade) {
	int human_hp = this->gethp();
	int human_def = this->getdef();
	int attacker_atk = shade.getatk();
	// human is the defender
	int damagetaken = ceil((100/(100+human_def)) * attacker_atk);
	int human_newhp = human_hp - damagetaken;
	if(human_newhp <= 0){
		this->sethp(0);
		this->dead();
		int cur_gold = shade.getgold();
		shade.setgold(cur_gold+4);
		} else {
		this->sethp(human_newhp);
	}
}

void Human::beAttacked(Drow &drow) {
	int human_hp = this->gethp();
	int human_def = this->getdef();
	int attacker_atk = drow.getatk();
	// human is the defender
	int damagetaken = ceil((100/(100+human_def)) * attacker_atk);
	int human_newhp = human_hp - damagetaken;
	if(human_newhp <= 0){
		this->sethp(0);
		this->dead();
		int cur_gold = drow.getgold();
		drow.setgold(cur_gold+4);
		} else {
		this->sethp(human_newhp);
	}
}


void Human::beAttacked(Vampire &vampire) {
	int human_hp = this->gethp();
	int human_def = this->getdef();
	int vampire_atk = vampire.getatk();
	// human is the defender
	int damagetaken = ceil((100/(100+human_def)) * vampire_atk);
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
	}
}

void Human::beAttacked(Troll &troll){
	int human_hp = this->gethp();
	int human_def = this->getdef();
	int attacker_atk = troll.getatk();
	// human is the defender
	int damagetaken = ceil((100/(100+human_def)) * attacker_atk);
	int human_newhp = human_hp - damagetaken;
	if(human_newhp <= 0){
		this->sethp(0);
		this->dead();
		int cur_gold = troll.getgold();
		troll.setgold(cur_gold+4);
		} else {
		this->sethp(human_newhp);
	}
}

void Human::beAttacked(Goblin &goblin){
	int human_hp = this->gethp();
	int human_def = this->getdef();
	int attacker_atk = goblin.getatk();
	// human is the defender
	int damagetaken = ceil((100/(100+human_def)) * attacker_atk);
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
	}
}

// when human dies, it drops 2 normal pules of gold
