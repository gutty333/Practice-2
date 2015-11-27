#include "LineSegment.h"
#include <cmath>


LineSegment::LineSegment()
{
	Point end;
	end1 = end;
	end2 = end;
}
LineSegment::LineSegment(Point end1, Point end2)
{
	setEnd1(end1);
	setEnd2(end2);
}
void LineSegment::setEnd1(Point end)
{
	end1 = end;
}
void LineSegment::setEnd2(Point end)
{
	end2 = end;
}
Point LineSegment::getEnd1()
{
	return end1;
}
Point LineSegment::getEnd2()
{
	return end2;
}
double LineSegment::length()
{
	double length = end1.distanceTo(end2);

	return length;
}
double LineSegment::slope()
{
	double x = end1.getX();
	double x2 = end2.getX();
	double y = end1.getY();
	double y2 = end2.getY();

	return (y2 - y) / (x2 - x);
}