#pragma once
#include "Slave.h"
#include "Swordsman.h"

class Emperor : public Swordsman
{
public:
	void Work();

	Emperor();
	~Emperor();
	Emperor(string, int);

};