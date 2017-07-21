#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include "square.h"
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
	Character();
	~Character();
	void sethp(int hp);
	void setatk(int atk);
	void setdef(int def);
	void setmaxhp(int maxhp);
	void settype(string type);
	int gethp();
	int getatk();
	int getdef();
	int getmaxhp();
	string gettype();
	virtual void move(string direction)=0;
	virtual bool isDead()=0;
	virtual void dead()=0;
};

#endif

