
#include "Library.h"
#include <iostream>
using namespace std;


Library::Library()
{
	currentDate = 0;
}



// Add Member Function
void Library::addBook(Book* book)
{
	holdings.push_back(book);
}
void Library::addPatron(Patron* person)
{
	members.push_back(person);
}


// Get Book/Patron	Functions
// Checks to see if book/patron is in the vector 
// If not return NULL/0
Book* Library::getBook(string id)
{
	for (int x = 0; x < holdings.size(); x++)
	{
		if (holdings[x]->getIdCode() == id)
		{
			return holdings[x];
		}
	}

	return NULL;
}
Patron* Library::getPatron(string id)
{
	for (int x = 0; x < members.size(); x++)
	{
		if (members[x]->getIdNum == id)
		{
			return members[x];
		}
	}

	return NULL;
}



// Checkout Book Function
string Library::checkOutBook(string personID, string bookID)
{
	bool personFound = false;
	bool bookFound = false;

	int index, index2;

	for (int x = 0; x < members.size(); x++)
	{
		if (members[x]->getIdNum() == personID)
		{
			personFound = true;
			index = x;
		}
	}
	for (int x = 0; x < holdings.size(); x++)
	{
		if (holdings[x]->getIdCode() == bookID)
		{
			bookFound = true;
			index2 = x;
		}
	}


	if (!bookFound)
	{
		return "Book not found \n";
	}
	else if (!personFound)
	{
		return "Patron not found \n";
	}
	else if (holdings[index2]->getCheckedOutBy())
	{
		return "Book already checked out \n";
	}
	else if (holdings[index2]->getRequestedBy() != members[index])
	{
		return "Book on hold by other patron \n";
	}
	else
	{

		holdings[index2]->setCheckedOutBy(members[index]);
		holdings[index2]->setDateCheckedOut(currentDate);
		holdings[index2]->setLocation(CHECKED_OUT);
		if (holdings[index2]->getRequestedBy() == members[index])
		{
			holdings[index2]->setRequestedBy(NULL);
		}
		members[index]->addBook(holdings[index2]);
		return "Check out successful \n";
	}
}
// Return Book Function
string Library::returnBook(string id)
{
	bool bookFound = false;
	Patron* temp;
	int index;

	for (int x = 0; x < holdings.size(); x++)
	{
		if (holdings[x]->getIdCode() == id)
		{
			bookFound = true;
			index = x;
		}
	}


	if (!bookFound)
	{
		return "Book not found \n";
	}
	else if (holdings[index]->getLocation() != CHECKED_OUT)
	{
		return "Book already in library \n";
	}
	else
	{
		temp = holdings[index]->getCheckedOutBy();
		temp->removeBook(holdings[index]);
		holdings[index]->setCheckedOutBy(NULL);

		if (holdings[index]->getRequestedBy() != NULL)
		{
			for (int x = 0; x < members.size(); x++)
			{
				if (holdings[index]->getRequestedBy() == members[x])
				{
					holdings[index]->setLocation(CHECKED_OUT);
					holdings[index]->setCheckedOutBy(members[x]);
				}
			}
		}
		else
		{
			holdings[index]->setLocation(ON_SHELF);
		}
		return "return successful \n";
	}
}
// Request Book Function
string Library::requestBook(string patronId, string bookId)
{
	bool bookFound = false;
	bool patronFound = false;
	int index, index2;

	for (int x = 0; x < holdings.size(); x++)
	{
		if (holdings[x]->getIdCode() == bookId)
		{
			bookFound = true;
			index = x;
		}
	}
	for (int x = 0; x < members.size(); x++)
	{
		if (members[x]->getIdNum() == patronId)
		{
			patronFound = true;
			index2 = x;
		}
	}


	if (!bookFound)
	{
		return "Book not found \n";
	}
	else if (!patronFound)
	{
		return "Patron not found \n";
	}
	else if (holdings[index]->getRequestedBy() != members[index2])
	{
		return "Book on hold by other patron \n";
	}
	else
	{
		holdings[index]->setRequestedBy(members[index2]);
		if (holdings[index]->getLocation() == ON_SHELF)
		{
			holdings[index]->setLocation(ON_HOLD_SHELF);
		}
		return "request successful \n";
	}
}



// Pay Fine Function
string Library::payFine(string personId, double payment)
{
	bool patronFound = false;
	int index;

	for (int x = 0; x < members.size(); x++)
	{
		if (members[x]->getIdNum() == personId)
		{
			patronFound = true;
			index = x;
		}
	}

	if (!patronFound)
	{
		return "Patron not found \n";
	}
	else
	{
		members[index]->amendFine(payment);
		return "Payment successful \n";
	}
}



// Increment Current Date Function
void Library::incrementCurrentDate()
{
	currentDate++;
	bool fine;
	int extraDate;

	for (int x = 0; x <holdings.size() ; x++)
	{
		fine = false;

		if (currentDate > holdings[x]->getCheckOutLength())
		{
			extraDate = currentDate - holdings[x]->getCheckOutLength();
			fine = true;
		}

		if (fine)
		{
			while (extraDate > 0)
			{
				for (int y = 0; y < members.size(); y++)
				{
					members[y]->amendFine(.10);
				}

				extraDate--;
			}
		}
	}

}