#ifndef PATIENT_H
#define PATIENT_H
#include <string>
using namespace std;

class Patient
{
	private:
		string name;
		string date;
		int phone;
		int time;

	public:
		Patient();
		Patient(string, string,	int, int);
		void setName(string);
		void setDate(string);
		void setPhone(int);
		void setTime(int);
		string getName();
		string getDate();
		int getPhone();
		int getTime();
};

#endif