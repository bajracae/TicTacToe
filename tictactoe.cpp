#include <iostream>
#include "tictactoe.h"
#include "helper_function.h"

using namespace std;

int main(){
	int rows = 3;
	int cols = 3;
	int counter = 0;
	char player;
	char ** board = create_board(rows,cols);
	populate_board(board, rows, cols);
	cout << endl;
	cout << "         [ TIC TAC TOE ]" << endl;
	cout << endl;
	while(game_win(board, rows, cols) == false){
		if(counter % 2 == 0){
			player = 'x';
			print_board(board, rows, cols);
			cout << endl;
			cout << "             X's turn" << endl;
			cout << endl;
			insert_piece(board, rows, cols, player);
			counter++;
		}
		else{
			player = 'o';
			print_board(board, rows, cols);
			cout << endl;
			cout << "             O's turn" << endl;
			cout << endl;
			insert_piece(board, rows, cols, player);
			counter++;
		}
		if(draw_game(board, rows, cols) == true){
			print_board(board, rows, cols);
			cout << " THE GAME ENDED IN A TIE!" << endl;
			break;
		}
	}
	if(game_win(board, rows, cols) == true){
		print_board(board, rows, cols);
		cout << " GAME OVER!" << endl;
	}
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
	cout << "         ";
	for(int i = 0; i < rows; i++){
		cout << " --- ";
	}
	cout << endl;
	for(int i = 0; i < rows; i++){
		cout << "         ";
		for(int j = 0; j < cols; j++){			
			cout << "| " << board[i][j] << " |";
		}
		cout << endl;
		cout << "         ";
		for(int i = 0; i < rows; i++){
			cout << " --- ";
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

bool valid_r(int rows, string user_row){
	int r_int = get_int(user_row);
	if(r_int < 0 || r_int > rows){
		return false;
	}
	return true;
}

bool valid_c(int cols, string user_col){
	int c_int = get_int(user_col);
	if(c_int < 0 && c_int > cols){
		return false;
	}
	return true;
}

int get_r_input(int rows){
	string user_row = "";
	do{
		cout << "    Row: ";
		getline(cin, user_row);
	} while(user_row == "" || is_int(user_row) == false || valid_r(rows, user_row) == false);
	int r_int = get_int(user_row);
	return r_int;
}

int get_c_input(int cols){
	string user_col = "";
	do{
		cout << "    Column: ";
		getline(cin, user_col);
	} while(user_col == "" || is_int(user_col) == false || valid_r(cols, user_col) == false);
	int c_int = get_int(user_col);
	return c_int;
}

bool check_empty(char ** board, int r_int, int c_int, char player){
	if(board[r_int-1][c_int-1] == ' '){
		return true;
	}
	cout << " Spot is taken!" << endl;
	return false;
}

void insert_piece(char ** board, int rows, int cols, char player){
	int r_int, c_int;
	cout << " Where do you want to put your player: " << endl;
	do{
		r_int = get_r_input(rows);
		c_int = get_c_input(cols);
	} while(!check_empty(board, r_int, c_int, player));
	board[r_int-1][c_int-1] = player;
}

bool check_rows(char ** board, int rows, int cols){
	int check_x = 0, check_o = 0;
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			if(board[i][j] == 'x'){
				check_x++;
			}
			if(board[i][j] == 'o'){
				check_o++;
			}
		}
		if(check_x == rows){
			return true;
		}
		if(check_o == rows){
			return true;
		}
		else{
			check_x = 0;
			check_o = 0;
		}
	}
	return false;
}

bool check_cols(char ** board, int rows, int cols){
	int check_x = 0, check_o = 0;
	for(int i = 0; i < cols; i++){
		for(int j = 0; j < rows; j++){
			if(board[j][i] == 'x'){
				check_x++;
			}
			if(board[j][i] == 'o'){
				check_o++;
			}
		}
		if(check_x == rows){
			return true;
		}
		else if(check_o == rows){
			return true;
		}
		else{
			check_x = 0;
			check_o = 0;
		}
	}
	return false;
}

bool check_diagonal(char ** board, int rows, int cols){
	int check_x = 0, check_o = 0;
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			if(i == j){
				if(board[i][j] == 'x'){
					check_x++;
				}
				if(board[i][j] == 'o' ){
					check_o++;
				}
			}
		}
	}
	if(check_x == rows){
		return true;
	}
	if(check_o == rows){
		return true;
	}
	return false;
}

bool check_antidiagonal(char ** board, int rows, int cols){
	int check_x = 0, check_o = 0;
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			if((i + j) == (cols - 1)){
				if(board[i][j] == 'x'){
					check_x++;
				}
				if(board[i][j] == 'o'){
					check_o++;
				}
			}
		}
	}
	if(check_x == rows){
		return true;
	}
	if(check_o == rows){
		return true;
	}
	return false;
}

bool game_win(char ** board, int rows, int cols){
	if(check_rows(board, rows, cols) == true){
		return true;
	}
	else if(check_cols(board, rows, cols) == true){
		return true;
	}
	else if(check_diagonal(board, rows, cols) == true){
		return true;
	}
	else if(check_antidiagonal(board, rows, cols) == true){
		return true;
	}
	else{
		return false;
	}
}

bool draw_game(char ** board, int rows, int cols){
	int counter = 0;
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			if(board[i][j] == ' '){
				counter++;
			}
		}
	}
	if(counter > 0){
		return false;
	}
	return true;
}