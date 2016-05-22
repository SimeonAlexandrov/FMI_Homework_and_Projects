#pragma once
#include "Slave.h"

class Scholar : public Slave
{
public:
	void Work();

	Scholar();
	~Scholar();
	Scholar(string, int);

};