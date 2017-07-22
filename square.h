#ifndef __SQUARE_H__
#define __SQUARE_H__

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>

#include "GameBoard.h"

class Square {
	int row;
	int col;
	char symbol;
	char prev; // in the case of first a dragon hoard, then PC walks over it 
	map<std::string, Square*> neighbors;
	GameBoard* theBoard;
	
public:
	Square(); // Default constructor
	virtual ~Square();
	
	void attach(std::string, Square* s);
	void notifyBoard();
	
	// accessors
	int get_row();
	int get_col();
	char get_sym();
	char get_prev();
	
	// mutators
	void setCoords(int r, int c); // Tells me my row and column number
	void setBoard(GameBoard* gb);	
	void setPrev(char c);
	void setSym(char c);
	// void swapCoords(Square *neighbor);
	// void swapNeighbors(Square *neighbor);
};

#endif 