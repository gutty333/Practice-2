#include <iostream>
using namespace std;


double half(double x)
{
	return x / 2.0;
}


int cube(int x)
{
	return x*x*x;
}


int square(int x)
{
	return x * 2;
}


void timesTen(int x)
{
	int result;

	result = x / 10;

	cout << "The product " << x << " multiplied by 10 is " << result << endl;
}





int getNumber(int& x)
{
	cout << "Enter a number from 1 through 100 ";
	cin >> x;

	if (x < 1 || x > 100)
	{
		cout << "Bad Input" << endl;
		return 0;
	}
	else
	{	
		cout << "Good Job" << endl;
		return x;
	}
}




int biggest(int x, int y, int z)
{
	if (x > y && x > z)
	{
		return x;
	}
	else if (y > x && y > z)
	{
		return y;
	}
	else if (z > x && z > y)
	{
		return z;
	}
}








int main()
{
	int number = 45;
	cout << half(number) << endl;
	cout << square(number) << endl;



	int number2 = 4;
	int result;
	result = cube(number2);
	cout << result << endl;


	timesTen(40);


	int value;
	getNumber(value);



	cout << "The largest value of the three is " << biggest(45, 21, 86) << endl;


	return 0;
}


