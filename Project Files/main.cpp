#include <iostream>
#include <cstdio>
#include <string>
#include "sudoku.h"

using namespace std;

int main() {

	char board[9][9];

	//cout << "Enter filename to load:\n";

	//string input;
	//getline(cin,input);

	//input += ".dat";

	//const char * inputchar = input.c_str();

	//load_board(inputchar, board);
	
	//cout << endl;

	load_board("easy.dat", board);

	if (save_board("easy-copy.dat", board))
		cout << "Save board to 'easy-copy.dat' successful."
		<< endl;
	else
		cout << "Save board failed." << endl;
	cout << endl;

	display_board(board);

	
	// Hold console open. (Program closes after runnning when using debugging mode.)
	cin.get();

	return 0;
}
