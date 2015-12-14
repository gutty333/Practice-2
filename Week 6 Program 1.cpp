/*********************************************************************
	Line and Point Assignment Program
*********************************************************************/
#include <iostream>
#include <iomanip>
#include "Point.h"
#include "LineSegment.h"
using namespace std;

int main()
{
	cout << fixed << setprecision(2);

	Point p1(-1.5, 0);
	Point p2(1.5, 4);

	double distance = p1.distanceTo(p2);

	cout << "The distance is " << distance << endl;
	

	LineSegment line1(p1, p2);
	
	double slope = line1.slope();

	cout << "The slope is " << slope << endl;


	double point;
	Point p3;
	Point p4;
	cout << endl << "Place your own points:" << endl;
	cout << "Set the x for Point 1: ";
	cin >> point;
	p3.setX(point);
	cout << "Set the y for Point 1: ";
	cin >> point;
	p3.setY(point);
	cout << "Set the x for Point 2: ";
	cin >> point;
	p4.setX(point);
	cout << "Set the y for Point 2: ";
	cin >> point;
	p4.setY(point);

	distance = p3.distanceTo(p4);

	cout << "The distance for this point is " << distance << endl;

	line1.setEnd1(p3);
	line1.setEnd2(p4);
	slope = line1.slope();

	cout << "The slope for this point is " << slope << endl;





	return 0;
}