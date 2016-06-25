#pragma once
#include "Plant.h"

Plant::Plant()
{

}

Plant::Plant(Point p)
{
	int x = p.GetX();
	int y = p.GetY();
	m_coords.Set(x, y);
}

void Plant::SetCoords(int x, int y)
{
	m_coords.Set(x, y);
}

Point Plant::GetCoords() const
{
	Point toReturn;
	toReturn = m_coords;
	return toReturn;
}

void Plant::SetCapacity(unsigned int capacity)
{
	m_capacity = capacity;
}
unsigned int Plant::GetCapacity() const
{
	return m_capacity;
}

bool Plant::IsDead()
{
	if (m_capacity == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
