#pragma once
#include "Slave.h"

class Trader : public Slave 
{
public:
	void Work();
	Trader();
	~Trader();
	Trader(string, int);
	
	
	
};
