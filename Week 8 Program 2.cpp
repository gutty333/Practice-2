/*********************************************************************
	Movie Statistics

	Write a program that  can be used to gather  statistical  data  about  the number  of movies 
	college students  see in a month.  The  program should  ask  the  user how  many  students were 
	surveyed and  dynamically  allocate  an array  of that  size. The program should  then allow the 
	user to enter the number  of movies each student  has seen. The program should
	then calculate  the average, median,  and mode of the values entered.
*********************************************************************/
#include <iostream>
using namespace std;

void average(int* total, int size)
{
	double sum = 0;
	for (int x = 0; x < size; x++)
	{
		sum += *total;
		total++;
	}

	cout << "The average is " << sum / size << endl;
}



void medium(int* scores, int size)
{
	int high;
	bool swap;

	do
	{
		swap = false;

		for (int x = 0; x < size - 1; x++)
		{
			if (scores[x] > scores[x + 1])
			{
				high = scores[x];
				scores[x] = scores[x + 1];
				scores[x + 1] = high;
				swap = true;
			}
		}
	} while (swap);


	if (size % 2 == 0)
	{
		int index = size / 2;

		double medium = (scores[index] + scores[index + 1]) / 2.0;

		cout << "The medium of the set of numbers is " << medium << endl;
	}
	else
	{
		int index2 = size / 2;

		index2 += 1;

		cout << "The medium of the set of numbers is " << scores[index2] << endl;
	}
}


int main()
{
	int* students;
	int number;

	cout << "How many students were surveyed: ";
	cin >> number;

	students = new int[number];

	for (int x = 0; x < number; x++)
	{
		cout << "How many movies did student " << x + 1 << " see: ";
		cin >> students[x];
	}

	average(students, number);
	medium(students, number);

	delete[] students;
	students = 0;

	return 0;
}