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
	void setgold(int gold);
	void settype(string type);

	int gethp();
	int getatk();
	int getdef();
	int getmaxhp();
	int getgold(int gold);
	string gettype();
	virtual bool isDead();
	virtual void dead()=0;
};

#endif

