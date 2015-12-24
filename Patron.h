#ifndef PATRON_H
#define PATRON_H
#include <string>
#include <vector>
#include "Book.h"

//class LibraryItem;

class Patron
{
private:
	std::string idNum;
	std::string name;
	std::vector<Book*> checkedOutBooks;
	double fineAmount;
public:
	Patron(std::string idn, std::string n);
	std::string getIdNum();
	std::string getName();
	std::vector<Book*> getCheckedOutBooks();
	void addBook(Book* b);
	void removeBook(Book* b);
	double getFineAmount();
	void amendFine(double amount);
};

#endif