#ifndef LINESEGMENT_H
#define LINESEGMENT_H
#include "Point.h"

class LineSegment
{
	private:
		Point end1;
		Point end2;

	public:
		LineSegment();
		LineSegment(Point, Point);
		void setEnd1(Point);
		void setEnd2(Point);
		Point getEnd1();
		Point getEnd2();
		double length();
		double slope();
};

#endif