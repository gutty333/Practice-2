// Item class header/specification file


#ifndef ITEM_H
#define ITEM_H

#include <string>
using namespace std;

class Item
{
	private:
		string name;
		double price;
		int quantity;


	public:
		Item();
		Item(string, double, int);
		void setName(string);
		void setPrice(double);
		void setQuantity(int);
		string getName();
		double getPrice();
		int getQuantity();
};
#endif