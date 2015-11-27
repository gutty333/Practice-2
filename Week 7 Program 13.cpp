/*********************************************************************
	Character  Converter  Class

	Create  a CharConverter class that  performs  various  operations on strings. It should  have the 
	following  two public member  functions  to start  with.  Your instructor may ask you to add 
	additional functions  to the class.

	• The uppercase member  function  accepts  a string  and  returns  a copy of it with  all lowercase 
	letters converted  to uppercase.  If a character is already uppercase,  or is not a letter, it 
	should be left alone.
	• The  properWords member  function  accepts  a string  of words  separated by spaces and returns  
	a copy of it with the first letter of each word converted  to uppercase.

	Write  a simple program that  uses the class. It should  prompt the user to input  a string. Then 
	it should  call the properWords function  and display the resulting  string. Finally, it should   
	call  the  uppercase function   and  display  this  resulting   string.  The  program should  loop  
	to  allow  additional strings  to  be  converted   and  displayed  until  the  user
	chooses to quit.
*********************************************************************/
#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>
using namespace std;


class CharConverter
{
	public:
		string upperCase(string);
		string lowerCase(string);
		string properWord(string);
};
/*********************************************************************/
string CharConverter::upperCase(string name)
{ 

	for (int x = 0; x < name.length(); x++)
	{
		name[x] = toupper(name[x]);
	}

	return name;
}
string CharConverter::lowerCase(string name)
{
	for (int x = 0; x < name.length(); x++)
	{
		name[x] = tolower(name[x]);
	}

	return name;
}
string CharConverter::properWord(string name)
{
	int spaces;

	for (int x = 0; x < name.length(); x++)
	{
		
		if (x == 0)
		{
			name[x] = toupper(name[x]);
		}

		if (name[x] == ' ')
		{
			name[x+1] = toupper(name[x+1]);
		}
		else
		{
			name[x] = name[x];
		}
	}

	return name;
}


int main()
{
	string name;
	CharConverter test;

	do
	{
		cout << "Enter a string:(-1 to quit) ";
		getline(cin, name);

		if (name != "-1")
		{
			cout << "Proper Words: " << test.properWord(name) << endl;
			cout << "Upper Case: " << test.upperCase(name) << endl;
			cout << "Lower Case: " << test.lowerCase(name) << endl;
		}
		
	} while (name != "-1");


	return 0;
}