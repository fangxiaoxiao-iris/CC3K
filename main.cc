#include "floor.h"
#include <fstream>

int main() {
	string command;
	Floor f;
	bool ismoving = true;

	if(argc == 1) {

	} else {
		// read in file
	}

while (cin >> command) {
	if(command == "no" || command == "so" || command == "ea" || command == "we"
		|| command == "ne" || command == "nw" || command == "se" || command == "sw") {
		if(ismoving == true;) {
		f.pcMove(command);
	}
		f.enemyMove();
	} else if (command == "u") {
		cin >> command;
		if(ismoving == true) {
		f.enemyMove();
	}
		f.pcUse(command);
	} else if (command == "a") {
		cin >> command;
		f.pcAtk(command);
	} else if (command == "s" || command == "d" || command == "v" || command == "g" || command == "t") {
		// 
	} else if (command == "f") {
		ismoving = (ismoving ==  true) ? false : true;
	} else if (command == "r") {
		// f.restart();
		cout << "restart to be implemented" << endl;
	} else if (command == "q") {
		break;
	} else {
		cout << "Invalid Command. Please try again." << endl;
	}
}

}
