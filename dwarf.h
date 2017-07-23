#ifndef _DWARF_H_
#define _DWARF_H_

#include "character.h"

class Dwarf: public Character {
public:
	// default ctor
	Dwarf(int row, int col, char sym, char prev, GameBoard* theBoard);
	// dtor
	~Dwarf();

	// method for attack
	virtual void attack(PC &defender) override;

	// methods for beAttacked by PC 
	// PC is the attacker and dwarf is the defender
	virtual void beAttacked(Shade &shade) override;
	virtual void beAttacked(Drow &drow) override;
	virtual void beAttacked(Vampire &vampire) override;
	virtual void beAttacked(Troll &troll) override;
	virtual void beAttacked(Goblin &goblin) override;
};

#endif

