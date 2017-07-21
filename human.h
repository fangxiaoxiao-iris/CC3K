#ifndef _HUMAN_H_
#define _HUMAN_H_

#include "character.h"

class Enemy: public Character {
public:
	// default ctor
	Enemy();
	// dtor
	~Enemy();

	// method for attack
	virtual void attack(PC &defender) override;

	// methods for beAttacked by PC 
	// PC is the attacker and human is the defender
	virtual void beAttacked(Shade &shade) override;
	virtual void beAttacked(Drow &drow) override;
	virtual void beAttacked(Vampire &vampire) override;
	virtual void beAttacked(Troll &troll) override;
	virtual void beAttacked(Goblin &goblin) override;
	bool isDead() override;
    void dead() override;
};

#endif
