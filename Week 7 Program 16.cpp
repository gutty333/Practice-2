/*********************************************************************
	Drink  Machine  Simulator

	Create a class that simulates and manages a soft drink machine. Information on each drink type 
	should  be stored  in a structure that  has data  members  to hold  the drink  name,  the drink 
	price, and the number  of drinks of that type currently  in the machine.

	The class should have an array of five of these structures, initialized with the following data.

	Drink Name                     Cost					Number in Machine
	Cola                           1.00					20
	Root beer                      1.00					20
	Orange  soda                   1.00					20
	Grape soda                     1.00					20
	Bottled water                  1.50					20


	The class should  have two  public  member  functions,  displayChoices (which  displays  a menu of 
	drink  names and prices) and buyDrink (which  handles  a sale). The class should also have at least 
	two private member functions,  inputMoney, which is called by buyDrink to accept,  validate,  and  
	return  (to buyDrink) the amount of money  input,  and dailyReport, which  is called by the 
	destructor to report  how  many  of each drink  type remain in the machine at the end of the day 
	and how much money was collected. You may want to use additional functions  to make the program 
	more modular.

	The client program that  uses the class should  have a main processing  loop which calls the 
	displayChoices class member  function  and  allows  the patron to either  pick a drink  or quit  
	the  program. If the  patron selects a drink,  the  buyDrink class member  function  is called to 
	handle  the actual  sale. This function  should  be passed the patron’s  drink  choice. Here is 
	what the buyDrink function  should do:

	• Call the inputMoney function,  passing it the patron’s  drink choice.
	• If the patron no longer wishes to make the purchase, return  all input money.
	• If  the  machine  is  out  of  the  requested   soda,  display  an  appropriate “sold  out”
	message and return  all input money.
	• If the  machine  has  the  soda  and  enough  money  was  entered,  complete  the  sale by 
	updating the  quantity on  hand  and  money  collected  information, calculating  any change due to 
	be returned to the patron, and delivering the soda. This last action can
	be simulated  by printing  an appropriate “here is your beverage”  message.
*********************************************************************/
#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>
using namespace std;

struct Drinks
{
	string name;
	double cost;
	int number;
};


class Simulation
{
	private:
		Drinks softDrink[5];
		double money;
		bool enoughMoney;
		int amount;
		double total;
		void dailyReport();
		void inputMoney(int);

	public:
		Simulation();
		void setMoney(double);
		void displayChoices();
		void buyDrink(int);
		~Simulation();


};
/*********************************************************************/
Simulation::Simulation()
{
	for (int x = 0; x < 5; x++)
	{
		if (x == 4)
		{
			softDrink[x].cost = 1.50;
		}
		else
		{
			softDrink[x].cost = 1.00;
		}
		
		softDrink[x].number = 20;
	}

	softDrink[0].name = "Cola";
	softDrink[1].name = "Root-beer";
	softDrink[2].name = "Orange soda";
	softDrink[3].name = "Grape soda";
	softDrink[4].name = "Bottled water";

	money = 0.0;
	amount = 0;
	total = 0.0;
}
void Simulation::displayChoices()
{
	for (int x = 0; x < 5; x++)
	{
		cout << x + 1 << " " << softDrink[x].name << ": $" << softDrink[x].cost << endl;
	}
}
void Simulation::inputMoney(int choice)
{
	cout << "The cost for " << softDrink[choice - 1].name << " is $" << softDrink[choice - 1].cost << endl;
	cout << "How much money will you insert? ";
	cin >> money;

	if (money < softDrink[choice - 1].cost)
	{
		cout << "Can not deliver beverage, not enough money" << endl;
		enoughMoney = false;
	}
	else
	{
		enoughMoney = true;
	}
}
void Simulation::buyDrink(int choice)
{
	char purchaseChoice;

	inputMoney(choice);

	if (enoughMoney)
	{

		cout << "Do you want to make a purchase for this drink?(Y/N) ";
		cin >> purchaseChoice;
		while (toupper(purchaseChoice) != 'Y' && toupper(purchaseChoice) != 'N')
		{
			cout << "Please enter correct input, purchase drink (Y/N)? ";
			cin >> purchaseChoice;
		}


		if (toupper(purchaseChoice) == 'Y')
		{
			if (softDrink[choice-1].number <= 0)
			{
				cout << "We are sold out" << endl;
				cout << "Here is your money back $" << money << endl;
			}
			else
			{
				cout << "Here is your beverage" << endl;
				total += softDrink[choice - 1].cost;
				softDrink[choice - 1].number -= 1;
			}
			

			if (money > softDrink[choice - 1].cost)
			{
				money -= softDrink[choice - 1].cost;
				cout << "Here is your change $" << money << endl;
			}
		}
		else
		{
			cout << "Here is your money back $" << money << endl;
		}
	}
}
Simulation::~Simulation()
{
	for (int x = 0; x < 5; x++)
	{
		cout << "There are " << softDrink[x].number << " " << softDrink[x].name << " left in the machine" << endl;
	}

	cout << "The total amount of money collected during the day is $" << total << endl;
}


/*********************************************************************/
int main()
{
	int choice;
	string line;
	Simulation machine;

	cout << fixed << setprecision(2);

	do
	{
		cout << endl << "Select a drink below or enter -1 to quit" << endl;
		cout << line.assign(40, '-') << endl;
		machine.displayChoices();
		cin >> choice;

		switch (choice)
		{
			case 1: machine.buyDrink(choice);
					break;

			case 2:	machine.buyDrink(choice);
					break;

			case 3:	machine.buyDrink(choice);
					break;


			case 4:	machine.buyDrink(choice);
					break;

			case 5:	machine.buyDrink(choice);
					break;

			default: cout << endl << "Please enter a valid choice!" << endl << endl;
		}
	} while (choice != -1 && choice >= 1 && choice <= 5);


	return 0;
}