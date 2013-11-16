#include "Player.h"

Player::Player(char c){
	color = c;
}

Player::~Player(){

}

void Player::makeMove(Board &b, int pos){
	(*b).addPiece(this, pos);
}

char Player::getColor(){
	return color;
}