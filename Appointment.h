
#ifndef APPOINTMENT_H
#define APPOINTMENT_H
#include "Patient.h"
#include <vector>

class Appointment
{
	private:
		string dates[4];
		int appointmentTime[5];
		vector <Patient> list;

	public:
		Appointment();
		bool addPatient(Patient);
		bool checkDate(string);
		bool checkTime(int);
		bool fullWeek();
		void openSlots();
		void printReport();
};

#endif