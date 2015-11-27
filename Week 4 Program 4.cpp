/********************************************************
	Falling Distance

	The following formula  can be used to determine  the distance an object falls due to gravity in a specific time period:
	d = 1/2*g*t^2

	The variables in the formula  are as follows: d is the distance in meters, g is 9.8, and t is the 
	time in seconds that the object has been falling.

	Write   a  function   named   fallingDistance that   accepts   an  object’s  falling  time  (in 
	seconds)  as  an  argument. The  function  should  return  the  distance,  in  meters,  that  the 
	object has fallen during that time interval.  Write a program that demonstrates the function by 
	calling it in a loop  that  passes the values 1 through 10 as arguments  and  displays  the
	return  value.
**********************************************************/
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

const double gravity = 9.8;

double fallingDistance(double x)
{
	double distance;
	distance = (1 / 2.0)* gravity * pow(x, 2);
	return distance;
}

int main()
{
	cout << fixed << setprecision(2);

	for (int x = 1; x <= 10; x++)
	{
		cout << "At " << x << " seconds the distance of the falling object is " << fallingDistance(x) << " meters" << endl;
	}

	return 0;
}