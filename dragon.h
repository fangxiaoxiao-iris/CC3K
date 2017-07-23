#ifndef _DRAGON_H_
#define _DRAGON_H_

#include "character.h"
#include "enemy.h"

class Dragon: public Character {
	Gold *hoard;
public:
	// default ctor
	Dragon(int row, int col, char sym, char prev, GameBoard* theBoard);
	// dtor
	~Dragon();

	// method for attack
	virtual void attack(PC &defender) override;

	// methods for beAttacked by PC 
	// PC is the attacker and Dragon is the defender
	virtual void beAttacked(Shade &shade) override;
	virtual void beAttacked(Drow &drow) override;
	virtual void beAttacked(Vampire &vampire) override;
	virtual void beAttacked(Troll &troll) override;
	virtual void beAttacked(Goblin &goblin) override;
	void move() override;
    void dead() override;
};

#endif
