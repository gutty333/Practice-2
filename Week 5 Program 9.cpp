/*********************************************************************
	Movie Data

	Write a program that uses a structure named MovieData to store the following information about  a 
	movie:
	Title
	Director
	Year Released
	Running  time (in minutes)

	Include a constructor that allows all four of these member data values to be specified at the time a 
	MovieData variable is created.  The program should create two MovieData variables and pass each one 
	in turn to a function  that displays the information about  the movie in a clearly formatted 
	manner.  Pass the MovieData variables to the display function  by value.


	Modify the Movie Data program written  for Programming Challenge 8 to include two more
	members  that  hold  the  movie’s production costs  and  first-year  revenues.  The  constructor
	should be modified so that all six member values can be specified when a MovieData variable is
	created.  Modify  the  function  that  displays  the  movie  data  to  display  the  title,
	director, release year, running  time, and first year’s profit or loss. Also, improve the program by
	having the MovieData variables passed to the display function  as constant references.
*********************************************************************/
#include <iostream>
#include <string>
using namespace std;

struct MovieData
{
	string title;
	string director;
	int year, time;
	double cost, revenue;

	MovieData()
	{
		title = "";
		director = "";
		year = 0;
		time = 0;
		cost = 0;
		revenue = 0;
	}
	MovieData(string name, string author, int x, int y, double i, double j)
	{
		title = name;
		director = author;
		year = x;
		time = y;
		cost = i;
		revenue = j;
	}
};

void display(MovieData& x)
{

	string line;

	if (x.cost == 0)
	{
		x.director = "Billy Jane";
		x.title = "The one and only";
		x.year = 1987;
		x.time = 215;
		x.cost = 1488;
		x.revenue = 4574.25;

		cout << endl << "Movie information" << endl;
		cout << line.assign(40, '-') << endl;
		cout << "The name of the movie is " << x.title << endl;
		cout << "The movie is directed by " << x.director << endl;
		cout << "The movie came out in " << x.year << endl;
		cout << "The movie is " << x.time << " minutes long" << endl;
		cout << "In the first year the movie generated/lost $" << x.revenue - x.cost << endl;
		cout << line.assign(40, '-') << endl;
	}
	else
	{
		cout << endl << "Movie information" << endl;
		cout << line.assign(40, '-') << endl;
		cout << "The name of the movie is " << x.title << endl;
		cout << "The movie is directed by " << x.director << endl;
		cout << "The movie came out in " << x.year << endl;
		cout << "The movie is " << x.time << " minutes long" << endl;
		cout << "In the first year the movie generated/lost $" << x.revenue - x.cost << endl;
		cout << line.assign(40, '-') << endl;
	}
}

int main()
{
	MovieData movie1("Cowboys and Aliens", "Bill Gross", 2005, 120, 400000, 845123.75), movie2("Star Wars", "George Lucas", 1964, 184, 952301.75, 463125.85);
	MovieData movie3;



	display(movie1);
	display(movie2);
	display(movie3);

	return 0;
}