#ifndef __GAMEBOARD_H__
#define __GAMEBOARD_H__
#include <vector>
#include <iostream>
#include "square.h"

extern int width;
extern int height;




class GameBoard {
	std::vector<std::vector<char>> theGameBoard;
public:
	// custom constructor
	GameBoard(std::string fname); // use file to initialize GameBoard
	// custom destructor 
	~GameBoard();
	void notify(int row, int col, char sym);
	void changeSym(Square &whoNotified, std::string direction); // change symbol after move
	friend std::ostream& operator<< (std::ostream& out, const GameBoard& gb);
};

#endif
