/*********************************************************************
	Bin Manager Class

	Design and write an object-oriented program for managing  inventory  bins in a warehouse. To  do  
	this  you  will use two  classes: InvBin and  BinManager. The  InvBin class holds information about 
	 a single bin. The BinManager class will own  and  manage  an array  of InvBin objects. Here is a 
	skeleton of what  the InvBin and BinManager class declarations should look like:


	Client Program

	Once you have created  these two  classes, write  a menu-driven client program that  uses a
	BinManager object to manage its warehouse  bins. It should initialize it to use 9 of the bins,
	holding  the following  item descriptions  and quantities. The bin index where the item will be
	stored is also show here.
	The modular client program should  have functions  to display  a menu,  get and  validate  the
	user’s choice, and carry out the necessary activities to handle that choice. This includes adding
	items to a bin, removing  items from  a bin, and  displaying  a report  of all bins. Think  about
	what calls the displayReport client function  will need to make to the BinManager object to create
	this  report.  When  the  user  chooses  the  “Quit” option  from  the  menu,  the  program should
	call its displayReport function  one last time to display the final bin information. All I/O should
	be done in the client class. The BinManager class only accepts information, keeps the array of
	InvBin objects up to date, and returns  information to the client program.
	objects up to date, and returns  information to the client program.

*********************************************************************/
#include <iostream>
#include <string>
using namespace std;

class InvBin
{
	private:
		string itemName;
		int itemAmount;

	public:
		InvBin(string name = "Empty", int x = 0)
		{
			itemName = name;
			itemAmount = x;
		}
		void setDescription(string name)
		{
			itemName = name;
		}
		void setAmount(int x)
		{
			itemAmount = x;
		}
		string getDescription()
		{
			return itemName;
		}
		int getAmount()
		{
			return itemAmount;
		}
};


class BinManager
{
	private:
		InvBin objects[30];
		int binNumber;

	public:
		BinManager()
		{
			binNumber = 0;
		}
		BinManager(int size, string name[], int amount[])
		{
			for (int x = 0; x < size; x++)
			{
				objects[x].setDescription(name[x]);
				objects[x].setAmount(amount[x]);
			}
		}
		string getDescription(int index)
		{
			return objects[index].getDescription();
		}
		int getAmount(int index)
		{
			return objects[index].getAmount();
		}
		bool addParts(int binIndex, int amount)
		{
			if (amount < 1)
			{
				return false;
			}
			else
			{
				objects[binIndex - 1].setAmount(objects[binIndex - 1].getAmount() + amount);
				return true;
			}
		}
		bool removeParts(int binIndex, int amount)
		{
			if (amount < 1 || amount > objects[binIndex-1].getAmount())
			{
				return false;
			}
			else
			{
				objects[binIndex - 1].setAmount(objects[binIndex - 1].getAmount() - amount);
				return true;
			}
		}
};





void displayMenu(BinManager objects)
{
	cout << endl << "Warehouse Menu" << endl;
	string line;
	cout << line.assign(45, '-') << endl;
	for (int x = 0; x < 9; x++)
	{
		cout << x + 1 << ". " << objects.getDescription(x) << endl;
	}
	cout << "10. Quit" << endl;
}
void displayReport(BinManager objects)
{
	for (int x = 0; x < 9; x++)
	{
		cout << "There are now " << objects.getAmount(x) << " " << objects.getDescription(x) << endl;
	}
}


int main()
{

	string items[9] = { "regular pliers", "n.nose pliers", "screwdrivers", "p.head screw driver", "wrench-large", "wrench-small", "drill", "cordless drill", "hand saw" };

	int amount[9] = { 25, 5, 25, 6, 7, 18, 51, 16, 12 };

	BinManager warehouse(9, items, amount);

	int choice, selection, quantity;

	do
	{
		displayMenu(warehouse);
		cin >> choice;

		switch (choice)
		{
			case 1: 
				cout << "Want do you want to do to the " << warehouse.getDescription(choice-1) << endl;
				cout << "1. ADD" << endl;
				cout << "2. REMOVE" << endl;
				cin >> selection;
				switch (selection)
				{
					case 1: 
						cout << "How many items do you want to add? ";
						cin >> quantity;
						warehouse.addParts(choice, quantity);
						break;

					case 2: 
						cout << "How many items do you want to remove? ";
						cin >> quantity;
						warehouse.removeParts(choice, quantity);
						break;
				}
				break;

			case 2:
				cout << "Want do you want to do to the " << warehouse.getDescription(choice-1) << endl;
				cout << "1. ADD" << endl;
				cout << "2. REMOVE" << endl;
				cin >> selection;
				switch (selection)
				{
				case 1:
					cout << "How many items do you want to add? ";
					cin >> quantity;
					warehouse.addParts(choice, quantity);
					break;

				case 2:
					cout << "How many items do you want to remove? ";
					cin >> quantity;
					warehouse.removeParts(choice, quantity);
					break;
				}
				break;

			case 3:
				cout << "Want do you want to do to the " << warehouse.getDescription(choice-1) << endl;
				cout << "1. ADD" << endl;
				cout << "2. REMOVE" << endl;
				cin >> selection;
				switch (selection)
				{
				case 1:
					cout << "How many items do you want to add? ";
					cin >> quantity;
					warehouse.addParts(choice, quantity);
					break;

				case 2:
					cout << "How many items do you want to remove? ";
					cin >> quantity;
					warehouse.removeParts(choice, quantity);
					break;
				}
				break;

			case 4:
				cout << "Want do you want to do to the " << warehouse.getDescription(choice-1) << endl;
				cout << "1. ADD" << endl;
				cout << "2. REMOVE" << endl;
				cin >> selection;
				switch (selection)
				{
				case 1:
					cout << "How many items do you want to add? ";
					cin >> quantity;
					warehouse.addParts(choice, quantity);
					break;

				case 2:
					cout << "How many items do you want to remove? ";
					cin >> quantity;
					warehouse.removeParts(choice, quantity);
					break;
				}
				break;

			case 5:
				cout << "Want do you want to do to the " << warehouse.getDescription(choice-1) << endl;
				cout << "1. ADD" << endl;
				cout << "2. REMOVE" << endl;
				cin >> selection;
				switch (selection)
				{
				case 1:
					cout << "How many items do you want to add? ";
					cin >> quantity;
					warehouse.addParts(choice, quantity);
					break;

				case 2:
					cout << "How many items do you want to remove? ";
					cin >> quantity;
					warehouse.removeParts(choice, quantity);
					break;
				}
				break;

			case 6:
				cout << "Want do you want to do to the " << warehouse.getDescription(choice-1) << endl;
				cout << "1. ADD" << endl;
				cout << "2. REMOVE" << endl;
				cin >> selection;
				switch (selection)
				{
				case 1:
					cout << "How many items do you want to add? ";
					cin >> quantity;
					warehouse.addParts(choice, quantity);
					break;

				case 2:
					cout << "How many items do you want to remove? ";
					cin >> quantity;
					warehouse.removeParts(choice, quantity);
					break;
				}
				break;

			case 7:
				cout << "Want do you want to do to the " << warehouse.getDescription(choice-1) << endl;
				cout << "1. ADD" << endl;
				cout << "2. REMOVE" << endl;
				cin >> selection;
				switch (selection)
				{
				case 1:
					cout << "How many items do you want to add? ";
					cin >> quantity;
					warehouse.addParts(choice, quantity);
					break;

				case 2:
					cout << "How many items do you want to remove? ";
					cin >> quantity;
					warehouse.removeParts(choice, quantity);
					break;
				}
				break;

			case 8:
				cout << "Want do you want to do to the " << warehouse.getDescription(choice-1) << endl;
				cout << "1. ADD" << endl;
				cout << "2. REMOVE" << endl;
				cin >> selection;
				switch (selection)
				{
				case 1:
					cout << "How many items do you want to add? ";
					cin >> quantity;
					warehouse.addParts(choice, quantity);
					break;

				case 2:
					cout << "How many items do you want to remove? ";
					cin >> quantity;
					warehouse.removeParts(choice, quantity);
					break;
				}
				break;


			case 9:
				cout << "Want do you want to do to the " << warehouse.getDescription(choice - 1) << endl;
				cout << "1. ADD" << endl;
				cout << "2. REMOVE" << endl;
				cin >> selection;
				switch (selection)
				{
				case 1:
					cout << "How many items do you want to add? ";
					cin >> quantity;
					warehouse.addParts(choice, quantity);
					break;

				case 2:
					cout << "How many items do you want to remove? ";
					cin >> quantity;
					warehouse.removeParts(choice, quantity);
					break;
				}
				break;

			case 10: 
				displayReport(warehouse);
				break;

			default: cout << "Enter a valid input" << endl;
		}
	} while (choice >= 1 && choice < 10);

	return 0;
}
