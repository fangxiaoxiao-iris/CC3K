#include "character.h"
#include "square.h"

using namespace std;


Character::Character(): Square() {}

Character::~Character() {}

void Character::sethp(int hp) {
	this->hp = hp;
}

void Character::setatk(int atk){
	this->atk = atk;
}

void Character::setdef(int def){
	this->def = def;
}

void Character::setmaxhp(int maxhp){
	this->maxhp = maxhp;
}

void Character::setgold(int gold) {
	this->gold = gold;
}

void Character::settype(string type) {
	this->type = type;
}

int Character::gethp(){
	return this->hp;
}

int Character::getatk(){
	return this->atk;
}

int Character::getdef(){
	return this->def;
}

int Character::getmaxhp(){
	return this->maxhp;
}

int Character::getgold(){
	return this->gold;
}
int Character::gettype(){
	return this->type;
}