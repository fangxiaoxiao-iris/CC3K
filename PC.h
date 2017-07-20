#ifndef PC_H
#define PC_H
#include <vector>
#include <string>

class PC: public Character {
	std::vector<std::string> knownPotions;

public:
	PC();
	virtual void attack(Human &) = 0；
	virtual void attack(Dwarf &) = 0;
	virtual void attack(Halfling &) = 0;
	virtual void attack(Dragon &) = 0;
	virtual void attack(Orcs &) = 0;
	virtual void attack(Merchant &) = 0;
	virtual void beAttacked(Enemy &) = 0;
	virtual void use(Potion &);
	virtual void pickUp(Gold &); 
	void move(std::string direction) override;
	void dead() override;
	virtual ~PC() = 0;
};

#endif
