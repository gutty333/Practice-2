/*********************************************************************
	Population

	In a population, the birth rate and death rate are calculated  as follows:
	Birth Rate = Number of Births ÷ Population
	Death Rate = Number of Deaths  ÷ Population
	For example, in a population of 100,000 that has 8,000  births and 6,000  deaths per year,
	Birth Rate = 8,000  ÷ 100,000 = 0.08
	Death Rate = 6,000  ÷ 100,000 = 0.06

	Design a Population class that stores a current  population, annual  number  of births,  and annual 
	 number  of deaths  for  some  geographic  area.  The  class should  allow  these  three values  to 
	 be  set  in  either  of  two  ways:  by  passing  arguments   to  a  three-parameter constructor 
	when  a new Population object is created  or by calling the setPopulation, setBirths, and setDeaths 
	class member  functions.  In either case, if a population figure less than 2 is passed to the class, 
	use a default value of 2. If a birth or death figure less than
	0 is passed  in, use a default  value  of 0. The  class should  also  have getBirthRate and 
	getDeathRate functions  that  compute  and return  the birth  and death  rates. Write a short 
	program that uses the Population class and illustrates  its capabilities.
*********************************************************************/
#include <iostream>
#include <iomanip>
using namespace std;

class Population
{
	private:
		int population,
			birth,
			death;

	public:
		Population()
		{
			population = 2;
			birth = 0;
			death = 0;
		}
		Population(int x, int y, int z)
		{
			if (x < 2)
				population = 0;
			else
				population = x;
			if (y < 0)
				birth = 0;
			else
				birth = y;
			if (z < 0)
				death = 0;
			else
				death = z;
		}
		void setPopulation(int x)
		{
			if (x < 2)
				population = 0;
			else
				population = x;
		}
		void setBirth(int y)
		{
			if (y < 0)
				birth = 0;
			else
				birth = y;
		}
		void setDeath(int z)
		{
			if (z < 0)
				death = 0;
			else
				death = z;
		}
		double getBirth()
		{
			return static_cast<double>(birth) / population;
		}
		double getDeath()
		{
			return static_cast<double>(death) / population;
		}
};


int main()
{
	int population, birth, death;

	cout << "What is the starting population: ";
	cin >> population;

	cout << "What is the amount of birth and deaths: ";
	cin >> birth >> death;


	Population place1(20500, 1000, 4000), place2(population, birth, death), place3;

	place3.setPopulation(100000);
	place3.setBirth(8000);
	place3.setDeath(6000);

	cout << fixed << setprecision(2);

	cout << endl << "Birth rate is " << place3.getBirth() << endl;
	cout << "Death rate is " << place3.getDeath() << endl;

	cout << endl << "Birth rate is " << place2.getBirth() << endl;
	cout << "Death rate is " << place2.getDeath() << endl;

	cout << endl << "Birth rate is " << place1.getBirth() << endl;
	cout << "Death rate is " << place1.getDeath() << endl;


	return 0;
}