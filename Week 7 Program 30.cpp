/*********************************************************************
	Ascending Circles

	Program  8-28  from  Chapter 8 creates  an array  of four  Circle objects,  then  displays  the 
	area of each object. Using a copy of that program as a starting  point, modify it to create an 
	array  of eight Circle objects  initialized  with  the following  radius:  2.5,  4.0,  1.0,  3.0,  
	6.0, 5.5, 3.5, 2.0. Then use a bubble sort to arrange  the objects in ascending order of radius size
	before displaying the area of each object.
*********************************************************************/
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;


class Circle
{
	private:
		double radius;

	public:
		Circle();
		Circle(double);
		void setRadius(double);
		double getRadius();
		double getArea();
};


Circle::Circle()
{
	radius = 0;
}
Circle::Circle(double r)
{
	radius = r;
}
void Circle::setRadius(double r)
{
	radius = r;
}
double Circle::getRadius()
{
	return radius;
}
double Circle::getArea()
{
	return 3.14 * pow(radius, 2);
}



// Display Method
void display(Circle test[], int size)
{
	for (int x = 0; x < size; x++)
	{
		cout << test[x].getArea() << "  ";
	}
	cout << endl;
}


// Bubble Sort Function
void bubbleSort(Circle array[], int size)
{
	int temp;
	bool swap;


	do
	{
		swap = false;

		for (int x = 0; x < size - 1; x++)
		{
			if (array[x].getRadius() > array[x + 1].getRadius())
			{
				temp = array[x].getRadius();
				array[x].setRadius(array[x + 1].getRadius());
				array[x + 1].setRadius(temp);
				swap = true;
			}
		}
	} while (swap);
}



int main()
{
	const int total = 8;

	Circle test[total] = { Circle(2.5), Circle(4.0), Circle(1.0), Circle(3),
						Circle(6), Circle(5.5), Circle(3.5), Circle(2) };


	cout << fixed << setprecision(2);

	cout << "Original Area Order" << endl;
	display(test, total);

	cout << endl << "Area after Bubble Sort" << endl;
	bubbleSort(test, total);
	display(test, total);


	return 0;
}