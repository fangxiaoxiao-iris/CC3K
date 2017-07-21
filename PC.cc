#include <string>
#include <vector>
#include "PC.h"
using namespace std;

PC::PC(): Character() {
	vector <string> pArr;
	knownPotions = pArr;
}

void PC::use(Potion &) {
}

void PC::move(std::string direction) override {
	int r_coord = get_row();
	int c_coord = get_col();
	int r_update, c_update;
	if (direction == "no") {
		r_update = r_coord;
		setCoords(r_coord, c_coord+1);
	} else if (direction == "so") {

	} else if (direction == "ea") {

	} else if (direction == "we") {

	} else if (direction == "ne") {

	} else if (direction == "nw") {

	} else if (direction == "se") {

	} else if (direction == "sw") {

	} else {
		cout << "Invalid direction. Please choose a valid direction from 
		no (North), so (South), ea (East), we (West), ne (Northeast), 
		nw (Northwest), se (Southeast), sw (Southwest)" << endl;
	}
}

void PC::dead() override {
	if (isDead()) {
		notifyBoard();
	}
}