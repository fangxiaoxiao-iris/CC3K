#include "square.h"
#include "gameboard.h"
#include <iostream>
#include <utility>
#include <string>
#include <map>

using namespace std;

Square::Square(int row, int col, char sym, char prev, GameBoard* theBoard): 
row(row), col(col), symbol(sym), prev(prev), theBoard(theBoard) {}
 
Square::~Square() {}

// attach and notifyBoard 

void Square::attach(string direction, Square* s) {
	this->neighbors.emplace(direction, s);
}

void Square::notifyBoard() {
	int r = this->row;
	int c = this->col;
	char s = this->symbol;
	this->theBoard->notify(r, c, s);
}

void Square::notifyMove(string direction) {
	theBoard->changeSym(*this, direction);
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

map<string, Square*> &Square::getNeigh() {
	return this->neighbors;
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

void Square::setNeigh(map<std::string, Square*> neigh) {
	this->neighbors = neigh;
}


//swap the coordinates of Character and the coordinates of the position 
//that it is moving towards.
void Square::swapCoords(Square *neighbor){
	swap(row, neighbor->row);
	swap(col, neighbor->col);
}
//swap the neighbors of the Character and the neighbors of the position
//that it is moving towards.
void Square::swapNeighbors(Square *neighbor, string pos_nb, string pos_self){
	Square *temp = neighbors[pos_nb];
	neighbors[pos_nb] = this;
	neighbor->neighbors[pos_self] = temp;
	swap(neighbors, neighbor->neighbors);
}


