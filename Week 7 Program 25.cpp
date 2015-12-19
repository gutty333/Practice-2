/*********************************************************************
	Hit the Slopes

	Write a program that  can be used by a ski resort  to keep track  of local snow conditions for one 
	week. It should  have a seven-element  array  of structures, where  each structure holds  a date  
	and  the number  of inches of snow  in the base on that  date.  The program should  have the user 
	input  the name  of the month,  the starting  and  ending  date  of the seven-day  period  being  
	measured,  and  then  the  seven base  snow  depths.  The  program should  then sort the data  in 
	ascending  order  by base depth  and display the results. Here is a sample report.

	Snow Report December 12 – 18
	Date  Base
	13   42.3
	12   42.5
	14   42.8
	15   43.1
	18   43.1
	16   43.4
	17   43.8
*********************************************************************/
#include <iostream>
#include <string>
using namespace std;


struct Data
{
	int date;
	double snow;
};



int main()
{
	Data report[7];

	cout << "For what month are you doing the snow report: ";
	string month;
	cin >> month;


	cout << "What is the starting date: ";
	int start, end;
	cin >> start;
	end = start + 7;

	for (int x = 0; start < end; start++,x++)
	{
		report[x].date = start;
	}

	for (int x = 0; x < 7; x++)
	{
		cout << "What is the snow depth of date " << report[x].date << ": ";
		cin >> report[x].snow;
	}


	bool swap;
	int low;
	int dateTemp;
	do
	{
		swap = false;

		for (int x = 0; x < 6; x++)
		{
			if (report[x].snow > report[x + 1].snow)
			{
				low = report[x].snow;
				dateTemp = report[x].date;
				report[x].date = report[x + 1].date;
				report[x].snow = report[x + 1].snow;
				report[x + 1].snow = low;
				report[x + 1].date = dateTemp;
				swap = true;
			}
		}
	} while (swap);



	cout << endl << "Snow Report " << month << " " << start-7 << " - " << end-1 << endl;
	for (int x = 0; x < 7; x++)
	{
		cout << report[x].date << "  " << report[x].snow << endl;
	}


	return 0;
}