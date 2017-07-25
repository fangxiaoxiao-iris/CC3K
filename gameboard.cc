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


void GameBoard::changeSym(Square &whoNotified, string direction) {
	int cur_row = whoNotified.get_row();
	int cur_col = whoNotified.get_col();
	int cur_sym = whoNotified.get_sym();
	int prev_sym = whoNotified.get_prev();
	int prev_row, prev_col; 
	if (direction == "no") {
		prev_row = cur_row+1;
		prev_col = cur_col;
	} else if (direction == "so") {
		prev_row = cur_row-1;
		prev_col = cur_col;
	} else if (direction == "ea") {
		prev_row = cur_row;
		prev_col = cur_col-1;
	} else if (direction == "we") {
		prev_row = cur_row;
		prev_col = cur_col+1;
	} else if (direction == "ne") {
		prev_row = cur_row+1;
		prev_col = cur_col-1;
	} else if (direction == "nw") {
		prev_row = cur_row+1;
		prev_col = cur_col+1;
	} else if (direction == "se") {
		prev_row = cur_row-1;
		prev_col = cur_col-1;
	} else {
		prev_row = cur_row-1;
		prev_col = cur_col+1;
	}

	theGameBoard[cur_row][cur_col] = cur_sym;
	theGameBoard[prev_row][prev_col] = prev_sym;
}

ostream& operator<<(ostream& out, const GameBoard& gb) {
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 79; j++) {
			out << gb.theGameBoard[i][j];
			if (j == 78) {
				// print a newline at the end of every row
				out << endl;
			}
		}
	}
	return out;	
}
