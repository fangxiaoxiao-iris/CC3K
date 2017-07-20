#ifndef __SQUARE_H__
#define __SQUARE_H__

#include <iostream>
#include <string>
#include <vector>
#include <utility>

#include "GameBoard.h"

class Square {
	int row;
	int col;
	char symbol;
	char prev; // in the case of first a dragon hoard, then PC walks over it 
	vector<Square*> neighbors;
	GameBoard* theBoard;
	
public:
	Square(); // Default constructor
	virtual ~Square();
	
	void attach(Square* s);
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
};

#endif 