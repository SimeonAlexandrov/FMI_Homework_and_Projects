#pragma once
#ifndef _GRASS_h
#define _GRASS_h
#include "Plant.h"

class Grass : public Plant
{
public:
	Grass();
	Grass(Point);
	void BeingRainedOn();
};
#endif
