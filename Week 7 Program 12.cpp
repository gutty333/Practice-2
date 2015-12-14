/*********************************************************************
	Stats Class and Rainfall  Statistics

	Create  a Stats class whose member  data  includes an array  capable  of storing  30 double data  
	values, and whose member functions  include total, average, lowest, and highest functions  for 
	returning information about  the data to the client program. These are general versions  of the  
	same functions  you created  for Programming Challenge  7, but  now  they belong to the Stats 
	class, not the application program. In addition to these functions,  the Stats class should have a 
	Boolean storeValue function  that accepts a double value from the client program and stores it in 
	the array.  It is the job of this function  to keep track  of how many values are currently  in the 
	array,  so it will know  where to put the next value it receives and  will know  how  many  values 
	there  are to process  when  it is carrying  out  its other functions.  It is also the job of this 
	function  to make sure that no more than 30 values are accepted.  If the storeValue function  is 
	able to successfully store the value sent to it, it should  return  true to the client program. 
	However,  if the client program tries to store  a thirty-first value, the function  should  not  
	store  the value and  should  return  false to the client program.
	The client program should  create  and  use a Stats object  to carry  out  the  same rainfall 
	analysis requested  by Programming Challenge 7. Notice that the Stats object does no I/O. All input 
	and output is done by the client program.

	
	Stats Class and Track Statistics

	Write a client program that uses the Stats class you created for Programming Challenge 9 to  store
	and  analyze  “best” 100-yard dash  times  for  each  of the  15  runners  on  a track team. As in
	Programming Challenge 8, all I/O is done by the client program. In addition to main, the client
	program should  have two  other  functions:  a getData function  to accept input  from  the  user
	and  send  it to the Stats object  and  a createReport function  that creates and displays a report
	similar to the one shown here,

	Tulsa Tigers Track Team
	Average 100 yard-dash time: 11.16 seconds 
	Slowest runner: Jack        13.09 seconds 
	Fastest runner: Will        10.82 seconds
*********************************************************************/

#include <iostream>
using namespace std;


class Stats
{
	private:
		double data[15];

	public:
		Stats();
		double total();
		double average();
		double lowest();
		double highest();
		bool storeValue(double);
};


// Constructor
Stats::Stats()
{
	for (int x = 0; x < 15; x++)
	{
		data[x] = 0;
	}
}

// Total member function
double Stats::total()
{
	double total = 0;

	for (int x = 0; x < 15; x++)
	{
		total += data[x];
	}

	return total;
}

// Average member function
double Stats::average()
{
	double total = 0;

	for (int x = 0; x < 15; x++)
	{
		total += data[x];
	}

	return total /15;
}

// Lowest member function
double Stats::lowest()
{
	double lowest = data[0];

	for (int x = 0; x < 15; x++)
	{
		if (data[x] < lowest)
		{
			lowest = data[x];
		}
	}

	return lowest;
}


// Highest member function
double Stats::highest()
{
	double highest = data[0];

	for (int x = 0; x < 15; x++)
	{
		if (data[x] > highest)
		{
			highest = data[x];
		}
	}

	return highest;
}



// Store value member function
bool Stats::storeValue(double value)
{

	for (int x = 0; x < 15; x++)
	{
		if (data[x] == 0)
		{
			data[x] = value;

			if (x == 14)
			{
				return false;
			}
			else
			{
				return true;
			}
		}
	}

	return false;
}




// Functions for the second requirement
void getData(Stats& runners)
{
	double value;

	do
	{
		cout << "Enter a runner speed: ";
		cin >> value;

	} while (runners.storeValue(value));
}
void createReport(Stats runners)
{
	cout << endl << "Tulsa Tigers Track Team" << endl << endl;
	cout << "Average 100 yard-dash time: " << runners.average() << " seconds" << endl;
	cout << "Slowest runner: " << runners.lowest() << " seconds" << endl;
	cout << "Fastest runner: " << runners.highest() << " seconds" << endl;
}



int main()
{
	Stats test;
	Stats runners;
	
	
	double value;

	do
	{
		cout << "Enter a value to store: ";
		cin >> value;

	} while (test.storeValue(value));
	cout << "Total: " << test.total() << endl;
	cout << "Average: " << test.average() << endl;
	cout << "The lowest value: " << test.lowest() << endl;
	cout << "The highest value: " << test.highest() << endl;



	cout << endl << endl;


	// Second Requirement
	getData(runners);
	createReport(runners);


	return 0;
}