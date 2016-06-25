#include "Point.h"
Point::Point()
{
	m_x = 0;
	m_y = 0;
}
Point::Point(int x, int y)
{
	m_x = x;
	m_y = y;
}
void Point::SetY(int y)
{
	m_y = y;
}
void Point::SetX(int x)
{
	m_x = x;
}
int Point::GetX() const
{
	return m_x;
}
int Point::GetY() const
{
	return m_y;
}

void Point::Set(int x, int y)
{
	m_x = x;
	m_y = y;
}

double Point::GetDistanceTo(Point p)
{
	double distanceX = max(p.GetX(), m_x) - min(p.GetX(), m_x);
	double distanceY = max(p.GetY(), m_y) - min(p.GetY(), m_y);
	double manhattanDistance = sqrt(distanceX*distanceX + distanceY*distanceY);
	return manhattanDistance;
}

//bool Point::IsInsideOfWaterArea(WaterTerrain wt)
//{
//	if(m_x >= wt.GetUpperLeft().GetX() && m_x <= wt.GetLowerRight().GetX() && m_y <= wt.GetUpperLeft().GetY() && m_y >= wt.GetLowerRight().GetY())
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//
//bool Point::IsInsideOfWeatherArea(Weather w)
//{
//	if (m_x >= w.GetUpperLeft().GetX() && m_x <= w.GetLowerRight().GetX() && m_y <= w.GetUpperLeft().GetY() && m_y >= w.GetLowerRight().GetY())
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}

void Point::PrintCoords(Point p)
{
	cout << "x,y: " << p.GetX() << " " << p.GetY() << std::endl;
}
