/*********************************************************************
	Sorting  Benchmarks

	Write  a program that  uses two  identical  arrays  of at  least  20  integers.  It should  call a 
	function  that  uses the bubble  sort  algorithm to sort  one of the arrays  in ascending  order. 
	The function  should  count  the number  of exchanges  it makes.  The program should  then call a 
	function  that  uses the selection sort algorithm to sort the other  array.  It should  also
	count  the number  of exchanges it makes. Display these values on the screen.
*********************************************************************/
#include <iostream>
using namespace std;

// Display Method
void display(int array[], int size)
{
	for (int x = 0; x < size; x++)
	{
		cout << array[x] << " ";
	}
	cout << endl;
}

// Bubble Sort Method
void bubbleSort(int array[], int size)
{
	int temp, count = 0;
	bool swap;

	do
	{
		swap = false;


		for (int x = 0; x < size - 1; x++)
		{
			if (array[x] > array[x + 1])
			{
				temp = array[x];
				array[x] = array[x + 1];
				array[x + 1] = temp;
				swap = true;
				count++;
			}
		}
	} while (swap);


	cout << "It made a total of " << count << " exchanges in the bubble sort" << endl;
}



// Selection Sort Method
void selectionSort(int array[], int size)
{
	int index;
	int value;
	int count = 0;

	for (int x = 0; x < size - 1; x++)
	{
		index = x;
		value = array[x];

		for (int y = x + 1; y < size; y++)
		{
			if (array[y] < value)
			{
				index = y;
				value = array[y];
				count++;
			}
		}
		array[index] = array[x];
		array[x] = value;
	}

	cout << "It made a total of " << count << " exchanges in the selection sort" << endl;
}

int main()
{
	int test[20] = { 23, 27, 45, 12, 67, 435, 789, 9, 445, 32, 45, 12, 455, 67, 60, 980, 95, 407, 702, 2 };
	int test2[20] = { 23, 27, 45, 12, 67, 435, 789, 9, 445, 32, 45, 12, 455, 67, 60, 980, 95, 407, 702, 2 };


	cout << "No sorted" << endl;
	display(test, 20);
	display(test2, 20);



	cout << endl << "Bubble Sort" << endl;
	bubbleSort(test, 20);
	display(test, 20);


	// The selection sort should benefit and have less exchanges.
	cout << endl << "Selection Sort" << endl;
	selectionSort(test2, 20);
	display(test2, 20);

	return 0;
}