#include "DiceCup.h"
#include <ctime>
#include <cstdlib>

// Default Construct
DiceCup::DiceCup()
{
	diceNumber = 1;
	faceNumber = 2;
}
// Construct Overload
DiceCup::DiceCup(int x, int y)
{
	setDiceNumber(x);
	setFaceNumber(y);
}
// Mutator Function
void DiceCup::setDiceNumber(int x)
{
	diceNumber = x;
}
// Mutator Function
void DiceCup::setFaceNumber(int y)
{
	faceNumber = y;
}
// Roll Dice Function
int DiceCup::rollDice()
{
	int value = 0;

	for (int x = 1; x <= diceNumber; x++)
		value += rand() % faceNumber + 1;

	return value;
}