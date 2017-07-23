#ifndef TROLL_H
#define TROLL_H
#include "PC.h"

class GameBoard;
class Enemy;
class Dragon;
class Human;
class Dwarf;
class Elf;
class Halfling;
class Orcs;
class Merchant;

class Troll: public PC {
	Troll(int row, int col, char sym, char prev, GameBoard* theBoard); 
	// defualt ctor
	~Troll(); // dtors
	void attack(Enemy &e) override;
	void beAttacked(Human &hu) override;
	void beAttacked(Dwarf &dw) override;
	void beAttacked(Elf &el) override;
	void beAttacked(Dragon &dr) override;
	void beAttacked(Halfling &ha) override;
	void beAttacked(Orcs &o) override;
	void beAttacked(Merchant &m) override;
};

#endif
