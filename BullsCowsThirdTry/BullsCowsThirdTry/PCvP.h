#pragma once
#include "ProtoGame.h"
#include "Human.h"
#include "PC.h"
class PCvP : public ProtoGame
{
	//WARNING!
	//The methods which are going to be used below are scam. The real algotrithms used for computers are way too complex for the creator of this project
	//I made some research about the theory of the game Bulls and Cows and apparently, a guy named Alexey Slovesnov wrote a book about the theory of the game and even implemented it in a C++ project.
	//However, the project contains roughly a 10 000 rows of code, which is rather discouraging for me.

public:
	PCvP();

	void Play();
	bool HasWon();
	void SaveScore();
private:
	PC computer;
	Human yugi;
	int m_guessCount;
	void ExportGuessCount(int);
	int GetGuessCount() const;

};