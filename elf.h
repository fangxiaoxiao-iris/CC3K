#ifndef _ELF_H_
#define _ELF_H_

#include "character.h"

class Elf: public Character {
public:
	// default ctor
	Elf();
	// dtor
	~Elf();

	// method for attack
	virtual void attack(PC &defender) override;

	// methods for beAttacked by PC 
	// PC is the attacker and Elf is the defender
	virtual void beAttacked(Shade &shade) override;
	virtual void beAttacked(Drow &drow) override;
	virtual void beAttacked(Vampire &vampire) override;
	virtual void beAttacked(Troll &troll) override;
	virtual void beAttacked(Goblin &goblin) override;
};

#endif

