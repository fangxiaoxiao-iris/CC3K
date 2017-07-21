#ifndef SHADE_H
#define SHADE_H

class Shade: public PC {
	int maxhp;
public:
	Shade(); // defualt ctor
	~Shade(); // dtors
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
