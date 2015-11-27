/*********************************************************************
	Rainfall  Statistics

	Write  a modular program that  analyzes  a year’s worth  of rainfall  data.  In addition to main, 
	the  program should  have  a getData function  that  accepts  the  total  rainfall  for each of 12 
	months  from the user and stores it in a double array.  It should  also have four value-returning 
	functions    that   compute    and   return    to   main the   totalRainfall, averageRainfall, 
	driestMonth, and  wettestMonth. These last two  functions  return the number  of the month  with 
	the lowest and highest rainfall  amounts, not  the amount of rain that  fell those months.  Notice  
	that  this month  number  can be used to obtain  the amount of rain that fell those months.  This 
	information should be used either by main or by a displayReport function  called by main to print  
	a summary  rainfall  report  similar to the following:

	2010 Rain Report for Neversnows County
	Total rainfall: 23.19 inches
	Average monthly rainfall: 1.93 inches
	The least rain fell in January with 0.24 inches.
	The most rain fell in April with 4.29 inches.
*********************************************************************/
#include <iostream>
#include <string>
using namespace std;


double getData(double array[])
{
	for (int x = 0; x < 12; x++)
	{
		cout << "Enter the total rainfall for month " << x + 1 << ". ";
		cin >> array[x];
	}

	return array[12];
}
double totalRainfall(double array[])
{
	double total = 0;

	for (int x = 0; x < 12; x++)
	{
		total += array[x];
	}

	return total;
}
double averageRainfall(double array[])
{
	return totalRainfall(array)/12;
}
int driestMonth(double array[])
{
	int count = 0;
	double low = array[0];

	for (int x = 0; x < 12; x++)
	{
		if (array[x] < low)
		{
			low = array[x];
			count = x;
		}
	}

	return count;
}
int wettestMonth(double array[])
{
	int count = 0;
	double high = array[0];

	for (int x = 0; x < 12; x++)
	{
		if (array[x] > high)
		{
			high = array[x];
			count = x;
		}
	}

	return count;
}



int main()
{
	double rain[12];
	string month[12] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

	getData(rain);

	cout << endl << "2010 Rain Report for Neversnow County" << endl << endl;
	cout << "Total rainfall: " << totalRainfall(rain) << " inches" << endl;
	cout << "Average monthly rainfall: " << averageRainfall(rain) << " inches" << endl;
	cout << "The least rain fell in " << month[driestMonth(rain)] << " with " << rain[driestMonth(rain)] << " inches" << endl;
	cout << "The most rain fell in " << month[wettestMonth(rain)] << " with " << rain[wettestMonth(rain)] << " inches" << endl;




	return 0;
}