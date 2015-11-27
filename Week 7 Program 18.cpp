/*********************************************************************
	Tic-Tac-Toe Game

	Write a modular program that allows two players to play a game of tic-tac-toe. Use a two- 
	dimensional  char array  with  3 rows  and  3 columns  as the game board. Each element  of the 
	array  should  be initialized  with an asterisk (*). The program should  display the initial board  
	configuration and then start a loop that does the following:

	• Allow player 1 to select a location on the board  for an X by entering a row and column number.  
	Then redisplay the board  with an X replacing the * in the chosen location.
	• If there  is no  winner  yet and  the  board  is not  yet full,  allow  player  2 to  select a 
	location   on  the  board   for  an  O  by  entering  a  row  and  column  number.   Then redisplay 
	the board  with an O replacing  the * in the chosen location.

	The  loop  should  continue  until  a player  has  won  or  a tie has  occurred,  then  display  a 
	message indicating  who won, or reporting that a tie occurred.

	• Player 1 wins when there are three Xs in a row, a column,  or a diagonal  on the game board.
	• Player 2 wins when there are three Os in a row, a column,  or a diagonal  on the game board.
	• A tie occurs when all of the locations  on the board  are full, but there is no winner.

	Input  Validation:  Only  allow legal moves  to be entered.  The row must  be 1, 2, or 3. The 
	column  must be 1, 2, or 3. The (row, column)  position  entered must currently  be
	empty  (i.e., still have an asterisk in it).
*********************************************************************/
#include <iostream>
#include <string>
#include <cctype>
using namespace std;



void initialBoard(char board[][3], int row)
{
	for (int x = 0; x < row; x++)
	{
		for (int col = 0; col < 3; col++)
		{
			board[x][col] = '*';
		}
	}

	for (int x = 0; x < row; x++)
	{
		for (int col = 0; col < 3; col++)
		{
			cout << board[x][col];
		}
		cout << endl;
	}
}
void updateBoard(char board[][3], int row)
{
	for (int x = 0; x < row; x++)
	{
		for (int col = 0; col < 3; col++)
		{
			cout << board[x][col];
		}
		cout << endl;
	}
}
bool validate(char board[][3],int row, int col )
{
	if (board[row - 1][col - 1] == 'X' || board[row - 1][col - 1] == 'O')
	{
		return false;
	}
	else
	{
		return true;
	}
}
void player1(char board[][3], int& row, int& col)
{
	
	cout << "Player 1. enter X position(row and column): ";
	cin >> row >> col;
	while (row < 1 || row > 3 || col < 1 || col > 3)
	{
		cout << "Please enter valid location: ";
		cin >> row >> col;
	}

	if (validate(board, row, col))
	{
		board[row - 1][col - 1] = 'X';
	}
	else
	{
		while (!validate(board, row, col))
		{
			cout << "Please enter another location on the board: ";
			cin >> row >> col;

			while (row < 1 || row > 3 || col < 1 || col > 3)
			{
				cout << "Please enter valid location: ";
				cin >> row >> col;
			}
		}

		board[row - 1][col - 1] = 'X';
	}
}
void player2(char board[][3], int& row, int& col)
{
	cout << "Player 2. enter O position(row and column): ";
	cin >> row >> col;
	while (row < 1 || row > 3 || col < 1 || col > 3)
	{
		cout << "Please enter a valid location: ";
		cin >> row >> col;
	}

	if (validate(board, row, col))
	{
		board[row - 1][col - 1] = 'O';
	}
	else
	{
		while (!(validate(board, row, col)))
		{
			cout << "Please enter another location on the board: ";
			cin >> row >> col;

			while (row < 1 || row > 3 || col < 1 || col > 3)
			{
				cout << "Please enter a valid location: ";
				cin >> row >> col;
			}
		}

		board[row - 1][col - 1] = 'O';
	}
}
bool diagonal(char board[][3])
{
	if ((board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') || (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X'))
	{
		cout << endl << "Player 1 wins the game!" << endl;
		return false;
	}
	else if ((board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O') || (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O'))
	{
		cout << endl << "Player 2 wins the game!" << endl;
		return false;
	}
	else
	{
		return true;
	}
}
bool horizontal(char board[][3])
{
	if ((board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X') || (board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X') || (board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X'))
	{
		cout << endl << "Player 1 wins the game!" << endl;
		return false;
	}
	else if ((board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O') || (board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O') || (board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O'))
	{
		cout << endl << "Player 2 wins the game!" << endl;
		return false;
	}
	else
	{
		return true;
	}
}
bool vertical(char board[][3])
{
	if ((board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X') || (board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X') || (board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X'))
	{
		cout << endl << "Player 1 wins the game!" << endl;
		return false;
	}
	else if ((board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O') || (board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O') || (board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O'))
	{
		cout << endl << "Player 2 wins the game!" << endl;
		return false;
	}
	else
	{
		return true;
	}
}
bool endGame(char board[][3])
{
	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			
			if (board[row][col] == '*')
			{
	
				return true;
				
			}
		}
	}
	return false;
}


int main()
{

	char game[3][3];
	int row, colum;
	char choice;

	initialBoard(game, 3);

	while (horizontal(game) && vertical(game) && diagonal(game))
	{
		player1(game, row, colum);
		updateBoard(game, 3);
		if (!horizontal(game) || !vertical(game) || !diagonal(game))
		{
			cout << "Do you want to play again? (Y/N) ";
			cin >> choice;
			if (toupper(choice) == 'Y')
			{
				initialBoard(game, 3);
				continue;
			}
			else
			{
				break;
			}
		}

		if (endGame(game))
		{
			player2(game, row, colum);
			updateBoard(game, 3);
			if (!horizontal(game) || !vertical(game) || !diagonal(game))
			{
				cout << "Do you want to play again? (Y/N) ";
				cin >> choice;
				if (toupper(choice) == 'Y')
				{
					initialBoard(game, 3);
					continue;
				}
				else
				{
					break;
				}
			}
		}
		else
		{
			cout << endl << "Game ended in a tie!" << endl;
			cout << "Do you want to play again? (Y/N) ";
			cin >> choice;
			if (toupper(choice) == 'Y')
			{
				initialBoard(game, 3);
				continue;
			}
			else
			{
				break;
			}
		}	
	}

	return 0;
}