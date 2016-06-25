 #pragma once
#include "ProtoGame.h"
#include "Human.h"
#include "PC.h"

class PvPC : public ProtoGame
{
public:
	PvPC();
	PvPC(Human, PC);
	void Play();
	bool HasWon(int);
	void SaveScore();
private:
	Human yugi;
	PC computer;
	int m_guessCount;
	void ExportGuessCount(int);
	
};