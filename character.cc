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
	return this->getmaxhp;
}

int Character::gettype(){
	return this->type;
}