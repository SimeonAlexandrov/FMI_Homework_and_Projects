#include "Grass.h"

void Grass::BeingRainedOn()
{
	SetCapacity(100);
}

Grass::Grass()
{

}
Grass::Grass(Point coords)
{
	int x = coords.GetX();
	int y = coords.GetY();
	m_coords.Set(x, y);
}
