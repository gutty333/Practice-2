#include <iostream>
#include "PatientAccount.h"
using namespace std;

// Default Constructor
PatientAccount::PatientAccount()
{
	days = 1;
	charges = 0;
	rate = 500.00;
}
PatientAccount::PatientAccount(double price, double r, int d)
{
	days = d;
	rate = r;
	charges = price;
}


// Setter Functions
void PatientAccount::setSurgeryCharges(int choice)
{
	if (choice == 1)
		charges += cost2.getArm();
	else if (choice == 2)
		charges += cost2.getHip();
	else if (choice == 3)
		charges += cost2.getLeg();
	else if (choice == 4)
		charges += cost2.getKnee();
	else if (choice == 5)
		charges += cost2.getNeck();
}
void PatientAccount::setPharmacyCharges(int choice)
{
	if (choice == 1)
		charges += cost1.getTrt();
	else if (choice == 2)
		charges += cost1.getPainkillers();
	else if (choice == 3)
		charges += cost1.getStemcells();
	else if (choice == 4)
		charges += cost1.getVitamins();
	else if (choice == 5)
		charges += cost1.getAminoAcid();
}
void PatientAccount::setCharges(double amount)
{
	charges = amount;
}
void PatientAccount::setDays(int d)
{
	days = d;
}
void PatientAccount::setRate(double r)
{
	rate = r;
}


// Getter Functions
double PatientAccount::getCharges()
{
	return charges;
}
int PatientAccount::getDays()
{
	return days;
}
double PatientAccount::getRate()
{
	return rate;
}
double PatientAccount::getCost()
{
	return rate* days + charges;
}