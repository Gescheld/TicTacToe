#pragma once
#include <iostream>
#include "Player.h"

class Game
{
private:
	Player* player1;
	Player* player2;

public:
	// constructor initializes player1 and player2
	Game(Player* ply1, Player* ply2)
	{
		player1 = ply1; 
		player2 = ply2; 
	};

	// save original player
	Player* currentPlayer; 
	
	void run(Field* field)
	{
		// show player name and players character (X or O)
		std::cout << "Player 1 Name: " << player1->name << ". Char: " << player1->playerChar << std::endl;
		std::cout << "Player 2 Name: " << player2->name << ". Char: " << player2->playerChar << std::endl;

		// start with random player perspective
		field->isPlayer1Perspective = std::rand() %2;
		currentPlayer = field->isPlayer1Perspective ? player1 : player2; 

		// play as long as the field is free or no one has won
		while (!field->isFull() && !field->hasPlayerWon(player1->playerChar) && !field->hasPlayerWon(player2->playerChar))
		{
			if (player1->giveUp || player2->giveUp) return;
			currentPlayer->doTurn(field); 

			field->switchPerspective();
			switchCurrentPlayer(); 
		}

		// clear consol and draw final field
		system("cls");
		field->drawField();
		// Current player wins
		if (field->hasPlayerWon(player1->playerChar))
		{
			std::cout << "Player "<< player1->name << " (" << player1->playerChar << ")"<< " won" << std::endl;
			std::cout << "Player " << player2->name << " (" << player2->playerChar << ")" << " lost" << std::endl;
		}
		// current player losts
		else if (field->hasPlayerWon(player2->playerChar))
		{
			std::cout << "Player " << player2->name << " (" << player2->playerChar << ")" << " won" << std::endl;
			std::cout << "Player " << player1->name << " (" << player1->playerChar << ")" << " lost" << std::endl;

		}
		// Tie
		else std::cout << "\nTie \n";
	}

	void switchCurrentPlayer()
	{
		currentPlayer = (currentPlayer == player1) ? player2 : player1; 
	}
	

};
