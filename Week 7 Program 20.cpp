/*********************************************************************
	The mode is the value that appears most often in a set of data. Write a function named findMode
	that takes as parameters an array of ints and the size of the array, and returns a vector containing the
	mode(s). If there is just a single mode, the vector will only contain that one value, but if
	multiple values tie, the vector will need to contain all of the modes. This includes the case where
	every number in the array appears only once. Each mode should appear only once in the vector.  The
	values in the vector that is returned must be in ascending order. Depending on your algorithm, it
	may be easier (though less efficient) to just sort the vector at the end before returning it.
	Sorting a vector is similar to  sorting an array, but specifying the beginning and end of the
	vector look a little bit different.  If your vector is named result, then it would look like this:
	"std::sort(result.begin(), result.end());". Don't alter the original  array.
*********************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;



void findMode(int dataArray[], int size)
{
	int mode = 0;
	vector <int> numbers(0);

	for (int x = 0; x < size; x++)
	{
		int count = 0;
		for (int y = 0; y < size; y++)
		{
			if (dataArray[x] == dataArray[y])
			{
				count++;
				if (count >= mode)
				{
					mode = count;
				}
			}
		}
	}

	cout << "The numbers here repeat " << mode << " times" << endl;



	for (int x = 0; x < size; x++)
	{
		int count2 = 0;
		int find = 0;

		for (int y = 0; y < size; y++)
		{
			if (dataArray[x] == dataArray[y])
			{
				count2++;
				if (count2 >= find)
				{
					find = count2;
					if (find == mode)
					{
						numbers.push_back(dataArray[x]);
					}
				}
			}
		}
	}


	for (int x = 0; x < numbers.size(); x++)
	{
		for (int y = numbers.size()-1; y > x; y--)
		{
			if (numbers[x] == numbers[y])
			{
				numbers.erase(numbers.begin() + y);
			}
		}
	}


	sort(numbers.begin(), numbers.end());

	for (int x = 0; x < numbers.size(); x++)
	{
		cout << numbers[x] << endl;
	}
	cout << endl << endl;
}





int main()
{
	int test[5] = { 2, 34, 2, 54, 6 };
	int test2[12] = { 4, 54, 2, 12, 6, 3, 4, 4, 15, 12, 5, 12 };
	int test3[7] = { 2, 3, 5, 5, 3, 1, 4 };
	int test4[7] = { 2, 3, 5, 6, 7, 1, 4 };


	findMode(test, 5);
	findMode(test2, 12);
	findMode(test3, 7);
	findMode(test4, 7);

	return 0;
}

