/********************************************************
	Order Status

	The Middletown Wholesale Copper  Wire Company sells spools of copper  wiring for $100 each and 
	ships them for $10 apiece. Write a program that displays the status of an order.  It should  use 
	two  functions.  The  first  function  asks  for  the  following  data  and  stores  the input 
	values in reference parameters.

	• The number  of spools ordered.
	• The number  of spools in stock.
	• Any special shipping and handling  charges (above the regular $10 rate).

	The second function  receives as arguments  any values needed to compute  and display the following 
	information:

	• The number  of ordered  spools ready to ship from current stock.
	• The number  of ordered  spools  on backorder (if the number  ordered  is greater  than
	what is in stock).
	• Total  selling price of the portion ready  to ship (the number  of spools  ready  to ship
	times $100).
	• Total shipping and handling  charges on the portion ready to ship.
	• Total of the order ready to ship.
	The  shipping  and  handling   parameter in  the  second  function   should  have  the  default
	argument 10.00.
**********************************************************/
#include <iostream>
#include <iomanip>
#include <cctype>
using namespace std;

const double price = 100.0, shippingPrice = 10.0;


void status(int& spool, int& stock, char& choice, double& charges)
{
	cout << "How many spools do you want to order? ";
	cin >> spool;

	cout << "How many spools are in stock at the moment? ";
	cin >> stock;

	cout << "Will there be any special shipping and handling  charges? (Y/N) ";
	cin >> choice;

	if (toupper(choice) == 'Y')
	{
		cout << "What will the amount of charges be: ";
		cin >> charges;
	}
	else
	{
		charges = 0;
		cout << "No extra charges be added to the order" << endl;
	}
}



void results(int spool, int stock, double charges)
{
	cout << "You ordered a total of " << spool << " spools" << endl;
	
	if (spool > stock)
	{
		cout << "We have a total of " << spool - stock << " spools on backorder" << endl;
	}

	int order = spool*price;
	int shipping = spool * shippingPrice + charges;
	cout << "The price amount for your spools ready to ship is $" << order << endl;
	cout << "The price amount for the shipping only is $" << shipping << endl;

	cout << "The total cost of you order is $" <<fixed << setprecision(2) << order + shipping << endl;
}



int main()
{
	int order, stock;
	char choice;
	double charges;

	status(order, stock, choice, charges);

	results(order, stock, charges);

	return 0;
}