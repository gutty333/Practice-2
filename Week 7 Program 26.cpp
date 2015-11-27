/*********************************************************************
	String Selection Sort

	Modify  the  selectionSort function  presented  in  this  chapter  so  it  sorts  an  array  of 
	strings instead of an array of ints. Test the function  with a driver program. Use Program  9-9
	as a skeleton to complete.
*********************************************************************/
#include <iostream>
#include <string>
using namespace std;


void sortString(string data[], int size)
{
	string low = "";
	bool swap;

	do
	{
		swap = false;

		for (int x = 0; x < size - 1; x++)
		{
			if (data[x] > data[x + 1])
			{
				low = data[x];
				data[x] = data[x + 1];
				data[x + 1] = low;
				swap = true;
			}
		}
	} while (swap);
}



void display(string data[], int size)
{
	for (int x = 0; x < size; x++)
	{
		cout << data[x] << endl;
	}
}



int main()
{

	const int size = 20;


	string name[size] = { "Collins, Bill", "Smith, Bart", "Michalski, Joe", "Griffin, Jim",
		"Sanchez, Manny", "Rubin, Sarah", "Taylor, Tyrone", "Johnson, Jill", "Allison, Jeff","Moreno,  Juan", 
		"Wolfe, Bill",  "Whitman, Jean", "Moretti, Bella", "Wu, Hong",     "Patel, Renee",   
		"Harrison, Rose", "Smith, Cathy", "Conroy, Pat", "Kelly, Sean", "Holland, Beth" };

	sortString(name, size);
	
	display(name, size);

	return 0;
}