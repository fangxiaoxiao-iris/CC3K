#include "floor.h"
#include <fstream>

int main(int argc, char* argv[]) {
	int level = 1;
	string cmd;
	string race;
	string full_name;
	Floor f;
	bool move = true;
	
	// Ascii art: welcome
	
	ifstream file ("cc3k_welcome.txt");
	string line;
	while(getline(file, line)) {
		for (int i = 0; i < 53; i++) {
			cout << line[i];
		}
		cout << endl;
	}
		
	cout << "Please choose a player character from the following races: " << endl;
	cout << "s - Shade, d - Drow, v - Vampire, t - Troll, g - Goblin, f - Fariy." << endl;
	
	cin >> race;
	
	while (race != "s" && race != "d" && race != "v" && race != "t" && race != "g" && race != "f") {
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
	} else if (race == "g") {
		full_name = "Goblin";
	} else {
		full_name = "Fairy";
	}
		
	// initialize the floor
	
	if (argc == 1) {
		f.init_no_file("cc3kfloor.txt", race);
		cout << f;
		cout << "Race: " << full_name << " Gold: " << f.getPC()->getgold() <<
			"                                            " << "Floor " << level << endl;
		cout << "HP: " << f.getPC()->gethp() << endl;
		cout << "Atk: " << f.getPC()->getatk() << endl;
		cout << "Def: " << f.getPC()->getdef() << endl;
		cout << "Action: "; 
	} else {
		string fname = argv[1];
		f.init_file(fname, race);
		cout << f;
		cout << "Race: " << full_name << " Gold: " << f.getPC()->getgold() <<
			"                                            " << "Floor " << level << endl;
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
			f.auto_attack(*(f.getPC()));
			if (f.getPC()->isDead()) {
				
				ifstream file ("gameover.txt");
				string line;
				while(getline(file, line)) {
					for (int i = 0; i < 42; i++) {
						cout << line[i];
					}
					cout << endl;
				}
				cout << "You have collected " << f.getScore() << " pile(s) of gold in this round." << endl;
				break;
			}
			//check stair 
			if (f.at_stair()) {
				int HP_record = f.getPC()->gethp();
				int gold_record = f.getPC()->getgold();
				vector<string> &knownPotions = f.getPC()->getKnownPotions();
				if (argc == 1) {
					f.init_no_file("cc3kfloor.txt", race);
				} else {
					string fname = argv[1];
					f.init_file(fname, race);
				}
				
				f.getPC()->sethp(HP_record);
				f.getPC()->setgold(gold_record);
				for(auto p: knownPotions) {
					f.getPC()->setKnownPotions(p);
				}
				
				++level;
				if (level == 6) {
					ifstream file ("youwon.txt");
					string line;
					while(getline(file, line)) {
						for (int i = 0; i < 72; i++) {
							cout << line[i];
						}
						cout << endl;
					}
					cout << "You have collected " << f.getScore() << " pile(s) of gold in this round." << endl;
					break;
				}
			}
			
			cout << f;
			cout << "Race: " << full_name << " Gold: " << f.getPC()->getgold() <<
				"                                            " << "Floor " << level << endl;
			cout << "HP: " << f.getPC()->gethp() << endl;
			cout << "Atk: " << f.getPC()->getatk() << endl;
			cout << "Def: " << f.getPC()->getdef() << endl;
			cout << "Action: "; 
			cout << "PC moves." << endl;
			
			
		} else if (cmd == "u") {
			cin >> cmd;
			f.pcUse(cmd);
			if (f.getPC()->isDead()) {
				ifstream file ("gameover.txt");
				string line;
				while(getline(file, line)) {
					for (int i = 0; i < 42; i++) {
						cout << line[i];
					}
					cout << endl;
				}
				cout << "You have collected " << f.getScore() << " pile(s) of gold in this round." << endl;
				break;
			}
			if (move == true) {
				f.enemyMove();
			}
			
			cout << f;
			cout << "Race: " << full_name << " Gold: " << f.getPC()->getgold() <<
				"                                            " << "Floor " << level << endl;
			cout << "HP: " << f.getPC()->gethp() << endl;
			cout << "Atk: " << f.getPC()->getatk() << endl;
			cout << "Def: " << f.getPC()->getdef() << endl;
			cout << "Action: "; 
			cout << "PC uses potion." << endl;
		} else if (cmd == "a") {
			cin >> cmd;
			f.pcAtk(cmd);
			
			cout << f;
			cout << "Race: " << full_name << " Gold: " << f.getPC()->getgold() <<
				"                                            " << "Floor " << level << endl;
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
			level = 1;
			cout << "Please choose a player character from the following races: " << endl;
			cout << "s - Shade, d - Drow, v - Vampire, t - Troll, g - Goblin, f - Fariy." << endl;
	
			cin >> race;
	
			while (race != "s" && race != "d" && race != "v" && race != "t" && race != "g" && race != "f") {
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
			} else if (race == "g") {
				full_name = "Goblin";
			} else {
				full_name = "Fairy";
			}
			
			if (argc == 1) {
				f.init_no_file("cc3kfloor.txt", race);
				cout << f;
				cout << "Race: " << full_name << " Gold: " << f.getPC()->getgold() <<
					"                                            " << "Floor " << level << endl;
				cout << "HP: " << f.getPC()->gethp() << endl;
				cout << "Atk: " << f.getPC()->getatk() << endl;
				cout << "Def: " << f.getPC()->getdef() << endl;
				cout << "Action: "; 
			} else {
				string fname = argv[1];
				f.init_file(fname, race);
				cout << f;
				cout << "Race: " << full_name << " Gold: " << f.getPC()->getgold() <<
					"                                            " << "Floor " << level << endl;
				cout << "HP: " << f.getPC()->gethp() << endl;
				cout << "Atk: " << f.getPC()->getatk() << endl;
				cout << "Def: " << f.getPC()->getdef() << endl;
				cout << "Action: " << endl; 
			}
			
		} else if (cmd == "q") {
			
			break;
			
		} else if (cmd == "b") {
			cin >> cmd;
			if (!(cmd == "no" || cmd == "so" || cmd == "ea" || cmd == "we"
				|| cmd == "ne" || cmd == "nw" || cmd == "se" || cmd == "sw")) {
				cout << "Invalid instruction. Please follow the format: b <direction> <potion>." << endl;
				continue;
			}

			if ((f.getPC()->getNeigh()[cmd])->get_sym() == 'M') {
				cin >> cmd;
				if (f.getPC()->getgold() >= 2) {
					if (cmd == "RH") {
						int cur_hp = f.getPC()->gethp();
						int max_hp = f.getPC()->getmaxhp();
						int cur_gold = f.getPC()->getgold();
						int update_hp = ((cur_hp + 10) <= max_hp) ? (cur_hp + 10) : max_hp;
						int update_gold = cur_gold - 2;
						f.getPC()->sethp(update_hp);
						f.getPC()->setgold(update_gold);
					} else if (cmd == "BA") {
						int cur_atk = f.getPC()->getatk();
						int cur_gold = f.getPC()->getgold();
						int update_atk = cur_atk + 5;
						int update_gold = cur_gold - 2;
						f.getPC()->setatk(update_atk);
						f.getPC()->setgold(update_gold);
					} else if (cmd == "BD") {
						int cur_def = f.getPC()->getdef();
						int cur_gold = f.getPC()->getgold();
						int update_def = cur_def + 5;
						int update_gold = cur_gold - 2;
						f.getPC()->setdef(update_def);
						f.getPC()->setgold(update_gold);
					} else {
						cout << "I don't sell this kind of Potion. I only sell RH, BA, BD." << endl;
					}
					cout << f;
					cout << "Race: " << full_name << " Gold: " << f.getPC()->getgold() <<
						"                                            " << "Floor " << level << endl;
					cout << "HP: " << f.getPC()->gethp() << endl;
					cout << "Atk: " << f.getPC()->getatk() << endl;
					cout << "Def: " << f.getPC()->getdef() << endl;
					cout << "Action: "; 
					cout << "PC buys Potion from Merchant." << endl;
				} else {
					cout << "Sorry, you don't have enough money." << endl;
				}
			} else {
				cout << "No Merchant on this direction." << endl;
			} 
		} else {
			cout << "Invalid Command. Please try again." << endl;
		}
		
	}

}
