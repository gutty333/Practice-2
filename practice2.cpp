#include <iostream>
#include <string>
using namespace std;

int main()
{
	string name, city, food, state;
	int score, total, age, number;

	cout << "What was your score on the test: ";
	cin >> score;


	cout << "What is the name of the city you are from: ";
	cin.get();
	getline(cin, city);

	cout << "What was the total score on you credit: ";
	cin >> total;


	cout << "Enter your name here: ";
	cin.get();
	getline(cin, name);

	cout << "What state are you from? ";
	getline(cin, state);

	cout << "How old are you? ";
	cin >> age;

	cout << "What is your favorite food? ";
	cin.get();
	getline(cin, food);


	cout << "Enter you favorite number: ";
	cin >> number;


	cout << endl << endl << endl;
	cout << "Score: " << score << endl;
	cout << "Age: " << age << endl;
	cout << "Number: " << number << endl;
	cout << "Total: " << total << endl;
	cout << "Name: " << name << endl;
	cout << "City: " << city << endl;
	cout << "State: " << state << endl;
	cout << "Food: " << food << endl;

	return 0;

}