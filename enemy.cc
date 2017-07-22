#include "enemy.h"
#include <string>

using namespace std;

static void proper_random_ move(Enemy &e, int r_update, int c_update, int index) {
	if((e.neighbors[index].get_sym() == '.')) {
		e.setCoords(r_update, c_update);
		e.notifyBoard();
	} else {
		cout << "Invalid direction. You are heading to a dead end." << endl;
	}
} 

void Enemy::move(){
	int r_coord = get_row();
	int c_coord = get_col();
	int r_update;
	int c_update;

	int random = rand % 8;

	if(random == 0) {

	} else if (random == 1) {

	} else if (random == 2) {

	} else if (random == 3) {

	} else if (random == 4) {

	} else if (random == 5) {

	} else if (random == 6) {

	} else {
		// random == 7
	}

}

