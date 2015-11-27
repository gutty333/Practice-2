#include <iostream>
#include <ctime>
#include <cstdlib>

#ifndef DICECUP_H
#define DICECUP_H

class DiceCup
{
	private:
		int diceNumber;
		int faceNumber;

	public:
		DiceCup();
		DiceCup(int, int);
		void setDiceNumber(int);
		void setFaceNumber(int);
		int rollDice();

};

#endif