#pragma once
#include "Human.h"
#include "PC.h"
#include "ProtoGame.h"

class PvP : public ProtoGame
{
public:
	PvP();
	void Play();
	bool HasWon(int);
	void SaveScore();
	
private:
	Human yugi; //aka Player 1
	Human kaiba; ////aka Player 2
	int m_guessCount;
	void ExportGuessCount(int);
	int GetGuessCount() const;
};