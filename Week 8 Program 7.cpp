/*********************************************************************
	Write a void function that takes as parameters three pointers-to-int 
	(a pointer to num1, a pointer to num2 and a pointer to num3) 
	and sorts the values in num1, num2 and num3 into ascending order, so that num1 has the lowest value, 
	num2 the middle value, and num3 the highest value. Since this function is void, your test code 
	in main should prompt the user for the three values, print them out, call the function to sort them, 
	and then print them again (hopefully now sorted). 

	For example, if the user enters: 24, -7 and 15, then the output should look like this:
	original order: 24 -7 15 
	sorted order: -7 15 24
*********************************************************************/
#include <iostream>
using namespace std;


void sortPointer(int* num1, int* num2, int* num3)
{
	int mid = *num2;
	int high = *num3;
	int low = *num1;

	if (*num2 < low)
	{
		mid = low;
		low = *num2;
	}
	
	if (*num3 < low)
	{
		mid = low;
		low = *num3;
	}

	if (*num1 > high)
	{
		mid = high;
		high = *num1;
	}
	
	if (*num2 > high)
	{
		mid = high;
		high = *num2;
	}

	*num1 = low;
	*num2 = mid;
	*num3 = high;
}



int main()
{
	int numbers[3];

	for (int x = 0; x < 3; x++)
	{
		cout << "Enter number: ";
		cin >> numbers[x];
	}


	cout << endl << "Original Order" << endl;
	for (int y = 0; y < 3; y++)
	{
		cout << numbers[y] << " ";
	}
	cout << endl;

	sortPointer(numbers, numbers + 1, numbers + 2);

	cout << endl << "Sorted Order" << endl;
	for (int y = 0; y < 3; y++)
	{
		cout << numbers[y] << " ";
	}
	cout << endl;

	return 0;
}