#ifndef POTION_H
#define POTION_H
#include <string>

class Potion: public Item {
public:
	Potion(std::string type);
	~Potion();
	void used(PC &P);
}

#endif
