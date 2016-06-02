#pragma once
#include "ProtoGame.h"
#include "Human.h"
#include "PC.h"

class PvPC : public ProtoGame
{
public:
	PvPC();
	~PvPC();
	void Play();
	bool HasWon(int);
	void SaveScore();
private:
	Player *yugi = new Human;
	Player *computer = new PC;
	int m_guessCount;
	void ExportGuessCount(int);
	
};