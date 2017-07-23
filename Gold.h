#ifndef GOLD_H
#define GOLD_H
#include <string>

class Gold: public Item {
public:
	Gold(std::string type, int value);
	~Gold();
	void picked(PC &P);
}

#endif
