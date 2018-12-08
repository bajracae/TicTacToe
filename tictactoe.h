using namespace std;

char ** create_board(int length, int width);
void populate_board(char ** board, int length, int width);
void print_board(char ** board, int length, int width);
void delete_board(char ** board, int rows, int cols);
void insert_piece(char ** board, char piece);