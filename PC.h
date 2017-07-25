#ifndef PC_H
#define PC_H
#include <vector>
#include <string>
#include "square.h"
#include "character.h"

class Enemy;
class Dragon;
class Human;
class Dwarf;
class Elf;
class Halfling;
class Orcs;
class Merchant;
class Gold;
class Potion;

class PC: public Character {
	std::vector<std::string> knownPotions;

public:
	PC(int row, int col, char sym, char prev, GameBoard* theBoard);
	~PC();
	std::vector<std::string> &getKnownPotions();
	void setKnownPotions(std::string pName);
	virtual void attack(Enemy &e) = 0;
	virtual void beAttacked(Human &hu) = 0;
	virtual void beAttacked(Dwarf &dw) = 0;
	virtual void beAttacked(Elf &el) = 0;
	virtual void beAttacked(Dragon &dr) = 0;
	virtual void beAttacked(Halfling &ha) = 0;
	virtual void beAttacked(Orcs &o) = 0;
	virtual void beAttacked(Merchant &m) = 0;
	void move(std::string);
	void use(Potion &p);
	void pickUp(Gold &g);
	bool isOnStair();
};

#endif
