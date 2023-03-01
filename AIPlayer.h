#pragma once
#include <random>
#include <time.h>

#include "Player.h"

class AIPlayer : public Player
{
private:
	int diffLevel = 0;
	int intelligenceLevel = 0;
public:
	AIPlayer(char AIChar, char opponentChar);
	void levelSelection();
	void doTurn(Field* field) override;
};



