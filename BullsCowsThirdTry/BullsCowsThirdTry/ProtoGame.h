#pragma once
#include "Player.h"
class ProtoGame
{
public:
	ProtoGame();
	ProtoGame(Player, Player);
	virtual void Play();
	virtual bool HasWon();
	virtual void SaveScore();
	
protected:
	Player m_One;
	Player m_Two;
};