#include <string>
#include <vector>
#include "Square.h"
#include "PC.h"
using namespace std;

PC::PC(int row, int col, char sym, char prev, GameBoard* theBoard): 
Character(row, col, sym, prev, theBoard) {
	vector <string> pArr;
	knownPotions = pArr;
}

void PC::use(string direction) {
	string type = gettype();
	// Troll gains 5HP every turn.
	if (type == "Troll") {
		int t_cur_hp = gethp();
		int t_max_hp = getmaxhp();
		int t_update_hp = ((t_cur_hp + 5) <= t_max_hp) ? 
		(t_cur_hp + 5) : t_max_hp;
		sethp(t_update_hp);
	}

	if (neighbors[direction]->get_sym() == 'P') {
		neighbors[direction]->used(*this);
		knownPotions.emplace_back(neighbors[direction]->getItemType());
	} else {
		cout << "No Potion available in this direction. 
		Please enter a valid direction." << endl;
	}
}

// change PC's coordinates and notify neighbors.
static void proper_move(PC &p, string index_nb, string index_p) {
	if (((p.neighbors[index_nb]).get_sym() == '.') || 
		((p.neighbors[index_nb]).get_sym() == '#') || 
		((p.neighbors[index_nb]).get_sym() == '+')) {
			p.swapCoords(p.neighbors[index_nb]);
			char p_prev_sym = p.get_prev();
			p.setPrev(p.neighbors[index_nb]);
			(p.neighbors[index_nb]).setSym(p_prev_sym);
			p.swapNeighbors(p.neighbors[index_nb], index_nb, index_p);
			p.notifyBoard();
		} else if ((p.neighbors[index_nb]).get_sym() == 'G') {
			p.swapCoords(p.neighbors[index_nb]);
			(p.neighbors[index_nb]).picked(p);
			p.setPrev(p.neighbors[index_nb]);
			p.swapNeighbors(p.neighbors[index_nb], index_nb, index_p);
			p.notifyBoard();
		} else {
			cout << "Invalid direction. You are heading to a dead end." << endl;
		}
}

void PC::move(std::string direction) override {
	string type = gettype();
	// Troll gains 5HP every move.
	if (type == "Troll") {
		int t_cur_hp = gethp();
		int t_max_hp = getmaxhp();
		int t_update_hp = ((t_cur_hp + 5) <= t_max_hp) ? 
		(t_cur_hp + 5) : t_max_hp;
		sethp(t_update_hp);
	}

	if (direction == "no") {
		proper_move(*this, "no", "so");
	} else if (direction == "so") {
		proper_move(*this, "so", "no");
	} else if (direction == "ea") {
		proper_move(*this, "ea", "we");
	} else if (direction == "we") {
		proper_move(*this, "we", "ea");
	} else if (direction == "ne") {
		proper_move(*this, "ne", "sw");
	} else if (direction == "nw") {
		proper_move(*this, "nw", "se");
	} else if (direction == "se") {
		proper_move(*this, "se", "nw");
	} else if (direction == "sw") {
//		r_update = r_coord+1;
//		c_update = c_coord-1;
		proper_move(*this, "sw", "ne");
	} else {
		cout << "Invalid direction. Please choose a valid direction from 
		no (North), so (South), ea (East), we (West), ne (Northeast), 
		nw (Northwest), se (Southeast), sw (Southwest)" << endl;
	}

	for (auto nb: neighbors) {
		if (nb->get_sym() == 'P') {
			string type = nb->getItemType();
			bool known = false;
			for (auto p: knownPotions) {
				if (p == type) {
					known = true;
					cout << "Potion of type " << type << 
					" available on your " << nb.first << endl;
				}
			}
			if (known == false) {
				cout << "Potion of an unknown type available on your "
				<< nb.first << endl;
			}
		}
	}
}

bool PC::isDead() override {
	return (gethp() == 0);
}