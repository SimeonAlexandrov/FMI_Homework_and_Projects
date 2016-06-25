#include "WaterTerrain.h"

WaterTerrain::WaterTerrain()
{

}
WaterTerrain::WaterTerrain(Point p, Point q)
{
	int upperLeftX = p.GetX();
	int upperLeftY = p.GetY();
	int lowerRightX = q.GetX();
	int lowerRightY = q.GetY();

	m_upperLeft.Set(upperLeftX, upperLeftY);
	m_lowerRight.Set(lowerRightX, lowerRightY);
}



Point WaterTerrain::GetUpperLeft() const
{
	return m_upperLeft;
}

Point WaterTerrain::GetLowerRight() const
{
	return m_lowerRight;
}

bool WaterTerrain::IsInWater(Point p)
{	
	if (p.GetX() >= GetUpperLeft().GetX() && p.GetX() <= GetUpperLeft().GetX() && p.GetY() <= GetUpperLeft().GetY() && p.GetY() >= GetLowerRight().GetY())
	{
		return true;
	}
	else
	{
		return false;
	}
}
