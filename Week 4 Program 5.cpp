/********************************************************
	Kinetic Energy
	In physics, an object that is in motion  is said to have kinetic energy. The following formula can 
	be used to determine  a moving object’s kinetic energy:
	KE = 1/2 * m * v^2

	The  variables  in the  formula  are  as follows:  KE is the  kinetic  energy  in joules,  m is the 
	object’s mass in kilograms,  and v is the object’s velocity in meters per second.

	Write a function  named  kineticEnergy that  accepts an object’s mass (in kilograms)  and velocity 
	(in meters  per second)  as arguments. The function  should  return  the amount of
	kinetic energy that the object has. Demonstrate the function by calling it in a program that asks the user to enter values for mass and velocity
**********************************************************/
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double kineticEnergy(double x, double y)
{
	double ke;

	ke = (1 / 2.0) * x *pow(y, 2);
	return ke;
}

int main()
{
	cout << fixed << setprecision(1);

	double mass, velocity;

	cout << "What is the mass and velocity of the object? ";
	cin >> mass >> velocity;

	cout << "The Kinetic Energy of the object is " << kineticEnergy(mass, velocity) << endl;

	return 0;
}