/*********************************************************************
	Validation Program

	For this project, you will write two functions: one named stringIsInt (string is int) and one named 
	stringIsFloat (string is float). stringIsInt() should take a C++ string parameter and 
	return true if that string represents a valid int value and false otherwise.  stringIsFloat() should take a C++ string 
	parameter and return true if that string represents a valid  floating-point value and false otherwise. 

	1)a string represents a valid int value if and only if it consists of (at most one) optional sign character (+ or -) 
	followed by a sequence of (at least one) decimal digits. Spaces at the front or end of the string should have no effect, 
	nor should spaces between a sign character and the first digit, but spaces between digits are not allowed. 
	No other characters are allowed (this is just for decimal values).

	2)a string represents a valid floating-point value if and only if it consists of (at most one) optional sign 
	character (+ or -) followed by a sequence of (at least one) decimal digits, optionally containing at most 
	one decimal point. The decimal point may appear before any digits, but must be followed by at least one digit. 
	Spaces at the front or end of the string should have no effect, nor should spaces between a sign character and 
	the first digit (or decimal point if it comes before any digits), but spaces between digits or between a digit 
	and a decimal point are not allowed. No other characters are allowed (this is just for decimal values).
*********************************************************************/
#include <iostream>
#include <cmath>
#include <string>
#include <cctype>
#include <vector>
using namespace std;


bool stringIsInt(string test)
{
	bool signCharacter = false, digit;
	int index, digitCount = 0, characterCount= 0;
	int size = test.size();
	vector <int> storeDigit;

	// Checking to see if other characters are included
	for (int x = 0; x < size; x++)
	{
		if (test[x] != '+' && test[x] != '-' && test[x] != ' ' && !isdigit(test[x]))
		{
			return false;
		}
	}

	// Checking for sign character
	for (int x = 0; x < size; x++)
	{
		if (test[x] == '+' || test[x] == '-')
		{
			characterCount++;
			signCharacter = true;
			index = x;
		}
	}

	if (characterCount > 1) // Only one sign character allowed
	{
		return false;
	}

	//Checking for decimal digits
	if (signCharacter)
	{
		for (index; index < size; index++)
		{
			if (isdigit(test[index]))
			{
				digitCount++;
				storeDigit.push_back(index);
			}
		}
	}

	// Checking for the decimal digit placement
	// If there is a space between digit, it will result in false
	if (digitCount == 1)
	{
		return true;
	}
	else if (digitCount > 1)
	{
		for (int y = 0; y < storeDigit.size()-1; y++)
		{
			digit = false;

			if (storeDigit[y] + 1 == storeDigit[y+1])
			{
				digit = true;
			}
			else
			{
				return false;
			}
		}

		if (digit)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

bool stringIsFloat(string test)
{
	bool signCharacter = false, digit;
	bool decimalPoint = false;
	int index, digitCount = 0, decimalCount = 0, characterCount = 0;
	int size = test.size();
	vector <int> storeDigit;

	// Checking to see if other characters are included
	for (int x = 0; x < size; x++)
	{
		if (test[x] != '+' && test[x] != '-' && test[x] != ' ' && test[x] != '.' && !isdigit(test[x]))
		{
			return false;
		}
	}

	// Checking for sign and decimal point
	for (int x = 0; x < size; x++)
	{
		if (test[x] == '+' || test[x] == '-')
		{
			characterCount++;
			signCharacter = true;
			index = x;
		}

		if (test[x] == '.')
		{
			decimalPoint = true;
			storeDigit.push_back(x);
			decimalCount++;
		}
	}
	if (characterCount > 1) // Only one sign character allowed
	{
		return false;
	}
	if (decimalCount > 1) // Only one decimal point allowed
	{
		return false;
	}
	if (decimalPoint) // Making sure decimal point is after the sign character
	{
		if (storeDigit[0] < index)
		{
			return false;
		}
	}

	//Checking for decimal digits
	if (signCharacter)
	{
		for (index; index < size; index++)
		{
			if (isdigit(test[index]))
			{
				digitCount++;
				storeDigit.push_back(index);
			}
		}
	}

	if (digitCount == 1)
	{
		return true;
	}
	else if (digitCount > 1)
	{
		// Checking for decimal digit placement and decimal point
		for (int y = 0; y < storeDigit.size() - 1; y++)
		{
			digit = false;

			// Condition in the case the decimal point is not at the start
			// EX 32.45
			if (storeDigit[y] > storeDigit[y + 1])
			{
				for (int z = y + 1; z < storeDigit.size() - 1; z++)
				{
					digit = false;

					if ((storeDigit[y] - storeDigit[z]) == 1)
					{
						if (storeDigit[z] + 2 == storeDigit[z + 1])
						{
							digit = true;
						}
						else
						{
							return false;
						}
					}
					else if (storeDigit[z] + 1 == storeDigit[z + 1])
					{
						digit = true;
					}
					else
					{
						return false;
					}
				}

				if (digit)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			// Condition in the case the decimal point is at the start
			// EX .3452  or .   4532
			else if (storeDigit[y] < storeDigit[y + 1])
			{
				for (int i = y + 1; i < storeDigit.size() - 1; i++)
				{
					digit = false;

					if (storeDigit[i] + 1 == storeDigit[i + 1])
					{
						digit = true;
					}
					else
					{
						return false;
					}
				}

				if (digit)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
		}
	}
}



int main()
{
	string test1= "fjasdl + 2321"; // F
	string test2 = "+34324"; // T
	string test3 = "     - 21548 "; // T
	string test4 = "+  4453 566";// F
	string test13 = "  +3432+"; // F
	string test14 = " -   +  123"; // F
	string test15 = " +2"; // T;

	string test5 = "fjasdl + 2.321"; // F
	string test6 = "-343.24";// T
	string test7 = "   .  - 21548 ";// F
	string test8 = "+  44.53 566";// F
	string test9 = "+  44.5356.6";// F
	string test10 = "  -  .543"; // T
	string test11 = "  + 435.  "; // T
	string test12 = "+332."; // T
	string test16 = "+33244"; // T
	string test17 = "- .  5"; // T
	string test18 = "  +  .   2758"; // T
	string test19 = "  +  345.  903"; // F

	cout << "Testing for Int" << endl;
	cout << stringIsInt(test1) << endl;
	cout << stringIsInt(test2) << endl;
	cout << stringIsInt(test3) << endl;
	cout << stringIsInt(test4) << endl;
	cout << stringIsInt(test13) << endl;
	cout << stringIsInt(test14) << endl;
	cout << stringIsInt(test15) << endl;

	cout << endl << endl << "Testing for Float" << endl;
	cout << stringIsFloat(test5) << endl;
	cout << stringIsFloat(test6) << endl;
	cout << stringIsFloat(test7) << endl;
	cout << stringIsFloat(test8) << endl;
	cout << stringIsFloat(test9) << endl;
	cout << stringIsFloat(test10) << endl;
	cout << stringIsFloat(test11) << endl;
	cout << stringIsFloat(test12) << endl;
	cout << stringIsFloat(test16) << endl;
	cout << stringIsFloat(test17) << endl;
	cout << stringIsFloat(test18) << endl;
	cout << stringIsFloat(test19) << endl;

	return 0;
}