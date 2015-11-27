/********************************************************
	String Compare

	You  know  that  the  == operator can  be  used  to  test  if two  string objects  are  equal. 
	However,  you will recall that they are not considered  equal, even when they hold the exact same 
	letters,  if the cases of any letters are different.  So, for example,  if name1 = "Jack" and  
	name2 = "JACK", they are not  considered  the same. Write  a program that  asks the user to enter 
	two names and stores them in string objects. It should  then report  whether or not, ignoring case, 
	they are the same.

	To help the program accomplish  its task,  it should  use two functions  in addition to main,
	upperCaseIt() and sameString(). Here are their function  headers.
	string upperCaseIt(string s)
	Boolean sameString (string s1, string s2)

	The sameString function,  which receives the two strings to be compared, will need to call 
	upperCaseIt for  each  of  them  before  testing  if they  are  the  same.  The  upperCaseIt 
	function  should  use a loop so that  it can call the toupper function  for every character in the 
	string it receives before returning it back to the sameString function.
**********************************************************/
#include <iostream>
#include <string>
#include <cctype>
using namespace std;


string upperCaseIt(string name)
{
	for (int x = 0; x <= name.length(); x++)
	{
		name[x] = toupper(name[x]);
	}

	return name;
}


bool samestring(string name1, string name2)
{
	if (upperCaseIt(name1) == upperCaseIt(name2))
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
	string name1, name2;

	cout << "Write any name: ";
	getline(cin, name1);

	cout << "Write another name: ";
	getline(cin, name2);


	
	if (samestring(name1, name2))
	{
		cout << "The names are the same" << endl;
	}
	else
	{
		cout << "The names are not the same" << endl;
	}
	


	return 0;
}
