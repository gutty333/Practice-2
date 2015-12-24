// Shopping Cart header/specification file

#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include "Item.h"

class ShoppingCart
{
	private:
		Item* list[100];
		int arrayEnd;

	public:
		ShoppingCart();
		void addItem(Item*);
		double totalPrice();
		int getAmount();
};

#endif