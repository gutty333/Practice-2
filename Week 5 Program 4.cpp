/*********************************************************************
	Widget Factory

	Design a class for a widget manufacturing plant. Assuming that 10 widgets may be produced each 
	hour,  the class object will calculate how many days it will take to produce  any number of 
	widgets. (The plant operates two 8-hour shifts per day.) Write a program that asks the user for the 
	number  of widgets that  have been ordered  and then displays the number  of days it will take  to 
	produce  them.  Think  about  what  values your  program should  accept  for the
	number  of widgets ordered.
*********************************************************************/
#include <iostream>
#include <cmath>
using namespace std;

class Widget
{
	private:
		int widget;

	public:
		Widget()
		{
			widget = 0;
		}

		Widget(int w)
		{
			widget = w;
		}

		int calculate()
		{
			return round((widget / 10.0) / 16);
		}
};


int main()
{
	int order;

	cout << "How many widgets did you order? ";
	cin >> order;


	Widget factory1, factory2(150), factory3(order);

	cout << "The number of days it took for the factory to produce widgets is " << factory1.calculate() << endl;
	cout << "The number of days it took for the factory to produce widgets is " << factory2.calculate() << endl;
	cout << "The number of days it took for the factory to produce widgets is " << factory3.calculate() << endl;

	return 0;
}