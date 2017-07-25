#include "floor.h"

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <memory>

using namespace std;

Floor::Floor() {}

Floor::~Floor() {
	delete Board;
	for (auto row: this->theFloor) {
		for (auto col: row) {
			delete col;
		}
	}	
}

bool Floor::GameOver() {
	return this->player->isDead();	
}

bool Floor::GameWin() {
	return this->level == 6;
}


void Floor::clearFloor() {	
	theFloor.clear();
	en_arr.clear();
	po_arr.clear();
	gold_arr.clear();
}

void Floor::init_no_file(string name, string race) {  // parameter name is always the default name
	// record the HP of player in this game
	//int HP_record = this->player->gethp();
	this->clearFloor(); // clearFloor: remains player, level and fname

	//int en_count = 0;
	// set fname field
	this->fname = name;
	
	//set Board field, will change it later
	GameBoard* gb = new GameBoard(name);
	this->Board = gb;
	
	// set level field
	this->level = this->level + 1;
	
	// set theRoom field
	// set the size of theRoom to 5
	//pair<int,int> poi;
	// vector<pair<int, int>> pairs;
	//this->theRoom.reserve(5);
	
	// set the first room, this->theRoom[0].pos.emplace_back(k);
	// row: 3-6 col: 3-28
	vector<pair <int, int>> room1;
	
	for (int i = 3; i <= 6; i++) {
		for (int j = 3; j <= 28; j++) {
			pair<int, int> k = make_pair(i, j);
			
			room1.emplace_back(k);
		}
	}
	
	// set the second room, this->theRoom[1].pos.emplace_back(k);
	// row: 15-21 col: 4-24
	vector<pair <int, int>> room2;
	
	for (int i = 15; i <= 21; i++) {
		for (int j = 4; j <= 24; j++) {
			pair<int, int> k = make_pair(i, j);
			room2.emplace_back(k);
		}
	}
	
	// set the third room, this->theRoom[2].pos.emplace_back(k);
	// row: 10-12 col: 38-49
	vector<pair <int, int>> room3;
	
	for (int i = 10; i <= 12; i++) {
		for (int j = 38; j <= 49; j++) {
			pair<int, int> k = make_pair(i, j);
			room3.emplace_back(k);
		}
	}
	
	// set the forth room, this->theRoom[3].pos.emplace_back(k);
	// divide into two rectangles and two random rows
	vector<pair <int, int>> room4;
	
	
	// first rectangle
	// row: 3-6 col: 39-61
	
	for (int i = 3; i <= 6; i++) {
		for (int j = 39; j <= 61; j++) {
			pair<int, int> k = make_pair(i, j);
			room4.emplace_back(k);
		}
	}
	
	// second rectangle
	// row: 7-12 col: 61-75
	for (int i = 7; i <= 12; i++) {
		for (int j = 61; j<= 75; j++) {
			pair<int, int> k = make_pair(i, j);
			room4.emplace_back(k);
		}
	}
	
	// first random row
	// row: 5 col: 62-69
	for (int j = 62; j<= 69; j++) {
		pair<int, int> k = make_pair(5, j);
		room4.emplace_back(k);
	}
	
	// second random row
	// row: 6 col: 62-72
	for (int j = 62; j <= 72; j++) {
		pair<int, int> k = make_pair(6, j);
		room4.emplace_back(k);
	}
	
	// set the fifth room, this->theRoom[3].pos.emplace_back(k);
	// divide into two rectangles
	vector<pair <int, int>> room5;
	
	// set the first rectangle
	// row: 19-21 col: 37-75
	for (int i = 19; i <= 21; i++) {
		for (int j = 37; j <= 75; j++) {
			pair<int, int> k = make_pair(i, j);
			room5.emplace_back(k);
		}
	}
	
	// set the second rectangle
	// row: 16-21 col: 65-75
	for (int i = 16; i<= 21; i++) {
		for (int j = 65; j <= 75; j++) {
			pair<int, int> k = make_pair(i, j);
			room5.emplace_back(k);
		}
	}
	this->theRoom.emplace_back(room1);
	this->theRoom.emplace_back(room2);
	this->theRoom.emplace_back(room3);
	this->theRoom.emplace_back(room4);
	this->theRoom.emplace_back(room5);
	
	
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
	this->make_stair(player_room, in_file);
	
	
	// generate potions
	for (int i = 0; i < 10; i++) {
		// 0: RH, 1: BA, 2: BD, 3: PH, 4: WA, 5: WD
		int p_num = rand() % 6;
		make_potion(p_num, in_file);		
	}
	
	// generate gold
	for (int i = 0; i < 10; i++) {
		// 0-4: normal: 6, 5: dragon hoard: 9, 6-7: small hoard: 8
		int g_num = rand() % 8;
		if (g_num >= 0 && g_num <= 4) {
			make_gold(6, in_file);
		} else if (g_num == 5) {
			make_gold(9, in_file);
		} else {
			make_gold(8, in_file);
		}		
	}
	
	// generate enemy 
	for (int i = 0; i < 20; i++) {
		// human: 0-3, dwarf: 4-6, halfling: 7-11, elf: 12-13, orc: 14-15, merchant: 16-17
		int e_num = rand() % 18;
		if (e_num >= 0 && e_num <= 3) {
			this->make_enemy('H', in_file);
		} else if (e_num >= 4 && e_num <= 6) {
			this->make_enemy('W', in_file);
		} else if (e_num >= 7 && e_num <= 11) {
			this->make_enemy('L', in_file);
		} else if (e_num >= 12 && e_num <= 13) {
			this->make_enemy('E', in_file);
		} else if (e_num >= 14 && e_num <= 15) {
			this->make_enemy('O', in_file);
		} else {
			this->make_enemy('M', in_file);
		}
	}
	// initialize using vector<vector<char>>

	// set theFloor field	
	for (int i = 0; i < 25; i++) {
		
		vector<Square*> square_arr;
		for (int j = 0; j < 79; j++) {
			
			char c = in_file[i][j];
			// if we encounter special cases: num, letter
			if (c == '@') {  // player character 
				if (race == "s") {
					Shade *temp = new Shade{i, j, '@', '.', gb};
					square_arr.emplace_back(temp);
					
					// set player field
					PC* p = temp;
					this->player = p;
					
				} else if (race == "d") {
					//Drow temp{i, j, '@', '.', gb};
					Drow *temp = new Drow{i, j, '@', '.', gb};
					square_arr.emplace_back(temp);
					
					// set player field
					PC* p = temp;
					this->player = p;
					
				} else if (race == "v") {
					//Vampire temp{i, j, '@', '.', gb};
					Vampire *temp = new Vampire{i, j, '@', '.', gb};
					square_arr.emplace_back(temp);
					
					// set player field
					PC* p = temp;
					this->player = p;
					
				} else if (race == "g") {
					//Goblin temp{i, j, '@', '.', gb};
					Goblin *temp = new Goblin{i, j, '@', '.', gb};
					square_arr.emplace_back(temp);
					
					// set player field
					PC* p = temp;
					this->player = p;
					
				} else if (race == "t"){
					//Troll temp{i, j, '@', '.', gb};
					Troll *temp = new Troll{i, j, '@', '.', gb};
					square_arr.emplace_back(temp);
					
					// set player field
					PC* p = temp;
					this->player = p;
					
				} else {
					// Fairy
					Fairy *temp = new Fairy{i, j, '@', '.', gb};
					square_arr.emplace_back(temp);
					
					// set player field
					PC* p = temp;
					this->player = p;
					
				}
			} else if (c == 'H') {    // all types of enemies :(

				//Human temp{i, j, 'H', '.', gb};
				Human *temp = new Human{i, j, 'H', '.', gb};
				//Human *ph;
				//ph = &temp;		
				square_arr.emplace_back(temp);
				en_arr.push_back(temp);
				//en_arr[en_count] = ph;
				//en_count ++;
			} else if (c == 'W') {
				//Dwarf temp{i, j, 'W', '.', gb};	
				Dwarf *temp = new Dwarf{i, j, 'W', '.', gb};
				//Dwarf *pd;
				//pd = &temp;	
				square_arr.emplace_back(temp);
				en_arr.push_back(temp);
				//en_arr[en_count] = pd;
				//en_count ++;
			} else if (c == 'E') {
				//Elf temp{i, j, 'E', '.', gb};
				Elf *temp = new Elf{i, j, 'E', '.', gb};
				//Elf *pe;
				//pe = &temp;	
				square_arr.emplace_back(temp);
				en_arr.push_back(temp);
				//en_arr[en_count] = pe;
				//en_count ++;
			} else if (c == 'O') {

				//Orcs temp{i, j, 'O', '.', gb};
				Orcs *temp = new Orcs{i, j, 'O', '.', gb};
				//Orcs *po;
				//po = &temp;	
				square_arr.emplace_back(temp);
				en_arr.push_back(temp);
				//en_arr[en_count] = po;
				//en_count ++;
			} else if (c == 'M') {
				//Merchant temp{i, j, 'M', '.', gb};	
				Merchant *temp = new Merchant{i, j, 'M', '.', gb};
				//Merchant *pm;
				//pm = &temp;	
				square_arr.emplace_back(temp);
				en_arr.push_back(temp);
				//en_arr[en_count] = pm;
				//en_count ++;
			} else if (c == 'D') {
				//Dragon temp{i, j, 'D', '.', gb};
				Dragon *temp = new Dragon{i, j, 'D', '.', gb};
				//Dragon *pdr;
				//pdr = &temp;	
				square_arr.emplace_back(temp);
				en_arr.push_back(temp);
				//en_arr[en_count] = pdr;
				//en_count ++;
			} else if (c == 'L') {
				//Halfling temp{i, j, 'L', '.', gb};
				Halfling *temp = new Halfling{i, j, 'L', '.', gb};
				//Halfling *pha;
				//pha = &temp;	
				square_arr.emplace_back(temp);
				en_arr.push_back(temp);
				//en_arr[en_count] = pha;
				//en_count ++;
			} else if (c == '0') {   // Potion: RH
				//Potion temp{i, j, 'P', '.', gb, "RH"};	
				Potion *temp = new Potion{i, j, 'P', '.', gb, "RH"};	
				square_arr.emplace_back(temp);
				po_arr.emplace_back(temp);
			} else if (c == '1') {  // Potion: BA
				//Potion temp{i, j, 'P', '.', gb, "BA"};
				Potion *temp = new Potion{i, j, 'P', '.', gb, "BA"};	
				square_arr.emplace_back(temp);
				po_arr.emplace_back(temp);
			} else if (c == '2') { // Potion: BD
				//Potion temp{i, j, 'P', '.', gb, "BD"};			
				Potion *temp = new Potion{i, j, 'P', '.', gb, "BD"};		
				square_arr.emplace_back(temp);
				po_arr.emplace_back(temp);
			} else if (c == '3') { // Potion: PH
				//Potion temp{i, j, 'P', '.', gb, "PH"};
				Potion *temp = new Potion{i, j, 'P', '.', gb, "PH"};	
				square_arr.emplace_back(temp);
				po_arr.emplace_back(temp);
			} else if (c == '4') { // Potion: WA
				//Potion temp{i, j, 'P', '.', gb, "WA"};
				Potion *temp = new Potion{i, j, 'P', '.', gb, "WA"};		
				square_arr.emplace_back(temp);
				po_arr.emplace_back(temp);
			} else if (c == '5') { // Potion: WD
				//Potion temp{i, j, 'P', '.', gb, "WD"};
				Potion *temp = new Potion{i, j, 'P', '.', gb, "WD"};		
				square_arr.emplace_back(temp);
				po_arr.emplace_back(temp);
			} else if (c == '6') { // normal gold pile
				//Gold temp{i, j, 'G', '.', gb, "normal", 2, true};
				Gold *temp = new Gold{i, j, 'G', '.', gb, "normal", 2, true};
				square_arr.emplace_back(temp);
				gold_arr.emplace_back(temp);
			} else if (c == '7') { // small hoard 
				//Gold temp{i, j, 'G', '.', gb, "small", 1, true};
				Gold *temp = new Gold{i, j, 'G', '.', gb, "small", 1, true};
				square_arr.emplace_back(temp);
				gold_arr.emplace_back(temp);
			} else if (c == '8') { // merchant hoard
				//Gold temp{i, j, 'G', '.', gb, "merchant_h", 4, true};
				Gold *temp = new Gold{i, j, 'G', '.', gb, "merchant_h", 4, true};
				square_arr.emplace_back(temp);
				gold_arr.emplace_back(temp);
			} else if (c == '9') { // dragon hoard 
				//Gold temp{i, j, 'G', '.', gb, "dragon_h", 6, false};	
				Gold *temp = new Gold{i, j, 'G', '.', gb, "dragon_h", 6, false};
				square_arr.emplace_back(temp);
				gold_arr.emplace_back(temp);
			} else { // other stuff: wall, doorway, floor tile, passage
				Square *temp = new Square{i, j, c, c, gb};
				//Square temp{i, j, c, '.', gb};
				square_arr.emplace_back(temp);				
			}			 
		}		
		this->theFloor.emplace_back(square_arr);		
	}
	
	// attach neighbors 
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 79; j++) {
			if (i - 1 >= 0) {
				this->theFloor[i][j]->attach("no", this->theFloor[i - 1][j]);
			}
			
			if (i + 1 < 25) {
				this->theFloor[i][j]->attach("so", this->theFloor[i + 1][j]);
			}
			
			if (j - 1 >= 0) {
				this->theFloor[i][j]->attach("we", this->theFloor[i][j - 1]);
			}
			
			if (j + 1 < 79) {
				this->theFloor[i][j]->attach("ea", this->theFloor[i][j + 1]);
			}
			
			// that's not enough, adjacent 8 squares
			
			if (i - 1 >= 0 && j - 1 >= 0) {
				this->theFloor[i][j]->attach("nw", this->theFloor[i - 1][j - 1]);
			}
			
			if (i + 1 < 25 && j + 1 < 79) {
				this->theFloor[i][j]->attach("se", this->theFloor[i + 1][j + 1]);
			}
			
			if (i - 1 >= 0 && j + 1 < 79) {
				this->theFloor[i][j]->attach("ne", this->theFloor[i - 1][j + 1]);
			}
			
			if (i + 1 < 25 && j - 1 >= 0) {
				this->theFloor[i][j]->attach("sw", this->theFloor[i + 1][j - 1]);
			}
		}
	}
}


void Floor::init_file(string name, string race) {
	
	this->clearFloor();
	
	// set the size of the en_arr
	//int en_count = 0;
	
	// set fname field
	this->fname = name;
	
	// set the level field 
	this->level = this->level + 1;
	
	//set Board field 
	GameBoard* gb = new GameBoard(name);
	this->Board = gb;
	
	// set theFloor field
	ifstream file(name);
	
	for (int i = 0; i < 25; i++) {
		
		vector<Square*> square_arr;
		string line;
		getline(file, line);
		
		for (int j = 0; j < 79; j++) {
			char c = line[j];
			
			// if we encounter special cases: num, letter
			if (c == '@') {  // player character 
				
				if (race == "s") {
					Shade *temp = new Shade{i, j, '@', '.', gb};
					square_arr.emplace_back(temp);
					
					// set player field
					PC* p = temp;
					this->player = p;
					
				} else if (race == "d") {
					//Drow temp{i, j, '@', '.', gb};
					Drow *temp = new Drow{i, j, '@', '.', gb};
					square_arr.emplace_back(temp);
					
					// set player field
					PC* p = temp;
					this->player = p;
					
				} else if (race == "v") {
					//Vampire temp{i, j, '@', '.', gb};
					Vampire *temp = new Vampire{i, j, '@', '.', gb};
					square_arr.emplace_back(temp);
					
					// set player field
					PC* p = temp;
					this->player = p;
					
				} else if (race == "g") {
					//Goblin temp{i, j, '@', '.', gb};
					Goblin *temp = new Goblin{i, j, '@', '.', gb};
					square_arr.emplace_back(temp);
					
					// set player field
					PC* p = temp;
					this->player = p;
					
				} else if (race == "t"){
					//Troll temp{i, j, '@', '.', gb};
					Troll *temp = new Troll{i, j, '@', '.', gb};
					square_arr.emplace_back(temp);
					
					// set player field
					PC* p = temp;
					this->player = p;
					
				} else {
					// Fairy
					Fairy *temp = new Fairy{i, j, '@', '.', gb};
					square_arr.emplace_back(temp);
					
					// set player field
					PC* p = temp;
					this->player = p;
					
				}
			} else if (c == 'H') {    // all types of enemies :(

				//Human temp{i, j, 'H', '.', gb};
				Human *temp = new Human{i, j, 'H', '.', gb};
				//Human *ph;
				//ph = &temp;		
				square_arr.emplace_back(temp);
				en_arr.push_back(temp);
				//en_arr[en_count] = ph;
				//en_count ++;
			} else if (c == 'W') {
				//Dwarf temp{i, j, 'W', '.', gb};	
				Dwarf *temp = new Dwarf{i, j, 'W', '.', gb};
				//Dwarf *pd;
				//pd = &temp;	
				square_arr.emplace_back(temp);
				en_arr.push_back(temp);
				//en_arr[en_count] = pd;
				//en_count ++;
			} else if (c == 'E') {
				//Elf temp{i, j, 'E', '.', gb};
				Elf *temp = new Elf{i, j, 'E', '.', gb};
				//Elf *pe;
				//pe = &temp;	
				square_arr.emplace_back(temp);
				en_arr.push_back(temp);
				//en_arr[en_count] = pe;
				//en_count ++;
			} else if (c == 'O') {

				//Orcs temp{i, j, 'O', '.', gb};
				Orcs *temp = new Orcs{i, j, 'O', '.', gb};
				//Orcs *po;
				//po = &temp;	
				square_arr.emplace_back(temp);
				en_arr.push_back(temp);
				//en_arr[en_count] = po;
				//en_count ++;
			} else if (c == 'M') {
				//Merchant temp{i, j, 'M', '.', gb};	
				Merchant *temp = new Merchant{i, j, 'M', '.', gb};
				//Merchant *pm;
				//pm = &temp;	
				square_arr.emplace_back(temp);
				en_arr.push_back(temp);
				//en_arr[en_count] = pm;
				//en_count ++;
			} else if (c == 'D') {
				//Dragon temp{i, j, 'D', '.', gb};
				Dragon *temp = new Dragon{i, j, 'D', '.', gb};
				//Dragon *pdr;
				//pdr = &temp;	
				square_arr.emplace_back(temp);
				en_arr.push_back(temp);
				//en_arr[en_count] = pdr;
				//en_count ++;
			} else if (c == 'L') {
				//Halfling temp{i, j, 'L', '.', gb};
				Halfling *temp = new Halfling{i, j, 'L', '.', gb};
				//Halfling *pha;
				//pha = &temp;	
				square_arr.emplace_back(temp);
				en_arr.push_back(temp);
				//en_arr[en_count] = pha;
				//en_count ++;
			} else if (c == '0') {   // Potion: RH
				//Potion temp{i, j, 'P', '.', gb, "RH"};	
				Potion *temp = new Potion{i, j, 'P', '.', gb, "RH"};	
				square_arr.emplace_back(temp);
				po_arr.emplace_back(temp);
			} else if (c == '1') {  // Potion: BA
				//Potion temp{i, j, 'P', '.', gb, "BA"};
				Potion *temp = new Potion{i, j, 'P', '.', gb, "BA"};	
				square_arr.emplace_back(temp);
				po_arr.emplace_back(temp);
			} else if (c == '2') { // Potion: BD
				//Potion temp{i, j, 'P', '.', gb, "BD"};			
				Potion *temp = new Potion{i, j, 'P', '.', gb, "BD"};		
				square_arr.emplace_back(temp);
				po_arr.emplace_back(temp);
			} else if (c == '3') { // Potion: PH
				//Potion temp{i, j, 'P', '.', gb, "PH"};
				Potion *temp = new Potion{i, j, 'P', '.', gb, "PH"};	
				square_arr.emplace_back(temp);
				po_arr.emplace_back(temp);
			} else if (c == '4') { // Potion: WA
				//Potion temp{i, j, 'P', '.', gb, "WA"};
				Potion *temp = new Potion{i, j, 'P', '.', gb, "WA"};		
				square_arr.emplace_back(temp);
				po_arr.emplace_back(temp);
			} else if (c == '5') { // Potion: WD
				//Potion temp{i, j, 'P', '.', gb, "WD"};
				Potion *temp = new Potion{i, j, 'P', '.', gb, "WD"};		
				square_arr.emplace_back(temp);
				po_arr.emplace_back(temp);
			} else if (c == '6') { // normal gold pile
				//Gold temp{i, j, 'G', '.', gb, "normal", 2, true};
				Gold *temp = new Gold{i, j, 'G', '.', gb, "normal", 2, true};
				square_arr.emplace_back(temp);
				gold_arr.emplace_back(temp);
			} else if (c == '7') { // small hoard 
				//Gold temp{i, j, 'G', '.', gb, "small", 1, true};
				Gold *temp = new Gold{i, j, 'G', '.', gb, "small", 1, true};
				square_arr.emplace_back(temp);
				gold_arr.emplace_back(temp);
			} else if (c == '8') { // merchant hoard
				//Gold temp{i, j, 'G', '.', gb, "merchant_h", 4, true};
				Gold *temp = new Gold{i, j, 'G', '.', gb, "merchant_h", 4, true};
				square_arr.emplace_back(temp);
				gold_arr.emplace_back(temp);
			} else if (c == '9') { // dragon hoard 
				//Gold temp{i, j, 'G', '.', gb, "dragon_h", 6, false};	
				Gold *temp = new Gold{i, j, 'G', '.', gb, "dragon_h", 6, false};
				square_arr.emplace_back(temp);
				gold_arr.emplace_back(temp);
			} else { // other stuff: wall, doorway, floor tile, passage
				Square *temp = new Square{i, j, c, c, gb};
				//Square temp{i, j, c, '.', gb};
				square_arr.emplace_back(temp);				
			}			 
		}			
		this->theFloor.emplace_back(square_arr);
	}	

	// attach neighbors 
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 79; j++) {
			if (i - 1 >= 0) {
				this->theFloor[i][j]->attach("no", this->theFloor[i - 1][j]);
			}
			
			if (i + 1 < 25) {
				this->theFloor[i][j]->attach("so", this->theFloor[i + 1][j]);
			}
			
			if (j - 1 >= 0) {
				this->theFloor[i][j]->attach("we", this->theFloor[i][j - 1]);
			}
			
			if (j + 1 < 79) {
				this->theFloor[i][j]->attach("ea", this->theFloor[i][j + 1]);
			}
			
			// that's not enough, adjacent 8 squares
			
			if (i - 1 >= 0 && j - 1 >= 0) {
				this->theFloor[i][j]->attach("nw", this->theFloor[i - 1][j - 1]);
			}
			
			if (i + 1 < 25 && j + 1 < 79) {
				this->theFloor[i][j]->attach("se", this->theFloor[i + 1][j + 1]);
			}
			
			if (i - 1 >= 0 && j + 1 < 79) {
				this->theFloor[i][j]->attach("ne", this->theFloor[i - 1][j + 1]);
			}
			
			if (i + 1 < 25 && j - 1 >= 0) {
				this->theFloor[i][j]->attach("sw", this->theFloor[i + 1][j - 1]);
			}
		}
	}
	// set player neighbors
	this->player->setNeigh(theFloor[this->player->get_row()][this->player->get_col()]->getNeigh());	
	// remain the HP of the player
}


void Floor::restart() {
	
}


// generate a series of things :(
// remember to erase the pos after generating!
int Floor::make_player(vector<vector<char>> &in_file) {
	// generate coordinate
	int room_num = rand() % 5;
	int size = this->theRoom[room_num].size();
	
	int index_num = rand() % size;
	
	int row = this->theRoom[room_num][index_num].first;
	int col = this->theRoom[room_num][index_num].second;
		
	in_file[row][col] = '@';
	this->Board->notify(row, col, '@');
	
	// erase the occupied pos
	this->theRoom[room_num].erase(this->theRoom[room_num].begin() + index_num);
	return room_num;
}

void Floor::make_stair(int player_room, vector<vector<char>> &in_file) {
	// generate coordinates
	int room_num = rand() % 5;
	while (room_num == player_room) {
		room_num = rand() % 5;
	}
	
	int size = this->theRoom[room_num].size();
	
	int index_num = rand() % size;
	
	int row = this->theRoom[room_num][index_num].first;
	int col = this->theRoom[room_num][index_num].second;
	
    in_file[row][col] = '\\';
	this->Board->notify(row, col, '\\');
	
	// erase the occupied pos
	this->theRoom[room_num].erase(this->theRoom[room_num].begin() + index_num);	
}

void Floor::make_potion(int type, vector<vector<char>> &in_file) {
	
		int room_num = rand() % 5;
		int size = this->theRoom[room_num].size();
	
		int index_num = rand() % size;
	
		int row = this->theRoom[room_num][index_num].first;
		int col = this->theRoom[room_num][index_num].second;
	
		in_file[row][col] = type + 48;
		this->Board->notify(row, col, 'P');
	
		// erase the occupied pos
		this->theRoom[room_num].erase(this->theRoom[room_num].begin() + index_num);	
		
}

void Floor::make_gold(int type, vector<vector<char>> &in_file) {
	
	if (type == 9) {
		
		// when the gold type is 9, should also make a dragon enemy
		
		int room_num = rand() % 5;
		int size = this->theRoom[room_num].size();
	
		int index_num = rand() % size;
	
		int row = this->theRoom[room_num][index_num].first;
		int col = this->theRoom[room_num][index_num].second;
	
		in_file[row][col] = type + 48;
		this->Board->notify(row, col, 'G');
	
		// erase the occupied pos
		this->theRoom[room_num].erase(this->theRoom[room_num].begin() + index_num);		
		
		// when the gold type is 9, should also make a dragon enemy, beside the dragon hoard 
		
		/*room_num = rand() % 5;
		size = this->theRoom[room_num].size();
		
		index_num = rand() % size;
		
		row = this->theRoom[room_num][index_num].first;
		col = this->theRoom[room_num][index_num].second;
		
		in_file[row][col] = 'D';
		this->Board->notify(row, col, 'D');
	
		// erase the occupied pos
		this->theRoom[room_num].erase(this->theRoom[room_num].begin() + index_num);		
		*/
		
		int dragon_r, dragon_c;
		do {
			int random = rand() % 8;
			if(random == 0) {
				dragon_r = row-1;
				dragon_c = col;
			} else if (random == 1) {
				dragon_r = row+1;
				dragon_c = col;
			} else if (random == 2) {
				dragon_r = row;
				dragon_c = col-1;
			} else if (random == 3) {
				dragon_r = row;
				dragon_c = col+1;
			} else if (random == 4) {
				dragon_r = row-1;
				dragon_c = col+1;
			} else if (random == 5) {
				dragon_r = row-1;
				dragon_c = col-1;
			} else if (random == 6) {
				dragon_r = row+1;
				dragon_c = col+1;
			} else {
				dragon_r = row+1;
				dragon_c = col-1;
			}
		} while (in_file[dragon_r][dragon_c] != '.');
		
		in_file[dragon_r][dragon_c] = 'D';
		this->Board->notify(dragon_r, dragon_c, 'D');
	
		// erase the occupied pos
		this->theRoom[room_num].erase(this->theRoom[room_num].begin() + index_num);	
		
		
		
	}	else {
		int room_num = rand() % 5;
		int size = this->theRoom[room_num].size();
	
		int index_num = rand() % size;
	
		int row = this->theRoom[room_num][index_num].first;
		int col = this->theRoom[room_num][index_num].second;
	
		in_file[row][col] = type + 48;
		this->Board->notify(row, col, 'G');
	
		// erase the occupied pos
		this->theRoom[room_num].erase(this->theRoom[room_num].begin() + index_num);	
	}
}

void Floor::make_enemy(char type, vector<vector<char>> &in_file) {
	int room_num = rand() % 5;
	int size = this->theRoom[room_num].size();
	
	int index_num = rand() % size;
	
	int row = this->theRoom[room_num][index_num].first;
	int col = this->theRoom[room_num][index_num].second;
	
	in_file[row][col] = type;
	this->Board->notify(row, col, type);
	
	// erase the occupied pos
	this->theRoom[room_num].erase(this->theRoom[room_num].begin() + index_num);			
}

void Floor::pcMove(string direction) {
	int row = this->player->get_row();
	int col = this->player->get_col();
	this->player->move(direction);
	for (auto nb: this->player->getNeigh()) {
		if (nb.second->get_sym() == 'P') {
			int row = nb.second->get_row();
			int col = nb.second->get_col();
			string pType;
			for (auto p: this->po_arr) {
				if (p->get_row() == row && p->get_col() == col) {
					pType = p->getItemType();
				}
			}
			
			bool known = false;
			for (auto p: this->player->getKnownPotions()) {
				if (p == pType) {
					known = true;
					cout << "Potion of type " << pType << 
					" available on your " << nb.first << endl;
				}
			}
			if (known == false) {
				cout << "Potion of an unknown type available on your "
				<< nb.first << endl;
			}
		}
	}
	if (this->player->get_prev() == 'G') {
		cout << "prev" << endl;
		for (int i = 0; i < this->gold_arr.size(); ++i) {
			if (row == this->gold_arr[i]->get_row() && col == this->gold_arr[i]->get_col()) {
				cout << "loop" << endl;
				if (this->gold_arr[i]->getavailable()) {
					cout << "pick up" << endl;
					this->player->pickUp(*(this->gold_arr[i]));
					this->player->setPrev('.');
				} else {
					cout << "You have to kill the Dragon first." << endl;
				}
				break;	
			}
		}
	}
}


void Floor::pcAtk(string direction) {
	if ((this->player->getNeigh()[direction]->get_sym() == 'H') ||
	(this->player->getNeigh()[direction]->get_sym() == 'D') ||
	(this->player->getNeigh()[direction]->get_sym() == 'W') ||
	(this->player->getNeigh()[direction]->get_sym() == 'M') ||
	(this->player->getNeigh()[direction]->get_sym() == 'O') ||
	(this->player->getNeigh()[direction]->get_sym() == 'E') ||
	(this->player->getNeigh()[direction]->get_sym() == 'L')) {
		int row = this->player->getNeigh()[direction]->get_row();
		int col = this->player->getNeigh()[direction]->get_col();
		for (int i = 0; i < en_arr.size(); i++) {
			if (row == this->en_arr[i]->get_row() && col == this->en_arr[i]->get_col()) {
				this->player->attack(*this->en_arr[i]);
				break;
			}
		}
	} else {
		cout << "No Enemy in this direction. " <<
		"Please enter a valid direction." << endl;
	}
}

void Floor::pcUse(string direction) {
	if (this->player->getNeigh()[direction]->get_sym() == 'P') {
		int row = this->player->getNeigh()[direction]->get_row();
		int col = this->player->getNeigh()[direction]->get_col();
	
		for (int i = 0; i < this->po_arr.size(); i++) {
			if (row == this->po_arr[i]->get_row() && col == this->po_arr[i]->get_col()) {
				this->player->use(*(this->po_arr[i]));
				//this->player->getNeigh()[direction]->setSym('.');
				this->player->setKnownPotions(this->po_arr[i]->getItemType());
				break;
			}
		}
	} else {
		cout << "No Potion available in this direction. " <<
		"Please enter a valid direction." << endl;
	}
}

void Floor::enemyMove() {
	//int size = this->en_arr.size();
	
	for (int i = 0; i < en_arr.size(); i++) {
		if (!en_arr[i]->isDead()) {
			this->en_arr[i]->move();
		}
	}
}

bool Floor::at_stair() {
	return this->player->isOnStair();
}

void Floor::auto_attack(PC& player) {
	for (int i = 0; i < en_arr.size(); ++i) {
		if (!en_arr[i]->isDead()) {
			en_arr[i]->attack(player);
		}
	}
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
	if (this->player->gettype() == "Shade") {
		return ceil(this->player->getgold() * 1.5);
	} else {
		return this->player->getgold();
	}
}

PC* Floor::getPC() {
	return player;	
}

ostream &operator<<(std::ostream &out, const Floor &f) {
	out << *f.Board;
	return out;
}
