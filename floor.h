#ifndef __FLOOR_H__
#define __FLOOR_H__

#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>

#include "enemy.h"
#include "gameboard.h"
#include "Gold.h"
#include "Potion.h"
#include "room.h"
#include "Shade.h"
#include "square.h"


class Floor {
	std::vector<vector<Square>> theFloor; 
	
	GameBoard* Board;
	int level;
	
	// manage the floor
	
	std::vector<Enemy> en_arr; // 20 enemies on a floor 
	std::vector<Potion> po_arr; // 10 potions on a floor
	std::vector<Gold> gold_arr; // 10 golds on a floor
	std::vector<Room> theRoom;
	
	// any need to record the 5 rooms?
	
	std::string fname; // optional command line argument
	PC* player;
	
public:
	Floor();
	~Floor();
	
	bool GameOver();
	bool GameWin();
	void clearFloor();
	
	void init_no_file(std::string name, std::string race); 
	void init_file(std::string name, std::string race);  // initialize the floor with the file
	void restart();
	
	// generate a series of things :(
	
	int make_player();
	void make_stair(int player_room);
	void make_potion();
	void make_gold();
	void make_enemy();
	
	void pcMove(std::string direction);
	void pcAtk(std::string direction);
	void pcUse(std::string direction);
	void enemyMove();
	void check_enemy();
	bool at_stair();
		
	// mutators 
	
	void setFname(std::string name);
		
	// accessors 
	
	int getLevel();
	int getScore();
	
	PC* getPC();
	friend std::ostream &operator<<(std::ostream &out, const Floor &f);	
};

#endif 