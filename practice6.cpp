/*********************************************************
Make a two player tic tac toe game.

Modify the program so that it will announce when a player has won the game (and which player won, x or o)

Modify the program so that it is a one player game against the computer (with the computer making its moves randomly)

Modify the program so that anytime the player is about to win (aka, they have 2 of 3 x's in a row, 
the computer will block w/ an o)
********************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Game
{
private:
	char board[3][3];
	int player;


public:
	Game();
	void playersPlay(int, int);
	void turn(int);
	void updateBoard();
	bool validateInput(int, int);
	bool endGame();
	bool computerCheat(int&, int&);
};

// Default Constructor, it will initialize a basic tic tac toe board
Game::Game()
{
	player = 0;

	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			board[row][col] = '*';
		}
		cout << endl;
	}
}
// Update function, will be used to display the most current board each is called
void Game::updateBoard()
{
	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			cout << board[row][col] << " ";
		}
		cout << endl;
	}
}

// Validate input method, this will make sure they cannot make a play on a spot that is already taken
// If spot is taken return true
bool Game::validateInput(int x, int y)
{
	if (board[x][y] == 'X' || board[x][y] == 'O')
	{
		return true;
	}
	else
	{
		return false;
	}
}

// Player turn function
void Game::turn(int x)
{
	player = x;
}

// Function for simulating a player making a play
void Game::playersPlay(int x, int y)
{
	if (player == 1)
	{	
		board[x][y] = 'X';
	}
	else if (player == 2)
	{
		board[x][y] = 'O';
	}
}

// Will end the game if there are 3 similar matches in a row, column, or diagonal line
bool Game::endGame()
{
	char spot1, spot2, spot3;

	// Checking the rows
	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 1; col++)
		{
			spot1 = board[row][col];
			spot2 = board[row][col + 1];
			spot3 = board[row][col + 2];

			if (spot1 == spot2 && spot1 == spot3)
			{
				if (spot1 == 'X')
				{
					cout << "Player 1 wins" << endl;
					return 1;
				}
				else if (spot1 == 'O')
				{
					cout << "Player 2 wins" << endl;
					return 1;
				}
			}
		}	
	}

	// Checking the columns
	for (int col = 0; col < 3; col++)
	{
		for (int row = 0; row < 1; row++)
		{
			spot1 = board[row][col];
			spot2 = board[row+1][col];
			spot3 = board[row+2][col];

			if (spot1 == spot2 && spot1 == spot3)
			{
				if (spot1 == 'X')
				{
					cout << "Player 1 wins" << endl;
					return 1;
				}
				else if (spot1 == 'O')
				{
					cout << "Player 2 wins" << endl;
					return 1;
				}
			}
		}
	}

	// Checking Diagonal
	for (int x = 0; x < 1;x++)
	{
		for (int y = 0; y < 1; y++)
		{
			spot1 = board[x][y];
			spot2 = board[x + 1][y + 1];
			spot3 = board[x + 2][y + 2];

			if (spot1 == spot2 && spot1 == spot3)
			{
				if (spot1 == 'X')
				{
					cout << "Player 1 wins" << endl;
					return 1;
				}
				else if (spot1 == 'O')
				{
					cout << "Player 2 wins" << endl;
					return 1;
				}
			}
		}

		for (int z = 2; z < 3; z++)
		{
			spot1 = board[x][z];
			spot2 = board[x + 1][z - 1];
			spot3 = board[x + 2][z - 2];

			if (spot1 == spot2 && spot1 == spot3)
			{
				if (spot1 == 'X')
				{
					cout << "Player 1 wins" << endl;
					return 1;
				}
				else if (spot1 == 'O')
				{
					cout << "Player 2 wins" << endl;
					return 1;
				}
			}
		}
	}
	
	// End if all the spots have been taken
	bool open=false;
	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			if (board[row][col] == '*')
			{
				open = true;
			}
		}
	}
	if (!open)
	{
		cout << "Game ends in a tie" << endl;
		return 1;
	}
	else
	{
		return 0;
	}
}


// Computer cheat function, will do its best to make sure player 1 does not win
// It will still need to follow the rules
/*********************************
Assume player 1 has these spots (player 1 = X), and now the computer needs to make a choice

	X * *			X * X
	* X *	---->	O X *
	X O O			X O O

In this scenario, the computer will stop the column from matching, but player 1 would win with the diagonal match
Overall this method will help the computer make better choices, but if you get out-played, then get good :)
**********************************/
bool Game::computerCheat(int& computerRow, int& computerCol)
{
	int spot1, spot2, spot3;

	// This is somewhat similar to the end game loops
	// This time we just check the placement of player 1
	// Checking the rows
	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 1; col++)
		{
			spot1 = board[row][col];
			spot2 = board[row][col + 1];
			spot3 = board[row][col + 2];

			if ((spot1 == 'X' && spot2 == 'X') || (spot2 == 'X' && spot3 == 'X') || (spot1 == 'X' && spot3 == 'X'))
			{
				if (spot1 == '*')
				{
					computerRow = row;
					computerCol = col;
					return 1;
				}
				else if (spot2 == '*')
				{
					computerRow = row;
					computerCol = col+1;
					return 1;
				}
				else if (spot3 == '*')
				{
					computerRow = row;
					computerCol = col+2;
					return 1;
				}
			}
		}
	}

	// Checking the columns
	for (int col = 0; col < 3; col++)
	{
		for (int row = 0; row < 1; row++)
		{
			spot1 = board[row][col];
			spot2 = board[row + 1][col];
			spot3 = board[row + 2][col];

			if ((spot1 == 'X' && spot2 == 'X') || (spot2 == 'X' && spot3 == 'X') || (spot1 == 'X' && spot3 == 'X'))
			{
				if (spot1 == '*')
				{
					computerRow = row;
					computerCol = col;
					return 1;
				}
				else if (spot2 == '*')
				{
					computerRow = row+1;
					computerCol = col;
					return 1;
				}
				else if (spot3 == '*')
				{
					computerRow = row+2;
					computerCol = col;
					return 1;
				}
			}
		}
	}

	// Checking Diagonal
	for (int x = 0; x < 1; x++)
	{
		for (int y = 0; y < 1; y++)
		{
			spot1 = board[x][y];
			spot2 = board[x + 1][y + 1];
			spot3 = board[x + 2][y + 2];

			if ((spot1 == 'X' && spot2 == 'X') || (spot2 == 'X' && spot3 == 'X') || (spot1 == 'X' && spot3 == 'X'))
			{
				if (spot1 == '*')
				{
					computerRow = x;
					computerCol = y;
					return 1;
				}
				else if (spot2 == '*')
				{
					computerRow = x+1;
					computerCol = y+ 1;
					return 1;
				}
				else if (spot3 == '*')
				{
					computerRow = x+2;
					computerCol = y+2;
					return 1;
				}
			}
		}

		for (int z = 2; z < 3; z++)
		{
			spot1 = board[x][z];
			spot2 = board[x + 1][z - 1];
			spot3 = board[x + 2][z - 2];

			if ((spot1 == 'X' && spot2 == 'X') || (spot2 == 'X' && spot3 == 'X') || (spot1 == 'X' && spot3 == 'X'))
			{
				if (spot1 == '*')
				{
					computerRow = x;
					computerCol = z;
					return 1;
				}
				else if (spot2 == '*')
				{
					computerRow = x+1;
					computerCol = z-1;
					return 1;
				}
				else if (spot3 == '*')
				{
					computerRow = x+2;
					computerCol = z- 2;
					return 1;
				}
			}
		}
	}

	return 0;
}

// Input spot function
// Allows the player to make their play
// Validates that input is in range
void inputSpot(int& x, int& y)
{
	cout << "What row: ";
	cin >> x;
	while (x > 3)
	{
		cout << "Please young jedi enter in a range of 0-2: ";
		cin >> x;
	}
	cout << "What column: ";
	cin >> y;
	while (y > 3)
	{
		cout << "Please young jedi enter in a range of 0-2: ";
		cin >> y;
	}
}

int main()
{
	srand(time(0));
	int choice, turn = 1;
	int row, col;
	cout << "Tic Tac Toe Game" << endl;
	cout << "1. Play with two players" << endl;
	cout << "2. Play with computer" << endl;
	cin >> choice;

	Game tic;
	switch (choice)
	{
		case 1:
		{
			do
			{
				if (turn == 2)
				{
					turn = 1;
				}

				tic.turn(turn);
				cout << "Player 1 is your turn" << endl;
				inputSpot(row, col);
				while (tic.validateInput(row, col))
				{
					cout << "Spot was taken already please choose a different spot" << endl;
					inputSpot(row, col);
				}
				tic.playersPlay(row, col);
				tic.updateBoard();

				if (!tic.endGame())
				{	
					turn = 2;
					tic.turn(turn);
					cout << "Player 2 is your turn" << endl;
					inputSpot(row, col);
					while (tic.validateInput(row, col))
					{
						cout << "Spot was taken already please choose a different spot" << endl;
						inputSpot(row, col);
					}
					tic.playersPlay(row, col);
					tic.updateBoard();
				}
				cout << endl;
			} while (!tic.endGame());
			break;
		}

		case 2:
		{
			do
			{
				if (turn == 2)
				{
					turn = 1;
				}

				tic.turn(turn);
				cout << "Player 1 is your turn" << endl;
				inputSpot(row, col);
				while (tic.validateInput(row, col))
				{
					cout << "Spot was taken already please choose a different spot" << endl;
					inputSpot(row, col);
				}
				tic.playersPlay(row, col);
				tic.updateBoard();

				if (!tic.endGame())
				{
					turn = 2;
					tic.turn(turn);
					cout << "Computer is your turn" << endl;
					row = rand() % 3;
					col = rand() % 3;
					while (tic.validateInput(row, col))
					{
						cout << "Spot was taken already please choose a different spot" << endl;
						row = rand() % 3;
						col = rand() % 3;
					}
					if (tic.computerCheat(row, col)) // Computer power up
					{
						tic.playersPlay(row, col);
					}
					tic.playersPlay(row, col);
					tic.updateBoard();
				}
				cout << endl;
			} while (!tic.endGame());
			break;
		}

		default:
			cout << "Invalid input" << endl;
	}

	return 0;
}