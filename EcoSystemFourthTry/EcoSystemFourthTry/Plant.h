#pragma once
#ifndef _PLANT_h
#define _PLANT_h
#include "Point.h"
class Plant
{
public:
	Plant();
	Plant(Point);
	void SetCoords(int, int);
	Point GetCoords() const;

	void SetCapacity(unsigned int);
	unsigned int GetCapacity() const;

	virtual void BeingRainedOn() = 0;

protected:
	unsigned int m_capacity;
	Point m_coords;
	bool IsDead();

};
#endif // _PLANT_h
