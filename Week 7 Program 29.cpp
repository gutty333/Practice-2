/*********************************************************************
	Sorting  Orders

	Write a program that uses two identical arrays of eight integers. It should display the contents of
	the first array, then call a function  to sort it using an ascending order bubble sort, modified to
	print out the array contents after each pass of the sort. Next the program should display the
	contents  of the second array,  then call a function  to sort it using an ascending order selection
	sort, modified to print out the array contents  after each pass of the sort.
*********************************************************************/
#include <iostream>
using namespace std;



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
	bool swap;
	int temp;

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
				display(array, size);
			}
		}


	} while (swap);
}



// Selection Sort Method
void selectionSort(int array[], int size)
{
	int index, value;


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
			}
		}

		array[index] = array[x];
		array[x] = value;
		display(array, size);
	}
}
int main()
{
	int test[8] = { 32, 5, 1223, 65, 23, 3, 87, 45 };
	int test2[8] = { 32, 5, 1223, 65, 23, 3, 87, 45 };

	cout << "Original Display" << endl;
	display(test, 8);
	display(test2, 8);

	cout << endl << "Bubble Sort " << endl;
	bubbleSort(test, 8);

	cout << endl << "Selection Sort " << endl;
	selectionSort(test2, 8);


	return 0;
}