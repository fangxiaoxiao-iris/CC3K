#ifndef __GAMEBOARD_H__
#deifne __GAMEBOARD_H__
#include <vector>
#include <iostream>

extern int width;
extern int height;




class GameBoard {
	vector<vector<char>> theGameBoard;
public:
	// custom constructor
	GameBoard(std::string fname); // use file to initialize GameBoard
	// custom destructor 
	~GameBoard();
	void notify(int row, int col, char sym);
	void changeSym(Square &whoNotified, std::string direction) // change symbol after move
	friend std::ostream& operator<< (std::ostream& out, const GameBoard& gb);
};

#endif