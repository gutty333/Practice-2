// Shopping Cart source/implementation file

#include "ShoppingCart.h"


// Default Constructor
ShoppingCart::ShoppingCart()
{
	arrayEnd = 0;

	for (int x = 0; x < 100; x++)
	{
		list[x] = NULL;
	}
}


// Add Item member function
void ShoppingCart::addItem(Item* product)
{
	if (arrayEnd < 100)
	{
		list[arrayEnd] = product;
		arrayEnd++;
	}
}


// Total Price Member Function
double ShoppingCart::totalPrice()
{
	double total = 0;

	for (int x = 0; x < arrayEnd; x++)
	{
		total += list[x]->getPrice() * list[x]->getQuantity();
	}

	return total;
}


// Get Amount Method
int ShoppingCart::getAmount()
{
	return arrayEnd;
}