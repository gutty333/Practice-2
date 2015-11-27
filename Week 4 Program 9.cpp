/********************************************************
	Star Search

	A particular talent competition has 5 judges, each of whom awards  a score between 0 and
	10 to each performer. Fractional scores, such as 8.3, are allowed.  A performer’s final score is 
	determined by dropping the  highest  and  lowest  score  received,  then  averaging  the  3 
	remaining   scores.  Write  a  program  that   uses  these  rules  to  calculate   and  display  a 
	contestant’s score. It should include the following functions:

	• void getJudgeData() should  ask the user for a judge’s score, store it in a reference parameter 
	variable, and validate it. This function  should be called by main once for each of the 5 judges.
	• double calcScore() should  calculate  and  return  the average  of the 3 scores that remain  
	after  dropping the  highest  and  lowest  scores  the  performer received.  This function  should 
	be called just once by main and should be passed the 5 scores.

	Two additional functions,  described below, should be called by calcScore, which uses the returned 
	information to determine  which of the scores to drop.

	• int findLowest() should find and return  the lowest of the 5 scores passed to it.
	• int findHighest() should find and return  the highest of the 5 scores passed to it.
**********************************************************/
#include <iostream>
#include <iomanip>
using namespace std;

// Function used to get the scores from the user
void getJudgeData(double& x)
{
	cout << "What is the judge's score? ";
	cin >> x;

	while (x < 0 || x > 10)
	{
		cout << "Please enter a score between 0 and 10: ";
		cin >> x;
	}
}

// Function used to find the lowest of the scores
int findLowest(double a, double b, double c, double d, double e)
{
	if (a < b && a < c && a < d && a < e)
	{
		return a;
	}
	else if (b < a && b < c && b < d && b < e)
	{
		return b;
	}
	else if (c < a && c < b && c < d && c < e)
	{
		return c;
	}
	else if (d < a && d < c && d < b && d < e)
	{
		return d;
	}
	else if (e < a && e < c && e < d && e < b)
	{
		return e;
	}
}


// Function used to find the highest of the scores
int findhighest(double a, double b, double c, double d, double e)
{
	if (a > b && a > c && a > d && a > e)
	{
		return a;
	}
	else if (b > a && b > c && b > d && b > e)
	{
		return b;
	}
	else if (c > a && c > b && c > d && c > e)
	{
		return c;
	}
	else if (d > a && d > c && d > b && d > e)
	{
		return d;
	}
	else if (e > a && e > c && e > d && e > b)
	{
		return e;
	}
}


// Function used to not include the lowest or highest and only have 3 values to get the average
double calcScore(double a, double b, double c, double d, double e)
{
	double average, total;

	total = (a + b + c + d + e) - (findhighest(a,b,c,d,e) + findLowest(a,b,c,d,e));

	average = total / 3.0;

	return average;
}






int main()
{
	double score1, score2, score3, score4, score5;
	cout << fixed << setprecision(1);

	getJudgeData(score1);
	getJudgeData(score2);
	getJudgeData(score3);
	getJudgeData(score4);
	getJudgeData(score5);

	cout << "Your final score is " << calcScore(score1, score2, score3, score4, score5) << endl;

	return 0;
}

