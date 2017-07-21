#ifndef _MERCHANT_H_
#define _MERCHANT_H_

#include "character.h"

class Merchant: public Character {
	bool isHostile;
public:
	// default ctor
	Merchant();
	// dtor
	~Merchant();

	// method for attack
	virtual void attack(PC &defender) override;

	// methods for beAttacked by PC 
	// PC is the attacker and Merchant is the defender
	virtual void beAttacked(Shade &shade) override;
	virtual void beAttacked(Drow &drow) override;
	virtual void beAttacked(Vampire &vampire) override;
	virtual void beAttacked(Troll &troll) override;
	virtual void beAttacked(Goblin &goblin) override;
    void dead() override;
};

#endif

