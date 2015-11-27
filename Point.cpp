#include "Point.h"
#include <cmath>

Point::Point()
{
	xCoord = 0;
	yCoord = 0;
}
Point::Point(double x, double y)
{
	setX(x);
	setY(y);
}
void Point::setX(double x)
{
	xCoord = x;
}
void Point::setY(double y)
{
	yCoord = y;
}
double Point::getX()
{
	return xCoord;
}
double Point::getY()
{
	return yCoord;
}
double Point::distanceTo(const Point& point1)
{
	double x = xCoord - point1.xCoord;
	double y = yCoord - point1.yCoord;

	double distance = sqrt(pow(x, 2) + pow(y, 2));

	return distance;
}