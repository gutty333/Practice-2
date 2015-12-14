/*********************************************************************
	Theater  Ticket Sales

	Create  a  TicketManager class  and  a  program that  uses  it  to  sell tickets  for  a  single 
	performance theater  production. This project  is intended  to be designed and written  by a team 
	of 2–4 students.  Here are some suggestions:
	• One  student  might  design and  write  the client program that  uses the class, while other team 
	members design and write the TicketManager class and all of its functions.
	• Each student  should be given about  the same workload.
	• The class design and the names, parameters, and return  types of each function  should be decided 
	in advance.
	• The project  can be implemented either  as a multi-file  program, or all the functions can be cut 
	and pasted into a single file.

	Here are the specifications:
	• The theater’s auditorium has 15 rows, with 30 seats in each row. To represent  the seats, the  
	TicketManager class should  have a two-dimensional array  of SeatStructures. Each of these 
	structures should  have data  members  to keep track  of the seat’s price and whether  or not it is 
	available or already sold.
	• The seat prices should  be read  in from  the SeatPrices.dat file. It contains  15 values 
	representing  the price for each row. All seats in a given row are the same price, but different 
	rows  have different  prices. The seat availability  information should  be read  in from  the 
	SeatAvailability.dat file. It contains 450 characters (15 rows with 30 characters each), indicating 
	which seats have been sold ('*') and which are available ('#'). Initially all seats are available.  
	However,  once the program runs and the file is updated, some of the seats will have been sold. The 
	obvious function to read in the data from these files and set up the array is the constructor that 
	runs when the TicketManager object is first created.
	• The client program should  be a menu-driven program that  provides  the user with a
	menu of box office options,  accepts and validates user inputs,  and calls appropriate class 
	functions  to carry out desired tasks. The menu should  have options  to display the seating chart, 
	 request  tickets, print  a sales report,  and exit the program.
	• When the user selects the display seats menu option,  a TicketManager function  should be called 
	that creates and returns  a string holding a chart,  similar to the one shown here. It  should  
	indicate  which  seats  are  already  sold  (*) and  which  are  still  available  for
	purchase (#). The client program should then display the string.
							Seats
				123456789012345678901234567890
	Row 1		***###***###*########*****#### 
	Row 2		####*************####*******## 
	Row 3		**###**********########****### 
	Row 4		**######**************##****** 
	Row 5		********#####*********######## 
	Row 6		##############************#### 
	Row 7		#######************########### 
	Row 8		************##****############ 
	Row 9		#########*****############**** 
	Row 10		#####*************############ 
	Row 11		#**********#################** 
	Row 12		#############********########* 
	Row 13		###***********########**###### 
	Row 14		############################## 
	Row 15		##############################

	• When  the user selects the request  tickets  menu  option,  the program should  prompt
	for the number  of seats the patron wants,  the desired row  number,  and  the desired starting
	seat number.  A TicketManager ticket request function  should then be called and  passed  this
	information so  that  it  can  handle  the  ticket  request.  If any  of the requested  seats do
	not  exist,  or are not  available,  an appropriate message should  be returned to be displayed  by
	the client program. If the seats exist and  are available,  a string should be created and returned
	that lists the number  of requested  seats, the price per seat in the requested  row, and the total
	price for the seats. Then the user program should ask if the patron wishes to purchase  these
	seats.
	• If the patron indicates  they do want  to buy the requested  seats,  a TicketManager purchase
	tickets module should be called to handle the actual sale. This module must be able to accept
	money, ensure that it is sufficient to continue  with the sale, and if it is, mark  the seat(s) as
	sold, and  create and  return  a string  that  includes  a ticket  for each seat sold (with the
	correct  row, seat number,  and price on it).
	• When the user selects the sales report menu option,  a TicketManager report  module should  be
	called. This module  must create and return  a string holding  a report  that tells how  many
	seats have been sold,  how  many  are still available,  and  how  much money has been collected so
	far for the sold seats. Think  about  how your team will either calculate  or collect and store
	this information so that  it will be available  when it is needed for the report.
	• When the day of ticket sales is over and the quit menu choice is selected, the program needs to
	be able to write the updated seat availability  data  back out to the file. The obvious  place to
	do this is in the TicketManager destructor.
*********************************************************************/
#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <fstream>
using namespace std;

ifstream infile("SeatPrices.dat");
ifstream infile2("SeatAvailability.dat");
ofstream outfile("SeatResult.dat");

struct SeastStructures
{
	double cost;
	char valid;
};

class TicketManager
{
	private:
		SeastStructures theater[15][30];
		int seatTotal;
		double priceTotal;



	public:
		TicketManager();
		~TicketManager();
		void viewPrice();
		void viewSeats();
		void orderSeats(int, int, int, char&);
		void updateSeats(int, int, int);
		void report();
};


// Default Constructor
TicketManager::TicketManager()
{
	seatTotal = priceTotal = 0;

	double price;

	for (int row = 0; row < 15; row++)
	{

		infile >> price;

		for (int col = 0; col < 30; col++)
		{
			theater[row][col].cost = price;
			infile2 >> theater[row][col].valid;
		}
	}
}
// Destructor
TicketManager::~TicketManager()
{
	for (int row = 0; row < 15; row++)
	{
		outfile << "Row " << left << setw(8) << row + 1;

		for (int col = 0; col < 30; col++)
		{
			outfile << theater[row][col].valid;
		}

		outfile << endl;
	}

	outfile << "Seats Sold: " << seatTotal << endl;
	outfile << "Seats Available: " << (15 * 30) - seatTotal << endl;
	outfile << "Money Collected: $" << priceTotal << endl;

	outfile.close();
}



// View Price member function
void TicketManager::viewPrice()
{
	for (int row = 0; row < 15; row++)
	{
		for (int col = 0; col < 30; col++)
		{
			cout << theater[row][col].cost<< " ";
		}

		cout << endl;
	}
}


// View Seats member function
void TicketManager::viewSeats()
{

	for (int row = 0; row < 15; row++)
	{
		cout << "Row " << left << setw(8) << row + 1;

		for (int col = 0; col < 30; col++)
		{
			cout << theater[row][col].valid;
		}

		cout << endl;
	}
}


// Order Seats Member Function
void TicketManager::orderSeats(int number, int rowNum, int startNum, char& purchase)
{
	bool order = true; 


	for (int x = 0; x < number; x++)
	{
		if (theater[rowNum][startNum+x].valid == '*')
		{
			cout << "Seats are not available" << endl;
			order = false;
			purchase = 'N';
			break;
		}
	}

	if (order)
	{
		cout << "The number of requested seats: " << number << endl;
		cout << "The price for each seat in this row is: $" << theater[rowNum][0].cost << endl;
		cout << "The total cost is: $" << theater[rowNum][0].cost * number << endl;
		cout << endl << "Do you want to purchase these seats? (Y/N) ";
		cin >> purchase;
	}
}



// Update Seats Member Function
void TicketManager::updateSeats(int number, int row, int colum)
{
	for (int x=0; x < number; x++)
	{
		theater[row][colum+x].valid = '*';
	}
}





// Report Member Function
void TicketManager::report()
{
	for (int row = 0; row < 15; row++)
	{
		for (int col = 0; col < 30; col++)
		{
			if (theater[row][col].valid == '*')
			{
				seatTotal++;
				priceTotal += theater[row][col].cost;
			}
		}
	}

	cout << "Seats Sold: " << seatTotal << endl;
	cout << "Seats Available: " << (15 * 30) - seatTotal << endl;
	cout << "Money Collected: $" << priceTotal << endl;
}





// Client/Test Program
int main()
{
	


	string line;
	int choice, row, seatAmount, startingSeat;
	char purchase;
	TicketManager theater;

	cout << fixed << setprecision(2);

	do
	{
		cout << "Box Office Option Menu" << endl;
		cout << "1. Display Seating Chart" << endl;
		cout << "2. Request Tickets" << endl;
		cout << "3. Print Sales Report" << endl;
		cout << "4. Exit Program" << endl;
		cin >> choice;

		while (choice < 1 || choice > 4)
		{
			cout << "Please enter a valid input (1-4): ";
			cin >> choice;
		}

		switch (choice)
		{
			case 1:
				cout << endl << "Displaying the seating chart of the theater" << endl;
				theater.viewSeats();
				break;


			case 2:
				cout << endl << "How many seats do you want: ";
				cin >> seatAmount;

				cout << "In what row do you want to sit? ";
				cin >> row;

				cout << "Set your starting/column seat number: ";
				cin >> startingSeat;


				theater.orderSeats(seatAmount, row, startingSeat, purchase);
				

				if (toupper(purchase) == 'Y')
				{
					cout << "The seats have been purchased" << endl;
					theater.updateSeats(seatAmount, row, startingSeat);
				}
				else
				{
					cout << "The seats have not been purchased" << endl;
				}

				break;


			case 3:
				cout << endl << "Here is the report " << endl;

				theater.report();
				break;


			case 4:
				cout << endl << "Thank you for the time, come again soon!" << endl;
				break;
		}

		cout << endl;
	} while (choice != 4);
	
	
	infile.close();
	infile2.close();



	return 0;
}