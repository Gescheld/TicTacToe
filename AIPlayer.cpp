#include "AIPlayer.h"

// Choose degree of difficulty
void AIPlayer::levelSelection()
{
	giveUp = false;
	char input = ' ';
	std::cout << "\n\nDIFFICULTY\n\n1: Easy\n2: Medium\n3: Hard\n\n4: Return\n";
	std::cin >> input;
	int inputNumber = input - '0'; // char to int
	// Return to menu
	if (input == '4' || input == 'q' || input == 'Q') {
		giveUp = true;
		system("cls");
		return;
	}
	if (1 <= inputNumber && 4 > inputNumber) {
		this->diffLevel = inputNumber;
		// Get the intelligence Level depending on the difficulty. Later used for Modulu calculation
		if (inputNumber == 1) this->intelligenceLevel =3;
		else if (inputNumber == 2) this->intelligenceLevel = 4;
		else { this->intelligenceLevel = 1; std::cout << "HARD" << std::endl; }
	}
	else { system("cls"); std::cout << "\nInvalid Input!"; levelSelection(); }
}

AIPlayer::AIPlayer(char AIChar, char opponentChar) //constructor
{
	system("cls"); // clear console
	AIPlayer::levelSelection();
	this->type = Player::playerType::AI; 
	this->name = "AI"; 
	this->playerChar = AIChar; 
	this->opponentChar = opponentChar; 
}

void AIPlayer::doTurn(Field* field)
{
	int numPossibilities = field->getNumFreePositions();
	int* possibilities = new int[numPossibilities];

	srand((unsigned int)time(nullptr));
	int intelligence = rand() % intelligenceLevel + 1;
	std::cout << "intelligence: " << intelligence << std::endl;
	field->getFreePositions(possibilities);

	for (int i = 0; i < numPossibilities; i++)
	{
		// Hard: 100%, Medium: 75%, Easy: 33% chance of enter the loop
		if (intelligence != 2 || intelligenceLevel == 1) {

			// test own mark for a win
			field->putMarkAt(possibilities[i], playerChar);
			if (field->hasPlayerWon(playerChar)) 
			{
				return;
			}
			field->putEmptyMarkAt(possibilities[i]); // deletes previously set mark
		}
		if (intelligence != 3 || intelligenceLevel == 1) {
			// test opponent mark for a win
			field->putMarkAt(possibilities[i], opponentChar);
			if (field->hasPlayerWon(opponentChar))
			{
				field->putEmptyMarkAt(possibilities[i]);
				field->putMarkAt(possibilities[i], playerChar);
				return;
			}
			field->putEmptyMarkAt(possibilities[i]); // deletes previously set mark
		}
		if (intelligence != 1 || intelligenceLevel == 1) {
			if (possibilities[i] == 4) {
				field->putMarkAt(possibilities[i], playerChar); // place it in the middle
				return;
			}
		}
	}
	field->putMarkAt(possibilities[rand() % numPossibilities], playerChar); // choose a random field
}

