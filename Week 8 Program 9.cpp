/*********************************************************************
	Write a function that takes two parameters - an array of doubles and the size of the
	array - and returns the average of the values in the array.  Write a main method that asks the user 
	how many values they want to enter, uses "new" to dynamically allocate an array of doubles of that 
	size, reads user input for that many values, storing them in the array, and then passes that array 
	to the function and prints out the return value.
	Lastly it should use "delete" to deallocate the array.
*********************************************************************/
#include <iostream>
using namespace std;


double average(double array[], int size)
{
	double total = 0;

	for (int x = 0; x < size; x++)
	{
		total += array[x];
	}

	return total/size;
}


int main()
{

	cout << "How many values do you want to enter: ";
	int size;
	cin >> size;


	double* numbers = new double[size];


	for (int x = 0; x < size; x++)
	{
		cout << x + 1 << ". Enter a number: ";
		cin >> numbers[x];
	}


	cout << endl << "The average is " << average(numbers, size) << endl;

	delete[] numbers;
	numbers = 0;

	return 0;
}