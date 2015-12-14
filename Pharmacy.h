/*
The Pharmacy class will have stored within it the price of at least five types of
medication. It can update the charges variable of the PatientAccount class.
*/


#ifndef PHARMACY_H
#define PHARMACY_H

class Pharmacy
{
	private:
		double trt, vitamins, painKillers, aminoAcid, stemCells;

	public:
		Pharmacy();
		double getTrt();
		double getVitamins();
		double getPainkillers();
		double getAminoAcid();
		double getStemcells();
};

#endif