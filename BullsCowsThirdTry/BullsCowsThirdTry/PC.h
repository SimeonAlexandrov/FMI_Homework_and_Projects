#pragma once
#pragma once
#include "Player.h"
#include<random>

class PC : public Player
{
public:
	PC();
	int SelectRandom(); 
	int MakeGuess();
	void Respond(int);
};