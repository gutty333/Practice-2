/*********************************************************************
	Movie Statistics

	Write a program that  can be used to gather  statistical  data  about  the number  of movies 
	college students  see in a month.  The  program should  ask  the  user how  many  students were 
	surveyed and  dynamically  allocate  an array  of that  size. The program should  then allow the 
	user to enter the number  of movies each student  has seen. The program should
	then calculate  the average, median,  and mode of the values entered.
*********************************************************************/
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

// Display Function
void display(int scores[], int size)
{
	for (int x = 0; x < size; x++)
	{
		cout << scores[x] << " ";
	}
	cout << endl;
}

// Sort Function
void sort(int scores[], int size)
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
}

// Average Function
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

// Medium Function
void medium(int* scores, int size)
{
	if (size % 2 == 0)
	{
		int index = size / 2;

		double medium = (scores[index] + scores[index - 1]) / 2.0;

		cout << "The medium of the set of numbers is " << medium << endl;
	}
	else
	{
		int index2 = size / 2;

		cout << "The medium of the set of numbers is " << scores[index2] << endl;
	}
}

// Mode Function
void mode(int scores[], int size)
{
	int count;
	int most=-1;
	int value, index = 1, temp;
	vector <int> temp2;
	bool single = false;


	for (int x = 0; x < size - 1; x++)
	{
		value = scores[x];
		count = 0;

		for (int y = x+1; y < size; y++)
		{
			if (scores[y] == value)
			{
				count++;
			}
		}


		if (count == 0)
		{
			continue;
		}
		else if (count > most)
		{
			most = count;
			temp = x;
			temp2.push_back(scores[x]);
			single = true;
		}
		else if (count == most) 
		{
			// In this section was trying to see if I can get it with dynamically allocating an array
			// Ended up going with vector

			temp2.push_back(scores[x]);

			single = false;
			index++;
		}
	}



	if (most == -1)
	{
		cout << "There is no mode in the set of numbers" << endl;
	}
	else if (single)
	{
		cout << "The mode of the set of numbers is " << scores[temp] << endl;
	}
	else
	{
		cout << "The modes in the set of numbers are: ";

		for (int z = 0; z < index; z++)
		{
			cout << temp2[z] << " ";
		}
		cout << endl;
	}
}

int main()
{
	int* students;
	int number;


	cout << fixed << setprecision(2);
	cout << "How many students were surveyed: ";
	cin >> number;

	students = new int[number];

	for (int x = 0; x < number; x++)
	{
		cout << "How many movies did student " << x + 1 << " see: ";
		cin >> students[x];
	}

	cout << endl << "Original" << endl;
	display(students, number);
	
	
	cout << endl << "Sorted" << endl;
	sort(students, number);
	display(students, number);
	average(students, number);
	medium(students, number);
	mode(students, number);

	delete[] students;
	students = 0;

	return 0;
}