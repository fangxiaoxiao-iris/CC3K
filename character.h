#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include "subject.h"
#include <string>

using namespace std;

class Square;

class Character: public Subject {
protected:
	int hp;
	int atk;
	int def;
	int maxhp;
	string type;

	Square* s;
public:
	Character(int hp, int atk, int def, int maxhp, Square* s);
	~Character();
	virtual void sethp(int hp);
	virtual void setatk(int atk);
	virtual void setdef(int def);
	virtual void setmaxhp(int maxhp);
	virtual int gethp();
	virtual int getatk();
	virtual int getdef();
	virtual int getmaxhp();
	virtual void move(int x, int y)=0;
	virtual void attack(Character& defender)=0;
	virtual void beAttacked(Character& attcker)=0;
	virtual bool isDead();
	virtual void dead();
};

#endif

