#include "Box.h"

Box::Box()
{
	height = 1;
	width = 1;
	lenght = 1;
}
Box::Box(double x, double y, double z)
{
	setHeight(x);
	setWidth(y);
	setLenght(z);
}
void Box::setHeight(double x)
{
	height = x;
}
void Box::setWidth(double y)
{
	width = y;
}
void Box::setLenght(double z)
{
	lenght = z;
}
double Box::getVolume()
{
	return height*width*lenght;
}
double Box::getSurfaceArea()
{
	return 2*(lenght * width) + 2*(lenght*height) + 2*(width*height);
}