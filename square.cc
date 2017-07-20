#include "square.h"
#include "gameboard.h"
#include <iostream>

using namespace std;














void Square::attach(Square* s) {
	this->neighbors.emplace_back(s);
}

void Square::notifyBoard() {
	int r = this->row;
	int c = this->col;
	char s = this->symbol;
	this->theBoard->notify(r, c, s);
}

int Square::get_row() {
	return 
}