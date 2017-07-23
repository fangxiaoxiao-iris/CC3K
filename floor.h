#ifndef __FLOOR_H__
#define __FLOOR_H_

#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>

#include "character.h"
#include "dragon.h"
#include "Drow.h"
#include "dwarf.h"
#include "elf.h"
#include "enemy.h"
#include "floor.h"
#include "gameboard.h"
#include "Goblin.h"
#include "Gold.h"
#include "halfling.h"
#include "human.h"
#include "Item.h"
#include "merchant.h"
#include "orcs.h"
#include "PC.h"
#include "Potion.h"
#include "room.h"
#include "Shade.h"
#include "square.h"
#include "Troll.h"
#include "Vampire.h"

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
		
	// mutators 
	
	void setFname(std::string name);
		
	// accessors 
	
	int getLevel();
	int getScore();
	
	friend std::ostream &operator<<(std::ostream &out, const Floor &f);	
};

#endif 