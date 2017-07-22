#include "floor.h"

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;


/*
	std::vector<Square*> theFloor; // do not use arrays of arrays, use just one array 
	                               // the length should be 79 * 25 
	GameBoard* Board;
	PC* player;
	int level;
	
	// manage the floor
	
	std::vector<Enemy*> en_arr; // 20 enemies on a floor 
	std::vector<Potion*> po_arr; // 10 potions on a floor
	std::vector<Gold*> gold_arr; // 10 golds on a floor
	
	// any need to record the 5 rooms?
	
	std::string fname; // optional command line argument
	
*/


Floor::Floor();

Floor::~Floor() {
	delete Board;
	delete player;
}

bool GameOver() {
	
}
bool GameWin();


void clearFloor() {	
	theFloor.clear();
	en_arr.clear();
	po_arr.clear();
	gold_arr.clear();
}

void init_no_file(std::string name) {  // parameter name is always the default name
	
	// where to add the level, in main.cc?
	
	
	this->clearFloor(); // clearFloor: remains player, level and fname

	
	this->level = this->level + 1;
	
	//set Board field
	
	GameBoard* gb = new GameBoard(name); // give filename as parameter
	this->Board = gb;
	
	// set theFloor field 
	
	ifstream file(name);
	for (int i = 0; i < 25; i++) {
		
		vector<Square> square_arr;
		string line;
		getline(file, line);
		
		for (int j = 0; j < 79; j++) {
			Square temp;
			temp.setCoords(i, j);
			temp.setSym(line[j]);
			temp.setPrev('i'); // invalid previous char when initializing 
			temp.setBoard(gb);
			
			square_arr.emplace_back(temp);
		}
		
		this->theFloor.emplace_back(square_arr);
	}
	
	// attach neighbors 
	
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 79; j++) {
			if (i - 1 >= 0) {
				this->theFloor[i][j].attach("no", &this->theFloor[i - 1][j]);
			}
			
			if (i + 1 < 25) {
				this->theFloor[i][j].attach("so", &this->theFloor[i + 1][j]);
			}
			
			if (j - 1 >= 0) {
				this->theFloor[i][j].attach("we", &this->theFloor[i][j - 1]);
			}
			
			if (j + 1 < n) {
				this->theFloor[i][j].attach("ea", &this->theFloor[i][j + 1]);
			}
			
			// that's not enough, adjacent 8 squares
			
			if (i - 1 >= 0 && j - 1 >= 0) {
				this->theFloor[i][j].attach("nw", &this->theFloor[i - 1][j - 1]);
			}
			
			if (i + 1 < 25 && j + 1 < 79) {
				this->theFloor[i][j].attach("se", &this->theFloor[i + 1][j + 1]);
			}
			
			if (i - 1 >= 0 && j + 1 < 79) {
				this->theFloor[i][j].attach("ne", &this->theFloor[i - 1][j + 1]);
			}
			
			if (i + 1 < 25 && j - 1 >= 0) {
				this->theFloor[i][j].attach("sw", &this->theFloor[i + 1][j - 1]);
			}
		}
	}	
}


void Floor::init_file(std::string name) {
	
	this->clearFloor();
	
	this->level = this->level + 1;
	
	//set Board field 
	
	GameBoard* gb = new GameBoard(name);
	this->Board = gb;
	
	// set theFloor field
	
	ifstream file(name);
	
	for (int i = 0; i < 25; i++) {
		
		vector<Square> square_arr;
		string line;
		getline(file, line);
		
		for (int j = 0; j < 79; j++) {
			char c = line[j];
			
			// if we encounter special cases: num, letter
			
			if (c == '@') {  // player character 
				PC temp;
				temp.settype("s");
				temp.setCoords(i, j);
				temp.setSym('@');
				temp.setPrev('i');
				temp.setBoard(gb);
				
				square_arr.emplace_back(temp);
			} else if (c == 'H') {    // all types of enemies :(
				Human temp;
				temp.setCoords(i, j);
				temp.setSym('H');
				temp.setPrev('i');
				temp.setBoard(gb);
				
				square_arr.emplace_back(temp);
				en_arr.emplace_back(temp);
			} else if (c == 'W') {
				Dwarf temp;
				temp.setCoords(i, j);
				temp.setSym('W');
				temp.setPrev('i');
				temp.setBoard(gb);
				
				square_arr.emplace_back(temp);
				en_arr.emplace_back(temp);
			} else if (c == 'E') {
				Elf temp;
				temp.setCoords(i, j);
				temp.setSym('E');
				temp.setPrev('i');
				temp.setBoard(gb);
				
				square_arr.emplace_back(temp);
				en_arr.emplace_back(temp);
			} else if (c == 'O') {
				Orc temp;
				temp.setCoords(i, j);
				temp.setSym('O');
				temp.setPrev('i');
				temp.setBoard(gb);
				
				square_arr.emplace_back(temp);
				en_arr.emplace_back(temp);
			} else if (c == 'M') {
				Merchant temp;
				temp.setCoords(i, j);
				temp.setSym('M');
				temp.setPrev('i');
				temp.setBoard(gb);
				
				square_arr.emplace_back(temp);
				en_arr.emplace_back(temp);
			} else if (c == 'D') {
				Dragon temp;
				temp.setCoords(i, j);
				temp.setSym('D');
				temp.setPrev('i');
				temp.setBoard(gb);
				
				square_arr.emplace_back(temp);
				en_arr.emplace_back(temp);
			} else if (c == 'L') {
				Halfling temp;
				temp.setCoords(i, j);
				temp.setSym('D');
				temp.setPrev('i');
				temp.setBoard(gb);
				
				square_arr.emplace_back(temp);
				en_arr.emplace_back(temp);
			} else if (c == '0') {   // Potion: RH
				Potion temp;
				
				temp.setCoords(i, j);
				temp.setSym('P');
				temp.setPrev('i');
				temp.setBoard(gb);
				
				temp.setType("RH");
				
				square_arr.emplace_back(temp);
				po_arr.emplace_back(temp);
			} else if (c == '1') {  // Potion: BA
				Potion temp;
				
				temp.setCoords(i, j);
				temp.setSym('P');
				temp.setPrev('i');
				temp.setBoard(gb);
				
				temp.setType("BA");
				
				square_arr.emplace_back(temp);	
				po_arr.emplace_back(temp);
			} else if (c == '2') { // Potion: BD
				Potion temp;
				
				temp.setCoords(i, j);
				temp.setSym('P');
				temp.setPrev('i');
				temp.setBoard(gb);
				
				temp.setType("BD");
				
				square_arr.emplace_back(temp);
				po_arr.emplace_back(temp);
			} else if (c == '3') { // Potion: PH
				Potion temp;
				
				temp.setCoords(i, j);
				temp.setSym('P');
				temp.setPrev('i');
				temp.setBoard(gb);
				
				temp.setType("PH");
				
				square_arr.emplace_back(temp);
				po_arr.emplace_back(temp);
			} else if (c == '4') { // Potion: WA
				Potion temp;
				
				temp.setCoords(i, j);
				temp.setSym('P');
				temp.setPrev('i');
				temp.setBoard(gb);
				
				temp.setType("WA");
				
				square_arr.emplace_back(temp);
				po_arr.emplace_back(temp);
			} else if (c == '5') { // Potion: WD
				Potion temp;
				
				temp.setCoords(i, j);
				temp.setSym('P');
				temp.setPrev('i');
				temp.setBoard(gb);
				
				temp.setType("WD");
				
				square_arr.emplace_back(temp);
				po_arr.emplace_back(temp);
			} else if (c == '6') { // normal gold pile
				Gold temp;
				
				temp.setCoords(i, j);
				temp.setSym('G');
				temp.setPrev('i');
				temp.setBoard(gb);
				
				temp.setValue(2);
				
				square_arr.emplace_back(temp);
				gold_arr.emplace_back(temp)
			} else if (c == '7') { // small hoard 
				Gold temp;
				
				temp.setCoords(i, j);
				temp.setSym('G');
				temp.setPrev('i');
				temp.setBoard(gb);
				
				temp.setValue(1);
				
				square_arr.emplace_back(temp);
				po_arr.emplace_back(temp);
			} else if (c == '8') { // merchant hoard
				Gold temp;
				
				temp.setCoords(i, j);
				temp.setSym('G');
				temp.setPrev('i');
				temp.setBoard(gb);
				
				temp.setValue(4);
				
				square_arr.emplace_back(temp);
				po_arr.emplace_back(temp);
			} else if (c == '9') { // dragon hoard 
				Gold temp;
				
				temp.setCoords(i, j);
				temp.setSym('G');
				temp.setPrev('i');
				temp.setBoard(gb);
				
				temp.setValue(6);
				
				square_arr.emplace_back(temp);
				po_arr.emplace_back(temp);
			} else { // other stuff: wall, doorway, floor tile, passage
				Square temp;
				
				temp.setCoords(i, j);
				temp.setSym(c);
				temp.setPrev('i');
				temp.setBoard(gb);
				
				square_arr.emplace_back(temp);				
			}			 
		}
		
		this->theFloor.emplace_back(square_arr);
	}
	
	// attach neighbors 
	
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 79; j++) {
			if (i - 1 >= 0) {
				this->theFloor[i][j].attach(&this->theFloor[i - 1][j]);
			}
			
			if (i + 1 < 25) {
				this->theFloor[i][j].attach(&this->theFloor[i + 1][j]);
			}
			
			if (j - 1 >= 0) {
				this->theFloor[i][j].attach(&this->theFloor[i][j - 1]);
			}
			
			if (j + 1 < n) {
				this->theFloor[i][j].attach(&this->theFloor[i][j + 1]);
			}
			
			// that's not enough, adjacent 8 squares
			
			if (i - 1 >= 0 && j - 1 >= 0) {
				this->theFloor[i][j].attach(&this->theFloor[i - 1][j - 1]);
			}
			
			if (i + 1 < 25 && j + 1 < 79) {
				this->theFloor[i][j].attach(&this->theFloor[i + 1][j + 1]);
			}
			
			if (i - 1 >= 0 && j + 1 < 79) {
				this->theFloor[i][j].attach(&this->theFloor[i - 1][j + 1]);
			}
			
			if (i + 1 < 25 && j - 1 >= 0) {
				this->theFloor[i][j].attach(&this->theFloor[i + 1][j - 1]);
			}
		}
	}		
}


void restart();
void clear();

// generate a series of things :(

void make_player();
void make_stair();
void make_potion();
void make_gold();
void make_enemy();

void pcMove(string direction) {
	
}
void pcAtk(string direction) {
	
}

// use potion? pick up gold?




// mutators 

void Floor::setFname(std::string name) {
	this->fname = name;
}



// accessors 

int getLevel() {
	return this->level;
}

int getScore() {
	if (this->player->getType() == "s") {
		return this->player->getGold() * 1.5;
	} else {
		return this->player->getGold;
	}
}

friend std::ostream &operator<<(std::ostream &out, const Floor *f);

