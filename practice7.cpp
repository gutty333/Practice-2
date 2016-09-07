/*********************************************************
Make a program that outputs a simple grid based gameboard to the screen using either numbers or characters.
i.e.

. . . . . . . . . .
. G . . . . . . . .
. . . . . . T . . .
. . . . . . . . . .
. . . . T . . . . .
. . . . . . T . . .
. . . . . . . . . X

or

0 0 0 0 0 0 0 0 0 0
0 5 0 0 6 0 0 0 0 0
0 0 0 0 0 0 7 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 7 0 0 0 0 0 0
0 0 0 0 0 0 7 0 0 0
0 0 0 0 0 0 0 0 0 4

Allow the user (marked by G in the example) to move either up, down, left, or right each turn. 
If the player steps on a trap then they lose. If they make it to the treasure 'X' then they win.

Add enemies that move randomly in any direction once per turn. (enemies just like traps cause the player to lose if touched)

HINT: Don't let the player move off the gameboard! Your program will crash if they move off the top or bottom of the board!
(the same holds true for enemies)
********************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>
using namespace std;

const int rowSize = 10;
const int colSize = 10;
class Game
{
	private:
		char board[rowSize][colSize];
		int playerRow, playerColumn;


	public:
		Game();
		void display();
		void movement(int);
		bool boundCheck(int, int);
		void simulateEnemy();
		void placeTraps();
		void placeEnemy();
		int endGame();

};

// Default Constructor
// As a basic program it will start the player at the top left;
// The end point will be at the bottom right
Game::Game()
{
	for (int row = 0; row < rowSize; row++)
	{
		for (int col = 0; col < colSize; col++)
		{
			board[row][col] = '-';
		}
	}

	playerRow = 0;
	playerColumn = 0;

	board[playerRow][playerColumn] = 'G';
	board[rowSize-1][colSize-1] = 'X';
}

// Display method, will showcase the board
void Game::display()
{
	for (int row = 0; row < rowSize; row++)
	{
		for (int col = 0; col < colSize; col++)
		{
			cout << board[row][col] << " ";
		}
		cout << endl;
	}
}


// Player movement method
// Will have a menu in which 1 = up, 2 = right, 3 = down, 4 = left
void Game::movement(int direction)
{
	if (direction == 1) // Move up from the current spot
	{
		board[playerRow][playerColumn] = '-';
		playerRow -= 1;
		if (!endGame())
		{
			if (boundCheck(playerRow, playerColumn))
			{
				playerRow += 1;
				cout << "Sorry but you cannot move out of bound" << endl;
			}
			board[playerRow][playerColumn] = 'G';
		}
	}
	else if (direction == 2) // Move right from the current spot
	{
		board[playerRow][playerColumn] = '-';
		playerColumn += 1;
		if (!endGame())
		{
			if (boundCheck(playerRow, playerColumn))
			{
				playerColumn -= 1;
				cout << "Sorry but you cannot move out of bound" << endl;
			}
			board[playerRow][playerColumn] = 'G';
		}
	}
	else if (direction == 3) // Move down from the current spot
	{
		board[playerRow][playerColumn] = '-';
		playerRow += 1;
		if (!endGame())
		{
			if (boundCheck(playerRow, playerColumn))
			{
				playerRow -= 1;
				cout << "Sorry but you cannot move out of bound" << endl;
			}
			board[playerRow][playerColumn] = 'G';
		}
	}
	else if (direction == 4) // Move left from the current spot
	{
		board[playerRow][playerColumn] = '-';
		playerColumn -= 1;
		if (!endGame())
		{
			if (boundCheck(playerRow, playerColumn))
			{
				playerColumn += 1;
				cout << "Sorry but you cannot move out of bound" << endl;
			}
			board[playerRow][playerColumn] = 'G';
		}
	}
}

// Bound checking, will make sure that the player does not go out of bound
// In this case to the board is 10x10
bool Game::boundCheck(int row, int col)
{
	if (row > rowSize-1 || row < 0)
	{
		return true;
	}
	else if (col > colSize-1 || col < 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// Will randomly place traps on the board
void Game::placeTraps()
{
	// As a start we can have 1-20 traps
	// If we further develop this program, depending on the difficulty the number of traps increase or decrease
	int trapTotal = rand() % (rowSize+colSize) + 1;
	int row, col;

	for (int x = 0; x < trapTotal; x++)
	{
		// Random spots
		row = rand()% rowSize;
		col = rand()% colSize;

		// Assure that they are not on the destination spot
		// Also that they are not in the player starting position
		while ((row == rowSize - 1 && col == colSize - 1) || (row == 0 && col == 0))
		{
			row = rand()% rowSize;
			col = rand()% colSize;
		}
		board[row][col] = 'T'; 
	}
}
// Place enemies function
void Game::placeEnemy()
{
	int enemyTotal = rand() % (rowSize + colSize) + 1;
	int row, col;

	for (int x = 0; x < enemyTotal; x++)
	{
		// Random spots
		row = rand()% rowSize;
		col = rand()% colSize;

		// Assure that they are not on the destination spot
		while ((row == rowSize - 1 && col == colSize - 1) || (row == 0 && col == 0))
		{
			row = rand()% rowSize;
			col = rand()% colSize;
		}
		board[row][col] = 'E';
	}
}
// Simulate enemy movement
void Game::simulateEnemy()
{
	int moveDirection;

	for (int row = 0; row < rowSize; row++)
	{
		for (int col = 0; col < colSize; col++)
		{
			// Number from 1-4, similar to the player this will represent the direction the enemy will move
			moveDirection = rand()% 4 + 1;

			if (board[row][col] == 'E')
			{
				if (moveDirection == 1) // Move up from the current spot
				{
					board[row][col] = '-';
					if (!endGame() && !boundCheck(row - 1, col))
					{
						board[row-1][col] = 'E';
					}
					else
					{
						board[row][col] = 'E';
					}
				}
				else if (moveDirection == 2) // Move right from the current spot
				{
					board[row][col] = '-';
					if (!endGame() && !boundCheck(row, col + 1))
					{
						board[row][col+1] = 'E';
					}
					else
					{
						board[row][col] = 'E';
					}
				}
				else if (moveDirection == 3) // Move down from the current spot
				{
					board[row][col] = '-';
					if (!endGame() && !boundCheck(row + 1, col))
					{
						board[row+1][col] = 'E';
					}
					else
					{
						board[row][col] = 'E';
					}
				}
				else if (moveDirection == 4) // Move left from the current spot
				{
					board[row][col] = '-';
					if (!endGame() && !boundCheck(row, col - 1))
					{
						board[row][col-1] = 'E';
					}
					else
					{
						board[row][col] = 'E';
					}
				}
			}
		}
	}
}

// End Game function
// If the player reaches the X, game ends
// If the player falls on a trap, game ends
int Game::endGame()
{
	// Check if the player is on a trap or enemy
	for (int row = 0; row < rowSize; row++)
	{
		for (int col = 0; col < colSize; col++)
		{
			if (board[row][col] == 'T' || board[row][col] == 'E')
			{
				if (playerRow == row && playerColumn == col)
				{
					return 1;
				}
			}
		}
	}

	// Check if the player reached the destination
	if (playerRow == rowSize-1 && playerColumn == colSize-1)
	{
		return 2;
	}
	else
	{
		return 0;
	}
}


int main()
{
	srand(time(0));
	int choice;
	char choice2;

	// This will allow the player to view the map certain amount of times
	// In other words they can check where the traps/enemy will be
	// This number can change if the programmed is develop based on difficulty level
	// int mapCount = 3;

	Game test;

	cout << "Welcome to the Dungeon" << endl;
	cout << "Here is the map" << endl;
	test.display();
	cout << endl << "Your goal is to get to the treasure (X location)" << endl;
	cout << "Sadly there will be traps along the way" << endl;
	cout << "Enemies have entered the dungeon also" << endl;
	test.placeEnemy(); // Adding Enemies
	test.placeTraps(); // Adding Traps

	do
	{
		cout << "Where would you like to move" << endl;
		cout << "\t1. UP" << endl;
		cout << "\t2. RIGHT" << endl;
		cout << "\t3. DOWN" << endl;
		cout << "\t4. LEFT" << endl;
		cin >> choice;

		test.movement(choice); // Player Moves
		test.simulateEnemy(); // Enemies Move
		test.display();
		/*if (!test.endGame())
		{
			if (mapCount)
			{
				cout << "Would you like to view the map (Y/N): ";
				cin >> choice2;
				if (toupper(choice2) == 'Y')
				{
					test.display();
					mapCount--;
				}
			}
		}*/
		cout << endl;
	} while (!test.endGame());

	if (test.endGame() == 1)
	{
		cout << "Game over, you have lost" << endl;
		cout << "You either landed on a trap or enemy spot" << endl;
	}
	else if (test.endGame() == 2)
	{
		cout << "Congratulations, you have won" << endl;
	}

	return 0;
}