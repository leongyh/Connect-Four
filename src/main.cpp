#include <stdio.h>
#include <iostream>
#include <stdlib.h>

#include "Board.h"
#include "Player.h"

using namespace std;

int main(int argc, char *argv[]){
	char p1, p2;
	bool namePass = false;

	Board *game;
	Player *player1;
	Player *player2;
	Player *turn;

	printf("%s\n", "Welcome to Hung's Connect-Four (ASCII version)!");

	while(!namePass){
		printf("%s", "Welcome, Player 1. Please select a color (R/B): ");
		cin >> p1; 

		if(p1 == (char)'R' || p1 == (char)'B'){
			namePass = true;
		}
		else{
			printf("%s\n", "Please enter 'R' or 'B' only.");
		}
	}
	
	(p1 == 'B') ? p2 = 'R' : p2 = 'B';
	printf("%s%c\n", "Welcome, Player 2. Your color is: ", p2);

	player1 = new Player(p1);
	player2 = new Player(p2);
	game = new Board(*player1, *player2);

	turn = player1;

	while(!(*game).getState()){
		int move;
		bool moveMade = false;

		printf("\n%s\n", "+------------------------------------------------+");
		(*game).printBoard();
		printf("\n%s\n", "+------------------------------------------------+");

		printf("MESSAGE: Color %c's turn. Please select a column (1-7) to insert your chip into: ", (*turn).getColor());
		cin >> move; 

		//asserts 1-7
		if(move < 1 || move > 7){
			printf("%s\n", "MESSAGE: Invalid column. Select a number from 0 to 6 only.");
			continue;
		}

		moveMade = (*game).addPiece(*turn, move - 1);

		if(moveMade && (turn == player1)){
			//printf("%s\n", "Piece added!");
			turn = player2;
		} else if(moveMade && (turn == player2)){
			//printf("%s\n", "Piece added!");
			turn = player1;
		} else{
			printf("%s\n", "MESSAGE: Cannot add a piece at that position. Please try again.");
		}
	}

	printf("\n%s\n", "+------------------------------------------------+");
	(*game).printBoard();
	printf("\n%s\n", "+------------------------------------------------+");

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