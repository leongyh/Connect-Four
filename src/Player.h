#pragma once
#include "Board.h"

class Player
{
private:
	char color;

public:
	Player(char c);
	~Player();
	char getColor();
};