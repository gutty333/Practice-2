#include <iostream>
#include <string>
#include <cctype>
#include <vector>
using namespace std;


int main()
{
	int phoneNumber;
	vector <int> phone;

	string name;
	vector <string> names;


	string dates[4] = { "Monday", "Tuesday", "Wednesday", "Thursday" };
	string dateSelect;
	vector <string> myDate;
	bool dateValid = false;


	int timeSelected;
	vector <int> myTime;
	int time[5] = { 10, 11, 12, 13, 14 };

	bool dateRepeat = false;
	bool timeRepeat = false;

	char choice;
	int counter = 0;
	int size;


	cout << "Computer Class Schedule" << endl;
	
	do
	{
		cout << "What is your name? ";
		getline(cin, name);
		names.push_back(name);
		size = names.size();

		cout << "What is your phone number: ";
		cin >> phoneNumber;
		phone.push_back(phoneNumber);



		cout << "For which date of the week do you want to make an appointment? ";
		cin >> dateSelect;
		for (int x = 0; x < 4; x++)
		{
			cout << "inside the date loop" << endl;
			if (dateSelect == dates[x])
			{
				dateValid = true;
			}
		}
		while (!dateValid)
		{
			cout << "Please enter a valid date" << endl;
			cin >> dateSelect;
			for (int x = 0; x < 4; x++)
			{
				if (dateSelect == dates[x])
				{
					dateValid = true;
				}
			}
		}
		myDate.push_back(dateSelect);


		cout << "At what time do you want your appointment? ";
		cin >> timeSelected;
		while (timeSelected > 14 || timeSelected < 10)
		{
			cout << "Please enter a valid time" << endl;
			cin >> timeSelected;
		}
		if (timeSelected > 12)
		{
			timeSelected -= 12;
		}
		myTime.push_back(timeSelected);



		if (names.size() > 1)
		{
			vector <int> index;

			for (int x = 0; x < size; x++)
			{
				for (int i = 0; i < size-1; i++)
				{
					if (myDate[x] == myDate[i + 1])
					{
						dateRepeat = true;
						cout << "The date is the same" << endl;
						index.push_back(i);
					}
					else
					{
						dateRepeat = false;
					}
				}

			}


			for (int y = 0; y < size; y++)
			{
				if (dateRepeat)
				{
					for (int z = 0; z < size-1; z++)
					{
						if (myTime[y] == myTime[z + 1])
						{
							timeRepeat = true;
							cout << "That time is already taken" << endl;
							names.pop_back();
							myDate.pop_back();
							myTime.pop_back();
						}
						else
						{
							timeRepeat = false;
						}

					}
				}
			}
		}

		cout << "Make another appointment. (Y/N) ";
		cin >> choice;

		cin.ignore();
		counter++;
	} while (toupper(choice) == 'Y');
	





	return 0;

}