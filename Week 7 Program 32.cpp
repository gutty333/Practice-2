/*********************************************************************
	Using Files—String Selection Sort Modification

	Modify  the program you wrote  for Programming Challenge  6 so it reads in the 20 strings from a 
	file. The data can be found in the names.dat file.



	Using Vectors—String Selection Sort Modification

	Modify  the program you wrote  for Programming Challenge  13 so it stores the names in a vector of
	strings, rather  than  in an array  of strings. Create  the vector without specifying a size and
	then use the push_back member function  to add an element holding each string to the vector as it
	is read in from a file. Instead  of assuming there are always 20 strings, read in the strings and
	add them to the vector until there is no data  left in the file. The data  can be found in the
	names.dat file.
*********************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


// Display Method
void display(string array[], int size)
{
	for (int x = 0; x < size; x++)
	{
		cout << array[x] << endl;
	}
}
void display(vector <string> names)
{
	for (int x = 0; x < names.size(); x++)
	{
		cout << names[x] << endl;
	}
}



// Selection Sort
void selectionSort(string array[], int size)
{
	string name;
	int index;


	for (int x = 0; x < size - 1; x++)
	{
		index = x;
		name = array[x];

		for (int y = x + 1; y < size; y++)
		{
			if (array[y] < name)
			{
				index = y;
				name = array[y];
			}
		}
		array[index] = array[x];
		array[x] = name;
	}
}
void selectionSort(vector <string>& names)
{
	string name;
	int index;


	for (int x = 0; x < names.size() - 1; x++)
	{
		index = x;
		name = names[x];

		for (int y = x + 1; y < names.size(); y++)
		{
			if (names[y] < name)
			{
				index = y;
				name = names[y];
			}
		}
		names[index] = names[x];
		names[x] = name;
	}
}




int main()
{

	string names[20];
	vector <string> names2;
	string store;
	string line;
	line.assign(20, '-');


	ifstream infile("names.dat");

	

	while (getline(infile, store))
	{
		names2.push_back(store);
	}

	infile.clear();
	infile.seekg(0, ios::beg);

	for (int x = 0; x < 20; x++)
	{
		getline(infile, names[x]);
	}


	cout << "Original" << endl;
	cout << line << endl;
	display(names, 20);
	cout << endl << "Original Vector" << endl;
	cout << line << endl;
	display(names2);

	cout << endl << endl << "Selection Sort" << endl;
	cout << line << endl;
	selectionSort(names, 20);
	selectionSort(names2);
	display(names, 20);
	cout << endl << "Selection Sort Vector" << endl;
	cout << line << endl;
	display(names2);


	infile.close();

	return 0;
}