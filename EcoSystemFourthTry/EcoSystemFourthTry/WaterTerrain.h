#pragma once
#ifndef _WATER_TERRAIN_h
#define _WATER_TERRAIN_h
#include "Point.h"
class WaterTerrain
{
public:
	WaterTerrain();
	WaterTerrain(Point, Point);
	Point GetUpperLeft() const;
	Point GetLowerRight() const;

	bool IsInWater(Point);
private:
	Point m_upperLeft;
	Point m_lowerRight;
};
#endif
