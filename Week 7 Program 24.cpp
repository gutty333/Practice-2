/*********************************************************************
	Annual Rainfall  Report

	Write a program that  displays the name of each month in a year and its rainfall  amount, sorted  
	in order  of rainfall  from  highest  to  lowest.  The  program should  use an  array  of 
	structures, where each structure holds the name of a month  and its rainfall  amount. Use a 
	constructor to set the month  names.  Make  the program modular by calling on different
	functions  to input the rainfall amounts, to sort the data,  and to display the data.
*********************************************************************/
#include <iostream>
#include <string>
using namespace std;

struct Report
{
	string month;
	int rain;
	Report()
	{
		month = "";
		rain = 0;
	}
	Report(string name = "")
	{
		month = name;
	}
};


void inputRain(Report year[], int size)
{
	for (int x = 0; x < 12; x++)
	{
		cout << "What is the rainfall amount for " << year[x].month << ": ";
		cin >> year[x].rain;
	}
}

void sortRain(Report year[], int size)
{
	int high = 0;
	bool swap;

	do
	{
		swap = false;

		for (int x = 0; x < size - 1; x++)
		{
			if (year[x].rain < year[x + 1].rain)
			{
				high = year[x].rain;
				year[x].rain = year[x+1].rain;
				year[x + 1].rain = high;
				swap = true;
			}
		}
	} while (swap);
}


void display(Report year[], int size)
{
	for (int x = 0; x < size; x++)
	{
		cout << year[x].rain << endl;
	}
}



int main()
{
	Report year[12] = { Report("January"), Report("February"), Report("March"), Report("April" ), Report("May"), Report("June"), Report("July"), Report("August"), Report("September"), Report("October"), Report("November"), Report("December") };


	inputRain(year, 12);

	sortRain(year, 12);

	display(year, 12);

	return 0;
}