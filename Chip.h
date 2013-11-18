#pragma once
#include "Player.h"

class Chip{
private:
	Player* owner;
	int col, row;

public:
	Player* getOwner();
};