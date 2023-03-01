#include "LocalPlayer.h"

LocalPlayer::LocalPlayer(char playerChar, char opponentChar, std::string input_name)
{
	this->playerChar = playerChar; 
	this->opponentChar = opponentChar; 
	this->type = Player::playerType::local; 
	this->name = input_name;
}

void LocalPlayer::doTurn(Field* field)
{
	int pos = 0;
	char input = ' ';
	while (true)
	{
		giveUp = false;
		field->drawField();
		std::cout << "\n" << name << " Select field you want to put your mark at:  ";
		std::cin >> input; 
		// quitting is always possible
		if (input == 'q' || input == 'Q') 
		{
			giveUp = true;
			return;
		}
		pos = input - '0'; // char to int
		pos--; // configurate input bewteen 1-9 to 0-8 (field[0:8])
		if (pos <= 8 && pos >= 0)
		{
			// check if field is empty
			if (field->isEmptyMarkAt(pos))
			{
				field->putMarkAt(pos, playerChar);
				return;
			}
			else
			{
				system("cls"); // clear console
				std::cout << "Field at position " << pos+1 << " is already occupied.\nPlease try again";
			}
		}
		else
		{
			std::cout << "Input not recognized: Please try again\n " << std::endl;
			pos = 0;
		}
	}
}

