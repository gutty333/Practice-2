/*********************************************************************
	Inventory Class

	Design an Inventory class that can hold information for an item in a retail store’s inventory. 

	The class should have the following private member variables.
	itemNumber        An int that holds the item’s number.
	quantity          An int that holds the quantity of the item on hand.
	cost              A double that holds the wholesale per-unit  cost of the item

	The class should have the following public member functions.
	default  constructor = Sets all the member variables to 0.
	constructor #2 = Accepts an item’s number,  quantity, and cost as arguments. Calls other class functions  to copy these values into the appropriate member variables.  Then calls the getTotalCost function.
	setItemNumber = Accepts an int argument and copies it into the itemNumber member variable.
	setQuantity = Accepts an int argument and copies it into the quantity member variable.
	setCost = Accepts a double argument and copies it into the cost member variable.
	getItemNumber = Returns  the value in itemNumber. 
	getQuantity = Returns  the value in quantity. 
	getCost = Returns  the value in cost. 
	getTotalCost = Computes and return the totalCost.

	Demonstrate the class by writing  a simple program that  uses it. This program should  validate the user inputs to ensure that negative values are not accepted for item number,  quantity, or cost.

	Note that there are some typos with this program, you also need a  member variable for totalCost.
	Also a member function for totalCost, include accessors and mutators.
*********************************************************************/
#include <iostream>
using namespace std;

class Inventory
{
	private:
		int number;
		int quantity;
		double cost;
		double totalCost;



	public:
		Inventory()
		{
			number = 0;
			quantity = 0;
			cost = 0;
			totalCost = 0;
		}
		Inventory(int x, int y, double z)
		{
			setNumber(x);
			setQuantity(y);
			setCost(z);
			setTotalCost(y, z);
		}
		void setNumber(int x)
		{
			number = x;
		}
		void setQuantity(int y)
		{
			quantity = y;
		}
		void setCost(double z)
		{
			cost = z;
		}
		void setTotalCost(double i, double j)
		{
			totalCost = i * j;
		}
		int getNumber()
		{
			return number;
		}
		int getQuantity()
		{
			return quantity;
		}
		double getCost()
		{
			return cost;
		}
		double getTotalCost()
		{
			return totalCost;
		}
			
};


int main()
{
	int number, amount;
	double price;

	do
	{
		cout << "What is the item number: ";
		cin >> number;

		cout << "What is the item quantity: ";
		cin >> amount;

		cout << "What is the cost of each item: ";
		cin >> price;

	} while (number < 0 || amount < 0 || price < 0);


	Inventory unit(number, amount, price);

	cout << "The total cost of item " << unit.getNumber() << " is $" << unit.getTotalCost() << endl;


	return 0;
}