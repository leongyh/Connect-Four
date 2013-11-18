#pragma once
#include "Player.h"

#include <stdlib.h>

class Player;

class Chip{
private:
	Player* owner;
	int col, row;

public:
	Chip(Player *p, int c, int r);
	~Chip();
	Player* getOwner();
	bool isEmpty();
	int getRow();
	int getCol();
};