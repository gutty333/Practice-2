#include <iostream>
#include "Point.h"
#include "LineSegment.h"
using namespace std;


int main()
{
	Point test(-1.5, 0.0);
	Point test2(1.5, 4.0);

	LineSegment end(test, test2);


	cout << test.getX() << endl;
	cout << test2.getX() << endl;
	cout << test.distanceTo(test2) << endl;

	cout << endl << end.getEnd1().getX() << endl;
	cout << end.getEnd2().getX() << endl;



	return 0;
}