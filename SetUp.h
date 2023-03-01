#pragma once
#include <iostream>
#include "Field.h"
#include "AIPlayer.h"
#include "LocalPlayer.h"
#include "Game.h"

class SetUp
{
private:
	Field field = Field(); // An overall field (reset needed)

public:
	void help();
	void printMenu(char* inputpointer);
	void menu();

};