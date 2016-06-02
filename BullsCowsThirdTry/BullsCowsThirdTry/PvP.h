#pragma once
#include "Human.h"
#include "PC.h"
#include "ProtoGame.h"

class PvP : public ProtoGame
{
public:
	PvP();
	PvP(Human, Human);
	~PvP();
	PvP(const PvP & one, const PvP & two);
	PvP& operator=(const PvP&);
	
	void Play();
	bool HasWon(int);
	void SaveScore();
	void Print();

	
private:
	Player *yugi = new Human; //aka Player 1
	Player *kaiba = new Human; ////aka Player 2
	int m_guessCount;
	void ExportGuessCount(int);
	int GetGuessCount() const;
};