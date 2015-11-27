/********************************************************
	Population

	In a population, the birth  rate  is the percentage  increase  of the population due to births, and 
	 the  death  rate  is the  percentage  decrease  of the  population due  to  deaths.  Write  a 
	program that asks for the following:
	• The starting  size of a population (minimum 2)
	• The annual  birth rate
	• The annual  death rate
	• The number  of years to display (minimum  1)
	The program should  then display the starting  population and the projected  population at the end 
	of each year. It should use a function  that calculates and returns  the projected  new size of the 
	population after a year. The formula  is

	N = P(1 + B)(1 - D)

	where N is the new population size, P is the previous population size, B is the birth rate, and D 
	is the death  rate.  Annual  birth  rate and death  rate are the typical number  of births  and 
	deaths  in a year  per  1000  people,  expressed  as a decimal.  So, for  example,  if there  are 
	normally  about  32 births  and 26 deaths  per 1000  people in a given population, the birth
	rate would be .032 and the death rate would be .026.


	Transient  Population

	Modify  Programming Challenge  15 to also consider  the effect on population caused  by people
	moving  into  or  out  of a geographic  area.  Given  as input  a starting  population size, the
	annual  birth rate, the annual  death rate, the number  of individuals  that typically move into
	the area each year, and the number  of individuals  that  typically leave the area each year, the
	program should  project  what  the population will be numYears from now. You can either  prompt the
	user to input  a value for numYears, or you can set it within
	the program.
**********************************************************/
#include <iostream>
using namespace std;


void getInfo(int& size, double& birth, double& death, int& year)
{
	cout << "What are the starting population size? ";
	cin >> size;
	while (size < 2)
	{
		cout << "The starting population must be greater than 2, enter a number again: ";
		cin >> size;
	}


	cout << "What is the annual birth rate? ";
	cin >> birth;

	cout << "What is the annual death rate? ";
	cin >> death;

	cout << "For how many years do you want your result? ";
	cin >> year;
	while (year < 1)
	{
		cout << "The year must be greater than 1, enter a number again:	";
		cin >> year;
	}
}


void result(int size, double birth, double death, int year)
{
	
	birth /= 1000;
	death /= 1000;
	int newPopulation = size * (1 + birth) * (1 - death);
	int moveIn, moveOut, total = 0;

	for (int x = 1; x <= year; x++)
	{
		cout << "How many people will move in and out on year " << x << " ";
		cin >> moveIn >> moveOut;

		total = moveIn - moveOut;

		cout << "For year " << x << " the population will be " << newPopulation + total<< endl;
		newPopulation = (newPopulation+total) * (1 + birth) * (1 - death);
	}
}




int main()
{
	int size, year;
	double birth, death;

	getInfo(size, birth, death, year);

	result(size, birth, death, year);

	return 0;
}