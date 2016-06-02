#pragma once
#include "ProtoGame.h"

class PvPC : public ProtoGame
{
public:
	PvPC();
	void Play();
	bool HasWon(int);
	void SaveScore();
private:
	Human yugi
};