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

void init_no_file(string name, string race) {  // parameter name is always the default name
	
	// record the HP of player in this game
	int HP_record = this->player->gethp();
		
	this->clearFloor(); // clearFloor: remains player, level and fname

	// set fname field
	this->faname = name;

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
	
	// generate
		
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
				/*
				PC temp;
				temp.settype("s");
				temp.setCoords(i, j);
				temp.setSym('@');
				temp.setPrev('i');
				temp.setBoard(gb);
				
				square_arr.emplace_back(temp);
				*/
				
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


void restart();
void clear();

// generate a series of things :(

void make_player(string race) {
	// generate coordinate
	int room_num = rand() % 5;
	int size = this->theRoom[room_num].pos.size();
	
	int index_num = rand() % size;
	
	int row = this->theRoom[room_num].pos[index_num].first;
	int col = this->theRoom[room_num].pos[index_num].second;
	
	// change the corresponding square
	
	if (race == "s") {
		Shade temp;
		// this->theFloor[row][col] = temp;
		// Do I need to change theFloor?
		
		temp.setSym('@');
		temp.setCoords(row, col);
		temp.setPrev('.');
		temp.setBoard(this->Board);
		
		t
	} else if (race == "d") {
		Drow temp;
		
	}
	
	
	
	this->theFloor[row][col] 
}
void make_stair();
void make_potion();
void make_gold();
void make_enemy();

void pcMove(string direction) {
	int old_r = this->player->get_row();
	int old_c = this->player->get_col();
	
	
	
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

friend std::ostream &operator<<(std::ostream &out, const Floor &f);
