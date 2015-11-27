/*********************************************************************
	Test Scores #1

	Write a program that  dynamically  allocates  an array  large enough  to hold a user-defined number  
	of test scores.  Once  all the scores are entered,  the array  should  be passed  to a function   
	that  sorts  them  in  ascending  order.  Another   function   should  be  called  that calculates  
	the  average  score.  The  program should  display  the  sorted  list of scores  and averages  with 
	 appropriate headings.  Use pointer  notation rather  than  array  notation
	whenever possible.
*********************************************************************/
#include <iostream>
using namespace std;



void average(int* score, int size)
{
	int total = 0;

	for (int x = 0; x < size; x++)
	{
		total += *score;
		score++;
	}

	cout << "The average of the scores is " << double(total) / size << endl;
}


void sortArray(int* scores, int size)
{
	int high;
	bool swap;

	do
	{
		swap = false;

		for (int x = 0; x < size-1; x++)
		{
			if (scores[x] > scores[x+1])
			{
				high = scores[x];
				scores[x] = scores[x + 1];
				scores[x + 1] = high;
				swap = true;
			}
		}
	} while (swap);
}



int main()
{
	int* scores;
	
	int number;

	cout << "How many test scores do you want to enter: ";
	cin >> number;


	scores = new int[number];

	for (int x = 0; x < number; x++)
	{
		cout << x + 1 << ". Enter score: ";
		cin >> *(scores + x);
	}


	sortArray(scores, number);

	cout << endl << "The score average is" << endl;
	average(scores, number);


	cout << endl << "The scores in ascending order" << endl;
	for (int x = 0; x < number; x++)
	{
		cout << *(scores + x) << endl;
	}

	delete[] scores;
	scores = 0;

	return 0;
}
