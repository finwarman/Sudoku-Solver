#ifndef SUDOKU_H
#define SUDOKU_H

void load_board(const char *filename, char board[9][9]);
	/* Reads in characters from the file with name
	'filename' into the two-dimensional character
	array 'board'*/

void display_board(const char board[9][9]);
	/* Displays the 2D character array board in a
	friendly layout familiar to Sudoku players.
	Row indices (in the form of letters 'A' to 'I')
	and column indices (in the form of digits '1'
	to '9') are included in the output to help with
	the identification of particular board positions.*/

bool is_complete(char board[][9]);
	/* Returns true if the 9x9 charcter array 'board'
	(sudoku board) is complete. */
	
bool make_move(char position[2], char digit, char board[][9]);
	/* attempts to place a 'digit' (1 through 9) onto a 9x9
	Sudoku board called 'board' at a given 'position' (i.e. A1) */
	
bool save_board(const char *filename, char board[][9]);
	/* outputs the two-dimensional character array 'board'
	to a file with name 'filename'.  Returns true if the
	file was successfully written, false otherwise */
	
bool solve_board(char board[][9]);
	/* attempts to solve the Sudoku puzzle in input/output
	parameter 'board'. Returns true if a solution is found
	and 'board' should contain the solution. If a solution
	does not exist, return false and 'board' should contain
	the original board */
	
bool exists_in_box(char digit, int spot_row, int spot_col, char board[][9]);
	/* returns true if the 'digit' already exists in the 3x3 box that the
	spot is in on the Sudoku board, 'board'.  Otherwise, it returns false */
	
bool digit_fits_in_col(char digit, int spot_row, int spot_col, char board[][9]);
	/* returns true if the 'digit' fits in any other positions within
	spot's column on 'board'.  Otherwise, it returns false */

bool digit_fits_in_row(char digit, int spot_row, int spot_col, char board[][9]);
	/* returns true if the 'digit' fits in any other positions within
	spot's row on 'board'.  Otherwise, it returns false */

bool digit_fits_in_box(char digit, int spot_row, int spot_col, char board[][9]);
	/* returns true if the 'digit' fits in any other positions within
	spot's 3x3 box on 'board'.  Otherwise, it returns false */

void attempt_solve(char board[][9], int count);
	/* attempts to solve the board using very simple logic.  Fills
	the board in with as many as it can do and outputs the number
	of boxes it was able to fill in to the console. The function
	should be called with int count = 0 */

bool possible(char position[2], char digit, char board[][9]);
	/* similar to make move but returns true if 'digit' could possibly
	go in 'position' on 'board' but does not actually place the value
	in that position */

#endif