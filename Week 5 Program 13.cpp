/*********************************************************************
	Dice Cup Assignment 
*********************************************************************/
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "DiceCup.h"
using namespace std;

int main()
{

	int dice, faces, rollAmount;

	srand(time(0));

	cout << "How many dice are inside the cup: ";
	cin >> dice;
	cout << "How many faces do each of the dice have ";
	cin >> faces;
	cout << "How many times do you want to roll the dices ";
	cin >> rollAmount;

	DiceCup dice1, dice2(2, 6), dice3(dice, faces);

	cout << endl << "Dice 1 is " << dice1.rollDice() << endl;
	cout << "Dice 2 is " << dice2.rollDice() << endl;


	for (int x = 1; x <= rollAmount; x++)
	{
		cout << "Roll " << x << " is " << dice3.rollDice() << endl;

	}

	return 0;
}