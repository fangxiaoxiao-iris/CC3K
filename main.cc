#include "floor.h"
#include <fstream>

int main(int argc, char* argv[]) {
	string cmd;
	string race;
	string full_name;
	Floor f;
	bool move = true;
	
	cout << "Please choose a player character from the following races: " << endl;
	cout << "s - Shade, d - Drow, v - Vampire, t - Troll, g - Goblin." << endl;
	
	cin >> race;
	
	while (race != "s" && race != "d" && race != "v" && race != "t" && race != "g") {
		cout << "Please choose a valid race." << endl;
        cin >> race;
	}
	
	if (race == "s") {
		full_name = "Shade";
	} else if (race == "d") {
		full_name = "Drow";
	} else if (race == "v") {
		full_name = "Vampire";
	} else if (race == "t") {
		full_name = "Troll";
	} else {
		full_name = "Goblin";
	}
		
	// initialize the floor
	
	if (argc == 1) {
		cout << "arg" << endl;
		f.init_no_file("cc3kfloor.txt", race);
		cout << f;
		cout << "Race: " << full_name << " Gold: " << f.getPC()->getgold() <<
			"                                            " << "Floor " << f.getLevel() << endl;
		cout << "HP: " << f.getPC()->gethp() << endl;
		cout << "Atk: " << f.getPC()->getatk() << endl;
		cout << "Def: " << f.getPC()->getdef() << endl;
		cout << "Action: "; 
	} else {
		string fname = argv[1];
		f.init_file(fname, race);
		cout << f;
		cout << "Race: " << full_name << " Gold: " << f.getPC()->getgold() <<
			"                                            " << "Floor " << f.getLevel() << endl;
		cout << "HP: " << f.getPC()->gethp() << endl;
		cout << "Atk: " << f.getPC()->getatk() << endl;
		cout << "Def: " << f.getPC()->getdef() << endl;
		cout << "Action: " << endl; 
	}
	
	while (cin >> cmd) {
		// PC moves
		if(cmd == "no" || cmd == "so" || cmd == "ea" || cmd == "we"
		|| cmd == "ne" || cmd == "nw" || cmd == "se" || cmd == "sw") {
			f.pcMove(cmd);
			if (move == true) {
				f.enemyMove();	
			}
			
			//check stair 
			if (f.at_stair()) {
				int HP_record = f.getPC()->gethp();
				if (argc == 1) {
					f.init_no_file("cc3kfloor.txt", race);
				} else {
					string fname = argv[1];
					f.init_file(fname, race);
				}
				f.getPC()->sethp(HP_record);
			}
			
			cout << f;
			cout << "Race: " << full_name << " Gold: " << f.getPC()->getgold() <<
				"                                            " << "Floor " << f.getLevel() << endl;
			cout << "HP: " << f.getPC()->gethp() << endl;
			cout << "Atk: " << f.getPC()->getatk() << endl;
			cout << "Def: " << f.getPC()->getdef() << endl;
			cout << "Action: "; 
			cout << "PC moves." << endl;
		} else if (cmd == "u") {
			cin >> cmd;
			f.pcUse(cmd);
			if (move == true) {
				f.enemyMove();
			}
			
			cout << f;
			cout << "Race: " << full_name << " Gold: " << f.getPC()->getgold() <<
				"                                            " << "Floor " << f.getLevel() << endl;
			cout << "HP: " << f.getPC()->gethp() << endl;
			cout << "Atk: " << f.getPC()->getatk() << endl;
			cout << "Def: " << f.getPC()->getdef() << endl;
			cout << "Action: "; 
			cout << "PC uses potion." << endl;
		} else if (cmd == "a") {
			cin >> cmd;
			f.pcAtk(cmd);
			
			// check enemy
			//f.check_enemy();
			
			cout << f;
			cout << "Race: " << full_name << " Gold: " << f.getPC()->getgold() <<
				"                                            " << "Floor " << f.getLevel() << endl;
			cout << "HP: " << f.getPC()->gethp() << endl;
			cout << "Atk: " << f.getPC()->getatk() << endl;
			cout << "Def: " << f.getPC()->getdef() << endl;
			cout << "Action: "; 
			cout << "PC attacks an enemy." << endl;
		} else if (cmd == "f") {
			move = (move ==  true) ? false : true;
			
			cout << "Enemies change moving state." << endl;
		} else if (cmd == "r") {
			// f.restart();
			cout << "restart to be implemented" << endl;
			
		} else if (cmd == "q") {
			
			break;
			
		} else {
			cout << "Invalid Command. Please try again." << endl;
		}
		
	}

}
