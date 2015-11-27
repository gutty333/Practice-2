/********************************************************
	Using Files—Travel Expenses

	This program should be designed and written by a team of students. Here are some
	suggestions:
	• One student should design function main, which will call the other functions in
	the program. The rest of the functions should be designed by other team members.
	• Analyze the program requirements so each student is given about the same workload.
	• Decide on the function names, parameters, and return types in advance.
	• Use stubs and drivers to test and debug the program.
	• The program can be implemented either as a multi-file program, or all the functions
	can be cut and pasted into the main file.

	Here is the assignment. Write a program that calculates and displays the total travel
	expenses of a businessperson on a trip. The program should have functions that ask for
	and return the following:
	• The total number of days spent on the trip
	• The time of departure on the first day of the trip, and the time of arrival back home
	on the last day of the trip
	• The amount of any round-trip airfare
	• The amount of any car rentals
	• Miles driven, if a private vehicle was used. Vehicle allowance is $0.58 per mile.
	• Parking fees. (The company allows up to $12 per day. Anything in excess of this
	must be paid by the employee.)
	• Taxi fees. (The company allows up to $40 per day for each day a taxi was used.
	Anything in excess of this must be paid by the employee.)
	• Conference or seminar registration fees
	• Hotel expenses. (The company allows up to $90 per night for lodging. Anything in
	excess of this must be paid by the employee.)
	• The cost of each meal eaten. On the first day of the trip, breakfast is allowed as an
	expense if the time of departure is before 7 a.m. Lunch is allowed if the time of
	departure is before noon. Dinner is allowed if the time of departure is before 6 p.m.
	On the last day of the trip, breakfast is allowed if the time of arrival is after 8 a.m.
	Lunch is allowed if the time of arrival is after 1 p.m. Dinner is allowed if the time of
	arrival  is after 7 p.m. The program should  only ask for the costs of allowable  meals.
	(The company  allows  up  to $18  for breakfast, $12  for lunch,  and  $20  for dinner. Anything in
	excess of this must be paid by the employee.)

	The  program should  perform  the  necessary  calculations to  determine  the  total  amount spent
	by the business traveler in each category (mileage charges, parking,  hotel, meals, etc.) as well
	as the maximum amount allowed  in each category.  It should then create a well laid out  expense
	report   that  includes  the  amount spent  and  the  amount allowed   in  each category,  as well
	as the total  amount spent  and  total  amount allowed  for the entire  trip.
	This report  should be written  to a file.
**********************************************************/
#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>
using namespace std;

const double	vehicleMile = .58,
				parkingFee = 12.0,
				taxiFee = 40.0,
				hotelFee = 90.0,
				breakfastFee = 18.0,
				lunchFee = 12.0,
				dinnerFee = 20.0,
				mileCost = 1.25;



void getData(char& choice, char& choice2, int& days, double& leave, double& arrive, double& trip, double& carRent, int& distance, double& parking, double& taxiCost, double& hotelCost, double& extraFee)
{

	cout << "How many days are you spending on the trip? ";
	cin >> days;

	cout << "At what time are you leaving to your destination? (first day) ";
	cin >> leave;

	cout << "At what time did you arrive home? (last day) ";
	cin >> arrive;

	cout << "What is the cost of the round trip? ";
	cin >> trip;

	cout << "What was the cost for renting a car? ";
	cin >> carRent;

	cout << "How many miles did you drive? ";
	cin >> distance;
	cout << "Did you use a private vehicle? (Y/N) ";
	cin >> choice;

	cout << "The total cost of parking per day? ";
	cin >> parking;

	cout << "The total cost of taxi? ";
	cin >> taxiCost;

	cout << "Did you have any conference or registration fees? (Y/N) ";
	cin >> choice2;
	if (toupper(choice2) == 'Y')
	{
		cout << "What was the total cost of the conference/registration? ";
		cin >> extraFee;
	}

	cout << "What was the hotel cost per night? ";
	cin >> hotelCost;
}

double mile(int distance, char choice)
{

	if (toupper(choice) == 'Y')
	{
		return distance * vehicleMile;
	}
	else
	{
		return distance * mileCost;
	}
}

double parkingCost(double parking, int days)
{
	double total, total2;
	total = days * parking;
	total2 = days * parkingFee;


	if (parking > parkingFee)
	{
		return total - total2;
	}
	else
	{
		return total;
	}
}

double taxiCost(double taxiCost)
{
	if (taxiCost > taxiFee)
	{
		return taxiCost - taxiFee;
	}
	else
	{
		return taxiCost;
	}
}

double conference(double fee, char choice)
{

	if (toupper(choice) == 'Y')
	{

		return fee;
	}
	else
	{
		fee = 0;

		return fee;
	}
}

double hotelExpense(double hotelCost, int days)
{
	if (hotelCost > hotelFee)
	{
		double total, total2;

		total = days * hotelFee;
		total2 = days * hotelCost;

		return total2 - total;
	}
	else
	{
		return hotelCost * days;
	}
}

double meal(double leave, double arrive, double& breakfast, double& lunch, double& dinner, double& total)
{
	total= 0;

	if (leave < 7.00)
	{
		cout << "What is the cost of your breakfast? ";
		cin >> breakfast;
		if (breakfast > breakfastFee)
		{
			total = breakfast - breakfastFee;
		}
		else
		{
			total = 0;
		}
	}
	else if (leave > 7.00 && leave < 12.00)
	{
		cout << "What is the cost of your lunch? ";
		cin >> lunch;
		if (lunch > lunchFee)
		{
			total = lunch - lunchFee;
		}
		else
		{
			total = 0;
		}
	}
	else if (leave > 12.00 && leave < 18.00)
	{
		cout << "What is the cost of your dinner? ";
		cin >> dinner;
		if (dinner> dinnerFee)
		{
			total = dinner - dinnerFee;
		}
		else
		{
			total = 0;
		}
	}


	if (arrive > 19.00)
	{
		cout << "What was the cost of your dinner after arriving? ";
		cin >> dinner;
		if (dinner> dinnerFee)
		{
			total = total + (dinner - dinnerFee);
		}
		else
		{
			total = total + 0;
		}
	}
	else if (arrive > 13.00)
	{
		cout << "What was the cost of your lunch after arriving? ";
		cin >> lunch;
		if (lunch> lunchFee)
		{
			total = total + (lunch - lunchFee);
		}
		else
		{
			total = total + 0;
		}
	}
	else if (arrive > 8.00)
	{
		cout << "What was the cost of your breakfast after arriving? ";
		cin >> breakfast;
		if (breakfast> breakfastFee)
		{
			total = total + (breakfast - breakfastFee);
		}
		else
		{
			total = total + 0;
		}
	}

	return total;
}




int main()
{
	int days, distance;
	char choice, choice2;
	double leaveTime, arriveTime, parking, taxi, extra, hotel, trip, carRent, breakfast=0, lunch=0, dinner=0, mealAllowed = 0, total;

	string line;

	cout << fixed << setprecision(2);

	getData(choice, choice2, days, leaveTime, arriveTime, trip, carRent, distance, parking, taxi, hotel, extra);

	cout << endl << endl << "Expense Report" << endl << endl;
	cout << line.assign(50, '-') << endl;
	cout << "Your total meal charges are $" << meal(leaveTime, arriveTime, breakfast, lunch, dinner, total) << endl;
	cout << "Your total trip charges are $" << trip << endl;
	cout << "Your total mileage charges are $" << mile(distance, choice)<< endl;
	cout << "Your total parking charges are $" << parkingCost(parking, days) << endl;
	cout << "Your total taxi charges are $" << taxiCost(taxi) << endl;
	cout << "Your total car rental charges are $" << carRent << endl;
	cout << "Your total hotel charges are $" << hotelExpense(hotel, days)<< endl;
	cout << "Your total extra charges are $" << conference(extra, choice2) << endl;
	cout << line.assign(50, '-') << endl;
	cout << line.assign(25, '-') << endl;
	cout << line.assign(25, '-') << endl;
	cout << line.assign(50, '-') << endl;
	cout << "Your total mileage expense allowed is $" << distance * vehicleMile << endl;
	cout << "Your total parking expense allowed is $" << parkingFee * days<< endl;
	cout << "Your total taxi expense allowed is $" << taxiFee << endl;
	cout << "Your total hotel expense allowed is $" << hotelFee * days << endl;
	if (breakfast)
	{
		mealAllowed = breakfastFee;
	}
	if (lunch)
	{
		mealAllowed += lunchFee;
	}
	if (dinner)
	{
		mealAllowed += dinnerFee;
	}
	cout << "You total meal expense allowed is $"<< mealAllowed << endl;
	double totalExpense = mile(distance, choice) + parkingCost(parking, days) + taxiCost(taxi) + carRent + hotelExpense(hotel, days) + conference(extra, choice2) + total + trip;
	double totalAllowed = (distance * vehicleMile) + (parkingFee * days) + taxi + (hotelFee * days) + mealAllowed;
	cout << line.assign(50, '-') << endl;
	cout << line.assign(25, '-') << endl;
	cout << line.assign(25, '-') << endl;
	cout << line.assign(50, '-') << endl;
	cout << "The total amount that you spend on this trip is $" << totalExpense << endl;
	cout << "The total amount that you were allowed to spend on this trip is $" << totalAllowed << endl << endl;
	

	return 0;
}