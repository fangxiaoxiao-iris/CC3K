#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include "square.h"
#include <string>


using namespace std;

class Character: public Square {
protected:
	int hp;
	int atk;
	int def;
	int maxhp;
	int gold;
	string type;

public:
	Character(int row, int col, char sym, char prev, GameBoard* theBoard);
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
	int getgold();
	string gettype();
	bool isDead();
};

#endif
