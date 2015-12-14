
#include "Surgery.h"

Surgery::Surgery()
{
	arm = 3250.00;
	neck = 4550.75;
	leg = 5000;
	knee = 8650.45;
	hip = 1325;
}



double Surgery::getArm()
{
	return arm;
}
double Surgery::getHip()
{
	return hip;
}
double Surgery::getLeg()
{
	return leg;
}
double Surgery::getKnee()
{
	return knee;
}
double Surgery::getNeck()
{
	return neck;
}