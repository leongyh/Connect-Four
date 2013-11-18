#include "Board.h"

#include <stdio.h>
#include <stdlib.h>

#include <vector>

Board::Board(Player &p1, Player &p2){
	board = (Chip*) malloc(sizeof(Chip)*row_size*col_size);

	for(int i = 0; i < col_size; i++){
		for (int j = 0; j < row_size; j++){
			Chip *c = new Chip((Player*) NULL, i, j);
			board[j + i*row_size] = *c;
		}
	}

	state = 0;
	player1 = &p1;
	player2 = &p2;
}

Board::~Board(){
	delete [] board;
}

bool Board::addPiece(Player &p, int pos){
	bool added = false;
	int i = 0;
	Chip *c;

	//printf("%s%c\n", "Adding a piece of player: ", p.getColor());

	while(i < col_size && !added){
		//printf("Col checking iteration: %d\n", i);
		if((board[pos + i*row_size]).isEmpty() && !added){
			//Chip *temp = &board[pos + i*row_size];
			c = new Chip(&p, pos, i);

			board[pos + i*row_size] = *c;
			added = true;

			//delete &temp;

			//printf("Added chip of player %c's to position (%d, %d).\n", p.getColor(), (*c).getCol(), (*c).getRow());
		}

		i++;
	}

	//check if invalid move and if it is a draw
	if(!added){
		//printf("%s\n", "Checking if draw or invalid move.");

		if(checkDraw())	state = 3;

		return	 false;
	}

	//printf("%s\n", "Checking if win.");

	if(checkWin(*c)){
		Player* p = (*c).getOwner();

		if(p == player1) state = 1;
		else if(p == player2) state = 2;
		else{
			//printf("%s\n", "Unknown player added a chip.");
			//exit(0);
		}
	}

	return true;
}

int Board::getState(){
	return state;
}

bool Board::checkDraw(){
	for(int i = 0; i < col_size; i++)
		for (int j = 0; j < row_size; j++)
		{
			if((board[j + i*row_size]).isEmpty()) return false;
		}

	return true;
}

bool Board::checkWin(Chip &c){
	Player* p = c.getOwner();
	int col = c.getCol();
	int row = c.getRow();

	std::vector<Chip*> straight;
	int count = 0;

	//check horizontal
	for(int i = col - 3; i <= col + 3; i++){
		if(i >= 0 && i <= col_size){
			straight.push_back(&board[i + row*row_size]);
		}
	}

	for(int i = 0; i < straight.size(); i++){
		if((*(straight.at(i))).getOwner() == p){
			count++;
		} else{
			count = 0;
		}

		if(count == 4){
			return true;
		}
	}

	//check vertical
	count = 0;
	for(int i = row - 3; i <= row + 3; i++){
		if(i >= 0 && i <= row_size){
			straight.push_back(&board[col + i*row_size]);
		}
	}

	for(int i = 0; i < straight.size(); i++){
		if((*(straight.at(i))).getOwner() == p){
			count++;
		} else{
			count = 0;
		}

		if(count == 4){
			return true;
		}
	}

	//check diagonal increasing
	count = 0;
	for(int i = col - 3, j = row - 3; i <= col + 3 || j <= row + 3; i++, j++){
		if((i >= 0 && i <= col_size) && (j >= 0 && j <= row_size)){
			straight.push_back(&board[i + j*row_size]);
		}
	}

	for(int i = 0; i < straight.size(); i++){
		if((*(straight.at(i))).getOwner() == p){
			count++;
		} else{
			count = 0;
		}

		if(count == 4){
			return true;
		}
	}

	//check diagonal decreasing
	count = 0;
	for(int i = col - 3, j = row + 3; i <= col + 3 || j >= row - 3; i++, j--){
		if((i >= 0 && i <= col_size) && (j >= 0 && j <= row_size)){
			straight.push_back(&board[i + j*row_size]);
		}
	}

	for(int i = 0; i < straight.size(); i++){
		if((*(straight.at(i))).getOwner() == p){
			count++;
		} else{
			count = 0;
		}

		if(count == 4){
			return true;
		}
	}

	return false;
}

void Board::printBoard(){
	//draw position markers
	printf("\n%s\n", "+--Select a position to insert chip below-+");
	printf("%s\n\n", "+--1--+--2--+--3--+--4--+--5--+--6--+--7--+");

	//draw board
	printf("%s\n", "+-----+-----+-----+-----+-----+-----+-----+");
	for (int i = col_size - 1; i >=0; i--){
		for (int j = 0; j < row_size; j++){

			if(!(board[j + i*row_size]).isEmpty()){
				printf("|  %c  ", (*board[j + i*row_size].getOwner()).getColor());
			} else{
				printf("%s", "|     ");
			}
			
		}
		printf("|\n%s\n", "+-----+-----+-----+-----+-----+-----+-----+");
	}

	return;
}