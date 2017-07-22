#ifndef _ORCS_H_
#define _ORCS_H_

#include "character.h"

class Orcs: public Character {
public:
	// default ctor
	Orcs();
	// dtor
	~Orcs();

	// method for attack
	virtual void attack(PC &defender) override;

	// methods for beAttacked by PC 
	// PC is the attacker and Orcs is the defender
	virtual void beAttacked(Shade &shade) override;
	virtual void beAttacked(Drow &drow) override;
	virtual void beAttacked(Vampire &vampire) override;
	virtual void beAttacked(Troll &troll) override;
	virtual void beAttacked(Goblin &goblin) override;
};

#endif

