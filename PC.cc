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

// change PC's coordinates and notify neighbors.
static void proper_move(PC &p, int r_update, int c_update, int index) {
	if (((p.neighbors[index]).get_sym() == '.') || 
		((p.neighbors[index]).get_sym() == '#') || 
		((p.neighbors[index]).get_sym() == '+')) {
			p.setCoords(r_update, c_update);
			p.notifyBoard();
		} else {
			cout << "Invalid direction. You are heading to a dead end." << endl;
		}
}

void PC::move(std::string direction) override {
	string type = gettype();
	int r_coord = get_row();
	int c_coord = get_col();
	int r_update, c_update;
	if (type == "Troll") {
		int t_cur_hp = gethp();
		int t_update_hp = t_cur_hp + 5;
		sethp(t_update_hp);
	}

	if (direction == "no") {
		r_update = r_coord;
		c_update = c_coord-1;
		proper_move(*this, r_update, c_update, 0);
	} else if (direction == "so") {
		r_update = r_coord;
		c_update = c_coord+1;
		proper_move(*this, r_update, c_update, 1);
	} else if (direction == "ea") {
		r_update = r_coord+1;
		c_update = c_coord;
		proper_move(*this, r_update, c_update, 2);
	} else if (direction == "we") {
		r_update = r_coord-1;
		c_update = c_coord;
		proper_move(*this, r_update, c_update, 3);
	} else if (direction == "ne") {
		r_update = r_coord-1;
		c_update = c_coord+1;
		proper_move(*this, r_update, c_update, 4);
	} else if (direction == "nw") {
		r_update = r_coord-1;
		c_update = c_coord-1;
		proper_move(*this, r_update, c_update, 5);
	} else if (direction == "se") {
		r_update = r_coord+1;
		c_update = c_coord+1;
		proper_move(*this, r_update, c_update, 6);
	} else if (direction == "sw") {
		r_update = r_coord+1;
		c_update = c_coord-1;
		proper_move(*this, r_update, c_update, 7);
	} else {
		cout << "Invalid direction. Please choose a valid direction from 
		no (North), so (South), ea (East), we (West), ne (Northeast), 
		nw (Northwest), se (Southeast), sw (Southwest)" << endl;
	}
}

void PC::dead() override {
	notifyBoard();
}