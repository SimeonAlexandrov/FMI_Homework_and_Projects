#pragma once
#ifndef _POINT_h
#define _POINT_h
#include<algorithm>
#include<cmath>
#include<iostream>

using namespace std;
class Point
{
public:
	Point();
	Point(int, int);
	void SetX(int);
	void SetY(int);
	void Set(int, int);
	int GetX() const;
	int GetY() const;
	void PrintCoords(Point);
	double GetDistanceTo(Point);
	//bool IsInsideOfWaterArea(WaterTerrain);
	//bool IsInsideOfWeatherArea(Weather);

private:
	int m_x;
	int m_y;
};
#endif
