#include "gameboard.h"
#include <iostream>
using namespace std;

int height = 25;
int width = 79;

GameBoard::GameBoard() {}




GameBoard::~GameBoard() {}




void GameBoard::notify(int row, int col, char sym) {
	this->theGameBoard[row][col] = sym;
}

ostream& operator<<(ostream& out, const GameBoard& gb) {
	for (int i = 0; i < height; i++) {
		int j = 0;
		for (int j = 0; j < width; j++) {
			out << gb.theGameBoard[i][j];
			if (j = 78) {
				// print a newline at the end of every row
				out << endl;
			}
		}
	}
	return out;	
}