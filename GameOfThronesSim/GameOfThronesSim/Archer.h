#pragma once
#include "Slave.h"
#include "Soldier.h"

class Archer : public Soldier
{
public:
	void Work();

	Archer();
	~Archer();
	Archer(string, int);

};