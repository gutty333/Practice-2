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


int main()
{
	MonthlyBudget person1(500, 150, 65, 50, 250, 30, 100, 150, 75, 50), person2;









	return 0;
}
