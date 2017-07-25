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
void Square::swapNeighbors(Square *dest, string pos_nb, string pos_self){
	string direction;

	for (auto n : this->neighbors) {
		if(n.first != pos_nb) {
			for(auto m : n.second->neighbors) {
				if(m.second == this) {
					direction = m.first;
				}
			}
			n.second->neighbors[direction] = dest;
		}
	}

	for(auto n: dest->neighbors) {
		for(auto m : this->neighbors) {
			if(n.second != m.second && n.second != this) {
				for(auto j : n.second->neighbors) {
					if(j.second == dest) {
						direction = j.first;
					}
				}
				n.second->neighbors[direction] = this;
			}
		}
	}

	Square *temp = this->neighbors[pos_nb];
	this->neighbors[pos_nb] = this;
	dest->neighbors[pos_self] = temp;
	swap(neighbors, dest->neighbors);

}


