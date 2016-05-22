#pragma once
#include "Slave.h"

class Soldier : public Slave
{
public:
	void Work();

	Soldier();
	~Soldier();
	Soldier(string, int);

};