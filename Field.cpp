#include "Field.h"

// constructor
Field::Field()
{
	resetField();
}

// clear the field
void Field::resetField() {
	this->numFreePositions = fieldSize;

	for (int i = 0; i < fieldSize; i++)
	{
		field[i] = ' ';
	}
}

void Field::drawField()
{
	std::cout << "\n\n\n"
		<< "     " << field[0] << " | " << field[1] << " | " << field[2] << std::endl
		<< "    ---|---|---" << std::endl
		<< "     " << field[3] << " | " << field[4] << " | " << field[5] << std::endl
		<< "    ---|---|---" << std::endl
		<< "     " << field[6] << " | " << field[7] << " | " << field[8] << std::endl;
}

int Field::getNumFreePositions()
{
	return numFreePositions;
}

int* Field::getFreePositions(int* positions)
{
	int arrayPos = 0;
	for (int i = 0; i < fieldSize; i++)
	{
		if (field[i] == ' ')
		{
			positions[arrayPos] = i;
			arrayPos++;
		}
	}
	return positions;
}

void Field::switchPerspective()
{
	isPlayer1Perspective = !isPlayer1Perspective;
}

bool Field::putMarkAt(int pos, char playerChar)
{
	if (field[pos] == ' ')
	{
		field[pos] = playerChar;
		numFreePositions--;
		return true;
	}
	return false;
}

void Field::putEmptyMarkAt(int pos)
{
	if (field[pos] != ' ')
	{
		field[pos] = ' ';
		numFreePositions++; // only increase truly new free positions
	}
}

bool Field::isEmptyMarkAt(int pos)
{
	return field[pos] == ' ';
}


bool Field::hasPlayerWon(char playerChar)
{
	return hasXOWon(playerChar);
}


bool Field::isFull()
{
	return numFreePositions <= 0;
}

bool Field::hasXOWon(char character)
{
	// check the possibilites of winning
	if (field[0] == character && field[1] == character && field[2] == character
		|| field[0] == character && field[3] == character && field[6] == character
		|| field[0] == character && field[4] == character && field[8] == character
		|| field[1] == character && field[4] == character && field[7] == character
		|| field[2] == character && field[5] == character && field[8] == character
		|| field[2] == character && field[4] == character && field[6] == character
		|| field[3] == character && field[4] == character && field[5] == character
		|| field[6] == character && field[7] == character && field[8] == character)
	{
		return true;
	}
	return false;
}


	
