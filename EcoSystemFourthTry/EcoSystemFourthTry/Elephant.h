#pragma once
#ifndef _ELEPHANT_h
#define _ELEPHANT_h
#include "Animal.h"
#include<algorithm>
#include "Manatee.h"
class Elephant : public Animal
{
public:
	Elephant() {};
	Elephant(Point coords, char gender, unsigned int age, unsigned int maxAge, unsigned int stamina, unsigned int healthPoints, unsigned int foodCapacity);
	Point FindFood(std::vector<Grass>);
	Point FindFood(std::vector<Algae>);

	void Eat(Grass);
	void Eat(Algae);

	void ElephantInteract(Elephant, vector<Elephant> allElephants);

	void IsInWrongArea(vector<WaterTerrain>);
	 
private:

};
#endif
