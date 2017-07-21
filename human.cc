#include "human.h"
#include <cmath>

using namespace std;

Human::Human(): Enemy() {
	sethp(140);
	setatk(20);
	setdef(20);
	setmaxhp(140);
	setgold(0);
	settype("Human")
}

Human::~Human() {}

void Human::attack(PC &defender){
	int tmp = rand() % 2;
	if(tmp == 0) {
	defender.beAttacked(*this);
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
		} else {
		this->setup(human_newhp);
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
		} else {
		this->setup(human_newhp);
	}
}


void Human::beAttacked(Vampire &vampire) {
	int human_hp = this->gethp();
	int human_def = this->getdef();
	int vampire_atk = vampire.getatk();
	// human is the defender
	int damagetaken = ceil((100/(100+human_def)) * attacker_atk);
	int human_newhp = human_hp - damagetaken;
	// vampire gains 5 hp every successful attack
	int hp_gained = 5;
	vampire->sethp(vampire.hp + hp_gained);
	if(human_newhp <= 0){
		this->sethp(0);
		this->dead();
		} else {
		this->setup(human_newhp);
	}
}

void Human::beAttacked(Troll &troll){
	int human_hp = this->gethp();
	int human_def = this->getdef();
	int attacker_atk = troll.getatk();
	// human is the defender
	int damagetaken = ceil((100/(100+human_def)) * attacker_atk);
	int human_newhp = human_hp - damagetaken;
	int hp_regain = 5;
	int troll_newhp = (troll.hp + hp_regain) > troll.maxhp ? troll.maxhp : troll.hp + hp_regain;
	if(human_newhp <= 0){
		this->sethp(0);
		this->dead();
		} else {
		this->setup(human_newhp);
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
		goblin.setgold(goblin.getgold += goblin_goldgain);
		this->sethp(0);
		this->dead();
		} else {
		this->setup(human_newhp);
	}
}

// when human dies, it drops 2 normal pules of gold
void Human::dead();