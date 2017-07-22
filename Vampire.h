#ifndef VAMPIRE_H
#define VAMPIRE_H

class Vampire: public PC {
	Vampire(int row, int col, char sym, char prev, GameBoard* theBoard); 
	// defualt ctor
	~Vampire(); // dtors
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
