/*********************************************************************
	Report Heading

	Design a class called Heading that  has data  members  to hold  the company  name  and  the report  
	name.  A two-parameter default  constructor should  allow these to be specified at the time a new 
	Heading object is created.  If the user creates a Heading object without passing any arguments, 
	“ABC Industries” should be used as a default value for the company name and  “Report”  should  be  
	used  as  a  default  for  the  report  name.  The  class should  have member functions  to print a 
	heading in either one-line format,  as shown here:

	Pet Pals Payroll Report

	or in four-line  “boxed” format,  as shown here:
	********************************************* 
					Pet Pals
				Payroll Report
	*********************************************
	Try  to  figure  out  a way  to  center  the  headings  on  the  screen,  based  on  their  lengths.
	Demonstrate the class by writing  a simple program that  uses it.
*********************************************************************/
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Heading
{
private:
	string name;
	string report;

public:
	Heading(string companyName, string companyReport)
	{
		name = companyName;
		report = companyReport;
	}
	Heading()
	{
		name = "ABC Industries";
		report = "Report";
	}

	void print1()
	{
		cout << name << " " << report << endl;
	}

	void print2()
	{
		string line;
		int centerName = name.length();
		int centerReport = report.length();

		centerName = (40 - centerName) / 2;
		centerReport = (40 - centerReport) / 2;

		cout << line.assign(40, '*') << endl;
		cout << setw(centerName) << "" << name << endl;
		cout << setw(centerReport) << "" << report << endl;
		cout << line.assign(40, '*') << endl;
	}
};



int main()
{
	string company, report;

	cout << "Enter a company name ";
	getline(cin, company);

	cout << "Enter a company report ";
	getline(cin, report);

	Heading company1, company2(company, report), company3("Slingo", "Quarter Report");

	company1.print1();
	company1.print2();

	company2.print1();
	company2.print2();

	company3.print1();
	company3.print2();


	return 0;
}
