#pragma once
#include <iostream>
#include "Field.h"

// Abstract class from which each player inherits
class Player abstract
{
public:
	bool giveUp = false;
	enum playerType
	{
		local, AI
	};
	playerType type;
	std::string name;
	char playerChar = ' '; 
	char opponentChar = ' '; 
	virtual void doTurn(Field* field) = 0;
	virtual void onTie() {};

	virtual void PrintWin(Field* field, Player* playerWin, Player* playerLose)
	{
		std::cout << playerWin->name << " (" << playerWin->playerChar << ") won \n"; // due to switch perfpective
		std::cout << "\n" << playerLose->name << " (" << playerLose->playerChar<< ") lost \n";
	}

	virtual ~Player() {};  // destructor
};

