/*********************************************************************
	Write a class called Sphere that has a field for radius, of type double. It should have set and get
	methods for the radius, and a constructor that takes a double and passes it to the set method.  The 
	default constructor should set the radius to 0.0.  There should be a method called getVolume that 
	returns the volume of the Sphere object.

	In a separate file (sphereMain.cpp), write a void function called printSphereInfo that takes as a 
	parameter a pointer-to-Sphere and prints out the radius and volume of the Sphere the parameter 
	points to (appropriately labeled of course). In the same file, write a main method that asks the 
	user for the radius of a sphere, creates a new Sphere object with that radius, and passes the 
	address of that Sphere object to printSphereInfo. SphereMain.cpp will need to #include "Sphere.hpp".
*********************************************************************/
#include <iostream>
#include <string>
#include <cmath>
using namespace std;


class Sphere
{
	private:
		double radius;

	public:
		Sphere();
		Sphere(double);
		void setRadius(double);
		double getRadius();
		double getVolume();
};

Sphere::Sphere()
{
	radius = 0.0;
}
Sphere::Sphere(double r)
{
	setRadius(r);
}
void Sphere::setRadius(double r)
{
	radius = r;
}
double Sphere::getRadius()
{
	return radius;
}
double Sphere::getVolume()
{
	return (4.0 / 3)*3.14*pow(radius, 3);
}


void printSphereInfo(Sphere* test)
{
	cout << "Radius: " << test->getRadius() << endl;
	cout << "Volume: " << test->getVolume() << endl;
}




int main()
{
	cout << "Enter the radius of a Sphere: ";
	double radius;
	cin >> radius;

	Sphere* test = new Sphere;
	test->setRadius(radius);

	cout << endl;
	printSphereInfo(test);

	delete test;
	test = 0;

	return 0;
}