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
	GameBoard();
	// custom destructor 
	~GameBoard();
	void notify(int row, int col, char sym);
	friend std::ostream& operator<< (std::ostream& out, const GameBoard& gb);
};

#endif