#ifndef _DRAGON_H_
#define _DRAGON_H_

#include "enemy.h"
#include "PC.h"
#include "Shade.h"
#include "Drow.h"
#include "Vampire.h"
#include "Troll.h"
#include "Goblin.h"
#include "Gold.h"
#include "Fairy.h"

class Dragon: public Enemy {
public:
	// default ctor
	Dragon(int row, int col, char sym, char prev, GameBoard* theBoard);
	// dtor
	~Dragon();

	// method for attack
	void attack(PC &defender) override;

	// methods for beAttacked by PC 
	// PC is the attacker and Dragon is the defender
	void beAttacked(Shade &shade) override;
	void beAttacked(Drow &drow) override;
	void beAttacked(Vampire &vampire) override;
	void beAttacked(Troll &troll) override;
	void beAttacked(Goblin &goblin) override;
	void beAttacked(Fairy &fairy) override;
	void move() override;
};

#endif
