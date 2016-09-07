/*********************************************************************
	Chips and Salsa

	Write  a program that  lets a maker  of chips and  salsa keep track  of their  sales for five 
	different  types of salsa they produce:  mild, medium,  sweet, hot, and zesty. It should  use two 
	parallel  five-element arrays:  an array  of strings that  holds the five salsa names and an array  
	of integers that  holds the number  of jars sold during  the past  month  for each salsa type. The 
	salsa names  should  be stored  using an initialization list at the time the name array  is 
	created.  The program should  prompt the user to enter the number  of jars sold for each type. Once 
	this sales data  has been entered,  the program should  produce a report  that  displays sales for 
	each salsa type, total  sales, and the names of the highest
	selling and lowest selling products.



	Chips and Salsa Version 2

	Revise  Programming Challenge  3  to  use  an  array  of  Product objects  instead  of  two
	parallel arrays.  The Product class will need member variables to hold a product name and a
	quantity.

*********************************************************************/
#include <iostream>
#include <string>
using namespace std;

const int size = 5;
string salsa[size] = { "Mild", "Medium", "Sweet", "Hot", "Zesty" };



class Product
{
	private:
		string name[size];
		int quantity[size];

	public:
		Product()
		{
			for (int x = 0; x < size; x++)
			{
				name[x] = salsa[x];
			}
			for (int x = 0; x < size; x++)
			{
				quantity[x] = 0;
			}
		}
};




int main()
{
	
	int sold[size], total=0;

	for (int x = 0; x < size; x++)
	{
		cout << "How many jars of " << salsa[x] << " did you sell: ";
		cin >> sold[x];
		total += sold[x];
	}

	string line;

	cout << endl << "Chip and Salsa Report" << endl;
	cout << line.assign(40, '-') << endl;

	for (int x = 0; x < size; x++)
	{
		cout << x + 1 << ". The monthly sells for " << salsa[x] << " is " << sold[x] << endl;
	}

	cout << "The total sells of all the jars is " << total << endl;

	int low = sold[0];
	int high = sold[0];
	int count, count2;
	count = count2 = 0;

	for (int x = 0; x < size; x++)
	{
		if (sold[x] < low)
		{
			low = sold[x];

			count = x;
		}

		if (sold[x] > high)
		{
			high = sold[x];

			count2 = x;
		}

		
	}

	cout << "The highest jar of " << salsa[count2] << " had " << high << " sells" << endl;
	cout << "The lowest jar of " << salsa[count] << " had " << low << " sells" << endl;
	cout << line.assign(40, '-') << endl;

	Product salsaObject;



	return 0;
}