#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "character.h"
#include "subject.h"

class Enemy: public Character {
public:
	Enemy(int hp, int atk, int def, int maxhp, Square* s);
	~Enemy();


	virtual void move(int x, int y);

	virtual void attack(Character& defender)=0;
	virtual void beAttacked(Character& attacker)=0;
};

#endif
