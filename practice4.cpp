/*********************************************************
Write a program that asks the user to enter the number of pancakes eaten for breakfast by 10 different people (Person 1, Person 2, ..., Person 10)
Once the data has been entered the program must analyze the data and output which person ate the most pancakes for breakfast.

Modify the program so that it also outputs which person ate the least number of pancakes for breakfast.

Modify the program so that it outputs a list in order of number of pancakes eaten of all 10 people.
i.e.
Person 4: ate 10 pancakes
Person 3: ate 7 pancakes
Person 8: ate 4 pancakes
...
Person 5: ate 0 pancakes
********************************************************/

#include <iostream>
using namespace std;

void sort(int arr[], int size)
{
	int temp[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	int temp2, temp3;
	bool swap;

	do
	{
		swap = false;

		for (int x = 0; x < size-1; x++)
		{
			if (arr[x] < arr[x + 1])
			{
				temp2 = arr[x];
				arr[x] = arr[x + 1];
				arr[x + 1] = temp2;
				temp3 = temp[x];
				temp[x] = temp[x + 1];
				temp[x + 1] = temp3;
				swap = true;
			}
		}
	} while (swap);


	for (int y = 0; y < size; y++)
	{
		cout << "Person " << temp[y]+1 << ": ate " << arr[y] << " pancakes" << endl;
	}
}

void most_Least(int arr[], int size)
{
	int high = arr[0];
	int low = arr[0];
	int index, index2;

	for (int x = 0; x < size; x++)
	{
		if (low > arr[x])
		{
			low = arr[x];
			index = x;
		}

		if (high < arr[x])
		{
			high = arr[x];
			index2 = x;
		}
	}

	cout << "Person " << index + 1 << " ate the least pancakes which was a total of " << low << endl;
	cout << "Person " << index2 + 1 << " ate the most pancakes which was a total of " << high << endl;
}

int main()
{
	int person[10];
	int value;

	// Setting the pancakes eaten per person
	for (int x = 0; x < 10; x++)
	{
		cout << "How many pancakes did person " << 1 + x << " eat: ";
		cin >> value;

		person[x] = value;
	}

	cout << endl;
	// Displaying who ate the most and least
	most_Least(person, 10);

	cout << endl;
	// Sort and Display
	sort(person, 10);



	return 0;
}