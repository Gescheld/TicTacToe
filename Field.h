#pragma once
#include <iostream>

class Field
{
private:
	int numFreePositions = fieldSize;
	char field[9];
public:	

	// constructor with default parameters
	Field(); 
	bool hasXOWon(char character);
	bool isPlayer1Perspective = true;

	int fieldSize = 9;
	void resetField();
	void drawField();

	int getNumFreePositions(); // to determine array size for free all index
	int* getFreePositions(int* position); // saves all free positions

	void switchPerspective(); // between the two players

	bool putMarkAt(int pos, char playerChar);
	void putEmptyMarkAt(int pos);

	bool isEmptyMarkAt(int pos);

	bool hasPlayerWon(char playerChar);
	bool isFull();

};
