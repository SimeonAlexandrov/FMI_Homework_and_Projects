#pragma once
#pragma once
#include "Player.h"
#include<random>

class PC : public Player
{
public:
	PC();
	int SelectRandom();
	void GetSecretNumber(); //test
	void Respond(int);
};