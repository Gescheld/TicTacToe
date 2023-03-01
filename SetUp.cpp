#include "SetUp.h"

void SetUp::help() {
	system("cls");
	std::cout << "HELP\n\nSingleplayer:\nIn Singleplayermode you play against the Computer\n\n" << std::endl
		<< "Multiplayer:\nIn Multiplayermode you play against a second player.\nInput switches between X and O.\n" << std::endl
		<< "You can also play this mode if you want to test new tactics or just want to play against yourself.\n\n" << std::endl
		<< "Controls:\nTo choose a field you must enter a number between 1 and 9. The first field (1) is in the top left, the second (2) right next to it etc.\n\n" << std::endl;
	return;
}

void SetUp::printMenu(char* inputpointer)
{
	std::cout << "\n"
		<< "TicTacToe - Main Menu\n\n"
		<< "1: Singleplayer\n"
		<< "2: Multiplayer\n"
		<< "3: Help\n"
		<< "4: Quit\n\n\n"
		<< "Input: ";
	std::cin >> *inputpointer;
}

void SetUp::menu()
{
	char inputmenu;

	std::string name1 = " ";
	std::string name2 = " ";
	while (true)
	{
		printMenu(&inputmenu);
		
		// single player
		if (inputmenu == '1')
		{
			std::cout << "\nPlease enter your name: " << std::endl;
			std::cin >> name1;
			// start game
			(new Game(new LocalPlayer('X','O', name1), new AIPlayer('O','X')))->run(&field);
			field.resetField();
		}
		// multiplayer
		else if (inputmenu == '2')
		{
			std::cout << "\nPlease enter the name of player 1: " << std::endl;
			std::cin >> name1;
			std::cout << "\nPlease enter the name of player 2: " << std::endl;
			std::cin >> name2;

			// start game
			(new Game(new LocalPlayer('X', 'O', name1), new LocalPlayer('O', 'X',name2)))->run(&field);
			field.resetField();
		}
		// show help
		else if (inputmenu == '3')
		{
			help();
		}
		// quit
		else if (inputmenu == '4' || inputmenu == 'q' || inputmenu == 'Q')
		{
			break;	
		}
		else {
			std::cout << "\nINVALID INPUT.\nPlease try again. Choose 4 for help.\n ";
		}
	}
	
}
