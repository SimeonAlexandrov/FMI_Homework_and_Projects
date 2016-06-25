#include "ProtoGame.h"

ProtoGame::ProtoGame()
{
}

ProtoGame::ProtoGame(Player one, Player two)
{
	m_One = one;
	m_Two = two;
}

void ProtoGame::Play()
{
	cout << "playplayplay";
}

bool ProtoGame::HasWon()
{
	return false;
}

void ProtoGame::SaveScore()
{
	cout << "no score in protogames";
}


