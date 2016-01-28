/*********************************************************
Write a function titled say_hello() that outputs to the screen "Hello"

Modify the function so that it takes an integer argument and says hello a number of times equal to the value passed to it.

Make another function that takes two integers arguments and then returns an integer that is the product of the two integers.
(i.e., integer1: 4, Integer2: 5 returns: 20)

Make a function called half() that takes an integer argument. The function must print the number it received to the screen, then the program should divide that number by two to make a new number. If the new number is greater than zero the function then calls the function half() passing it the new number as its argument. If the number is zero or less than the function exits

Call the function half() with an argument of 100, the screen output should be
100
50
25
...
...
1.
********************************************************/
#include <iostream>
using namespace std;

// Hello Function
void say_hello(int total)
{
	for (int x = 0; x < total; x++)
	{
		cout << x + 1 << ". Hello" << endl;
	}
}

// Product Function
int product(int x, int y)
{
	return x*y;
}

// Half Function
void half(int num)
{
	if (num > 0)
	{
		cout << num << endl;
		num /= 2;
		half(num);
	}
}

int main()
{
	say_hello(10);

	cout << product(8, 85) << endl;

	half(100);

	return 0;
}