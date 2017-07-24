#include "enemy.h"
#include <string>

using namespace std;

Enemy::Enemy(int row, int col, char sym, char prev, GameBoard* theBoard):
	Character(row, col, sym, prev, theBoard) {}

Enemy::~Enemy() {}

static void proper_move(Enemy &e, string index_nb, string index_p) {
	if(((e.getNeigh())[index_nb]->get_sym() == '.')) {
			e.swapCoords((e.getNeigh())[index_nb]);
			e.notifyMove(index_nb);
			char p_prev_sym = e.get_prev();
			e.setPrev(e.getNeigh()[index_nb]->get_sym());
			e.getNeigh()[index_nb]->setSym(p_prev_sym);
			e.swapNeighbors((e.getNeigh())[index_nb], index_nb, index_p);
	}
} 

static bool isproper(Enemy &e, string index) {
	if((e.getNeigh())[index]->get_sym() == '.') {
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

	for(auto n: getNeigh()) {
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
		} while (!isproper(*this, randDirec));
		
		if(randDirec == "no") {
			proper_move(*this, "no", "so");
		} else if (randDirec == "so") {
			proper_move(*this, "so", "no");
		} else if (randDirec == "ea") {
			proper_move(*this, "ea", "we");
		} else if (randDirec == "we") {
			proper_move(*this, "we", "ea");
		} else if (randDirec == "ne") {
			proper_move(*this, "ne", "sw");
		} else if (randDirec == "nw") {
			proper_move(*this, "nw", "se");
		} else if (randDirec == "se") {
			proper_move(*this, "se", "nw");
		} else {
			proper_move(*this, "sw", "ne");
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