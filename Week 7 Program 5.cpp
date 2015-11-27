/*********************************************************************
	Perfect  Scores

	Write  a modular program that  accepts  up to 20 integer  test scores in the range  of 0 to
	100  from  the  user  and  stores  them  in  an  array.  Then  main should  report  how  many 
	perfect  scores were entered  (i.e., scores of 100),  using a value-returning countPerfect
	function  to help it.
*********************************************************************/
#include <iostream>
using namespace std;



// Perfect Score Function
int getPerfect(int test[])
{
	int count = 0;
	for (int x = 0; x < 20; x++)
	{
		if (test[x] == 100)
		{
			count++;
		}
	}

	return count;
}



// Function to get score from the user
void getScores()
{

	int score[20];

	for (int x = 0; x < 20; x++)
	{
		cout << "Enter a test score (0 -100): ";
		cin >> score[x];


		// Input validation
		while (score[x] < 0 || score[x] > 100)
		{
			cout << "Please enter a score in the range of 0 to 100: ";
			cin >> score[x];
		}
	}

	cout << "There are a total of " << getPerfect(score) << " perfect scores" << endl;
}





int main()
{
	getScores();

	return 0;
}
