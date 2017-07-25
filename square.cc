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
	if (pos_nb == "no") {
		(this->neighbors["ea"])->neighbors["we"] = dest;
		(this->neighbors["we"])->neighbors["ea"] = dest;
		(this->neighbors["ne"])->neighbors["sw"] = dest;
		(this->neighbors["nw"])->neighbors["se"] = dest;
		(this->neighbors["sw"])->neighbors["ne"] = dest;
		(this->neighbors["se"])->neighbors["nw"] = dest;
		(this->neighbors["so"])->neighbors["no"] = dest;
		
		(dest->neighbors["no"])->neighbors["so"] = this;
		(dest->neighbors["ea"])->neighbors["we"] = this;
		(dest->neighbors["we"])->neighbors["ea"] = this;
		(dest->neighbors["se"])->neighbors["nw"] = this;
		(dest->neighbors["nw"])->neighbors["se"] = this;
		(dest->neighbors["sw"])->neighbors["ne"] = this;
		(dest->neighbors["ne"])->neighbors["sw"] = this;
		
	} else if (pos_nb == "so") {
		(this->neighbors["ea"])->neighbors["we"] = dest;
		(this->neighbors["we"])->neighbors["ea"] = dest;
		(this->neighbors["ne"])->neighbors["sw"] = dest;
		(this->neighbors["nw"])->neighbors["se"] = dest;
		(this->neighbors["sw"])->neighbors["ne"] = dest;
		(this->neighbors["se"])->neighbors["nw"] = dest;
		(this->neighbors["no"])->neighbors["so"] = dest;
		
		(dest->neighbors["so"])->neighbors["no"] = this;
		(dest->neighbors["ea"])->neighbors["we"] = this;
		(dest->neighbors["we"])->neighbors["ea"] = this;
		(dest->neighbors["se"])->neighbors["nw"] = this;
		(dest->neighbors["nw"])->neighbors["se"] = this;
		(dest->neighbors["sw"])->neighbors["ne"] = this;
		(dest->neighbors["ne"])->neighbors["sw"] = this;
		
		
	} else if (pos_nb == "ea") {
		(this->neighbors["no"])->neighbors["so"] = dest;
		(this->neighbors["we"])->neighbors["ea"] = dest;
		(this->neighbors["ne"])->neighbors["sw"] = dest;
		(this->neighbors["nw"])->neighbors["se"] = dest;
		(this->neighbors["sw"])->neighbors["ne"] = dest;
		(this->neighbors["se"])->neighbors["nw"] = dest;
		(this->neighbors["so"])->neighbors["no"] = dest;
		
		(dest->neighbors["no"])->neighbors["so"] = this;
		(dest->neighbors["ea"])->neighbors["we"] = this;
		(dest->neighbors["so"])->neighbors["no"] = this;
		(dest->neighbors["se"])->neighbors["nw"] = this;
		(dest->neighbors["nw"])->neighbors["se"] = this;
		(dest->neighbors["sw"])->neighbors["ne"] = this;
		(dest->neighbors["ne"])->neighbors["sw"] = this;
		
	} else if (pos_nb == "we") {
		(this->neighbors["no"])->neighbors["so"] = dest;
		(this->neighbors["ea"])->neighbors["we"] = dest;
		(this->neighbors["ne"])->neighbors["sw"] = dest;
		(this->neighbors["nw"])->neighbors["se"] = dest;
		(this->neighbors["sw"])->neighbors["ne"] = dest;
		(this->neighbors["se"])->neighbors["nw"] = dest;
		(this->neighbors["so"])->neighbors["no"] = dest;
		
		(dest->neighbors["no"])->neighbors["so"] = this;
		(dest->neighbors["so"])->neighbors["no"] = this;
		(dest->neighbors["we"])->neighbors["ea"] = this;
		(dest->neighbors["se"])->neighbors["nw"] = this;
		(dest->neighbors["nw"])->neighbors["se"] = this;
		(dest->neighbors["sw"])->neighbors["ne"] = this;
		(dest->neighbors["ne"])->neighbors["sw"] = this;
		
	} else if (pos_nb == "ne") {
		(this->neighbors["ea"])->neighbors["we"] = dest;
		(this->neighbors["we"])->neighbors["ea"] = dest;
		(this->neighbors["no"])->neighbors["so"] = dest;
		(this->neighbors["nw"])->neighbors["se"] = dest;
		(this->neighbors["sw"])->neighbors["ne"] = dest;
		(this->neighbors["se"])->neighbors["nw"] = dest;
		(this->neighbors["so"])->neighbors["no"] = dest;
		
		(dest->neighbors["no"])->neighbors["so"] = this;
		(dest->neighbors["ea"])->neighbors["we"] = this;
		(dest->neighbors["we"])->neighbors["ea"] = this;
		(dest->neighbors["se"])->neighbors["nw"] = this;
		(dest->neighbors["nw"])->neighbors["se"] = this;
		(dest->neighbors["so"])->neighbors["no"] = this;
		(dest->neighbors["ne"])->neighbors["sw"] = this;
		
	} else if (pos_nb == "nw") {
		(this->neighbors["ea"])->neighbors["we"] = dest;
		(this->neighbors["we"])->neighbors["ea"] = dest;
		(this->neighbors["ne"])->neighbors["sw"] = dest;
		(this->neighbors["no"])->neighbors["so"] = dest;
		(this->neighbors["sw"])->neighbors["ne"] = dest;
		(this->neighbors["se"])->neighbors["nw"] = dest;
		(this->neighbors["so"])->neighbors["no"] = dest;
		
		(dest->neighbors["no"])->neighbors["so"] = this;
		(dest->neighbors["ea"])->neighbors["we"] = this;
		(dest->neighbors["we"])->neighbors["ea"] = this;
		(dest->neighbors["so"])->neighbors["no"] = this;
		(dest->neighbors["nw"])->neighbors["se"] = this;
		(dest->neighbors["sw"])->neighbors["ne"] = this;
		(dest->neighbors["ne"])->neighbors["sw"] = this;
		
	} else if (pos_nb == "se") {
		(this->neighbors["ea"])->neighbors["we"] = dest;
		(this->neighbors["we"])->neighbors["ea"] = dest;
		(this->neighbors["ne"])->neighbors["sw"] = dest;
		(this->neighbors["nw"])->neighbors["se"] = dest;
		(this->neighbors["sw"])->neighbors["ne"] = dest;
		(this->neighbors["no"])->neighbors["so"] = dest;
		(this->neighbors["so"])->neighbors["no"] = dest;
		
		(dest->neighbors["no"])->neighbors["so"] = this;
		(dest->neighbors["ea"])->neighbors["we"] = this;
		(dest->neighbors["we"])->neighbors["ea"] = this;
		(dest->neighbors["se"])->neighbors["nw"] = this;
		(dest->neighbors["so"])->neighbors["no"] = this;
		(dest->neighbors["sw"])->neighbors["ne"] = this;
		(dest->neighbors["ne"])->neighbors["sw"] = this;
		
	} else {
		// pos_nb == "sw"
		(this->neighbors["ea"])->neighbors["we"] = dest;
		(this->neighbors["we"])->neighbors["ea"] = dest;
		(this->neighbors["ne"])->neighbors["sw"] = dest;
		(this->neighbors["nw"])->neighbors["se"] = dest;
		(this->neighbors["no"])->neighbors["so"] = dest;
		(this->neighbors["se"])->neighbors["nw"] = dest;
		(this->neighbors["so"])->neighbors["no"] = dest;
		
		(dest->neighbors["no"])->neighbors["so"] = this;
		(dest->neighbors["ea"])->neighbors["we"] = this;
		(dest->neighbors["we"])->neighbors["ea"] = this;
		(dest->neighbors["se"])->neighbors["nw"] = this;
		(dest->neighbors["nw"])->neighbors["se"] = this;
		(dest->neighbors["sw"])->neighbors["ne"] = this;
		(dest->neighbors["so"])->neighbors["no"] = this;
		
		
		
	}
	Square *temp = this->neighbors[pos_nb];
	this->neighbors[pos_nb] = this;
	dest->neighbors[pos_self] = temp;
	swap(neighbors, dest->neighbors);
	

}

string Square::getItemType() {
	return "";
}

void Square::setavailable(bool available) {
}
