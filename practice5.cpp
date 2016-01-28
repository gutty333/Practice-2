/*********************************************************
Write a program that calculates a random number 1 through 100. The program then asks the user to guess the number.
If the user guesses too high or too low then the program should output "too high" or "too low" accordingly.
The program must let the user continue to guess until the user correctly guesses the number.

Modify the program to output how many guesses it took the user to correctly guess the right number.

Modify the program so that instead of the user guessing a number the computer came up with, the computer guesses the number that the user has secretly decided. The user must tell the computer whether it guessed too high or too low.

Modify the program so that no matter what number the user thinks of (1-100) the computer can guess it in 7 or less guesses.
********************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

int main()
{
	srand(time(NULL));

	int randomNum = rand() % 100 + 1;
	int guess, guessCount = 1;
	bool found = false;

	do
	{
		cout << "Guess a random number from 1-100: ";
		cin >> guess;

		if (guess == randomNum) // Condition for getting it correct
		{
			found = true;
			cout << "Congratulation you found the number in " << guessCount << " guess" << endl;
		}
		else if (guess < randomNum) // Condition for having a low guess
		{
			cout << "Too Low, keep trying" << endl;
		}
		else if (guess > randomNum) // Condition for having a high guess
		{
			cout << "Too high, keep trying" << endl;
		}
		guessCount++; // Keeping track of how many tries
		cout << endl;
	} while (!found);

	/**************************************************/
	cout << endl << endl << "Computer Section" << endl;
	cout << "Enter a number you want the computer to guess: ";
	cin >> guess;

	found = false;
	guessCount = 1;

	do
	{
		randomNum = rand() % 100 + 1;

		if (guess == randomNum) // Condition for getting it correct
		{
			found = true;
			cout << "Congratulation you found the number in " << guessCount << " guess" << endl;
		}
		else if (randomNum < guess) // Condition for having a low guess
		{
			cout << "Too Low: " << randomNum <<  endl;
		}
		else if (randomNum > guess) // Condition for having a high guess
		{
			cout << "Too high: " << randomNum << endl;
		}
		guessCount++;
		cout << endl;
	} while (!found);

	/**************************************************/
	cout << endl << endl << "Computer Section 2.0" << endl;
	cout << "Here the computer should guess much faster(less than 7)" << endl;
	cout << "Enter a number you want the computer to guess: ";
	cin >> guess;

	found = false;
	int maxRange = 100;
	int lowRange = 1;
	int newHigh = 0;
	guessCount = 1;
	

	do
	{
		randomNum = rand() % maxRange + lowRange;

		if (guess == randomNum)
		{
			found = true;
			cout << "Congratulation you found the number in " << guessCount << " guess" << endl;
		}
		else if (randomNum < guess)
		{
			cout << "Too Low: " << randomNum<<  endl;
			newHigh = maxRange + lowRange;
			lowRange = randomNum+1;
			
			maxRange = newHigh- lowRange;

			for (int x = 0; x < newHigh; x++) // Loop to further optimize the low range
			{
				if ((lowRange + x) < guess)
				{
					lowRange += x;
					maxRange = newHigh - lowRange;
				}
			}
		}
		else if (randomNum > guess)
		{
			cout << "Too high: " << randomNum << endl;
			maxRange = randomNum-lowRange;

			for (int x = 0; x < randomNum - 1; x++) // Loop to further optimize the max/high range
			{
				if ((randomNum - x) > guess)
				{
					maxRange = (randomNum-x) - lowRange;
				}
			}
		}

		guessCount++;
		cout << endl;
	} while (!found);

	return 0;
}