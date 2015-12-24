#include "Patron.h"
using namespace std;


// Constructor
Patron::Patron(string id, string name)
{
	idNum = id;
	this->name = name;
	fineAmount = 0;
}

// Getter Functions
string Patron::getIdNum()
{
	return idNum;
}
string Patron::getName()
{
	return name;
}
vector <Book*> Patron::getCheckedOutBooks()
{
	return checkedOutBooks;
}
double Patron::getFineAmount()
{
	return fineAmount;
}

// Add Book Function
void Patron::addBook(Book* bookItem)
{
	checkedOutBooks.push_back(bookItem);
}

// Remove Book Function
void Patron::removeBook(Book* bookItem)
{
	for (int x = 0; x < checkedOutBooks.size(); x++)
	{
		if (checkedOutBooks[x]->getIdCode() == bookItem->getIdCode())
		{
			checkedOutBooks.erase(checkedOutBooks.begin()+x);
		}
	}
}

// Amend Fine Function
void Patron::amendFine(double extra)
{
	fineAmount += extra;
}