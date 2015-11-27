/*********************************************************************
	Gratuity Calculator

	Design a Tips class that  calculates  the gratuity  on a restaurant meal.  Its only class member 
	variable, taxRate, should be set by a one-parameter constructor to whatever rate is passed to it 
	when a Tips object is created.  If no argument is passed, a default  tax rate of .065  should  be 
	used. The class should have just one public function, computeTip. This function needs to accept two 
	arguments, the total bill amount and the tip rate. It should use this information to compute what 
	the cost of the meal was before the tax was added. It should then apply the tip rate to just the 
	meal cost portion of the bill to compute and return the tip amount. Demonstrate the class by 
	creating  a program that  creates  a single Tips object,  then  loops  multiple  times to allow  
	the program user to retrieve the correct tip amount using various bill totals and desired tip 
	rates.
*********************************************************************/
#include <iostream>
using namespace std;

class Tips
{
	private:
		double taxRate;


	public:
		Tips(double x = .065)
		{
			taxRate = x;
		}
		double computeTip(double total, double tipRate)
		{
			double newRate = (taxRate * 100) + 100;
			double newTip = (tipRate * 100) + 100;
			double newTotal = (total / newTip) * 100;
			newTotal = (newTotal / newRate) * 100;
			return  newTotal * tipRate;
		}
		
};


int main()
{
	double total, tip;

	Tips order1(.5);
	
	for (int x = 1; x <= 5; x++)
	{
		cout << "What is the total: ";
		cin >> total;

		cout << "What is the tip rate: ";
		cin >> tip;

		cout << order1.computeTip(total, tip) << endl;
	}


		
	return 0;
}