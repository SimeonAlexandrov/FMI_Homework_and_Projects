#pragma once
#include<iostream>
#include<vector>
#include<fstream>
#include<string>
using namespace std;

class Player
{
public:
	Player();
	Player(int);
	void SetNumber(int);
	int GetNumber() const;

	virtual void Respond(int);
	virtual int MakeGuess(int);

	int CheckForBulls(int);
	int CheckForCows(int);

protected:
	int m_number;
	vector<int> a;
	void SetA();
	bool CheckIfNumberIsCorrect();
};