// Linear Search = Will step through an array sequentially
// Binary Search = Much more efficient, it will only search through half of the array. Elements must be sorted first
// Bubble Sort =  Can sort elements by comparing them to the element next to each other.
// Selection Sort = Best for large data. Locates the desired value right away and works from there

#include <iostream>
#include <string>
using namespace std;


void display(int array[], int size)
{
	for (int x = 0; x < size; x++)
	{
		cout << array[x] << " ";
	}
	cout << endl;
}




// This method works but is doing more iterations even after finding the value
void linearSearch(int test[], int size, int value)
{
	int index = -1;

	for (int x = 0; x < size; x++)
	{
		if (test[x] == value)
		{
			index = x;
		}
	}


	if (index == -1)
	{
		cout << "Value was not found" << endl;
	}
	else
	{
		cout << "Value was found in element " << index + 1 << endl;
	}
}
// Correct method using a while loop
// This will only do the require iterations once it finds the value
// If the value is located at the end, than it will do all of the elements
// Note that this can also be return function for just the index/position
void searchLinear(int array[], int size, int value)
{
	int position = -1;
	bool swap = false;
	int index = 0;

	while (!swap && index < size)
	{
		if (array[index] == value)
		{
			swap == true;
			position = index;
		}

		index++;
	}

	if (position == -1)
	{
		cout << "Value was not found" << endl;
	}
	else
	{
		cout << "Value was found in element " << position + 1 << endl;
	}
}



/*******************************************************************************/
// Binary Search practice function
void binarySearch(int array[], int size, int value)
{
	int index = -1;
	int middle;
	int first = 0;
	int last = size - 1;

	for (int x = 0; x < size; x++)
	{
		middle = (first + last) / 2;    // Midpoint or Mid index of the array
		 
		if (array[middle] == value) // Checking to see if the mid element is the value we are searching for
		{
			index = middle;
		}
		else if (array[middle] > value) // if the mid elements is greater than value, cut the iterations by half
		{
			last = middle -1 ;
		}
		else // if is less than value, it will also cut the iterations by half
		{
			first = middle +1;
		}
	}


	if (index== -1)
	{
		cout << "Value was not found" << endl;
	}
	else
	{
		cout << "Value was found in element " << index + 1 << endl;
	}
}
// Similar way but using the boolean swap
// This will end once is found, unlike the for loop
void searchBinary(int array[], int size, int value)
{
	bool swap = false;
	int index = -1;
	int first = 0, last = size - 1, middle;


	while (!swap && first <= last)
	{
		middle = (last + first) / 2;

		if (array[middle] == value)
		{
			index = middle;
			swap = true;
		}
		else if (array[middle] > value)
		{
			last = middle - 1;
		}
		else
		{
			first = middle + 1;
		}
	}


	if (index == -1)
	{
		cout << "Value was not found" << endl;
	}
	else
	{
		cout << "Value was found in element " << index + 1 << endl;
	}
}



/******************************************************************************/
// Bubble Sort Function
void bubbleSort(int array[], int size)
{
	int temp;
	bool swap;

	do
	{
		swap = false;

		for (int x = 0; x < size - 1; x++) // We only loop through size -1 because if we used size, when we compare x +1, that subscript is out of range. Ex. size = 10  if(array[9] > array[9+1]) array[10] is out of range
		{
			if (array[x] > array[x + 1]) // if the 1st element if greater, replace with the neighbor element. ascending order here
			{
				temp = array[x]; // passing element to temp, since element will be replaced by its neighbor
				array[x] = array[x + 1]; // the neighbor element value is now passed to the previous element
				array[x + 1] = temp; // the neighbor element takes the value of the other element we used for comparing
				swap = true;
			}
		}
	} while (swap); // If elements were swap, loop again to check if more sorting needs to be made after the change
}


// Selection Sort Function
void selectionSort(int array[], int size)
{
	int index, value;


	for (int x = 0; x < size - 1; x++) // Loop through all elements not including the very last
	{
		index = x;  // Reset index to the next element in array
		value = array[x]; // Hold the current value for comparison

		for (int y = x + 1; y < size; y++) // Loop all elements not including the previous one. Ex {2,1,5} only check 1 and 5
		{
			if (array[y] > value) // if element 2 is greater than current element in loop
			{
				index = y; // get location of that element
				value = array[y]; // get the value of the element
			}
		}
		array[index] = array[x]; // replace that element found with the current element.  Ex. {2,1,5}  becomes {2,2,5}
		array[x] = value; // set current element to the value  Ex. {2,2,5} becomes {1,2,5}
	}
}



int main()
{
	
	//int test[] = { 5, 23, 1, 45, 6, 78, 111, 66, 9, 33 };
	//int test2[] = { 23, 31, 45, 67, 87, 98, 102, 132, 345, 542 };
	//int value;

	//do
	//{
	//	cout << "Enter a value: (-1 to exit) ";
	//	cin >> value;

	//	// Linear Search Practice 
	//	linearSearch(test, 10, value);
	//	searchLinear(test, 10, value);


	//	// Binary Search Practice
	//	binarySearch(test2, 10, value);
	//	searchBinary(test2, 10, value);
	//} while (value != -1);




	int test3[] = { 3423, 34, 3545, 31, 12, 785, 78, 11, 54, 9, 88 };
	int test4[] = { 451,26,8799,6331,120,24,78,954,651,138,88};


	display(test3, 11);
	bubbleSort(test3, 11);
	display(test3, 11);
	cout << endl << endl;
	display(test4, 11);
	selectionSort(test4, 11);
	display(test4, 11);





	return 0;
}