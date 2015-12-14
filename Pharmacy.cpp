
#include "Pharmacy.h"


Pharmacy::Pharmacy()
{
	trt = 1275;
	painKillers = 500;
	aminoAcid = 225.75;
	vitamins = 125;
	stemCells = 2250;
}


double Pharmacy::getTrt()
{
	return trt;
}
double Pharmacy::getPainkillers()
{
	return painKillers;
}
double Pharmacy::getAminoAcid()
{
	return aminoAcid;
}
double Pharmacy::getVitamins()
{
	return vitamins;
}
double Pharmacy::getStemcells()
{
	return stemCells;
}