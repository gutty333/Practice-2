/*********************************************************************
	In a program you need to store the identification numbers  of 10 employees (as ints)
	and their weekly gross pay (as doubles).
	A)  Define  two   arrays   that   may  be  used  in  parallel   to  store   the  10  employee 
	identification numbers  and 10 weekly gross pay amounts.
	B)   Write a loop that uses these arrays to print each employee’s identification number
	and weekly gross pay.


	Revise your answer for question 33 to define and use an array of Payroll structures,
	instead of two parallel arrays. A Payroll structure should hold an employee ID and
	weekly gross pay amount.
*********************************************************************/
#include <iostream>
using namespace std;

struct Payroll
{
	int iD;
	double rate;
};


int main()
{

	const int size = 10;

	int iD[size] = { 48785, 5651, 8488, 35617, 54412, 878, 1545, 545487, 1215, 45477 };
	double rate[size] = {25.35,41.2,58.23,20.54,12.36,18.02,69.35,74.25,36.25,48.21};



	Payroll test1[size];

	for (int x = 0; x < size; x++)
	{
		test1[x].iD = iD[x];
		test1[x].rate = rate[x];
		cout << x + 1 << ") Test is " << test1[x].iD << " and also " << test1[x].rate << endl;
	}






	for (int x = 0; x < size; x++)
	{
		cout << x + 1 << ". Employees ID is " << iD[x] << " and the gross pay is $" << rate[x] << endl;
	}



	return 0;
}