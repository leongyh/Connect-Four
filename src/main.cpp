#include <stdio.h>
#include <iostream>
#include <cstdlib>

#include "Board.h"
#include "Player.h"

using namespace std;

int main(int argc, char *argv[]){
	char p1, p2;

	Board *game;
	Player *player1;
	Player *player2;
	Player *turn;

	printf("%s\n", "Welcome to Hung's Connect-Four (ASCII version)!");
	printf("%s", "Welcome, Player 1. Please select a color (R/B): ");
	cin >> p1; //assert R/B
	(p1 == 'B') ? p2 = 'R' : p2 = 'B';
	printf("%s%c\n", "Welcome, Player 2. Your color is: ", p2);

	player1 = new Player(p1);
	player2 = new Player(p2);
	game = new Board(*player1, *player2);

	turn = player1;

	while(!(*game).getState()){
		int move;

		(*game).printBoard();

		printf("Color %c turn. Please select a column (0-6) to insert your chip into: ", (*turn).getColor());
		cin >> move; //assert 0-6
		
		(*game).addPiece(*turn, move);

		if(turn == player1){
			turn = player2;
		} else if(turn == player2){
			turn = player1;
		}
	}

	switch((*game).getState()){
		case 1:
			printf("Player 1 (%c) wins!\n", p1);
			break;
		case 2: 
			printf("Player 2 (%c) wins!\n", p2);
			break;
		case 3:
			printf("%s\n", "The game ended in a tie!");
			break;
	}

	exit(0);
}