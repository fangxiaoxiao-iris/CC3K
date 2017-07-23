#ifndef _HALFLING_H_
#define _HALFLING_H_

#include "character.h"

class Halfling: public Character {
public:
	// default ctor
	Halfling(int row, int col, char sym, char prev, GameBoard* theBoard);
	// dtor
	~Halfling();

	// method for attack
	virtual void attack(PC &defender) override;

	// methods for beAttacked by PC 
	// PC is the attacker and Halfling is the defender
	virtual void beAttacked(Shade &shade) override;
	virtual void beAttacked(Drow &drow) override;
	virtual void beAttacked(Vampire &vampire) override;
	virtual void beAttacked(Troll &troll) override;
	virtual void beAttacked(Goblin &goblin) override;
    void dead() override;
};

#endif

