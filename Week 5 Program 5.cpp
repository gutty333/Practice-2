/*********************************************************************
	Car Class

	Write a class named Car that has the following member variables:

	• year. An int that holds the car’s model year.
	• make. A string object that  holds the make of the car.
	• speed. An int that  holds the car’s current  speed.

	In addition, the class should have the following member functions.

	• Constructor. The constructor should accept the car’s year and make as arguments and  assign
	these  values  to  the  object’s  year and  make member   variables.   The constructor should
	initialize the speed member variable to 0.
	• Accessors. Appropriate accessors functions  should  be created  to allow  values to
	be retrieved  from an object’s year,  make, and speed member  variables.
	• accelerate. The  accelerate function   should   add   5  to  the  speed member variable  each
	time it is called.
	• brake. The  brake function  should  subtract 5 from  the  speed member  variable each time it is
	called.

	Demonstrate the class in a program that creates a Car object, and then calls the accelerate
	function  five times. After each call to the accelerate function,  get the current  speed of the car
	and  display  it. Then,  call the brake function  five times. After each call to the brake function,
	get the current  speed of the car and display it.
*********************************************************************/
#include <iostream>
#include <string>
using namespace std;

class Car
{
	private:
		string make;
		int year;
		int speed;

	public:
		Car(int y, string model)
		{
			year = y;
			make = model;
			speed = 0;
		}
		int getYear()
		{
			return year;
		}
		string getMake()
		{
			return make;
		}
		int getSpeed()
		{
			return speed;
		}
		int accelerate()
		{
			return speed += 5;
		}
		int carBreak()
		{
			return speed -= 5;
		}
};


int main()
{
	int year;
	string make;

	cout << "What year is your car? ";
	cin >> year;

	cout << "What is your car model? ";
	cin >> make;


	// Class objects
	Car suv(2005, "Explorer"), sedan(year,make);


	// Sedan object
	cout << endl << "Sedan information" << endl;
	for (int x = 1; x <= 5; x++)
	{
		cout << sedan.accelerate() << endl;
	}
	cout << "Your speed is " << sedan.getSpeed() << " for the car model of " << sedan.getMake() << endl;
	for (int x = 1; x <= 5; x++)
	{
		sedan.carBreak();
	}
	cout << "You stopped the car with a speed of " << sedan.getSpeed() << endl;


	// SUV object
	cout << endl << "SUV information" << endl;
	cout << suv.getMake() << endl;
	cout << suv.getYear() << endl;
	for (int x = 1; x <= 20; x++)
	{
		suv.accelerate();
	}
	cout << "Your speed for the SUV is " << suv.getSpeed() << endl;


	return 0;
}