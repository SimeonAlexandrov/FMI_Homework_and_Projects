#pragma once
#include "Player.h"
class ProtoGame
{
public:
	ProtoGame();
	virtual void Play();
	virtual bool HasWon();
	virtual void SaveScore();
	
protected:
	Player One;
	Player Two;
};