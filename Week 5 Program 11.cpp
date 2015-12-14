/*********************************************************************
	Monthly Budget Screen Form

	A student  has established  the following monthly  budget:

	Housing												500.00
	Utilities											150.00
	Household expenses									65.00
	Transportation										50.00
	Food												250.00
	Medical												30.00
	Insurance											100.00
	Entertainment										150.00
	Clothing											75.00
	Miscellaneous										50.00

	Write a modular program that declares a MonthlyBudget structure with member variables to hold each
	of these expense categories.  The program should  create two MonthlyBudget structure variables.
	The first will hold the budget figures given above. The second will hold the  user-enter  amounts
	actually  spent  during  the  past  month.  Using Program  7-19  as a model,  the program should
	create a screen form that  displays each category  name and its budgeted  amount, then  positions
	the  cursor  next  to  it for  the  user  to  enter  the  amount actually spent in that category.
	Once the user data has all been entered, the program should compute  and display the amount over or
	under  budget  the student’s  expenditures were in each category,  as well as the amount over or under budget for the entire month.
*********************************************************************/
#include <iostream>
#include <Windows.h> // Needed to set cursor positions
using namespace std;

struct MonthlyBudget
{
	double housing, utilities, houseExpenses, transportation, food, medical, insurance, entertainment, clothing, miscellaneous;

	MonthlyBudget()
	{
		housing = utilities = houseExpenses = transportation = food, medical = insurance = entertainment = clothing = miscellaneous = 0;
	}
	MonthlyBudget(double a, double b, double c, double d, double e, double f, double g, double h, double i, double j)
	{
		housing = a;
		utilities = b;
		houseExpenses = c;
		transportation = d;
		food = e;
		medical = f;
		insurance = g;
		entertainment = h;
		clothing = i;
		miscellaneous = j;
	}
};




// Place cursors function
void placeCursor(HANDLE screen, int row, int col)
{
	COORD position;
	position.X = col;
	position.Y = row;

	SetConsoleCursorPosition(screen, position);
}



// Display function
void display(HANDLE screen, MonthlyBudget person, int total)
{
	placeCursor(screen, 3,10);
	cout << "Housing Cost $"<<person.housing <<": " << endl;
	placeCursor(screen, 5, 10);
	cout << "Utilities Cost $" << person.utilities << ": " << endl;
	placeCursor(screen, 7, 10);
	cout << "Household Expenses $" << person.houseExpenses << ": " << endl;
	placeCursor(screen, 9, 10);
	cout << "Transportation $" << person.transportation << ": " << endl;
	placeCursor(screen, 11, 10);
	cout << "Food $" << person.food << ": " << endl;
	placeCursor(screen, 13, 10);
	cout << "Medical $" << person.medical << ": " << endl;
	placeCursor(screen, 15, 10);
	cout << "Insurance $" << person.insurance << ": " << endl;
	placeCursor(screen, 17, 10);
	cout << "Entertainment $" << person.entertainment << ": " << endl;
	placeCursor(screen, 19, 10);
	cout << "Clothing $" << person.clothing << ": " << endl;
	placeCursor(screen, 21, 10);
	cout << "Miscellaneous $" << person.miscellaneous << ": " << endl;
	placeCursor(screen, 23, 10);
	cout << "Monthly Total $" << total << ": " << endl;
}



// User Input function
void input(HANDLE screen, MonthlyBudget& person)
{
	placeCursor(screen, 3, 35);
	cin >> person.housing;
	placeCursor(screen, 5, 35);
	cin >> person.utilities;
	placeCursor(screen, 7, 35);
	cin >> person.houseExpenses;
	placeCursor(screen, 9, 35);
	cin >> person.transportation;
	placeCursor(screen, 11, 35);
	cin >> person.food;
	placeCursor(screen, 13, 35);
	cin >> person.medical;
	placeCursor(screen, 15, 35);
	cin >> person.insurance;
	placeCursor(screen, 17, 35);
	cin >> person.entertainment;
	placeCursor(screen, 19, 35);
	cin >> person.clothing;
	placeCursor(screen, 21, 35);
	cin >> person.miscellaneous;
}



// Results function
void results(HANDLE screen, MonthlyBudget person1, MonthlyBudget person2, int total, int total2 )
{
	placeCursor(screen, 1, 40);
	cout << "Results" << endl;

	placeCursor(screen, 3, 40);
	if ((person1.housing - person2.housing) < 0)
	{
		cout << "You are over budget by " << person1.housing - person2.housing << endl;
	}
	else
	{
		cout << "You are under budget by " << person1.housing - person2.housing << endl;
	}
	placeCursor(screen, 5, 40);
	if ((person1.utilities - person2.utilities) < 0)
	{
		cout << "You are over budget by " << person1.utilities - person2.utilities << endl;
	}
	else
	{
		cout << "You are under budget by " << person1.utilities - person2.utilities << endl;
	}
	placeCursor(screen, 7, 40);
	if ((person1.houseExpenses - person2.houseExpenses) < 0)
	{
		cout << "You are over budget by " << person1.houseExpenses - person2.houseExpenses << endl;
	}
	else
	{
		cout << "You are under budget by " << person1.houseExpenses- person2.houseExpenses << endl;
	}
	placeCursor(screen, 9, 40);
	if ((person1.transportation - person2.transportation) < 0)
	{
		cout << "You are over budget by " << person1.transportation - person2.transportation << endl;
	}
	else
	{
		cout << "You are under budget by " << person1.transportation - person2.transportation << endl;
	}
	placeCursor(screen, 11, 40);
	if ((person1.food - person2.food) < 0)
	{
		cout << "You are over budget by " << person1.food - person2.food << endl;
	}
	else
	{
		cout << "You are under budget by " << person1.food - person2.food << endl;
	}
	placeCursor(screen, 13, 40);
	if ((person1.medical - person2.medical) < 0)
	{
		cout << "You are over budget by " << person1.medical - person2.medical << endl;
	}
	else
	{
		cout << "You are under budget by " << person1.medical - person2.medical << endl;
	}
	placeCursor(screen, 15, 40);
	if ((person1.insurance - person2.insurance) < 0)
	{
		cout << "You are over budget by " << person1.insurance - person2.insurance << endl;
	}
	else
	{
		cout << "You are under budget by " << person1.insurance - person2.insurance << endl;
	}
	placeCursor(screen, 17, 40);
	if ((person1.entertainment - person2.entertainment) < 0)
	{
		cout << "You are over budget by " << person1.entertainment - person2.entertainment << endl;
	}
	else
	{
		cout << "You are under budget by " << person1.entertainment - person2.entertainment << endl;
	}
	placeCursor(screen, 19, 40);
	if ((person1.clothing - person2.clothing) < 0)
	{
		cout << "You are over budget by " << person1.clothing - person2.clothing << endl;
	}
	else
	{
		cout << "You are under budget by " << person1.clothing - person2.clothing << endl;
	}
	placeCursor(screen, 21, 40);
	if ((person1.miscellaneous - person2.miscellaneous) < 0)
	{
		cout << "You are over budget by " << person1.miscellaneous - person2.miscellaneous << endl;
	}
	else
	{
		cout << "You are under budget by " << person1.miscellaneous - person2.miscellaneous << endl;
	}
	placeCursor(screen, 23, 35);
	cout << total2 << endl;
	placeCursor(screen, 23, 40);
	if ((total - total2) < 0)
	{
		cout << "Month over budget by " << total - total2 << endl;
	}
	else
	{
		cout << "Month under budget by " << total - total2 << endl;
	}
}

int main()
{
	MonthlyBudget person1(500, 150, 65, 50, 250, 30, 100, 150, 75, 50), person2;
	int total = 500 + 150 + 65 + 50 + 250 + 30 + 100 + 150 + 75 + 50;
	int total2 = 0;

	HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);

	display(screen, person1, total);
	input(screen, person2);
	total2 += person2.clothing + person2.entertainment + person2.food + person2.houseExpenses + person2.housing + person2.insurance + person2.medical + person2.miscellaneous + person2.transportation + person2.utilities;
	results(screen, person1, person2, total, total2);

	cout << endl;

	return 0;
}
