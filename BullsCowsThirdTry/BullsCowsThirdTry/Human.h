#pragma once
#include "Player.h"

class Human : public Player
{
public:
	Human();
	Human(int);
	void Respond(int);
	int MakeGuess(int);
	void ReadSecretNumberFromFile();
};