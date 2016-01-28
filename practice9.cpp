/*********************************************************
Write a program that asks for a user first name and last name separately.
The program must then store the users full name inside a single string and out put it to the string.
i.e.
Input:
John
Smith
Output:
John Smith

Modify the program so that it then replaces every a, e, i , o, u w/ the letter z.
i.e.
John Smith -> Jzhn Smzth

Modify the Program so that it reverses the users name
i.e.
John Smith -> htimS nhoJ
********************************************************/

#include <iostream>
#include <string>
using namespace std;


string replace(string name)
{
	int size = name.size();

	for (int x = 0; x < size; x++)
	{
		if (name[x] == 'a' || name[x] == 'e' || name[x] == 'i' || name[x] == 'o' || name[x] == 'u')
		{
			name[x] = 'z';
		}
	}

	return name;
}

void reverse(string name)
{
	int size = name.size();
	size -= 1;

	for (size; size>=0; size--)
	{
		cout << name[size];
	}
	cout << endl;
}

int main()
{
	string first, last, full;

	cout << "Enter first name: ";
	cin >> first;
	cout << "Enter last name: ";
	cin >> last;
	full = first+ " "+ last;
	cout << endl << "Your full name is: " << full << endl;
	cout << full << " -> " << replace(full) << endl;
	cout << full << " -> ";
	reverse(full);


	return 0;
}