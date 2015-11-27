/*********************************************************************
	Corporate Sales Data

	Write a program that  uses a structure named  CorpData to store the following  information on a 
	company  division:
	Division name (such as East, West, North, or South) First quarter sales
	Second quarter sales
	Third  quarter sales
	Fourth  quarter sales

	Include a constructor that allows the division name and four quarterly sales amounts to be specified
	at the time a CorpData variable is created.

	The  program  should   create  four  CorpData variables,   each  representing   one  of  the
	following  corporate divisions:  East,  West,  North, and  South.  These variables  should  be
	passed  one  at  a time,  as constant references,  to  a function  that  computes  the  division’s
	annual  sales total and quarterly average, and displays these along with the division name.
*********************************************************************/
#include <iostream>
#include <string>
using namespace std;

struct CorpData
{
	string name;
	double sales1, sales2, sales3, sales4;

	CorpData()
	{
		name = "";
		sales1 = sales2 = sales3 = sales4 = 0;
	}
	CorpData(string division, double x, double y, double z, double i)
	{
		name = division;
		sales1 = x;
		sales2 = y;
		sales3 = z;
		sales4 = i;
	}
};



void display(CorpData &x)
{
	cout << "What is the division name ";
	cin >> x.name;

	cout << "What are the quarterly sales values (enter 4 values): ";
	cin >> x.sales1 >> x.sales2 >> x.sales3 >> x.sales4;

	double total = x.sales1 + x.sales2 + x.sales3 + x.sales4;

	cout << "The total sales for the " << x.name << " division is $" << total << endl;
	cout << "The average for the " << x.name << " division is $" << total/4 << endl;
}


int main()
{
	CorpData division1, division2, division3, division4;

	display(division1);
	display(division2);
	display(division3);
	display(division4);

	return 0;
}