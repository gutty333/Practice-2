/*********************************************************************
	Driver’s License Exam

	The State Department of Motor Vehicles (DMV)  has asked  you to write  a program that grades  the  
	written  portion of  the  driver’s  license  exam,  which  has  20  multiple  choice questions.  
	Here are the correct  answers:

	1. B        5. C        9. C		13. D		17. C

	2. D		6. A        10. D		14. A		18. B

	3. A        7. B        11. B		15. D		19. D

	4. A        8. A        12. C       16. C		20. A


	To do this you should create a TestGrader class. The class will have an answers array of 20 
	characters, which holds the correct test answers. It will have two public member functions  that 
	enable  user  programs to  interact  with  the  class: setKey and  grade. The  setKey function 
	receives a 20-character string holding  the correct  answers and copies this information into its 
	answers array.  The  grade function  receives a  20-character array  holding  the  test  taker’s 
	answers  and compares  each of their answers  to the correct  one. An applicant must correctly 
	answer 15 or more of the 20 questions  to pass the exam. After “grading” the exam, the grade 
	function  should create and return  to the user a string that includes the following information:
	• a message indicating  whether  the applicant passed or failed the exam
	• the number  of right answers and the number  of wrong answers
	• a list of the question  numbers  for all incorrectly  answered  questions.

	The client program that  creates and uses a TestGrader object should  first make a single call to 
	setKey, passing it a string containing  the 20 correct  answers.  Once this is done it should  
	allow  a test taker’s  20 answers  to be entered,  making  sure only answers  of A–D are  accepted, 
	 and  store  them  in  a  20-character array.  Then  it  should  call  the  grade function   to  
	grade  the  exam  and  should  display  the  string  the  function   returns. The program should  
	loop  to  allow  additional tests  to  be entered  and  graded  until  the  user
	indicates  a desire to quit.
*********************************************************************/
#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>
using namespace std;

class TestGrader
{
private:
	string answer[20];

public:
	void setKey(string[]);
	void grade(string[]);
};
/*********************************************************************/
void TestGrader::setKey(string correct[])
{
	for (int x = 0; x < 20; x++)
	{
		answer[x] = correct[x];
	}
}
void TestGrader::grade(string test[])
{
	int right = 0;
	int wrong = 0;
	int count = 0;

	for (int x = 0; x < 20; x++)
	{
		if (test[x] == answer[x])
		{
			right += 1;
			count += 1;
		}
		else if (test[x] != answer[x])
		{
			wrong += 1;
		}
	}

	if (count >= 15)
	{
		cout << "Congratulations you have passed the driver's license exam" << endl;
	}
	else
	{
		cout << "You failed the driver's license exam" << endl;
	}

	cout << "You got a total of " << right << " right answers and a total of " << wrong << " wrong answers in the test" << endl;


	cout << "You got questions ";
	for (int x = 0; x < 20; x++)
	{
		if (test[x] != answer[x])
		{
			cout << x + 1 << " ";
		}
	}
	cout << "wrong" << endl;
}



int main()
{
	string answers[20] = { "B", "D", "A", "A", "C", "A", "B", "A", "C", "D", "B", "C", "D", "A", "D", "C", "C", "B", "D", "A"};

	TestGrader exam;

	exam.setKey(answers);


	string yourTest[20];
	int choice;

	do
	{
		for (int x = 0; x < 20; x++)
		{
			cout << "Enter the answer for question " << x + 1 << ": ";
			cin >> yourTest[x];


			while (yourTest[x] > "D")
			{
				cout << "Please enter from A-D: ";
				cin >> yourTest[x];
			}
		}

		exam.grade(yourTest);

		cout << endl << "Enter -1 to quit, else enter any number to retake the exam: ";
		cin >> choice;

	} while (choice != -1);
	


	return 0;
}