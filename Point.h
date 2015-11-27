#ifndef POINT_H
#define POINT_H

class Point
{
	private:
		double xCoord;
		double yCoord;


	public:
		Point();
		Point(double, double);
		void setX(double);
		void setY(double);
		double getX();
		double getY();
		double distanceTo(const Point&);
};

#endif