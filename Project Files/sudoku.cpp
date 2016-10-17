#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cassert>
#include "sudoku.h"

using namespace std;

// Add your own functions here:

/*Task 1 - Write boolean function 'is_complete(board)'.*/
bool is_complete(char board[9][9])
{
	for (int y = 0; y < 9; y++) // Iterate through all rows.
		for (int x = 0; x < 9; x++)	// Iterate through all columns.
			if('1' > board[y][x] || board[y][x] > '9') // Check if char value of board is within char value of interval [1,9].
				return false;
	return true;
}

/*Task 2 - Write boolean function 'make_move(position, digit, board)'.*/
bool make_move(char position[2], char digit, char board[9][9])
{
	// A = 0 ... I = 9.
	// ASCII Table: 'A' = dec(65). '1' = dec(49)	
	int xPos = position[1] - 49;
	int yPos = position[0] - 65;

	if (1 > xPos || xPos > 9 || 1 > yPos || yPos > 9) // Check both co-ords are within interval [1,9].
		return false;
	if (49 > digit || digit > 57) // Check input digit character is within ASCII [1,9]
		return false;
	if (board[yPos][xPos] != '.') // Check that chosen input cell is empty, denoted by containing a dot ('.').
		return false;

	// Check that digit is not already in row or column:
	for (int i = 0; i < 9; i++)
		if (board[yPos][i] == digit || board[i][xPos] == digit) // Simultanously check all rows & columns on iterator "i".
			return false;

	// Check that digit is not already in box:
	int xOrigin = xPos - (xPos % 3); // Get nearest mutiple of 3 below current value of X (Left edge).
	int yOrigin = yPos - (yPos % 3); // Get nearest mutiple of 3 below current value of Y (Top edge).
	for (int y = 0; y < 3; y++)
		for (int x = 0; x < 3; x++)
			if (board[yOrigin + y][xOrigin + x] == digit)
				return false;

	// As function has not yet returned, digit position must be valid so set board position to digit:
	board[yPos][xPos] = digit;
	return true;
}

/*Task 3 - Write boolean function 'save_board(filename, board)*/
bool save_board(const char *filename, char board[9][9])
{
	ofstream outStr; // Create output stream for saving to file.
	outStr.open(filename); // Load file of given name, creates it if non-existent.
	for(int y = 0; y < 9; y++) // Iterate through every value in board.
	{
		for (int x = 0; x < 9; x++)
		{
			outStr.put(board[y][x]); // Push char at position to output file stream.
		}
	}
	outStr.close(); // Done with output stream, close it. (Automatically closes all open files)

	ifstream inStr; // Create input stream to for loading file.
	inStr.open(filename); // Attempt to open file.
	if (!(inStr.fail())) // Checks if stream failed in opening file.
		return true;
	else
		return false; 
}







/* You are pre-supplied with the functions below. Add your own
function definitions to the end of this file. */

/* pre-supplied function to load a Sudoku board from a file */
void load_board(const char *filename, char board[9][9])
{
	cout << "Loading Sudoku board from file '" << filename << "'... ";

	ifstream in(filename);
	if (!in)
		cout << "Failed!" << endl;
	assert(in);

	char buffer[512];

	int row = 0;
	in.getline(buffer, 512);
	while (in && row < 9)
	{
		for (int n = 0; n<9; n++)
		{
			assert(buffer[n] == '.' || isdigit(buffer[n]));
			board[row][n] = buffer[n];
		}
		row++;
		in.getline(buffer, 512);
	}

	cout << ((row == 9) ? "Success!" : "Failed!") << endl;
	assert(row == 9);
}

/* internal helper function */
void print_frame(int row)
{
	if (!(row % 3))
		cout << "  +===========+===========+===========+" << endl;
	else
		cout << "  +---+---+---+---+---+---+---+---+---+" << endl;
}

/* internal helper function */
void print_row(const char *data, int row)
{
	cout << (char)('A' + row) << " ";
	for (int i = 0; i<9; i++)
	{
		cout << ((i % 3) ? ':' : '|') << " ";
		cout << ((data[i] == '.') ? ' ' : data[i]) << " ";
	}
	cout << "|" << endl;
}

/* pre-supplied function to display a Sudoku board */
void display_board(const char board[9][9])
{
	cout << "    ";
	for (int r = 0; r<9; r++)
		cout << (char)('1' + r) << "   ";
	cout << endl;
	for (int r = 0; r<9; r++)
	{
		print_frame(r);
		print_row(board[r], r);
	}
	print_frame(9);
}