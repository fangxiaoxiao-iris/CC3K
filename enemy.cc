#include "enemy.h"
#include <string>

using namespace std;

Enemy::Enemy(int row, int col, char sym, char prev, GameBoard* theBoard):
	Character(row, col, sym, prev, theBoard) {}

Enemy::~Enemy() {}

void Enemy::proper_move(string index_nb, string index_p) {
		swapCoords((neighbors)[index_nb]);
		notifyMove(index_nb);
		//char p_prev_sym = get_prev();
		//setPrev(neighbors[index_nb]->get_sym());
		//neighbors[index_nb]->setSym(p_prev_sym);
		swapNeighbors((neighbors)[index_nb], index_nb, index_p);
		cout << get_sym() << endl;
		cout << "end first move" << endl;
} 

bool Enemy::isproper(string index) {
	if((neighbors)[index]->get_sym() == '.') {
		return true;
	} else {
		return false;
	}
}

void Enemy::move() {
 	int random;
	bool stationary = true;
	string randDirec;
	
	//cout << neighbors.size() << endl;

	for(auto n: neighbors) {
		//cout << "iammoving" << endl;
		if(n.second->get_sym() == '.') {
			stationary = false;
		}
	}

	if(stationary == false) {
		/*
		for (auto nb: getNeigh()) {
			if (isproper(*this, nb.first)) {
				propermove = true;
			}
		}*/
		do {
			random = rand() % 8;
			if(random == 0) {
				randDirec = "no";
			} else if (random == 1) {
				randDirec = "so";
			} else if (random == 2) {
				randDirec = "we";
			} else if (random == 3) {
				randDirec = "ea";
			} else if (random == 4) {
				randDirec = "ne";
			} else if (random == 5) {
				randDirec = "nw";
			} else if (random == 6) {
				randDirec = "se";
			} else {
				randDirec = "sw";
			}
		} while (!isproper(randDirec));
		
		if(randDirec == "no") {
			proper_move("no", "so");
		} else if (randDirec == "so") {
			proper_move("so", "no");
		} else if (randDirec == "ea") {
			proper_move("ea", "we");
		} else if (randDirec == "we") {
			proper_move("we", "ea");
		} else if (randDirec == "ne") {
			proper_move("ne", "sw");
		} else if (randDirec == "nw") {
			proper_move("nw", "se");
		} else if (randDirec == "se") {
			proper_move("se", "nw");
		} else {
			proper_move("sw", "ne");
		}
	}
}

void Enemy::dead() {
	this->setSym('.');
	this->notifyBoard();
}

int Enemy::test() {
	return 1;
}