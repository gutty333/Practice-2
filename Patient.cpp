#include "Patient.h"

// Constructor
Patient::Patient()
{
	name = "";
	date = "";
	time = phone = 0;
}
Patient::Patient(string n, string d, int phoneNumber, int appointmentTime)
{
	name = n;
	date = d;
	phone = phoneNumber;
	time = appointmentTime;
}


// Setter functions
void Patient::setName(string n)
{
	name = n;
}
void Patient::setDate(string d)
{
	date = d;
}
void Patient::setPhone(int phoneNumber)
{
	phone = phoneNumber;
}
void Patient::setTime(int appointmentTime)
{
	time = appointmentTime;
}

// Getter functions
string Patient::getName()
{
	return name;
}
string Patient::getDate()
{
	return date;
}
int Patient::getPhone()
{
	return phone;
}
int Patient::getTime()
{
	return time;
}