#include "enemy.h"
#include <string>

using namespace std;

Enemy::Enemy(int row, int col, char sym, char prev, GameBoard* theBoard):
	Character(row, col, sym, prev, theBoard) {}

Enemy::~Enemy() {}

static void proper_move(Enemy &e, string index_nb, string index_p) {
	if((e.neighbors[index_nb].get_sym() == '.')) {
			e.swapCoords(p.neighbors[index_nb]);
			char e_prev_sym = e.get_prev();
			e.setPrev(e.neighbors[index_nb]);
			(e.neighbors[index_nb]).setSym(e_prev_sym);
			e.swapNeighbors(e.neighbors[index_nb], index_nb, index_p);
			e.notifyMove(index_nb);
	}
} 

static bool isproper(Enemy &e, int index) {
	if(e.neighbors[index].get_sym() == '.') {
		return true;
	} else {
		return false;
	}
}

void Enemy::move(){

	int random;
	bool propermove;
	bool stationary = true;

	for(auto n: neighbors) {
		if(n->get_sym() == '.') {
			stationary = false;
		}
	}

	if(stationary == false) {
	while(random = rand() % 8;) {
		propermove = isproper(*this, random);
		if(propermove == true) {
			if(random == 0) {
				proper_move(*this, "no", "so");
			} else if (random == 1) {
				proper_move(*this, "so", "no");
			} else if (random == 2) {
					proper_move(*this, "ea", "we");
			} else if (random == 3) {
					proper_move(*this, "we", "ea");
			} else if (random == 4) {
					proper_move(*this, "ne", "sw");
			} else if (random == 5) {
					proper_move(*this, "nw", "se");
			} else if (random == 6) {
					proper_move(*this, "se", "nw");
			} else {
				// random == 7
					proper_move(*this, "sw", "ne");
			}
		} else {
		continue;
}
}
}
	for(auto n: neighbors) {
		if(n->get_sym() == '@') {
			attack(*n);
		}
	}

}

void Enemy::dead() override {
	notifyBoard();
}

