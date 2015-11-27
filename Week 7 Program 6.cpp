/*********************************************************************
	Roman Numeral  Converter

	Write  a program that  displays  the  roman  numeral  equivalent  of any  decimal  number between
	1 and  20  that  the  user  enters.  The  roman  numerals  should  be stored  in an array  of
	strings  and  the decimal  number  that  the user enters  should  be used to locate the array
	element  holding  the roman  numeral  equivalent.  The program should  have a loop  that  allows
	the  user  to  continue  entering  numbers  until  an  end  sentinel  of 0 is
	entered.
*********************************************************************/
#include <iostream>
#include <string>
using namespace std;


void roman(double number)
{
	string test[] = { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", "X", "XI", "XII", "XIII", "XIV", "XV", "XVI", "XVII", "XVIII", "XIV", "XX" };

	cout << test[static_cast<int>(number)] << endl;
}


int main()
{
	double number;

	

	do
	{
		cout << "Enter a number: ";
		cin >> number;

		roman(number);

	} while (number != 0);





	return 0;
}
