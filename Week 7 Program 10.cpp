/*********************************************************************
	Lottery

	Write a program that  simulates  a lottery.  The program should  have an array  of 5 integers named 
	 winningDigits, with  a randomly generated  number  in the range  of 0 through 9 for each element 
	in the array. The program should ask the user to enter 5 digits and should store them in a second 
	integer array named player. The program must compare  the corresponding elements in the two arrays 
	and count  how many digits match.  For example, the following shows the winningDigits array and the 
	Player array with sample numbers stored in each. There are two matching  digits, elements 2 and 4.

	WinningDigits    7    4    9    1    3 
	player    4    2    9    7    3
	Once the user has entered a set of numbers,  the program should display the winning digits
	and the player’s digits and tell how many digits matched.
*********************************************************************/
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


int main()
{
	srand(time(0));

	int winningDigits[5] = { rand() % 9 + 1, rand() % 9 + 1, rand() % 9 + 1, rand() % 9 + 1, rand() % 9 + 1 };
	int player[5];


	cout << "Enter your numbers for the pick 5 lottery" << endl;
	for (int x = 0; x < 5; x++)
	{
		cout << "Number " << x + 1 << ". ";
		cin >> player[x];
	}


	int count = 0;

	for (int x = 0; x < 5; x++)
	{
		for (int y = 0; y < 5; y++)
		{
			if (winningDigits[x] == player[y])
			{
				count += 1;
			}
		}
	}


	cout << endl << endl << "The winning digits are ";
	for (int x = 0; x < 5; x++)
	{
		cout << winningDigits[x] << " ";
	}

	cout << endl << "The player digits are ";
	for (int x = 0; x < 5; x++)
	{
		cout << player[x] << " ";
	}


	cout << endl;
	if (count == 0)
	{
		cout << "No digits matched" << endl;
	}
	else
	{
		cout << "A total of " << count << " digit/s match" << endl;
	}


	return 0;

}
