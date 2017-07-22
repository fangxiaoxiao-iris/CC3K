#ifndef GOBLIN_H
#define GOBLIN_H

class Goblin: public PC {
	Goblin(int row, int col, char sym, char prev, GameBoard* theBoard); 
	// defualt ctor
	~Goblin(); // dtors
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
