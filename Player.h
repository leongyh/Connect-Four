#pragma once
#include "Board.h"

class Player
{
private:
	char color;

public:
	Player(char c);
	~Player();
	void makeMove(Board &b, int pos);
	char getColor();
};