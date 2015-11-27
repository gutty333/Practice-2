/********************************************************
	Winning Division

	Write   a  program  that   determines   which   of  a  company’s   four   divisions   (Northeast, 
	Southeast,   Northwest, and  Southwest)   had  the  greatest  sales  for  a  quarter.  It  should 
	include the following two functions,  which are called by main.

	• double getSales() is passed the name of a division. It asks the user for a division’s quarterly 
	sales figure, validates that the input is not less than 0, then returns  it. It should be called 
	once for each division.
	• void findHighest() is passed  the  four  sales  totals.  It  determines  which  is the largest 
	and prints the name of the high grossing division, along with its sales figure.
**********************************************************/
#include <iostream>
#include <string>
using namespace std;

double getSales(string name, double& x)
{
	cout << "What is the quarterly sales figure for " << name << " division? ";
	cin >> x;

	while (x < 0)
	{
		cout << "Please enter a positive number: ";
		cin >> x;
	}

	return x;
}

void findHighest(double a, double b, double c, double d)
{
	if (a > b && a > c && a > d)
	{
		cout << "The highest division is Northeast with a sales figure of $" << a << endl;
	}
	else if (b > a && b > c && b > d)
	{
		cout << "The highest division is Southeast with a sales figure of $" << b << endl;
	}
	else if (c > a && c > b && c > d)
	{
		cout << "The highest division is Northwest with a sales figure of $" << c << endl;
	}
	else if (d > a && d> c && d > b)
	{
		cout << "The highest division is Southwest with a sales figure of $" << d << endl;
	}
}


int main()
{
	double value1, value2, value3, value4;

	getSales("Northeast", value1);
	getSales("Southeast", value2);
	getSales("Northwest", value3);
	getSales("Southwest", value4);


	findHighest(value1, value2, value3, value4);


	return 0;

}