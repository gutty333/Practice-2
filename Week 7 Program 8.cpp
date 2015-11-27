/*********************************************************************
	Monkey  Business

	A local zoo wants to keep track of how many pounds  of food each of its three monkeys eats each day 
	during  a typical week. Write a program that  stores this information in a two- dimensional  3 × 7 
	array,  where each row represents  a different  monkey and each column represents  a different day 
	of the week. The program should first have the user input the data for each monkey. Then it should 
	create a report  that includes the following information:

	• Average amount of food eaten per day by the whole family of monkeys.
	• The least amount of food eaten during the week by any one monkey.
	• The greatest amount of food eaten during the week by any one monkey.
*********************************************************************/
#include <iostream>
using namespace std;



int main()
{
	int monkey[3][7];
	int total = 0;

	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 7; col++)
		{
			cout << "How many pounds of food did monkey " << row + 1 << " eat on day " << col + 1 << ": ";
			cin >> monkey[row][col];
			total += monkey[row][col];
		}
	}




	int low = monkey[0][0];
	int high = monkey[0][0];
	int count = 0, count2 = 0;

	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 7; col++)
		{
			if (monkey[row][col] < low)
			{
				low = monkey[row][col];
				count = row;
			}

			if (monkey[row][col] > high)
			{
				high = monkey[row][col];
				count2 = row;
			}
		}
	}


	cout << "The average amount of food eaten by all the monkeys is " << total / 21 << endl;
	cout << "The highest amount of food was " << high << " by monkey " << count2 + 1 << endl;
	cout << "The lowest amount of food was " << low << " by monkey " << count + 1 << endl;



	return 0;
}