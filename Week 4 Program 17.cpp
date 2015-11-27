/********************************************************
	3) Write a function that takes a string as a parameter and returns true if that string is a 
	palindrome and returns false otherwise (a palindrome is a string that reads the same forward and backward, like "racecar").
**********************************************************/
#include <iostream>
#include <string>
#include <cctype>
using namespace std;


bool test(string& name)
{
	cout << "Enter a string: ";
	getline(cin, name);

	int length = name.length();
	string newName;

	for (length; length >= 0; length--)
	{
		
		newName += name[length];
	}
	
	newName = newName.erase(0, 1);

	if (newName == name)
	{
		return true;
	}
	else
	{
		return false;
	}

}


int main()
{
	string name;

	cout << test(name) << endl;
	cout << test(name) << endl;
	cout << test(name) << endl;
	cout << test(name) << endl;
	cout << test(name) << endl;
	cout << test(name) << endl;
	cout << test(name) << endl;

	return 0;
}