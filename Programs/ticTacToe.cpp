#include <iostream>
using namespace std;

// Constants for the rows and columns
const int ROWS = 5;
const int COLS = 5;

// Function prototypes
void displayBoard(char[][COLS]);
void playerTurn(char[][COLS], char);
bool gameOver(char[][COLS]);
bool playerWins(char[][COLS], char);
bool playerCanWin(char[][COLS], char);
void displayWinner(char[][COLS]);

int main()
{

	// Welcome
	cout << "T I C - T A C - T O E\n\n";

	// Array for the game board.
	char gameBoard[ROWS][COLS] = {
		'*', '*', '*', '*', '*',
		'*', '*', '*', '*', '*',
		'*', '*', '*', '*', '*',
		'*', '*', '*', '*', '*',
		'*', '*', '*', '*', '*'

	};
	do {

		// Display the game board.
		displayBoard(gameBoard);

		// Let player 1 have a turn.
		playerTurn(gameBoard, 'X');

		// Let player 2 have a turn
		cout << endl;
		displayBoard(gameBoard);

		if (!gameOver(gameBoard)) {
			playerTurn(gameBoard, 'O');
		}

		// Let player 3 have a turn
		cout << endl;
		displayBoard(gameBoard);

		if (!gameOver(gameBoard)) {
			playerTurn(gameBoard, 'Z');
		}

	} while (!gameOver(gameBoard));

	//display board one more time
	displayBoard(gameBoard);

	//display winner
	displayWinner(gameBoard);

	system("pause");
	return 0;
}

void displayBoard(char board[][COLS])
{
	// Display the column headings.
	cout << "-------------------------\n\n";
	cout << "        Columns\n";
	cout << "        1 2 3 4 5\n";

	// Display the rows.
	for (int row = 0; row < ROWS; row++)
	{
		// Row label.
		cout << "Row " << (row + 1) << ":  ";

		// Row contents.
		for (int col = 0; col < COLS; col++)
		{
			cout << board[row][col] << " ";
		}
		cout << endl;
	}

	cout << "\n-------------------------\n";
}

void playerTurn(char board[][COLS], char symbol)
{
	int ROW;
	int COL;
	int ROW2;
	int COL2;
	int player = 0;

	if (symbol == 'X') {
		player = 1;
	}
	else if (symbol == 'O') {
		player = 2;
	}
	else if (symbol == 'Z') {
		player = 3;
	}

	cout << endl << "It's Player " << player << "'s turn:" << endl;
	do {
		cout << "  Row: ";
		cin >> ROW;
		cout << "  Collumn: ";
		cin >> COL;

		ROW2 = (ROW - 1);
		COL2 = (COL - 1);
	} 
	while (board[ROW2][COL2] != '*');

	board[ROW2][COL2] = symbol;
}

bool playerWins(char board[][COLS], char symbol) {
	//who is the player?
	int player = 0;
	if (symbol == 'X') {
		player = 1;
	}
	else if (symbol == 'O') {
		player = 2;
	}
	else if (symbol == 'Z') {
		player = 3;
	}

	//whoop-dee-doo

	//10 horizontal different ways
	if (board[0][0] == symbol && board[0][1] == symbol && board[0][2] == symbol && board[0][3] == symbol) {
		return true;
	}
	if (board[0][1] == symbol && board[0][2] == symbol && board[0][3] == symbol && board[0][4] == symbol) {
		return true;
	}
	if (board[1][0] == symbol && board[1][1] == symbol && board[1][2] == symbol && board[1][3] == symbol) {
		return true;
	}
	if (board[1][1] == symbol && board[1][2] == symbol && board[1][3] == symbol && board[1][4] == symbol) {
		return true;
	}
	if (board[2][0] == symbol && board[2][1] == symbol && board[2][2] == symbol && board[2][3] == symbol) {
		return true;
	}
	if (board[2][1] == symbol && board[2][2] == symbol && board[2][3] == symbol && board[2][4] == symbol) {
		return true;
	}
	if (board[3][0] == symbol && board[3][1] == symbol && board[3][2] == symbol && board[3][3] == symbol) {
		return true;
	}
	if (board[3][1] == symbol && board[3][2] == symbol && board[3][3] == symbol && board[3][4] == symbol) {
		return true;
	}
	if (board[4][0] == symbol && board[4][1] == symbol && board[4][2] == symbol && board[4][3] == symbol) {
		return true;
	}
	if (board[4][1] == symbol && board[4][2] == symbol && board[4][3] == symbol && board[4][4] == symbol) {
		return true;
	}
	//10 vertical different ways
	if (board[0][0] == symbol && board[1][0] == symbol && board[2][0] == symbol && board[3][0] == symbol) {
		return true;
	}
	if (board[1][0] == symbol && board[2][0] == symbol && board[3][0] == symbol && board[4][0] == symbol) {
		return true;
	}
	if (board[0][1] == symbol && board[1][1] == symbol && board[2][1] == symbol && board[3][1] == symbol) {
		return true;
	}
	if (board[1][1] == symbol && board[2][1] == symbol && board[3][1] == symbol && board[4][1] == symbol) {
		return true;
	}
	if (board[0][2] == symbol && board[1][2] == symbol && board[2][2] == symbol && board[3][2] == symbol) {
		return true;
	}
	if (board[1][2] == symbol && board[2][2] == symbol && board[3][2] == symbol && board[4][2] == symbol) {
		return true;
	}
	if (board[0][3] == symbol && board[1][3] == symbol && board[2][3] == symbol && board[3][3] == symbol) {
		return true;
	}
	if (board[1][3] == symbol && board[2][3] == symbol && board[3][3] == symbol && board[4][3] == symbol) {
		return true;
	}
	if (board[0][4] == symbol && board[1][4] == symbol && board[2][4] == symbol && board[3][4] == symbol) {
		return true;
	}
	if (board[1][4] == symbol && board[2][4] == symbol && board[3][4] == symbol && board[4][4] == symbol) {
		return true;
	}
	//8 horizontal different ways
	if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol && board[3][3] == symbol) {
		return true;
	}
	if (board[1][1] == symbol && board[2][2] == symbol && board[3][3] == symbol && board[4][4] == symbol) {
		return true;
	}
	if (board[1][0] == symbol && board[2][1] == symbol && board[3][2] == symbol && board[4][3] == symbol) {
		return true;
	}
	if (board[0][1] == symbol && board[1][2] == symbol && board[2][3] == symbol && board[3][4] == symbol) {
		return true;
	}
	if (board[0][4] == symbol && board[1][3] == symbol && board[2][2] == symbol && board[3][1] == symbol) {
		return true;
	}
	if (board[1][3] == symbol && board[2][2] == symbol && board[3][1] == symbol && board[4][0] == symbol) {
		return true;
	}
	if (board[1][4] == symbol && board[2][3] == symbol && board[3][2] == symbol && board[4][1] == symbol) {
		return true;
	}
	if (board[0][3] == symbol && board[1][2] == symbol && board[2][1] == symbol && board[3][0] == symbol) {
		return true;
	}
	return false;
}

bool playerCanWin(char board[][COLS], char symbol) {
	//who is the player?
	int player = 0;
	if (symbol == 'X') {
		player = 1;
	}
	else if (symbol == 'O') {
		player = 2;
	}
	else if (symbol == 'Z') {
		player = 3;
	}

	//counter thingy
	int count = 0;

	//wins horrizontaly
	for (int r = 0; r < 5; r++) {
		for (int c = 0; c < 2; c++) {
			if ((board[r][c] == symbol || board[r][c] == '*') && (board[r][c + 1] == symbol || board[r][c + 1] == '*') && (board[r][c + 2] == symbol || board[r][c + 2] == '*') && (board[r][c + 3] == symbol || board[r][c + 3] == '*')) {
				count++;
			}
		}
	}

	//wins verticaly
	for (int c = 0; c < 5; c++) {
		for (int r = 0; r < 2; r++) {
			if ((board[r][c] == symbol || board[r][c] == '*') && (board[r + 1][c] == symbol || board[r + 1][c] == '*') && (board[r + 2][c] == symbol || board[r + 2][c] == '*') && (board[r + 3][c] == symbol || board[r + 3][c] == '*')) {
				count++;
			}
		}
	}

	//wins diagonaly
	if ((board[0][0] == symbol || board[0][0] == '*') && (board[1][1] == symbol || board[1][1] == '*') && (board[2][2] == symbol || board[2][2] == '*') && (board[3][3] == symbol || board[3][3] == '*')) {
		count++;
	}
	if ((board[1][1] == symbol || board[1][1] == '*') && (board[2][2] == symbol || board[2][2] == '*') && (board[3][3] == symbol || board[3][3] == '*') && (board[4][4] == symbol || board[4][4] == '*')) {
		count++;
	}
	if ((board[1][0] == symbol || board[1][0] == '*') && (board[2][1] == symbol || board[2][1] == '*') && (board[3][2] == symbol || board[3][2] == '*') && (board[4][3] == symbol || board[4][3] == '*')) {
		count++;
	}
	if ((board[0][1] == symbol || board[0][1] == '*') && (board[1][2] == symbol || board[1][2] == '*') && (board[2][3] == symbol || board[2][3] == '*') && (board[3][4] == symbol || board[3][4] == '*')) {
		count++;
	}
	if ((board[0][4] == symbol || board[0][4] == '*') && (board[1][3] == symbol || board[1][3] == '*') && (board[2][2] == symbol || board[2][2] == '*') && (board[3][1] == symbol || board[3][1] == '*')) {
		count++;
	}
	if ((board[1][3] == symbol || board[1][3] == '*') && (board[2][2] == symbol || board[2][2] == '*') && (board[3][1] == symbol || board[3][1] == '*') && (board[4][0] == symbol || board[4][0] == '*')) {
		count++;
	}
	if ((board[1][4] == symbol || board[1][4] == '*') && (board[2][3] == symbol || board[2][3] == '*') && (board[3][2] == symbol || board[3][2] == '*') && (board[4][1] == symbol || board[4][1] == '*')) {
		count++;
	}
	if ((board[0][3] == symbol || board[0][3] == '*') && (board[1][2] == symbol || board[1][2] == '*') && (board[2][1] == symbol || board[2][1] == '*') && (board[3][0] == symbol || board[3][0] == '*')) {
		count++;
	}

	//return if player can win game
	if (count > 0) {
		return true;
	}
	else {
		return false;
	}
}

bool gameOver(char board[][COLS]) {
	if ((playerWins(board, 'X') == true)) {
		return true;
	}
	else if ((playerWins(board, 'O') == true)) {
		return true;
	}
	else if ((playerWins(board, 'Z') == true)) {
		return true;
	}
	else if (playerCanWin(board, 'X') != true) {
		return true;
	}
	else if (playerCanWin(board, 'O') != true) {
		return true;
	}
	else if (playerCanWin(board, 'Z') != true) {
		return true;
	}
	else {
		return false;
	}
	return false;
}

void displayWinner(char board[][COLS]) {
	if (playerWins(board, 'X') == true) {
		cout << "\nPlayer 1 (\'X\') is the winner!!!";
	}
	if (playerWins(board, 'O') == true) {
		cout << "\nPlayer 2 (\'O\') is the winner!!!";
	}
	if (playerWins(board, 'Z') == true) {
		cout << "\nPlayer 3 (\'Z\') is the winner!!!";
	}
}