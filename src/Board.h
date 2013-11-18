#pragma once
#include "Player.h"
#include "Chip.h"

class Player;
class Chip;

class Board{
private:
	static const int col_size = 6;
	static const int row_size = 7;

	/*
	Possible States:
	0 - Game still pending
	1 - Player 1 wins
	2 - Player 2 wins
	3 - Draw
	*/
	int state;

	Chip* board;
	Player* player1;
	Player* player2;

	bool checkDraw();
	bool checkWin(Chip &c);

public:
	Board(Player &p1, Player &p2);
	~Board();
	bool addPiece(Player &p, int pos);
	int getState();
	void printBoard();
};