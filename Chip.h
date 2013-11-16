#pragma once

class Chip{
private:
	Player* owner;
	int col, row;

public:
	Player* getOwner();
};