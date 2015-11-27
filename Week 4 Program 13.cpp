/********************************************************
	Overloaded  Hospital

	Write a program that computes  and displays the charges for a patient’s hospital  stay. First, the 
	program should ask if the patient  was admitted as an in-patient or an out-patient. If the patient  
	was an in-patient the following data should be entered:
	• The number  of days spent in the hospital
	• The daily rate
	• Charges for hospital  services (lab tests, etc.)
	• Hospital medication charges.
	If the patient  was an out-patient the following data should be entered:
	• Charges for hospital services (lab tests, etc.)
	• Hospital medication charges.
	Use a single, separate  function  to validate  that  no input  is less than  zero. If it is, it 
	should be re-entered  before being returned.

	Once  the  required   data   has  been  input   and  validated,   the  program  should   use  two 
	overloaded functions  to  calculate  the  total  charges.  One  of the  functions  should  accept 
	arguments  for  the  in-patient data,  while  the  other  function  accepts  arguments  for  out-
	patient  data.  Both functions  should return  the total charges.


	Using Files—Hospital Report

	Modify Programming Challenge 14, Overloaded Hospital, to write the report it creates to
	a file. Print the contents of the file to hand in to your instructor.
**********************************************************/
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <fstream>
using namespace std;

void info(int& choice, double& charges, double& medicalCharges, int& day, double& rate)
{
	cout << "Are you an in-patient of out-patient?" << endl;
	cout << setw(5) << "" << "1) In-patient" << endl;
	cout << setw(5) << "" << "2) Out-patient" << endl;
	cin >> choice;

	string line;

	if (choice == 1)
	{
		cout << "In-Patient" << endl;
		cout << line.assign(35, '-') << endl;
		cout << "How many days did you spent in the hospital? ";
		cin >> day;
		cout << "What was the daily rate at the hospital? ";
		cin >> rate;
		cout << "What are the charges for the hospital services? ";
		cin >> charges;
		cout << "What are the hospital medical charges? ";
		cin >> medicalCharges;
	}
	else if (choice == 2)
	{
		cout << "Out-Patient" << endl;
		cout << line.assign(35, '-') << endl;
		cout << "What are the charges for the hospital services? ";
		cin >> charges;
		cout << "What are the hospital medical charges? ";
		cin >> medicalCharges;
		day = rate = 0;
	}
	else
	{
		cout << "Please select a correct choice" << endl;
		exit(0);
		
	}
}


// Trying this step with arrays instead
void validate(int& day, double& rate, double& charges, double& medicalCharges)
{
	string name[4] = { "date", "rate", "charges", "medical charges" };
	double validate[4] = { day, rate, charges, medicalCharges };


	for (int x = 0; x < 4; x++)
	{
		if (validate[x] < 0)
		{
			cout << "Please enter a positive number for the " << name[x] << endl;
			cin >> validate[x];
		}
	}

	day = validate[0];
	rate = validate[1];
	charges = validate[2];
	medicalCharges = validate[3];

}


double calculate(double charges, double medicalCharges)
{
	return charges + medicalCharges;
}
double calculate(int day, double rate, double charges, double medicalCharges)
{
	return (day * rate) + charges + medicalCharges;
}



int main()
{
	ofstream outfile;
	outfile.open("report.txt");

	int day, choice;
	double rate, charges, medicalCharges;

	info(choice, charges, medicalCharges, day, rate);

	validate(day, rate, charges, medicalCharges);

	if (choice == 1)
	{
		cout << "Your total is $" << calculate(day, rate, charges, medicalCharges) << endl;
		outfile << "Your total is $" << calculate(day, rate, charges, medicalCharges) << endl;
	}
	else
	{
		cout << "You total is $" << calculate(charges, medicalCharges) << endl;
		outfile << "You total is $" << calculate(charges, medicalCharges) << endl;
	}

	outfile.close();

	return 0;
}