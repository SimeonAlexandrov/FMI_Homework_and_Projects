#pragma once
#ifndef _MANATEE_h
#define _MANATEE_h
#include "Animal.h"
class Manatee :public Animal
{
public:
	Manatee() {};
	Manatee(Point coords, char gender, unsigned int age, unsigned int maxAge, unsigned int stamina, unsigned int healthPoints, unsigned int foodCapacity);
	Point FindFood(std::vector<Grass>);
	Point FindFood(std::vector<Algae>);
	void Eat(Grass);
	void Eat(Algae);
	void IsInWrongArea(vector<WaterTerrain>);

	void ManateeInteract (Manatee, vector<Manatee>);

private:

};
#endif