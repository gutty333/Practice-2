/*********************************************************************
	Rain or Shine

	An amateur meteorologist wants to keep track of weather  conditions during the past year’s three 
	month  summer season and has designated  each day as either rainy (‘R’), cloudy (‘C’), or sunny 
	(‘S’). Write a program that stores this information in a 3 × 30 array of characters, where  the  
	row  indicates  the  month  (0  = June,  1  = July,  2  = August)  and  the  column indicates  the 
	day of the month.  Note  that  data  is not  being collected  for the 31st  of any month.  The  
	program should  begin  by reading  the  weather  data  in from  a file. Then  it should create a 
	report  that displays for each month  and for the whole three-month period, how many days were 
	rainy,  how many were cloudy,  and how many were sunny.  It should also report  which of the three 
	months  had the largest number  of rainy days. Data  for the program can be found in the 
	RainOrShine.dat file.
*********************************************************************/
#include <iostream>
#include <fstream>
using namespace std;


int main()
{

	ifstream infile;
	infile.open("RainOrShine.dat");


	char data[3][30];


	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 30; col++)
		{
			infile >> data[row][col];
		}
	}

	infile.close();


	int rainy = 0, cloudy = 0, sunny = 0, count = 0, count2 = 0, count3 = 0;

	int total[3] = { 0 };


	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 30; col++)
		{
			if (data[row][col] == 'R')
			{
				rainy +=1;

				if (row == 0)
					count += 1;

				if (row == 1)
					count2 += 1;

				if (row == 2)
					count3 += 1;
			}
			else if (data[row][col] == 'C')
			{
				cloudy +=1;
			}
			else if (data[row][col] == 'S')
			{
				sunny +=1;
			}
		}

		total[0] += rainy;
		total[1] += cloudy;
		total[2] += sunny;

		if (row == 0)
		{
			cout << "The month of June had " << rainy << " rainy days, " << cloudy << " cloudy days, and " << sunny << " sunny days" << endl;
		}
		else if (row == 1)
		{
			cout << "The month of July had " << rainy << " rainy days, " << cloudy << " cloudy days, and " << sunny << " sunny days" << endl;
		}
		else if (row == 2)
		{
			cout << "The month of July had " << rainy << " rainy days, " << cloudy << " cloudy days, and " << sunny << " sunny days" << endl;
		}
		
		rainy = cloudy = sunny = 0;
	}

	cout << "In the three months there were " << total[0] << " rainy days, " << total[1] << " cloudy days, and " << total[2] << " sunny days" << endl;

	if (count > count2 && count > count3)
	{
		cout << "The month of June had the most rainy days" << endl;
	}
	else if (count2 > count && count2 > count3)
	{
		cout << "The month of July had the most rainy days" << endl;
	}
	else if (count3 > count && count3 > count2)
	{
		cout << "The month of August had the most rainy days" << endl;
	}


	

	return 0;
}