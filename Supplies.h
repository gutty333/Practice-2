#include <iostream>
#include <string>
using namespace std;

#ifndef SUPPLIES_H
#define SUPPLIES_H


class Supplies
{
	private:
		int things,
			watch,
			frame;

	public:
		Supplies();
		Supplies(int, int, int);
		void setThing(int);
		void setWatch(int);
		void setFrame(int);
		void printPartsOrder();
		void produce1(int);
		void produce2(int);
};

#endif