#pragma once
#include "Player.h"

class LocalPlayer : public Player
{
public:
	LocalPlayer(char playerChar, char opponentChar, std::string name = "player");
	void doTurn(Field* field) override;
};


