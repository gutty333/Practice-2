/********************************************************
	Celsius Temperature Table

	The formula  for converting  a temperature from Fahrenheit  to Celsius is
	C = 5/9(F-32)
	Where F is the Fahrenheit  temperature and C is the Celsius temperature. 
	Write a function named Celsius that  accepts  a  Fahrenheit   temperature as  an  argument. 
	The  function should  return the temperature, converted  to Celsius. 
	Demonstrate the function  by calling it in a loop  that displays  a table  of the  Fahrenheit  temperatures 0 through 20  and  their Celsius equivalents.
**********************************************************/
#include <iostream>
#include <iomanip>
using namespace std;

double Celsius(double x)
{
	return (5 / 9.0)*(x - 32);
}


int main()
{
	cout << fixed << setprecision(2);

	for (int x = 0; x <= 20; x++)
	{
		cout << "When Fahrenheit is " << x << " Celsius is " << Celsius(x) << endl;
	}

	return 0;
}