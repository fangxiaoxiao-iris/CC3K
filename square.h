#ifndef __SQUARE_H__
#define __SQUARE_H__

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>

class GameBoard;

class Square {
	int row;
	int col;
	char symbol;
	char prev; // in the case of first a dragon hoard, then PC walks over it 
	GameBoard* theBoard;
	std::map<std::string, Square*> neighbors;
	//protected:
	//std::map<std::string, Square*> neighbors;
	
public:
	Square(int row, int col, char sym, char prev, GameBoard* theBoard); // Default constructor
	virtual ~Square();
	
	void attach(std::string, Square* s);
	void notifyBoard();
	void notifyMove(std::string direction);
	
	// accessors
	int get_row();
	int get_col();
	char get_sym();
	char get_prev();
	std::map<std::string, Square*> &getNeigh();
	virtual std::string getItemType();
	
	// mutators
	void setCoords(int r, int c); // Tells me my row and column number
	void setBoard(GameBoard* gb);	
	void setPrev(char c);
	void setSym(char c);
	void setNeigh(std::map<std::string, Square*> neigh);
	virtual void setavailable(bool available);
	void swapCoords(Square *neighbor);
	void swapNeighbors(Square *dest, std::string pos_nb, std::string pos_self);
};

#endif 
