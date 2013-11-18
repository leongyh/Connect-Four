#include "Chip.h"

Chip::Chip(Player *p, int c, int r){
	owner = p;
	col = c;
	row = r;
}

Chip::~Chip(){

}

Player* Chip::getOwner(){
	return owner;
}

bool Chip::isEmpty(){
	return (owner == NULL);
}

int Chip::getRow(){
	return row;
}

int Chip::getCol(){
	return col;
}