#pragma once
#ifndef _WEATHER_h
#define _WEATHER_h
#include "Point.h"
class Weather
{
public:
	Weather();
	Weather(Point, Point);
	Point GetUpperLeft() const;
	Point GetLowerRight() const;

	bool CheckIfPointIsInWeather(Point);
private:
	Point m_upperLeft;
	Point m_lowerRight;
};
#endif
