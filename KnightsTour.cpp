// KnightsTour.cpp : Defines the entry point for the console application.
// Author: Nicholas Sorgen
// Section: S
//Assignment: Knights Tour
//Description:	This code will simulate the movement of a knight chess piece.
//				It will move the knight to every space on a chess board
//				without touching a space twice. The input data is in the
//				actual code. The output will be to the screen.
//
//1.	Declare constants for array sizes
//2.	Create two - dimensional array and fill with zeroes
//3.	Create int movNum and set to one
//4.	 Call bool function moveKnight
//a.Go through checking moves 1 – 8
//b.Check that space has a zero and that it is in bounds
//c.Move knight to space and then call moveKnight again
//5.	Call function to display array
//a.	Create for loop to display array (Counter variable < arrayRow, Increment counter)
//b.	Create for loop(counter variable < arrayCol, Increment counter)
//c.	Array[arrayCol][arrayRow] = char++

#include "stdafx.h"
#include <iostream>
#include <iomanip>

using namespace std;

//1.	Declare constants for array sizes
const int ARRAYSIZE = 8;
const int KPOSTWO = 2;
const int KNEGTWO = -2;
const int KPOSONE = 1;
const int KNEGONE = -1;

void displayArray(int chess[][ARRAYSIZE], int rows, long int tryCounter);
bool moveKnight(int chess[][ARRAYSIZE], int rows, int movNum, int kRow, int kCol, long int &tryCounter, bool& moveCheck);
bool actualMove(int chess[][ARRAYSIZE], int rows, int movNum, int kRow, int kCol, int rowMove, int colMove, long int& tryCounter, bool moveCheck2);
bool moveReversal(int movNum, int chess[][ARRAYSIZE], int rows, int kRow, int kCol, int rowMove, int colMove, bool moveCheck3);

int main()
{
	//2.	Create two - dimensional array and fill with zeroes
	int chess[ARRAYSIZE][ARRAYSIZE] = { 0 };
	//3.	Create int movNum and set to one
	int movNum = 1;
	long int tryCounter = 1;
	int kRow = 0;
	int kCol = 0;
	bool moveCheck = false;
	chess[kRow][kCol] = movNum;
	//4.	 Call bool function moveKnight
	moveKnight(chess, ARRAYSIZE, movNum, kRow, kCol, tryCounter, moveCheck);
	displayArray(chess, ARRAYSIZE, tryCounter);
	system("pause");
	//5.	Call function to display array
	cout << endl;

    return 0;
}

void displayArray(int chess[][ARRAYSIZE], int rows, long int tryCounter)
{
	system("CLS");
	//a.	Create for loop to display array (Counter variable < ARRAYSIZE, Increment counter)
	cout << endl << "-----------------------------------------" << endl;
	for (int counterRow = 0; counterRow < ARRAYSIZE; counterRow++)
	{
		cout << "|";
		//b.	Create for loop(counter variable < arrayCol, Increment counter)
		for (int counterCol = 0; counterCol < ARRAYSIZE; counterCol++)
		{
			//c.	Array[arrayCol][arrayRow]
			cout << setw(3) << chess[counterRow][counterCol] << setw(2) << "|";
		}
		cout << endl << "|----|----|----|----|----|----|----|----|";
		cout << endl;
	}
	cout << "It took " << tryCounter << " tries to get to the end." << endl;
	cout << "There were " << tryCounter - (ARRAYSIZE * ARRAYSIZE) << " bad moves" << endl;
}


bool moveKnight(int chess[][ARRAYSIZE], int rows, int movNum, int kRow, int kCol, long int &tryCounter, bool& moveCheck)
{
	if (moveCheck == false && chess[kRow - 2][kCol + 1] == 0 && kRow - 2 <= ARRAYSIZE - 1 && kRow - 2 >= 0 && kCol + 1 <= ARRAYSIZE - 1 && kCol + 1 >= 0)//Move 1
	{
		moveCheck = actualMove(chess, ARRAYSIZE, movNum, kRow, kCol, KNEGTWO, KPOSONE, tryCounter, moveCheck);
	}
	if (moveCheck == false && chess[kRow - 1][kCol + 2] == 0 && kRow - 1 <= ARRAYSIZE - 1 && kRow - 1 >= 0 && kCol + 2 <= ARRAYSIZE - 1 && kCol + 2 >= 0)//Move 2
	{
		moveCheck = actualMove(chess, ARRAYSIZE, movNum, kRow, kCol, KNEGONE, KPOSTWO, tryCounter, moveCheck);
	}
	if (moveCheck == false && chess[kRow + 1][kCol + 2] == 0 && kRow + 1 <= ARRAYSIZE - 1 && kRow + 1 >= 0 && kCol + 2 <= ARRAYSIZE - 1 && kCol + 2 >= 0)//Move 3
	{
		moveCheck = actualMove(chess, ARRAYSIZE, movNum, kRow, kCol, KPOSONE, KPOSTWO, tryCounter, moveCheck);
	}
	if (moveCheck == false && chess[kRow + 2][kCol + 1] == 0 && kRow + 2 <= ARRAYSIZE - 1 && kRow + 2 >= 0 && kCol + 1 <= ARRAYSIZE - 1 && kCol + 1 >= 0)//Move 4
	{
		moveCheck = actualMove(chess, ARRAYSIZE, movNum, kRow, kCol, KPOSTWO, KPOSONE, tryCounter, moveCheck);
	}
	if (moveCheck == false && chess[kRow + 2][kCol - 1] == 0 && kRow + 2 <= ARRAYSIZE - 1 && kRow + 2 >= 0 && kCol - 1 <= ARRAYSIZE - 1 && kCol - 1 >= 0)//Move 5
	{
		moveCheck = actualMove(chess, ARRAYSIZE, movNum, kRow, kCol, KPOSTWO, KNEGONE, tryCounter, moveCheck);
	}
	if (moveCheck == false && chess[kRow + 1][kCol - 2] == 0 && kRow + 1 <= ARRAYSIZE - 1 && kRow + 1 >= 0 && kCol - 2 <= ARRAYSIZE - 1 && kCol - 2 >= 0)//Move 6
	{
		moveCheck = actualMove(chess, ARRAYSIZE, movNum, kRow, kCol, KPOSONE, KNEGTWO, tryCounter, moveCheck);
	}
	if (moveCheck == false && chess[kRow - 1][kCol - 2] == 0 && kRow - 1 <= ARRAYSIZE - 1 && kRow - 1 >= 0 && kCol - 2 <= ARRAYSIZE - 1 && kCol - 2 >= 0)//Move 7
	{
		moveCheck = actualMove(chess, ARRAYSIZE, movNum, kRow, kCol, KNEGONE, KNEGTWO, tryCounter, moveCheck);
	}
	if (moveCheck == false && chess[kRow - 2][kCol - 1] == 0 && kRow - 2 <= ARRAYSIZE - 1 && kRow - 2 >= 0 && kCol - 1 <= ARRAYSIZE - 1 && kCol - 1 >= 0)//Move 8
	{
		moveCheck = actualMove(chess, ARRAYSIZE, movNum, kRow, kCol, KNEGTWO, KNEGONE, tryCounter, moveCheck);
	}
	return moveCheck;
}


bool actualMove(int chess[][ARRAYSIZE], int rows, int movNum, int kRow, int kCol, int rowMove, int colMove, long int& tryCounter, bool moveCheck2)
{
	kRow = kRow + rowMove;
	movNum++;
	tryCounter++;
	kCol = kCol + colMove;
	chess[kRow][kCol] = movNum;
	moveKnight(chess, ARRAYSIZE, movNum, kRow, kCol, tryCounter, moveCheck2);
	bool endCheck = moveReversal(movNum, chess, ARRAYSIZE, kRow, kCol, rowMove, colMove, moveCheck2);
	return endCheck;
}


bool moveReversal(int movNum, int chess[][ARRAYSIZE], int rows, int kRow, int kCol, int rowMove, int colMove, bool moveCheck3)
{
	if (movNum < ARRAYSIZE * ARRAYSIZE && moveCheck3 == false)
	{
		chess[kRow][kCol] = 0;
	}
	else
	{
		moveCheck3 = true;
	}
	return moveCheck3;
}