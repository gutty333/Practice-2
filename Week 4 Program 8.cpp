/********************************************************
	Lowest Score Drop

	• Write a program that  calculates  the average of a group  of test scores, where the lowest score 
	in the group is dropped. It should use the following functions:
	• void getScore() should  ask  the  user  for  a  test  score,  store  it  in  a  reference 
	parameter variable,  and validate  that  it is not lower than  0 or higher than  100.  This 
	function  should be called by main once for each of the five scores to be entered.
	• void calcAverage() should  calculate  and  display  the average  of the four  highest scores.
	This function  should be called just once by main and should be passed the five scores.
	• int findLowest() should  find and return  the lowest of the five scores passed to it.
	It should be called by calcAverage, which uses the function  to determine  which one of the five
	scores to drop.
**********************************************************/
#include <iostream>
#include <iomanip>
using namespace std;

void getScore(int& x)
{
	cout << "What is your test score? ";
	cin >> x;

	while (x < 0 || x > 100)
	{
		cout << "Please enter a value between 0-100 for the score: ";
		cin >> x;
	}
}



int findLowest(int a, int b, int c, int d, int e)
{

	if (a < b && a < c && a < d && a < e)
	{
		return b + c + d + e;
	}
	else if (b < a && b < c && b < d && b < e)
	{
		return a + c + d + e;
	}
	else if (c < a && c < b && c < d && c < e)
	{
		return a + b + d + e;
	}
	else if (d < a && d < c && d < b && d < e)
	{
		return a + b + c + e;
	}
	else if (e < a && e < c && e < d && e < b)
	{
		return a + b + c + d;
	}
}



void calcAverage(int a, int b, int c, int d, int e)
{
	double average = findLowest(a, b, c, d, e) / 4.0;

	cout << "Your average from all the scores is " << fixed << setprecision(1) << average << endl;
}






int main()
{
	int score1, score2, score3, score4, score5;

	getScore(score1);
	getScore(score2);
	getScore(score3);
	getScore(score4);
	getScore(score5);


	calcAverage(score1, score2, score3, score4, score5);


	return 0;
}