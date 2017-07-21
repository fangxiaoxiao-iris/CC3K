#ifndef __FLOOR_H__
#define __FLOOR_H_

#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>

#include "grid.h"
// include nearly all the .h files :(




class Floor {
	std::vector<vector<Square>> theFloor; 
	
	GameBoard* Board;
	PC* player;
	int level;
	
	// manage the floor
	
	std::vector<Enemy*> en_arr; // 20 enemies on a floor 
	std::vector<Potion*> po_arr; // 10 potions on a floor
	std::vector<Gold*> gold_arr; // 10 golds on a floor
	
	// any need to record the 5 rooms?
	
	std::string fname; // optional command line argument
	
public:
	Floor();
	~Floor();
	
	bool GameOver();
	bool GameWin();
	void clearFloor();
	
	void init_no_file(std::string name); 
	void init_file(std::string name);  // initialize the floor with the file
	void restart();
	void clear();
	
	// generate a series of things :(
	
	void make_player();
	void make_stair();
	void make_potion();
	void make_gold();
	void make_enemy();
	
	void pcMove(std::string direction);
	void pcAtk(std::string direction);
	
	// use potion? pick up gold?
	
	
	
	
	// mutators 
	
	void setFname(std::string name);
	
	
	
	// accessors 
	
	int getLevel();
	int getScore();
	
	friend std::ostream &operator<<(std::ostream &out, const Floor *f);
	
	
};

#endif 