/*********************************************************************
	Array of Payroll Objects

	Design a PayRoll class that  has  data  members  for  an  employee’s hourly  pay  rate  and number  
	of hours  worked.  Write a program with an array  of seven PayRoll objects. The program should  
	read  the number  of hours  each employee  worked  and  their  hourly  pay rate  from  a  file and  
	call  class  functions   to  store  this  information in  the  appropriate objects. It should then 
	call a class function,  once for each object, to return  the employee’s gross pay, so this 
	information can be displayed.  Sample data  to test this program can be found  in the payroll.dat 
	file.
*********************************************************************/
#include <iostream>
#include <fstream>
using namespace std;

class Payroll
{
	private:
		double hours;
		double rate;


	public:
		Payroll()
		{
			hours = 0;
			rate = 0;
		}
		void setHour(double x)
		{
			hours = x;
		}
		void setRate(double y)
		{
			rate = y;
		}
		int getHour()
		{
			return hours;
		}
		double getRate()
		{
			return rate;
		}
		double pay()
		{
			return hours * rate;
		}
};




int main()
{


	Payroll workers[7];

	ifstream infile;
	infile.open("payroll.dat");
	


	for (int x = 0; x < 7; x++)
	{
		double hour;
		double rate;

		infile >> hour;
		infile >> rate;
		
		workers[x].setHour(hour);
		workers[x].setRate(rate);
	}

	infile.close();


	for (int x = 0; x < 7; x++)
	{
		cout << "The gross pay of employee " << x + 1 << " is $" << workers[x].pay() << endl;
	}

	return 0;
}