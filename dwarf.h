#ifndef _DWARF_H_
#define _DWARF_H_

#include "enemy.h"
#include "PC.h"
#include "Shade.h"
#include "Drow.h"
#include "Vampire.h"
#include "Troll.h"
#include "Goblin.h"
#include "Gold.h"
#include "Fairy.h"

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
	void beAttacked(Fairy &fairy) override;
};

#endif
