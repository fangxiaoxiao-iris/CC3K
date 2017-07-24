#include <string>
#include <vector>
#include "PC.h"
#include "Gold.h"
#include "Potion.h"
using namespace std;

PC::PC(int row, int col, char sym, char prev, GameBoard* theBoard): 
Character(row, col, sym, prev, theBoard) {
	vector <string> pArr;
	knownPotions = pArr;
}

PC::~PC(){}

vector<string> &PC::getKnownPotions(){
	return knownPotions;
}

void PC::setKnownPotions(std::string pName) {
	knownPotions.emplace_back(pName);
}

// change PC's coordinates and notify neighbors.
void PC::proper_move(string index_nb, string index_p) {
	if (((neighbors[index_nb])->get_sym() == '.') || 
		((neighbors[index_nb])->get_sym() == '#') || 
		((neighbors[index_nb])->get_sym() == '+') ||
		((neighbors[index_nb])->get_sym() == 'G')) {
			swapCoords(neighbors[index_nb]);
			notifyMove(index_nb);
			char p_prev_sym = get_prev();
			setPrev(neighbors[index_nb]->get_sym());
			neighbors[index_nb]->setSym(p_prev_sym);
			swapNeighbors(neighbors[index_nb], index_nb, index_p);
		} else if ((neighbors[index_nb])->get_sym() == '\\') {
			swapCoords(neighbors[index_nb]);
			notifyMove(index_nb);
			char p_prev_sym = get_prev();
			setPrev(neighbors[index_nb]->get_sym());
			(neighbors[index_nb])->setSym(p_prev_sym);
			swapNeighbors(neighbors[index_nb], index_nb, index_p);
		} else {
			cout << "Invalid direction. " <<
			"You are heading to a dead end." << endl;
		}
}

void PC::move(std::string direction) {
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
		proper_move("no", "so");
	} else if (direction == "so") {
		proper_move("so", "no");
	} else if (direction == "ea") {
		proper_move("ea", "we");
	} else if (direction == "we") {
		proper_move("we", "ea");
	} else if (direction == "ne") {
		proper_move("ne", "sw");
	} else if (direction == "nw") {
		proper_move("nw", "se");
	} else if (direction == "se") {
		proper_move("se", "nw");
	} else if (direction == "sw") {
//		r_update = r_coord+1;
//		c_update = c_coord-1;
		proper_move("sw", "ne");
	} else {
		cout << "Invalid direction. Please choose a valid direction from " <<
		"no (North), so (South), ea (East), we (West), ne (Northeast), " <<
		"nw (Northwest), se (Southeast), sw (Southwest)." << endl;
	}
}

void PC::use(Potion &p) {
	string type = gettype();
	// Troll gains 5HP every turn.
	if (type == "Troll") {
		int t_cur_hp = gethp();
		int t_max_hp = getmaxhp();
		int t_update_hp = ((t_cur_hp + 5) <= t_max_hp) ? 
		(t_cur_hp + 5) : t_max_hp;
		sethp(t_update_hp);
	}
	
	p.used(*this);
}

void PC::pickUp(Gold &g) {
	g.picked(*this);
}

bool PC::isOnStair() {
	if (get_prev() == '\\') {
		return true;
	} else {
		return false;
	}
}
