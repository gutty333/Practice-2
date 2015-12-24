/*********************************************************************
	Money Money Money #1

	Modify Program  10-19 (the United Cause case study program)  so it can be used with any
	set of donations. The program should  dynamically  allocate  the donations array and ask
	the user to input  its values.


	Money Money Money #2

	Modify  Program  10-19  (the  United  Cause case study  program)  so the  arrPtr array  is
	sorted  in descending order  instead of ascending order.
*********************************************************************/
#include <iostream>
#include <string>
#include <iomanip>
using namespace std; 

class DonationList
{
	private:
		int numDonations;
		double *donations;
		double **arrPtr;
		void selectSort();

	public:
		DonationList(int num, double gifts[]);
		~DonationList();
		void show();
		void showSorted();
};


DonationList::DonationList(int num, double gifts[])
{
	numDonations = num;
	
	if (num > 0)
	{
		// Allocate an array of doubles
		donations = new double[num];

		// Allocate an array of pointers-to-doubles
		arrPtr = new double*[num];

		// Initialize the arrays
		for (int count = 0; count < numDonations; count++)
		{
			donations[count] = gifts[count];
			arrPtr[count] = &donations[count];
		}
		
		// Now, sort the array of pointers
		selectSort();
	}
}


DonationList::~DonationList()
{
	if (numDonations > 0)
	{
		delete[] donations;
		donations = 0;
		
		delete[] arrPtr;
		arrPtr = 0;
	}
}



void DonationList::selectSort()
{
	int minIndex;
	double *minElem;

	for (int scan = 0; scan < (numDonations - 1); scan++)
	{
		minIndex = scan;
		minElem = arrPtr[scan];

		for (int index = scan + 1; index < numDonations; index++)
		{
			if (*(arrPtr[index]) < *minElem)
			{
				minElem = arrPtr[index];
				minIndex = index;
			}
		}
		arrPtr[minIndex] = arrPtr[scan];
		arrPtr[scan] = minElem;
	}
}




void DonationList::show()
{
	for (int count = 0; count < numDonations; count++)
	{
		cout << donations[count] << " ";
	}
	cout << endl;
}



void DonationList::showSorted()
{
	for (int count = 0; count < numDonations; count++)
	{
		cout << *(arrPtr[count]) << " ";
	}
	cout << endl;
}




int main()
{
	double funds[] =	{ 5, 100, 5, 25, 10,
						5, 25, 5, 5, 100,
						10, 15, 10, 5, 10 };

	int total;

	cout << "Enter the amount of donations: ";
	cin >> total;

	double* donations = new double[total];

	for (int x = 0; x < total; x++)
	{
		cout << x + 1 << ". Enter a donation value: ";
		cin >> donations[x];
	}
	
	cout << endl;
	DonationList ckGraphics(total, donations);
	cout << "The donations sorted in ascending order are:\n";
	ckGraphics.showSorted();
	
	cout << "The donations in their original order are:\n";
	ckGraphics.show();
	
	return 0;
}