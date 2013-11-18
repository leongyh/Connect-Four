#include "Player.h"

Player::Player(char c){
	color = c;
}

Player::~Player(){

}

char Player::getColor(){
	return color;
}