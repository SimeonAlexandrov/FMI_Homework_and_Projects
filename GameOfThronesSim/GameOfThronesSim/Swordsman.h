#pragma once
#include "Slave.h"
#include "Soldier.h"

class Swordsman : public Soldier
{
public:
	void Work();

	Swordsman();
	~Swordsman();
	Swordsman(string, int);

};