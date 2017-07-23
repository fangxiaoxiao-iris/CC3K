#ifndef SHADE_H
#define SHADE_H
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

class Shade: public PC {
	int maxhp;
public:
	Shade(int row, int col, char sym, char prev, GameBoard* theBoard); 
	// defualt ctor
	~Shade(); // dtors
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
