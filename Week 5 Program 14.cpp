/*********************************************************************
	Ups and Downs

	Write  a program that  displays  the word  UP on the bottom line of the screen a couple  of inches 
	to the left of center  and  displays  the word  DOWN on the top  line of the screen a couple of 
	inches to the right of center. Moving about  once a second, move the word UP up a line and  the  
	word  DOWN down  a line until  UP disappears  at  the  top  of the  screen  and
	DOWN disappears  at the bottom of the screen.



	Wrapping Ups and Downs

	Modify the program you wrote for Programming Challenge 12, so that after disappearing off of the
	screen,  the  word  UP reappears at  the  bottom of the  screen  and  the  word  DOWN reappears at
	the top  of the screen. Have  these words  each traverse  the screen three  times
	before the program terminates.
*********************************************************************/
#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;



// Place cursors function
void placeCursor(HANDLE screen, int row, int col)
{
	COORD position;
	position.X = col;
	position.Y = row;

	SetConsoleCursorPosition(screen, position);
}


void upMove(HANDLE screen, string name)
{
	for (int x = 100; x > 0; x--)
	{
		placeCursor(screen, 5, x);
		cout << name << endl;
	}
}

int main()
{

	HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);


	string up = "UP";


	upMove(screen,up);

	return 0;
}