#include "square.h"
#include "gameboard.h"
#include <iostream>

using namespace std;












// attach and notifyBoard 

void Square::attach(Square* s) {
	this->neighbors.emplace_back(s);
}

void Square::notifyBoard() {
	int r = this->row;
	int c = this->col;
	char s = this->symbol;
	this->theBoard->notify(r, c, s);
}

// accessors
int Square::get_row() {
	return this->row;
}

int Square::get_col() {
	return this->col;
}

char Square::get_sym() {
	return this->symbol;
}
char Square::get_prev() {
	return this->prev;
}

// mutators
void Square::setCoords(int r, int c) {
	this->row = r;
	this->col = c;	
	this->notifyBoard();
} // Tells me my row and column number

void Square::setBoard(GameBoard* gb) {
	this->theBoard = gb;
}

void Square::setPrev(char c) {
	this->prev = c;
}

void Square::setSym(char c) {
	this->symbol = c;
}

/*
//swap the coordinates of Character and the coordinates of the position 
that it is moving towards.
void Square::swapCoords(Square &neighbor){
	swap(row, neighbor.row);
	swap(col, neighbor.col);
}
//swap the neighbors of the Character and the neighbors of the position
that it is moving towards.
void Square::swapNeighbors(Square &neighbor){
	swap(neighbors, neighbor.neighbors);
}
*/

