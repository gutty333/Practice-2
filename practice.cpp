/*
	Fun program to simulate patients making appointments at the library
	It will only focus on a single week
	Appointments can only be made from Monday-Thursday open from 10-2
*/
#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include "Patient.h"
#include "Appointment.h"
using namespace std;

void appointmentProcess(string name, int phone, string date, int time, Patient& student, Appointment& schedule)
{
	
	cout << "What is your name: ";
	getline(cin, name);
	cout << "What is your phone number: ";
	cin >> phone;
	student.setName(name);
	student.setPhone(phone);

	cout << "For which date of the week do you want to make your appointment? ";
	cin >> date;
	while (!schedule.checkDate(date))
	{
		cout << "That date is not open, enter another date:(Monday-Thursday) ";
		cin >> date;
	}
	cout << "At what time do you want your appointment? ";
	cin >> time;
	while (!schedule.checkTime(time))
	{
		cout << "That time is not open, enter another time slot:(10-14) ";
		cin >> time;
	}

	student.setDate(date);
	student.setTime(time);
	if (!schedule.addPatient(student))
	{
		cout << "Sorry that slot is already taken by another student" << endl;
		cin.ignore();
		appointmentProcess(name, phone, date, time, student, schedule);
	}
}


int main()
{
	string line, name, date;
	int phone = 0;
	int time = 0;
	char choice;
	line.assign(50, '-');
	Patient student;
	Appointment schedule;

	do
	{
		cout << "Welcome to the Town Public Library" << endl;
		cout << "Computer Class Schedule" << endl;
		cout << line << endl;
		appointmentProcess(name, phone, date, time, student, schedule);

		cout << "Make more appointments? (Y/N) ";
		cin >> choice;
		cin.ignore();
		cout << endl;
	} while (toupper(choice) == 'Y' && !schedule.fullWeek());


	cout << endl << line << endl;
	schedule.printReport();
	
	return 0;
}