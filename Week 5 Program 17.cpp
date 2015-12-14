/*********************************************************************
	Patient Fees

	This program should be designed and written by a team of students. Here are some suggestions:
	• One or more students may work on a single class.
	• The requirements of the program should be analyzed so each student is given about the same workload.
	• The names, parameters, and return types of each function and class member function should be decided in advance.
	• The program will be best implemented as a multifile program.
	
	Write a program that computes a patient’s bill for a hospital stay. The different components
	of the program are
	• The PatientAccount class will keep a total of the patient’s charges. It will also keep
	track of the number of days spent in the hospital. The group must decide on the
	hospital’s daily rate.
	• The Surgery class will have stored within it the charges for at least five types of
	surgery. It can update the charges variable of the PatientAccount class.
	• The Pharmacy class will have stored within it the price of at least five types of
	medication. It can update the charges variable of the PatientAccount class.
	• The main program.
	The student who designs the main program will design a menu that allows the user to enter
	a type of surgery, enter one or more types of medication, and check the patient out of the
	hospital. When the patient checks out, the total charges should be displayed.
*********************************************************************/
#include <iostream>
#include <string>
#include <cctype>
#include "PatientAccount.h"
using namespace std;

int main()
{
	int choice, days;
	double medical, surgery;
	char choice2;
	string line;
	line.assign(50, '-');

	PatientAccount bill;

	do
	{
		cout << "Hospital Menu" << endl;
		cout << line << endl;
		cout << "Select the type of surgery" << endl;
		cout << "1. Arm Surgery" << endl;
		cout << "2. Hip Surgery" << endl;
		cout << "3. Leg Surgery" << endl;
		cout << "4. Knee Surgery" << endl;
		cout << "5. Neck Surgery" << endl;
		cin >> choice;

		bill.setSurgeryCharges(choice);


		do
		{
			cout << "Which Medications did the patient take? (enter -1 to exit)" << endl;
			cout << "1. TRT" << endl;
			cout << "2. Pain Killers" << endl;
			cout << "3. Stem Cells" << endl;
			cout << "4. Vitamins " << endl;
			cout << "5. Amino Acids" << endl;
			cin >> choice;

			bill.setPharmacyCharges(choice);

		} while (choice != -1);
		

		cout << "For how many days will the patient be at the hospital? ";
		cin >> days;
		bill.setDays(days);



		cout << endl << "Report" << endl;
		cout << line << endl;
		cout << "Total days at the hospital: " << bill.getDays() << endl;
		cout << "Hospital daily rate: $" << bill.getRate() << endl;
		cout << "Total Charges: $" << bill.getCharges() << endl;
		cout << "Total Cost after check out: $" << bill.getCost() << endl;

		bill.setCharges(0);

		cout << "Do you want to try with another patient? (Y/N) ";
		cin >> choice2;
		cout << endl << endl;
	} while (toupper(choice2) == 'Y');



	return 0;
}