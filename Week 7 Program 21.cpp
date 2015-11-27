/*********************************************************************
	A Caesar cipher is one in which all letters in the original message are shifted over the
	same number of spaces in the alphabet (wrapping back around if necessary).  For example, if the 
	original message is "Hello world.", and the offset is 4, then the enciphered message will be 
	"Lipps asvph."  You can assume that the message will be no longer than 50 characters.

	C-style strings are simply arrays of char with a null terminator. Write a function called
	encipher that takes a C-style string and an offset as parameters and prints out the enciphered form
	of the message.  Only letters should be shifted, but the case of letters should remain the same
	when shifted (you may want to revisit the character functions on page 205).
*********************************************************************/
#include <iostream>
#include <string>
using namespace std;

void encipher(string name, int offset)
{
	string newString = name;
	int convert;

	for (int x = 0; x < name.length(); x++)
	{
		if (newString[x] != ' ')
		{
			convert = static_cast<int>(newString[x]) + offset;
			if (convert > 90 && convert < 97)
			{
				convert -= 90;
				convert += 64;
			}
			else if(convert > 122 && convert < 127)
			{
				convert -= 122;
				convert += 96;
			}

			newString[x] = static_cast<char>(convert);
		}
	}

	for (int x = 0; x < newString.length(); x++)
	{
		cout << newString[x];
	}
	cout << endl;
}


int main()
{
	encipher("Hello World", 4);
	encipher("this is working just fine now", 4);
	encipher("please work", 2);
	encipher("abcdefghijklmnopqrstwvuxyz", 1);
	encipher("This should work okay", 0);
	encipher("New test ()", 2);


	return 0;
}

