#ifndef _HALFLING_H_
#define _HALFLING_H_

#include "enemy.h"

class PC;
class Shade;
class Drow;
class Vampire;
class Troll;
class Goblin;

class Halfling: public Enemy {
public:
	// default ctor
	Halfling(int row, int col, char sym, char prev, GameBoard* theBoard);
	// dtor
	~Halfling();

	// method for attack
	void attack(PC &defender) override;

	// methods for beAttacked by PC 
	// PC is the attacker and Halfling is the defender
	void beAttacked(Shade &shade) override;
	void beAttacked(Drow &drow) override;
	void beAttacked(Vampire &vampire) override;
	void beAttacked(Troll &troll) override;
	void beAttacked(Goblin &goblin) override;
};

#endif

