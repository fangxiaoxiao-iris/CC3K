#ifndef _DWARF_H_
#define _DWARF_H_

#include "enemy.h"

class PC;
class Shade;
class Drow;
class Vampire;
class Troll;
class Goblin;

class Dwarf: public Enemy {
public:
	// default ctor
	Dwarf(int row, int col, char sym, char prev, GameBoard* theBoard);
	// dtor
	~Dwarf();

	// method for attack
	void attack(PC &defender) override;

	// methods for beAttacked by PC 
	// PC is the attacker and dwarf is the defender
	void beAttacked(Shade &shade) override;
	void beAttacked(Drow &drow) override;
	void beAttacked(Vampire &vampire) override;
	void beAttacked(Troll &troll) override;
	void beAttacked(Goblin &goblin) override;
};

#endif

