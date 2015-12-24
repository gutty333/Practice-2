// Item class source/implementation file

#include "Item.h"

// Default Constructor
Item::Item()
{
	name = "";
	price = 0.0;
	quantity = 0;
}
// Constructor Overload
Item::Item(string n, double p, int q)
{
	name = n;
	price = p;
	quantity = q;
}


// Setter/Mutator Member Functions
void Item::setName(string n)
{
	name = n;
}
void Item::setPrice(double p)
{
	price = p;
}
void Item::setQuantity(int q)
{
	quantity = q;
}


// Getter/Accessors Member Functions
string Item::getName()
{
	return name;
}
double Item::getPrice()
{
	return price;
}
int Item::getQuantity()
{
	return quantity;
}