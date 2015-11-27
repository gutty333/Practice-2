/********************************************************
	isPrime Function

	A prime number  is an integer greater than 1 that is evenly divisible by only 1 and itself. For 
	example,  the  number  5 is prime  because  it can  only  be evenly divided  by 1 and  5. The 
	number  6, however,  is not prime because it can be divided by 1, 2, 3, and 6.

	Write  a Boolean  function  named  isPrime, which  takes  an  integer  as an  argument and returns  
	true if the argument is a prime  number,  and  false otherwise.  Demonstrate the
	function  in a complete program.
**********************************************************/
#include <iostream>
using namespace std;

bool isPrime(int x)
{
	int sum, test=1;

	sum = (x/x) + (x / 1);

	for (int y = 1; y <= 10; y++)
	{
		if (y == 1 || y == x)
		{
			continue;
		}

		if (x%y == 0)
		{
			test = 0;
		}
	}


	if (sum % 2 == 0 && test)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	cout << isPrime(7) << endl;
	cout << isPrime(72) << endl;
	cout << isPrime(8) << endl;
	cout << isPrime(13) << endl;
	cout << isPrime(5) << endl;
	cout << isPrime(29) << endl;
	cout << isPrime(25) << endl;
	cout << isPrime(17) << endl;
	cout << isPrime(81) << endl;

	return 0;

}

