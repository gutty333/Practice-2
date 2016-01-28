#include <iostream>
#include "Appointment.h"


Appointment::Appointment()
{
	dates[0] = "Monday";
	dates[1] = "Tuesday";
	dates[2] = "Wednesday";
	dates[3] = "Thursday";

	// Setting the time. 10 am - 2pm(14);
	for (int x = 0; x < 5; x++)
	{
		appointmentTime[x] = 10 + x;
	}
}

// Add Patient
bool Appointment::addPatient(Patient student)
{
	int size = list.size();
	for (int x = 0; x < size; x++)
	{
		// Checking to see if the appointment is already taken
		if (student.getDate() == list[x].getDate() && student.getTime() == list[x].getTime())
		{
			return false;
		}
	}


	list.push_back(student);
	return true;
}

// Check date function. This will check to see if the that date is available
bool Appointment::checkDate(string date)
{
	bool open = false;
	for (int x = 0; x < 4; x++)
	{
		if (date == dates[x])
		{
			open = true;
		}
	}

	return open;
}
// Check time function. This will check to see if the that time is available
bool Appointment::checkTime(int time)
{
	bool open = false;
	for (int x = 0; x < 5; x++)
	{
		if (time == appointmentTime[x])
		{
			open = true;
		}
	}

	return open;
}

// Full Week function
bool Appointment::fullWeek()
{
	if (list.size() >= 20)
	{
		cout << "We are sorry the week is already full" << endl;
		return true;
	}
	else
	{
		return false;
	}
}

// Open Slot Function
void Appointment::openSlots()
{
	// Need to compare list to the dates that have not been taken 
}
// Print Report
void Appointment::printReport()
{
	int size = list.size();

	if (size > 0)
	{
		for (int x = 0; x < size; x++)
		{
			cout << "Name: " << list[x].getName() << endl;
			cout << "Phone Number: " << list[x].getPhone() << endl;
			cout << "Date: " << list[x].getDate() << " at " << list[x].getTime() << endl << endl;
		}
	}
}