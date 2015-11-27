/*********************************************************************
	A weather  analysis program uses the following array to store the temperature for each
	hour of the day on each day of a week.
	int temp[7][24];

	Each row represents  a day (0 = Sunday, 1 = Monday, etc.) and each column represents a time (0 = 
	midnight,  1 = 1 a.m., … , 12 = noon,  13 = 1 p.m., etc.).
	A)  Write code to find Tuesday’s average temperature.
	B)   Write code to find the average weekly noon temperature.
*********************************************************************/
#include <iostream>
using namespace std;

int main()
{
	const int	days = 7,
				hour = 25;

	// This values are supposed to represent temperate degrees
	// For the sake of practice I am using simple consecutive numbers
	int temp[days][hour] = { { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24 },
							{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24 },
							{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24 },
							{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24 },
							{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24 },
							{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24 },
							{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24 } };

	int total = 0;

	//Loop to find the average of Tuesday
	for (int row = 2; row == 2; row++)
	{
		for (int col = 0; col < hour; col++)
		{
			total += temp[row][col];
		}
	}

	cout << "The average of Tuesday is " << static_cast<double>(total) / hour << endl;


	total = 0;
	//Loop to find average of noon, since we have no values, it should be 12
	for (int row = 0; row < days; row++)
	{
		for (int col = 12; col == 12; col++)
		{
			total += temp[row][col];
		}
	}

	cout << "The average weekly noon is  " << static_cast<double>(total) / days << endl;


	return 0;
}