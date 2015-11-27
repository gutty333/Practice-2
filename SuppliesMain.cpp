/*********************************************************************
	Write a class named Supplies that keeps track of parts needed for a factory
	production line. There are three parts to keep track of, and Supplies should have a field
	for how many of each are in stock.  The three parts are thingamajigs, watchamacallits, and 
	framistats.  There should be set methods for each of the three fields.  There should be a 
	constructor that takes three int parameters and calls the set methods to initialize the number of 
	each part in stock.  There should be a default constructor that uses the set methods to initialize 
	the amounts in stock to 100 thingamajigs, 70 watchamacallits, and 50 framistats. When the factory 
	orders more supplies, they want to order each part
	back up to the default amounts.  The class should have a method called printPartsOrder
	that will print out how many of each part need to be ordered to bring what's in stock up
	to those amounts.  For example, if the factory currently has 40 thingamajigs, 24 watchamacallits 
	and 12 framistats, then if printPartsOrder is called, it should print that the factory needs to 
	order 60 thingamajigs, 46 watchamacallits and 38
	framistats. There are two products this factory makes: doodad1 and doodad2. Producing a doodad1 
	uses 1 thingamajig, 2 watchamacallits and 1
	framistat. Producing a doodad2 uses 2 thingamajigs and 1 framistat.  You should have methods called 
	produceDoodad1 and produceDoodad2 that each take as a parameter how many are produced and updates 
	the parts in stock.  So for example, if the factory has the default amounts of all three parts and 
	then makes 20 of doodad1, then it will have 80 thingamajigs, 30 watchamacallits, and 30 framistats 
	left in stock.

	Write a main method (in the .cpp file) that asks the user how many of each part the factory 
	currently has in stock.  It should then allow the user to choose whether to produce doodad1, 
	produce doodad2, print a parts order, or quit.  If they choose to produce doodad1 or doodad2, 
	prompt them for how many to make, call the appropriate method and loop back to the user menu.  If 
	they print a parts order, call the appropriate method and loop back to the menu.  If they quit, the 
	program should end.
*********************************************************************/
#include <iostream>
#include <string>
#include "Supplies.h"
using namespace std;

int main()
{

	int things, watch, frames, choice;
	string line;

	cout << "How many things does the factory have in stock? ";
	cin >> things;
	cout << "How many watches does the factory have in stock? ";
	cin >> watch;
	cout << "How many frames does the factory have in stock? ";
	cin >> frames;

	Supplies store(things, watch, frames);


	do
	{
		cout << endl << endl << "Store Menu" << endl;
		cout << line.assign(40, '-') << endl;
		cout << "1. Produce doodad1" << endl;
		cout << "2. Produce doodad2" << endl;
		cout << "3. Print Report" << endl;
		cout << "4. Quit" << endl;
		cin >> choice;

		switch (choice)
		{
			case 1:
				int amount;
				cout << "How many do you want to produce? ";
				cin >> amount;

				store.produce1(amount);
				break;

			case 2:
				int amount2;
				cout << "How many do you want to produce? ";
				cin >> amount2;

				store.produce2(amount2);
				break;

			case 3:
				store.printPartsOrder();
				break;

			case 4:
				cout << "Thank you for stopping by, come again!" << endl;
				break;

			default:
				cout << "Enter a valid input" << endl;
		}
	} while (choice >= 1 && choice < 4);
	

	return 0;
}