#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include "subject.h"
#include <string>

using namespace std;

class Square;

class Character: public Square {
protected:
	int hp;
	int atk;
	int def;
	int maxhp;
	int gold;
	string type;

public:
	Character(int hp, int atk, int def, int maxhp);
	~Character();
	void sethp(int hp);
	void setatk(int atk);
	void setdef(int def);
	void setmaxhp(int maxhp);
	int gethp();
	int getatk();
	int getdef();
	int getmaxhp();
	int gettype();
	virtual void move(int x, int y)=0;
	virtual bool isDead()=0;
	virtual void dead()=0;
};

#endif

