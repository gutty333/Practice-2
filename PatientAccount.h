/*
The PatientAccount class will keep a total of the patient’s charges. It will also keep
track of the number of days spent in the hospital. The group must decide on the
hospital’s daily rate.
*/


#ifndef PATIENTACCOUNT_H
#define PATIENTACCOUNT_H
#include "Pharmacy.h"
#include "Surgery.h"

class PatientAccount
{

	private:
		double charges;
		double rate;
		int days;
		Pharmacy cost1;
		Surgery cost2;



	public:
		PatientAccount();
		PatientAccount(double, double, int);

		void setDays(int);
		void setRate(double);
		void setCharges(double);
		void setPharmacyCharges(int);
		void setSurgeryCharges(int);
		
		int getDays();
		double getCharges();
		double getRate();
		double getCost();
};

#endif