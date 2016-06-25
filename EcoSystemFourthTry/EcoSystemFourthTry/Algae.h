#pragma once
#ifndef _ALGAE_h
#define _ALGAE_h
#include "Plant.h"
#include "WaterTerrain.h"

class Algae : public Plant
{
public:
	bool CheckIfInWater();
	void BeingRainedOn();
};
#endif
