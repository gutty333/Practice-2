/*********************************************************************
	
*********************************************************************/
#include <iostream>
using namespace std;

#ifndef BOX_H
#define BOX_H

class Box
{
	private:
		double height;
		double width;
		double lenght;

	public:
		Box();
		Box(double, double, double);
		void setHeight(double);
		void setWidth(double);
		void setLenght(double);
		double getVolume();
		double getSurfaceArea();
};

#endif