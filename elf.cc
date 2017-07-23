#include "elf.h"
#include <cmath>

using namespace std;

Elf::Elf(int row, int col, char sym, char prev, GameBoard* theBoard): 
	Enemy(row, col, sym, prev, theBoard) {
	sethp(140);
	setatk(30);
	setdef(10);
	setmaxhp(140);
	setgold(0);
	settype("Elf");
}

Elf::~Elf() {}

void Elf::attack(PC &defender){
	int tmp = rand() % 2;
	if(tmp == 0) {
	defender.beAttacked(*this);
}
}
	
void Elf::beAttacked(Shade &shade) {
	int Elf_hp = this->gethp();
	int Elf_def = this->getdef();
	int attacker_atk = shade.getatk();
	// Elf is the defender
	int damagetaken = ceil((100/(100+Elf_def)) * attacker_atk);
	int Elf_newhp = Elf_hp - damagetaken;
	if(Elf_newhp <= 0){
		this->sethp(0);
		this->dead();
		} else {
		this->sethp(Elf_newhp);
	}
}

void Elf::beAttacked(Drow &drow) {
	int Elf_hp = this->gethp();
	int Elf_def = this->getdef();
	int attacker_atk = drow.getatk();
	// Elf is the defender
	int damagetaken = ceil((100/(100+Elf_def)) * attacker_atk);
	int Elf_newhp = Elf_hp - damagetaken;
	if(Elf_newhp <= 0){
		this->sethp(0);
		this->dead();
		} else {
		this->sethp(Elf_newhp);
	}
}


void Elf::beAttacked(Vampire &vampire) {
	int Elf_hp = this->gethp();
	int Elf_def = this->getdef();
	int vampire_atk = vampire.getatk();
	// Elf is the defender
	int damagetaken = ceil((100/(100+Elf_def)) * vampire_atk);
	int Elf_newhp = Elf_hp - damagetaken;
	// vampire gains 5 hp every successful attack
	int hp_gained = 5;
	vampire.sethp(vampire.gethp() + hp_gained);
	if(Elf_newhp <= 0){
		this->sethp(0);
		this->dead();
		} else {
		this->sethp(Elf_newhp);
	}
}

void Elf::beAttacked(Troll &troll){
	int Elf_hp = this->gethp();
	int Elf_def = this->getdef();
	int attacker_atk = troll.getatk();
	// Elf is the defender
	int damagetaken = ceil((100/(100+Elf_def)) * attacker_atk);
	int Elf_newhp = Elf_hp - damagetaken;
	int hp_regain = 5;
	int troll_newhp = (troll.gethp() + hp_regain) > troll.getmaxhp() ? troll.getmaxhp() : troll.gethp() + hp_regain;
	if(Elf_newhp <= 0){
		this->sethp(0);
		this->dead();
		} else {
		this->sethp(troll_newhp);
	}
}

void Elf::beAttacked(Goblin &goblin){
	int Elf_hp = this->gethp();
	int Elf_def = this->getdef();
	int attacker_atk = goblin.getatk();
	// Elf is the defender
	int damagetaken = ceil((100/(100+Elf_def)) * attacker_atk);
	int Elf_newhp = Elf_hp - damagetaken;
	if(Elf_newhp <= 0){
		// goblin steals 5 gold from every slain enemy
		int goblin_goldgain = 5;
		goblin.setgold(goblin.getgold() + goblin_goldgain);
		this->sethp(0);
		this->dead();
		} else {
		this->sethp(Elf_newhp);
	}
}
