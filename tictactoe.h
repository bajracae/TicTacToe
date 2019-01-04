#include <iostream>
#ifndef TICTACTOE_H					
#define TICTACTOE_H

using namespace std;

// Board functions
char ** create_board(int rows, int cols);
void populate_board(char ** board, int rows, int cols);
void print_board(char ** board, int rows, int cols);
void delete_board(char ** board, int rows, int cols);

// User functions
bool valid_r(int rows, string user_row);
bool valid_c(int cols, string user_col);
int get_r_input(int rows);
int get_c_input(int cols);
void insert_piece(char ** board, int rows, int cols, char player);

// End functions
bool check_rows(char ** board, int rows, int cols);
bool check_cols(char ** board, int rows, int cols);
bool check_diagonal(char ** board, int rows, int cols);
bool check_antidiagonal(char ** board, int rows, int cols);
bool game_win(char ** board, int rows, int cols);
bool draw_game(char ** board, int rows, int cols);

#endif