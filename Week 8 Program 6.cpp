/*********************************************************************
	Shopping Cart Project Program

	Test Program to make sure the classes are working properly
*********************************************************************/

#include <iostream>
#include <string>
#include <iomanip>
#include "ShoppingCart.h"
#include "Item.h"
using namespace std;



int main()
{
	string name;

	Item product;
	Item* food = &product;
	ShoppingCart list;

	cout << fixed << setprecision(2);

	cout << "Enter item name: ";
	cin >> name;
	food->setName(name);
	food->setPrice(1);
	food->setQuantity(14);
	list.addItem(food);


	food = new Item;
	cout << "Enter item name: ";
	cin >> name;
	food->setName(name);
	food->setPrice(1);
	food->setQuantity(14);
	list.addItem(food);


	food = new Item;
	cout << "Enter item name: ";
	cin >> name;
	food->setName(name);
	food->setPrice(2);
	food->setQuantity(4);
	list.addItem(food);


	food = new Item;
	cout << "Enter item name: ";
	cin >> name;
	food->setName(name);
	food->setPrice(0.85);
	food->setQuantity(17);
	list.addItem(food);


	cout << endl << "Report" << endl;
	cout << "Amount of Items: " << list.getAmount() << endl;
	cout << "Total price: $" << list.totalPrice() << endl;



	return 0;
}