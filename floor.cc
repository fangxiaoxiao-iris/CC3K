#include "floor.h"

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

Floor::Floor();

Floor::~Floor() {
	delete Board;
	delete player;
}

bool Floor::GameOver() {
	
}
bool Floor::GameWin() {
	
}


void Floor::clearFloor() {	
	theFloor.clear();
	en_arr.clear();
	po_arr.clear();
	gold_arr.clear();
}

void Floor::init_no_file(string name, string race) {  // parameter name is always the default name
	
	// record the HP of player in this game
	int HP_record = this->player->gethp();
		
	this->clearFloor(); // clearFloor: remains player, level and fname

	// set fname field
	this->faname = name;
	
	//set Board field, will change it later
	GameBoard* gb = new GameBoard(name);
	this->Board = gb;

	// set level field
	this->level = this->level + 1;
	
	// set theRoom field
	// set the size of theRoom to 5
	this->theRoom.reserve(5);
	
	// set the first room, this->theRoom[0].pos.emplace_back(k);
	// row: 3-6 col: 3-28
	for (int i = 3; i <= 6; i++) {
		for (int j = 3; j <= 28; j++) {
			pair<int, int> k = make_pair(i, j);
			this->theRoom[0].pos.emplace_back(k);
		}
	}
	
	// set the second room, this->theRoom[1].pos.emplace_back(k);
	// row: 15-21 col: 4-24
	for (int i = 15; i <= 21; i++) {
		for (int j = 4; j <= 24; j++) {
			pair<int, int> k = make_pair(i, j);
			this->theRoom[1].pos.emplace_back(k);
		}
	}
	
	// set the third room, this->theRoom[2].pos.emplace_back(k);
	// row: 10-12 col: 38-49
	for (int i = 10; i <= 12; i++) {
		for (int j = 38; j <= 49; j++) {
			pair<int, int> k = make_pair(i, j);
			this->theRoom[2].pos.emplace_back(k);
		}
	}
	
	// set the forth room, this->theRoom[3].pos.emplace_back(k);
	// divide into two rectangles and two random rows
	
	// first rectangle
	// row: 3-6 col: 39-61
	for (int i = 3; i <= 6; i++) {
		for (int j = 39; j <= 61; j++) {
			pair<int, int> k = make_pair(i, j);
			this->theRoom[3].pos.emplace_back(k);
		}
	}
	
	// second rectangle
	// row: 7-12 col: 61-75
	for (int i = 7; i <= 12) {
		for (int j = 61; j<= 75; j++) {
			pair<int, int> k = make_pair(i, j);
			this->theRoom[3].pos.emplace_back(k);
		}
	}
	
	// first random row
	// row: 5 col: 62-69
	for (int j = 62; j<= 69; j++) {
		pair<int, int> k = make_pair(5, j);
		this->theRoom[3].pos.emplace_back(k);
	}
	
	// second random row
	// row: 6 col: 62-72
	for (int j = 62; j <= 72; j++) {
		pair<int, int> k = make_pair(6, j);
		this->theRoom[3].pos.emplace_back(k);
	}
	
	// set the fifth room, this->theRoom[3].pos.emplace_back(k);
	// divide into two rectangles
	
	// set the first rectangle
	// row: 19-21 col: 37-75
	for (int i = 19; i <= 21; i++) {
		for (int j = 37; j <= 75; j++) {
			pair<int, int> k = make_pair(i, j);
			this->theRoom[4].pos.emplace_back(k);
		}
	}
	
	// set the second rectangle
	// row: 16-21 col: 65-75
	for (int i = 16; i<= 21; i++) {
		for (int j = 65; j <= 75; j++) {
			pair<int, int> k = make_pair(i, j);
			this->theRoom[4].pos.emplace_back(k);
		}
	}
	
	// create a vector<vector<char>> in_file, serve as the input file
	// note: this is different from gameboard, as this input file 
	// represent potion and gold as numbers
	
	vector<vector<char>> in_file;
	
	// copy plain floor to in_file
	ifstream file(name);
	for (int i = 0; i < 25; i++) {
		vector<char> char_arr;
		string line;
		getline(file, line);
		
		for (int j = 0; j < 79; j++) {
			char temp = line[j];
			char_arr.emplace_back(temp);
		}
		in_file.emplace_back(char_arr);
	}
	
	// begin generating, change in_file, change Board
	// pass in_file as parameter to make functions 
	
	// generate PC and stair
	int player_room = this->make_player(in_file);
	this->make_stair(player_room);
	
	// generate potions
	for (int i = 0; i < 10; i++) {
		// 0: RH, 1: BA, 2: BD, 3: PH, 4: WA, 5: WD
		int p_num = rand() % 6;
		make_potion(p_num);		
	}
	
	// generate gold
	for (int i = 0; i < 10; i++) {
		// 0-4: normal: 6, 5: dragon hoard: 9, 6-7: small hoard: 8
		int g_num = rand() % 8;
		if (g_num >= 0 & g_num <= 4) {
			make_potion(6);
		} else if (g_num = 5) {
			make_potion(9);
		} else {
			make_potion:(8);
		}		
	}
	
	// generate enemy 
	for (int i = 0; i < 20; i++) {
		// human: 0-3, dwarf: 4-6, halfling: 7-11, elf: 12-13, orc: 14-15, merchant: 16-17
		int e_num = rand() % 18;
		if (g >= 0 && g <= 3) {
			this->make_enemy('H');
		} else if (g >= 4 && g <= 6) {
			this->make_enemy('W');
		} else if (g >= 7 && g <= 11) {
			this->make_enemy('L');
		} else if (g >= 12 && g <= 13) {
			this->make_enemy('E')
		} else if (g >= 14 && g <= 15) {
			this->make_enemy('O')
		} else {
			this->make_enemy('M');
		}
	}
	
	// initialize using vector<vector<char>>
	
	// set theFloor field	
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 79; j++) {
			
			char c = in_file[i][j];
			// if we encounter special cases: num, letter
			if (c == '@') {  // player character 
				
				if (race == "s") {
					Shade temp;
					
					temp.settype("s");
					temp.setCoords(i, j);
					temp.setSym('@');
					temp.setPrev('.');
					temp.setBoard(gb);
					
					square_arr.emplace_back(temp);
					
					// set player field
					PC* p = new Shade(i, j, '@', '.', gb);
					this->player = p;
					
				} else if (race == "d") {
					Drow temp;
					
					temp.settype("d");
					temp.setCoords(i, j);
					temp.setSym('@');
					temp.setPrev('.');
					temp.setBoard(gb);
					
					square_arr.emplace_back(temp);
					
					// set player field
					PC* p = new Drow(i, j, '@', '.', gb);
					this->player = p;
					
				} else if (race == "v") {
					Vampire temp;
					
					temp.settype("v");
					temp.setCoords(i, j);
					temp.setSym('@');
					temp.setPrev('.');
					temp.setBoard(gb);
					
					square_arr.emplace_back(temp);
					
					// set player field
					PC* p = new Vampire(i, j, '@', '.', gb);
					this->player = p;
					
				} else if (race == "g") {
					Goblin temp;
					
					temp.settype("g");
					temp.setCoords(i, j);
					temp.setSym('@');
					temp.setPrev('.');
					temp.setBoard(gb);
					
					square_arr.emplace_back(temp);
					
					// set player field
					PC* p = new Goblin(i, j, '@', '.', gb);
					this->player = p;
					
				} else if (race == "t") {
					Troll temp;
					
					temp.settype("t");
					temp.setCoords(i, j);
					temp.setSym('@');
					temp.setPrev('.');
					temp.setBoard(gb);
					
					square_arr.emplace_back(temp);
					
					// set player field
					PC* p = new Troll(i, j, '@', '.', gb);
					this->player = p;
					
				}
			} else if (c == 'H') {    // all types of enemies :(
				Human temp;
				temp.setCoords(i, j);
				temp.setSym('H');
				temp.setPrev('.');
				temp.setBoard(gb);
				
				square_arr.emplace_back(temp);
				en_arr.emplace_back(temp);
			} else if (c == 'W') {
				Dwarf temp;
				temp.setCoords(i, j);
				temp.setSym('W');
				temp.setPrev('.');
				temp.setBoard(gb);
				
				square_arr.emplace_back(temp);
				en_arr.emplace_back(temp);
			} else if (c == 'E') {
				Elf temp;
				temp.setCoords(i, j);
				temp.setSym('E');
				temp.setPrev('.');
				temp.setBoard(gb);
				
				square_arr.emplace_back(temp);
				en_arr.emplace_back(temp);
			} else if (c == 'O') {
				Orc temp;
				temp.setCoords(i, j);
				temp.setSym('O');
				temp.setPrev('.');
				temp.setBoard(gb);
				
				square_arr.emplace_back(temp);
				en_arr.emplace_back(temp);
			} else if (c == 'M') {
				Merchant temp;
				temp.setCoords(i, j);
				temp.setSym('M');
				temp.setPrev('.');
				temp.setBoard(gb);
				
				square_arr.emplace_back(temp);
				en_arr.emplace_back(temp);
			} else if (c == 'D') {
				Dragon temp;
				temp.setCoords(i, j);
				temp.setSym('D');
				temp.setPrev('.');
				temp.setBoard(gb);
				
				square_arr.emplace_back(temp);
				en_arr.emplace_back(temp);
			} else if (c == 'L') {
				Halfling temp;
				temp.setCoords(i, j);
				temp.setSym('D');
				temp.setPrev('.');
				temp.setBoard(gb);
				
				square_arr.emplace_back(temp);
				en_arr.emplace_back(temp);
			} else if (c == '0') {   // Potion: RH
				Potion temp;
				
				temp.setCoords(i, j);
				temp.setSym('P');
				temp.setPrev('.');
				temp.setBoard(gb);
				
				temp.setType("RH");
				
				square_arr.emplace_back(temp);
				po_arr.emplace_back(temp);
			} else if (c == '1') {  // Potion: BA
				Potion temp;
				
				temp.setCoords(i, j);
				temp.setSym('P');
				temp.setPrev('.');
				temp.setBoard(gb);
				
				temp.setType("BA");
				
				square_arr.emplace_back(temp);	
				po_arr.emplace_back(temp);
			} else if (c == '2') { // Potion: BD
				Potion temp;
				
				temp.setCoords(i, j);
				temp.setSym('P');
				temp.setPrev('.');
				temp.setBoard(gb);
				
				temp.setType("BD");
				
				square_arr.emplace_back(temp);
				po_arr.emplace_back(temp);
			} else if (c == '3') { // Potion: PH
				Potion temp;
				
				temp.setCoords(i, j);
				temp.setSym('P');
				temp.setPrev('.');
				temp.setBoard(gb);
				
				temp.setType("PH");
				
				square_arr.emplace_back(temp);
				po_arr.emplace_back(temp);
			} else if (c == '4') { // Potion: WA
				Potion temp;
				
				temp.setCoords(i, j);
				temp.setSym('P');
				temp.setPrev('.');
				temp.setBoard(gb);
				
				temp.setType("WA");
				
				square_arr.emplace_back(temp);
				po_arr.emplace_back(temp);
			} else if (c == '5') { // Potion: WD
				Potion temp;
				
				temp.setCoords(i, j);
				temp.setSym('P');
				temp.setPrev('.');
				temp.setBoard(gb);
				
				temp.setType("WD");
				
				square_arr.emplace_back(temp);
				po_arr.emplace_back(temp);
			} else if (c == '6') { // normal gold pile
				Gold temp;
				
				temp.setCoords(i, j);
				temp.setSym('G');
				temp.setPrev('.');
				temp.setBoard(gb);
				
				temp.setValue(2);
				
				square_arr.emplace_back(temp);
				gold_arr.emplace_back(temp)
			} else if (c == '7') { // small hoard 
				Gold temp;
				
				temp.setCoords(i, j);
				temp.setSym('G');
				temp.setPrev('.');
				temp.setBoard(gb);
				
				temp.setValue(1);
				
				square_arr.emplace_back(temp);
				po_arr.emplace_back(temp);
			} else if (c == '8') { // merchant hoard
				Gold temp;
				
				temp.setCoords(i, j);
				temp.setSym('G');
				temp.setPrev('.');
				temp.setBoard(gb);
				
				temp.setValue(4);
				
				square_arr.emplace_back(temp);
				po_arr.emplace_back(temp);
			} else if (c == '9') { // dragon hoard 
				Gold temp;
				
				temp.setCoords(i, j);
				temp.setSym('G');
				temp.setPrev('.');
				temp.setBoard(gb);
				
				temp.setValue(6);
				
				square_arr.emplace_back(temp);
				po_arr.emplace_back(temp);
			} else { // other stuff: wall, doorway, floor tile, passage
				Square temp;
				
				temp.setCoords(i, j);
				temp.setSym(c);
				temp.setPrev('.');
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
		
	// set player neighbors
	this->player->setNeigh(theFloor[this->player->row][this->player->col].getNeigh());	
	
	// remain the HP of the player
	this->player->sethp(HP_record);		
}


void Floor::init_file(string name, string race) {
	
	// record the HP of player in this game
	int HP_record = this->player->gethp();
	
	this->clearFloor();
	
	// set fname field
	this->faname = name;
	
	// set the level field 
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
				
				if (race == "s") {
					Shade temp;
					
					temp.settype("s");
					temp.setCoords(i, j);
					temp.setSym('@');
					temp.setPrev('.');
					temp.setBoard(gb);
					
					square_arr.emplace_back(temp);
					
					// set player field
					PC* p = new Shade(i, j, '@', '.', gb);
					this->player = p;
					
				} else if (race == "d") {
					Drow temp;
					
					temp.settype("d");
					temp.setCoords(i, j);
					temp.setSym('@');
					temp.setPrev('.');
					temp.setBoard(gb);
					
					square_arr.emplace_back(temp);
					
					// set player field
					PC* p = new Drow(i, j, '@', '.', gb);
					this->player = p;
					
				} else if (race == "v") {
					Vampire temp;
					
					temp.settype("v");
					temp.setCoords(i, j);
					temp.setSym('@');
					temp.setPrev('.');
					temp.setBoard(gb);
					
					square_arr.emplace_back(temp);
					
					// set player field
					PC* p = new Vampire(i, j, '@', '.', gb);
					this->player = p;
					
				} else if (race == "g") {
					Goblin temp;
					
					temp.settype("g");
					temp.setCoords(i, j);
					temp.setSym('@');
					temp.setPrev('.');
					temp.setBoard(gb);
					
					square_arr.emplace_back(temp);
					
					// set player field
					PC* p = new Goblin(i, j, '@', '.', gb);
					this->player = p;
					
				} else if (race == "t") {
					Troll temp;
					
					temp.settype("t");
					temp.setCoords(i, j);
					temp.setSym('@');
					temp.setPrev('.');
					temp.setBoard(gb);
					
					square_arr.emplace_back(temp);
					
					// set player field
					PC* p = new Troll(i, j, '@', '.', gb);
					this->player = p;
					
				}
			} else if (c == 'H') {    // all types of enemies :(
				Human temp;
				temp.setCoords(i, j);
				temp.setSym('H');
				temp.setPrev('.');
				temp.setBoard(gb);
				
				square_arr.emplace_back(temp);
				en_arr.emplace_back(temp);
			} else if (c == 'W') {
				Dwarf temp;
				temp.setCoords(i, j);
				temp.setSym('W');
				temp.setPrev('.');
				temp.setBoard(gb);
				
				square_arr.emplace_back(temp);
				en_arr.emplace_back(temp);
			} else if (c == 'E') {
				Elf temp;
				temp.setCoords(i, j);
				temp.setSym('E');
				temp.setPrev('.');
				temp.setBoard(gb);
				
				square_arr.emplace_back(temp);
				en_arr.emplace_back(temp);
			} else if (c == 'O') {
				Orc temp;
				temp.setCoords(i, j);
				temp.setSym('O');
				temp.setPrev('.');
				temp.setBoard(gb);
				
				square_arr.emplace_back(temp);
				en_arr.emplace_back(temp);
			} else if (c == 'M') {
				Merchant temp;
				temp.setCoords(i, j);
				temp.setSym('M');
				temp.setPrev('.');
				temp.setBoard(gb);
				
				square_arr.emplace_back(temp);
				en_arr.emplace_back(temp);
			} else if (c == 'D') {
				Dragon temp;
				temp.setCoords(i, j);
				temp.setSym('D');
				temp.setPrev('.');
				temp.setBoard(gb);
				
				square_arr.emplace_back(temp);
				en_arr.emplace_back(temp);
			} else if (c == 'L') {
				Halfling temp;
				temp.setCoords(i, j);
				temp.setSym('D');
				temp.setPrev('.');
				temp.setBoard(gb);
				
				square_arr.emplace_back(temp);
				en_arr.emplace_back(temp);
			} else if (c == '0') {   // Potion: RH
				Potion temp;
				
				temp.setCoords(i, j);
				temp.setSym('P');
				temp.setPrev('.');
				temp.setBoard(gb);
				
				temp.setType("RH");
				
				square_arr.emplace_back(temp);
				po_arr.emplace_back(temp);
			} else if (c == '1') {  // Potion: BA
				Potion temp;
				
				temp.setCoords(i, j);
				temp.setSym('P');
				temp.setPrev('.');
				temp.setBoard(gb);
				
				temp.setType("BA");
				
				square_arr.emplace_back(temp);	
				po_arr.emplace_back(temp);
			} else if (c == '2') { // Potion: BD
				Potion temp;
				
				temp.setCoords(i, j);
				temp.setSym('P');
				temp.setPrev('.');
				temp.setBoard(gb);
				
				temp.setType("BD");
				
				square_arr.emplace_back(temp);
				po_arr.emplace_back(temp);
			} else if (c == '3') { // Potion: PH
				Potion temp;
				
				temp.setCoords(i, j);
				temp.setSym('P');
				temp.setPrev('.');
				temp.setBoard(gb);
				
				temp.setType("PH");
				
				square_arr.emplace_back(temp);
				po_arr.emplace_back(temp);
			} else if (c == '4') { // Potion: WA
				Potion temp;
				
				temp.setCoords(i, j);
				temp.setSym('P');
				temp.setPrev('.');
				temp.setBoard(gb);
				
				temp.setType("WA");
				
				square_arr.emplace_back(temp);
				po_arr.emplace_back(temp);
			} else if (c == '5') { // Potion: WD
				Potion temp;
				
				temp.setCoords(i, j);
				temp.setSym('P');
				temp.setPrev('.');
				temp.setBoard(gb);
				
				temp.setType("WD");
				
				square_arr.emplace_back(temp);
				po_arr.emplace_back(temp);
			} else if (c == '6') { // normal gold pile
				Gold temp;
				
				temp.setCoords(i, j);
				temp.setSym('G');
				temp.setPrev('.');
				temp.setBoard(gb);
				
				temp.setValue(2);
				
				square_arr.emplace_back(temp);
				gold_arr.emplace_back(temp)
			} else if (c == '7') { // small hoard 
				Gold temp;
				
				temp.setCoords(i, j);
				temp.setSym('G');
				temp.setPrev('.');
				temp.setBoard(gb);
				
				temp.setValue(1);
				
				square_arr.emplace_back(temp);
				po_arr.emplace_back(temp);
			} else if (c == '8') { // merchant hoard
				Gold temp;
				
				temp.setCoords(i, j);
				temp.setSym('G');
				temp.setPrev('.');
				temp.setBoard(gb);
				
				temp.setValue(4);
				
				square_arr.emplace_back(temp);
				po_arr.emplace_back(temp);
			} else if (c == '9') { // dragon hoard 
				Gold temp;
				
				temp.setCoords(i, j);
				temp.setSym('G');
				temp.setPrev('.');
				temp.setBoard(gb);
				
				temp.setValue(6);
				
				square_arr.emplace_back(temp);
				po_arr.emplace_back(temp);
			} else { // other stuff: wall, doorway, floor tile, passage
				Square temp;
				
				temp.setCoords(i, j);
				temp.setSym(c);
				temp.setPrev('.');
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
	
	// set player neighbors
	this->player->setNeigh(theFloor[this->player->row][this->player->col].getNeigh());	
	
	// remain the HP of the player
	this->player->sethp(HP_record);
}


void Floor::restart() {
	
}


// generate a series of things :(
// remember to erase the pos after generating!
int Floor::make_player(vector<vector<char>> in_file) {
	// generate coordinate
	int room_num = rand() % 5;
	int size = this->theRoom[room_num].pos.size();
	
	int index_num = rand() % size;
	
	int row = this->theRoom[room_num].pos[index_num].first;
	int col = this->theRoom[room_num].pos[index_num].second;
	
    in_file[row][col] = '@';
	this->Board->notify(row, col, '@');
	
	// erase the occupied pos
	this->theRoom[room_num].pos.erase(this->theRoom[room_num].pos.begin() + index_num);
	return room_num
}

void Floor::make_stair(int player_room) {
	// generate coordinates
	int room_num = rand() % 5;
	while (room_num == player_room) {
		room_num = rand() % 5;
	}
	
	int size = this->theRoom[room_num].pos.size();
	
	int index_num = rand() % size;
	
	int row = this->theRoom[room_num].pos[index_num].first;
	int col = this->theRoom[room_num].pos[index_num].second;
	
    in_file[row][col] = '\\';
	this->Board->notify(row, col, '\\');
	
	// erase the occupied pos
	this->theRoom[room_num].pos.erase(this->theRoom[room_num].pos.begin() + index_num);	
}

void Floor::make_potion(int type) {
	
	int room_num = rand() % 5;
	int size = this->theRoom[room_num].pos.size();
	
	int index_num = rand() % size;
	
	int row = this->theRoom[room_num].pos[index_num].first;
	int col = this->theRoom[room_num].pos[index_num].second;
	
	in_file[row][col] = type + 60;
	this->Board->notify(row, col, type + 60);
	
	// erase the occupied pos
	this->theRoom[room_num].pos.erase(this->theRoom[room_num].pos.begin() + index_num);		
}

void Floor::make_gold(int type) {
	int room_num = rand() % 5;
	int size = this->theRoom[room_num].pos.size();
	
	int index_num = rand() % size;
	
	int row = this->theRoom[room_num].pos[index_num].first;
	int col = this->theRoom[room_num].pos[index_num].second;
	
	in_file[row][col] = type + 60;
	this->Board->notify(row, col, type + 60);
	
	// erase the occupied pos
	this->theRoom[room_num].pos.erase(this->theRoom[room_num].pos.begin() + index_num);			
}

void Floor::make_enemy(char type) {
	int room_num = rand() % 5;
	int size = this->theRoom[room_num].pos.size();
	
	int index_num = rand() % size;
	
	int row = this->theRoom[room_num].pos[index_num].first;
	int col = this->theRoom[room_num].pos[index_num].second;
	
	in_file[row][col] = type
	this->Board->notify(row, col, type);
	
	// erase the occupied pos
	this->theRoom[room_num].pos.erase(this->theRoom[room_num].pos.begin() + index_num);			
}

void Floor::pcMove(string direction) {
	this->player->move(direction);
}


void Floor::pcAtk(string direction) {
	this->player->attack(direction);
}

void Floor::pcUse(string direction) {
	this->player->use(direction);
}

void Floor::enemyMove() {
	int size = this->en_arr.size();
	
	for (int i = 0; i < size; i++) {
		this->en_arr[i].move();
	}
}

void Floor::check_enemy() {
	int size = this->en_arr.size();
	
	for (int i = 0; i < size; i++) {
		if (this->en_arr.isDead()) {
			this->en_arr.erase(this->en_arr.begin() + i);
		}
		break;
	}
}

bool Floor::at_stair() {
	return this->player->isOnStair();
}

// mutators 

void Floor::setFname(std::string name) {
	this->fname = name;
}

// accessors 

int Floor::getLevel() {
	return this->level;
}

int Floor::getScore() {
	if (this->player->getType() == "s") {
		return this->player->getGold() * 1.5;
	} else {
		return this->player->getGold;
	}
}

PC* Floor::getPC() {
	return player;	
}

friend std::ostream &operator<<(std::ostream &out, const Floor &f) {
	out << *f.Board;
	return out;
}
