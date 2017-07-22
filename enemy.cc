#include "enemy.h"
#include <string>

using namespace std;

static void proper_move(Enemy &e, int r_update, int c_update, int index) {
	if((e.neighbors[index].get_sym() == '.')) {
		e.setCoords(r_update, c_update);
		p.swapNeighbors(e.neighbors[index_nb], index_nb, index_p);
		e.notifyBoard();
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
	int r_coord = get_row();
	int c_coord = get_col();
	int r_update;
	int c_update;
	int random;
	bool propermove;
	bool stationary = true;

	for(int i = 0; i <= 7; ++i) {
		if(this->neighbors[i].get_sym() == '.') {
			stationary = false;
		}
	}

	if(stationary == false) {
	while(random = rand() % 8;) {
		propermove = isproper(*this, random);
		if(propermove == true) {
			if(random == 0) {
				r_update = r_coord;
		        c_update = c_coord-1;
				proper_move(*this, r_update, c_update, 0, 1);
			} else if (random == 1) {
				r_update = r_coord;
				c_update = c_coord+1;
				proper_move(*this, r_update, c_update, 1, 0);
			} else if (random == 2) {
					r_update = r_coord+1;
					c_update = c_coord;
					proper_move(*this, r_update, c_update, 2, 3);
			} else if (random == 3) {
					r_update = r_coord-1;
					c_update = c_coord;
					proper_move(*this, r_update, c_update, 3, 2);
			} else if (random == 4) {
					r_update = r_coord-1;
					c_update = c_coord+1;
					proper_move(*this, r_update, c_update, 4, 7);
			} else if (random == 5) {
					r_update = r_coord-1;
					c_update = c_coord-1;
					proper_move(*this, r_update, c_update, 5, 6);
			} else if (random == 6) {
					r_update = r_coord+1;
					c_update = c_coord+1;
					proper_move(*this, r_update, c_update, 6, 5);
			} else {
				// random == 7
					r_update = r_coord+1;
					c_update = c_coord-1;
					proper_move(*this, r_update, c_update, 7, 4);
			}
		} else {
		continue;
}
}
}
}

void Enemy::dead() override {
	notifyBoard();
}

