
#include <iostream>
#include <string>
using namespace std;
#include "Book.h"


// Constructor
Book::Book(string id, string name, string author)
{
	idCode = id;
	title = name;
	this->author = author;
	checkedOutBy = requestedBy = NULL;
	location = ON_SHELF;
}




// Setter Member Function
void Book::setLocation(Locale area)
{
	location = area;
}
void Book::setCheckedOutBy(Patron* person)
{
	checkedOutBy = person;
}
void Book::setRequestedBy(Patron* person)
{
	requestedBy = person;
}
void Book::setDateCheckedOut(int date)
{
	dateCheckedOut = date;
}


// Getter Member Functions
int Book::getCheckOutLength()
{
	return CHECK_OUT_LENGTH;
}
string Book::getIdCode()
{
	return idCode;
}
string Book::getTitle()
{
	return title;
}
string Book::getAuthor()
{
	return author;
}
Locale Book::getLocation()
{
	return location;
}
Patron* Book::getCheckedOutBy()
{
	return checkedOutBy;
}
Patron* Book::getRequestedBy()
{
	return requestedBy;
}
int Book::getDateCheckedOut()
{
	return dateCheckedOut;
}