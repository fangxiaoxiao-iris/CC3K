#ifndef FAIRY_H
#define FAIRY_H
#include "PC.h"
#include "enemy.h"
#include "dragon.h"
#include "human.h"
#include "dwarf.h"
#include "elf.h"
#include "halfling.h"
#include "orcs.h"
#include "merchant.h"

class Fairy: public PC {
public:
	Fairy(int row, int col, char sym, char prev, GameBoard* theBoard); 
	// defualt ctor
	~Fairy(); // dtors
	void attack(Enemy &e) override;
	void beAttacked(Human &hu) override;
	void beAttacked(Dwarf &dw) override;
	void beAttacked(Elf &el) override;
	void beAttacked(Dragon &dr) override;
	void beAttacked(Halfling &ha) override;
	void beAttacked(Orcs &o) override;
	void beAttacked(Merchant &m) override;
};

#endif
