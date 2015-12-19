/*********************************************************************
	Search Benchmarks

	Write a program that has an array of at least 20 integers. It should call a function  that uses the 
	linear search algorithm to locate one of the values. The function  should keep a count of the 
	number  of comparisons it makes until it finds the value. The program then should  call a function  
	that  uses the binary  search  algorithm to locate  the same value. It should  also keep count  of 
	the number  of comparisons it makes. Display these values on the screen.
*********************************************************************/
#include <iostream>
#include <string>
using namespace std;


// Display Function
void display(int array[], int size)
{
	for (int x = 0; x < size; x++)
	{
		cout << array[x] << " ";
	}
	
	cout << endl;
}



// Sort Function, needed for the binary search function
void sortValues(int array[], int size)
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
			}
		}
	} while (swap);
}


// Linear Search Function
void linearSearch(int array[], int size, int value)
{
	int count=0, index=0;
	bool found= false;


	while (!found && index < size)
	{
		if (array[index] == value)
		{
			found = true;
		}
		else
		{
			count++;
		}

		index++;
	}


	if (found)
	{
		cout << "It took " << count << " tries to find the value in the linear" << endl;
	}
	else
	{
		cout << "Value not found" << endl;
	}
}


// Binary Search
void binarySearch(int array[], int size, int value)
{
	bool found = false;
	int mid, last = size - 1, first = 0, count = 0;


	while (!found && first <= last)
	{
		mid = (last + first) / 2;


		if (array[mid] == value)
		{
			found = true;
		}
		else if (array[mid] > value)
		{
			last = mid - 1;
			count++;
		}
		else
		{
			first = mid + 1;
			count++;
		}
	}

	if (found)
	{
		cout << "It took " << count << " tries to find the value in the binary" << endl;
	}
	else
	{
		cout << "Value not found" << endl;
	}
	
}






int main()
{
	int test[20] = { 23, 27, 45, 12, 67, 435, 789, 9, 445, 32, 45, 12, 455, 67, 60, 980, 95, 407, 702, 2};
	int value;

	display(test, 20);

	sortValues(test, 20);

	display(test, 20);


	do
	{
		cout << endl << "Enter a value: (-1 to exit) ";
		cin >> value;


		// The linear search should only benefit when the value is located very early in the list, assuming they are sorted
		linearSearch(test, 20, value);
		
		
		binarySearch(test, 20, value);
		
	} while (value != -1);


	return 0;
}