/********************************************************
	Markup

	Write  a  program that  asks  the  user  to  enter  an  item’s  wholesale  cost  and  its  markup
	percentage.  It should then display the item’s retail price. For example:
	• If an item’s wholesale  cost is 5.00  and its markup percentage  is 100%, then the item’s retail
	price is 10.00.
	• If an item’s wholesale cost is 5.00 and its markup percentage  is 50%,  then the item’s retail
	price is 7.50.

	The  program  should   have  a  function   named   calculateRetail that   receives  the wholesale
	cost and the markup percentage  as arguments  and returns  the retail price of
	the item.
**********************************************************/
#include <iostream>
#include <iomanip>
using namespace std;


double calculateRetail(double x, double y)
{
	y /= 100;

	return (x * y) + x;
}


int main()
{
	double price, percentage;

	cout << "What is the items whole cost? ";
	cin >> price;

	cout << "What is the markup percentage? ";
	cin >> percentage;

	cout << fixed << setprecision(2);

	cout << "If the items whole cost is $" << price << " and the markup percentage is " << setprecision(0) << percentage << "%, than the retail price is $" << setprecision(2) << calculateRetail(price, percentage) << endl;


	return 0;
}