/*********************************************************************
	 Box Assignment Program
*********************************************************************/
#include <iostream>
#include "Box.h"
using namespace std;

int main()
{
	double lenght = 5;
	double height = 4;
	double width = 6;

	Box rectangle1(height, width, lenght), rectangle2, rectangle3;

	rectangle3.setHeight(5);
	rectangle3.setWidth(8);
	rectangle3.setLenght(12);

	cout << endl << "The volume is " << rectangle1.getVolume() << " and the surface area is " << rectangle1.getSurfaceArea() << endl;

	cout << endl << "The volume is " << rectangle2.getVolume() << " and the surface area is " << rectangle2.getSurfaceArea() << endl;

	cout << endl << "The volume is " << rectangle3.getVolume() << " and the surface area is " << rectangle3.getSurfaceArea() << endl;

	return 0;
}
