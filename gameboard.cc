#include "gameboard.h"
#include <iostream>
#include <fstream>

using namespace std;

int height = 25;
int width = 79;

GameBoard::GameBoard(string fname) { // not that simple, can generalize two situations in one function
	ifstream file(fname);
	string line;
	for (int i = 0; i < 25; i++) {
		vector<char> char_arr;
		getline(file, line);
		for (int j = 0; j < 79; j++) {
			
			char c = line[j];
			if (c == '6' || c == '7' || c == '8' || c == '9') {
				char_arr.emplace_back('G');
			} else if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5'){
				char_arr.emplace_back('P');
			} else {
				char_arr.emplace_back(c);
			}
		}
		this->theGameBoard.emplace_back(char_arr);
	}
}

// did not implement 
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