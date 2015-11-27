#include "Supplies.h"


Supplies::Supplies()
{
	setThing(100);
	setWatch(70);
	setFrame(50);
}
Supplies::Supplies(int x, int y, int z)
{
	things = x;
	watch = y;
	frame = z;
}
void Supplies::setThing(int x)
{
	things = x;
}
void Supplies::setWatch(int y)
{
	watch = y;
}
void Supplies::setFrame(int z)
{
	frame = z;
}
void Supplies::printPartsOrder()
{
	int thingsParts = 100 - things;
	int watchParts = 70 - watch;
	int frameParts = 50 - frame;
	int zero = 0;

	cout << "The factory needs to order " << (things < 100 ? thingsParts : 0) << " thingamajigs, " << (watch < 70 ?watchParts : 0) << " watchamacallits and " << (frame< 50 ? frameParts : 0) << " framistats" << endl;
}
void Supplies::produce1(int amount)
{
	for (int x = 1; x <= amount; x++)
	{
		things -= 1;
		watch -= 2;
		frame -= 1;
	}
}
void Supplies::produce2(int amount)
{
	for (int x = 1; x <= amount; x++)
	{
		things -= 2;
		frame -= 1;
	}
}