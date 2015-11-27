/*********************************************************************
	In a program you need to store the names and populations of 12 countries.  Create an
	appropriate array to store this information and then write the code needed to read the information 
	into the array from a file named pop.dat.
*********************************************************************/
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Population
{
	string name;
	int population;
};


int main()
{
	Population test[12];

	ifstream infile;
	infile.open("pop.dat"); // Do not have the file

	for (int x = 0; x < 12; x++)
	{
		getline(infile, test[x].name);
		infile >> test[x].population;
	}

	infile.close();




	return 0;
}