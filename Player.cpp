#include "Player.h"

Player::Player(char c){
	color = c;
}

Player::~Player(){

}

Player::makeMove(Board &b, int pos){
	(*b).addPiece(this, int pos);
}