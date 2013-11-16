#include "Player.h"
#include "Chip.h"

class Board{
private:
	int const col_size = 7;
	int const row_size = 6;

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
	Board();
	~Board();
	bool addPiece(int pos, Chip &c);
	int getState();
	void printBoard();
};