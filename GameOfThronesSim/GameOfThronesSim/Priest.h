#pragma once
#include "Slave.h"

class Priest : public Slave
{
public:
	void Work();

	Priest();
	~Priest();
	Priest(string, int);

};