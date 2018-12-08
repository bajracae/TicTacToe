#include <iostream>
#include "tictactoe.h"

using namespace std;

int main(){
	int rows = 3;
	int cols = 3;
	char piece = 'x';
	char ** board = create_board(rows,cols);
	populate_board(board, rows, cols);
	print_board(board, rows, cols);
	insert_piece(board, piece);
	print_board(board, rows, cols);
	delete_board(board, rows, cols);
}

char ** create_board(int rows, int cols){
	char ** board;
	board = new char * [rows];
	for(int i = 0; i < rows; i++){
		board[i] = new char [cols];
	}
	return board;
}

void populate_board(char ** board, int rows, int cols){
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			board[i][j] = ' ';
		}
	}
}

void print_board(char ** board, int rows, int cols){
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){			
			cout << "| " << board[i][j] << " |";
		}
		cout << endl;
	}
}

void delete_board(char ** board, int rows, int cols){
	for(int i = 0; i < rows; i++){
		delete [] board[i];	
	}
	delete [] board;
}

bool 

void insert_piece(char ** board, int rows, int cols, char piece){
	int r, c;
	cout << "Where do you want to put your piece: " << endl;
	cin >> r;
	cin >> c;
	if((r > 0 && r < rows) && (c > 0 && c < cols)){
		board[r-1][c-1] = piece;
	}
	else{
		cout << "error" << endl;
	}
}