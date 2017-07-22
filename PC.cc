#include <string>
#include <vector>
#include "Square.h"
#include "PC.h"
using namespace std;

PC::PC(): Character() {
	vector <string> pArr;
	knownPotions = pArr;
}

void PC::use(Potion &) {
}

// change PC's coordinates and notify neighbors.
static void proper_move(PC &p, string index_nb, string index_p) {
	if (((p.neighbors[index_nb]).get_sym() == '.') || 
		((p.neighbors[index_nb]).get_sym() == '#') || 
		((p.neighbors[index_nb]).get_sym() == '+')) {
			p.swapCoords(p.neighbors[index_nb]);
			p.swapNeighbors(p.neighbors[index_nb], index_nb, index_p);
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
	// Troll gains 5HP every move.
	if (type == "Troll") {
		int t_cur_hp = gethp();
		int t_update_hp = t_cur_hp + 5;
		sethp(t_update_hp);
	}

	if (direction == "no") {
		r_update = r_coord;
		c_update = c_coord-1;
		proper_move(*this, r_update, c_update, "no", "so");
	} else if (direction == "so") {
		r_update = r_coord;
		c_update = c_coord+1;
		proper_move(*this, r_update, c_update, "so", "no");
	} else if (direction == "ea") {
		r_update = r_coord+1;
		c_update = c_coord;
		proper_move(*this, r_update, c_update, "ea", "we");
	} else if (direction == "we") {
		r_update = r_coord-1;
		c_update = c_coord;
		proper_move(*this, r_update, c_update, "we", "ea");
	} else if (direction == "ne") {
		r_update = r_coord-1;
		c_update = c_coord+1;
		proper_move(*this, r_update, c_update, "ne", "sw");
	} else if (direction == "nw") {
		r_update = r_coord-1;
		c_update = c_coord-1;
		proper_move(*this, r_update, c_update, "nw", "se");
	} else if (direction == "se") {
		r_update = r_coord+1;
		c_update = c_coord+1;
		proper_move(*this, r_update, c_update, "se", "nw");
	} else if (direction == "sw") {
		r_update = r_coord+1;
		c_update = c_coord-1;
		proper_move(*this, r_update, c_update, "sw", "ne");
	} else {
		cout << "Invalid direction. Please choose a valid direction from 
		no (North), so (South), ea (East), we (West), ne (Northeast), 
		nw (Northwest), se (Southeast), sw (Southwest)" << endl;
	}
}

void PC::dead() override {
	notifyBoard();
}