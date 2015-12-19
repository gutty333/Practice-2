/*********************************************************************
	Test Scores #1

	Write a program that  dynamically  allocates  an array  large enough  to hold a user-defined number  
	of test scores.  Once  all the scores are entered,  the array  should  be passed  to a function   
	that  sorts  them  in  ascending  order.  Another   function   should  be  called  that calculates  
	the  average  score.  The  program should  display  the  sorted  list of scores  and averages  with 
	 appropriate headings.  Use pointer  notation rather  than  array  notation
	whenever possible.


	Test Scores #2

	Modify  the program of Programming Challenge  1 to allow the user to enter name–score pairs. For
	each student  taking  a test, the user types a string representing  the name of the student,
	followed  by an integer representing  the student’s score. Modify  both  the sorting and
	average-calculating functions so they take arrays of structures, with each structure containing
	the name and score of a single student.  In traversing  the arrays,  use pointers
	rather  than  array  indices.
*********************************************************************/
#include <iostream>
#include <string>
using namespace std;

struct Student
{
	string name;
	int score;
};


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
void average(Student* scores, int size)
{
	int total = 0;

	for (int x = 0; x < size; x++)
	{
		total += scores[x].score;
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
void sortArray(Student* students, int size)
{
	int high;
	string temp;
	bool swap;

	do
	{
		swap = false;

		for (int x = 0; x < size - 1; x++)
		{
			if (students[x].score > students[x + 1].score)
			{
				high = students[x].score;
				students[x].score = students[x + 1].score;
				students[x + 1].score = high;
				temp = students[x].name;
				students[x].name = students[x + 1].name;
				students[x + 1].name = temp;
				swap = true;
			}
		}
	} while (swap);
}


int main()
{
	int* scores;
	Student* test2;
	
	int number;

	cout << "How many test scores do you want to enter: ";
	cin >> number;
	


	scores = new int[number];
	test2 = new Student[number];

	for (int x = 0; x < number; x++)
	{

		/*cout << x + 1 << ". Enter score: ";
		cin >> *(scores + x);*/

		cout << x + 1 << ". Enter name: ";
		cin.get();
		getline(cin,test2[x].name);

		cout << x + 1 << ". Enter score: ";
		cin >> test2[x].score;

	}


	//sortArray(scores, number);
	sortArray(test2, number);

	cout << endl << "The score average" << endl;
	//average(scores, number);
	average(test2, number);


	cout << endl << "The scores in ascending order" << endl;
	for (int x = 0; x < number; x++)
	{
		// cout << *(scores + x) << endl;
		cout << test2[x].name << ": " << test2[x].score<< endl;
	}

	delete[] scores;
	delete[] test2;
	test2 = 0;
	scores = 0;

	return 0;
}
