#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "character.h"

class Enemy: public Character {
public:
	Enemy(int row, int col, char sym, char prev, GameBoard* theBoard);
	~Enemy();

	virtual void move(string direction);

	virtual void attack(PC &defender)=0;

	virtual void beAttacked(Shade &shade)=0;
	virtual void beAttacked(Drow &drow)=0;
	virtual void beAttacked(Vampire &vampire)=0;
	virtual void beAttacked(Troll &troll)=0;
	virtual void beAttacked(Goblin &goblin)=0;

	virtual void dead();
};

#endif
