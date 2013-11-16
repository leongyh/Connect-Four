#pragma once
#include "Player.h"
#include "Chip.h"

class Board{
private:
	static const int col_size = 7;
	static const int row_size = 6;

	/*
	Possible States:
	0 - Game still pending
	1 - Player 1 wins
	2 - Player 2 wins
	3 - Draw
	*/
	int state;

	Chip* board;
	Player* player1, player2;

	bool checkDraw();
	bool checkWin();

public:
	Board(Player &p1, Player &p2);
	~Board();
	bool addPiece(int pos, Chip &c);
	int getState();
	void printBoard();
};