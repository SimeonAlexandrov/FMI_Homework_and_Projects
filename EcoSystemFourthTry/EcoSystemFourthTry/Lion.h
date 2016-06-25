#pragma once
#ifndef _LION_h
#define _LION_h
#include "Animal.h"
#include "Elephant.h"
class Lion : public Animal
{
public:
	Lion() {};
	Lion(Point coords, char gender, unsigned int age, unsigned int maxAge, unsigned int stamina, unsigned int healthPoints, unsigned int foodCapacity);
	Point FindFood(std::vector<Grass>);
	Point FindFood(std::vector<Elephant>);
	Point FindFood(std::vector<Algae>);

	void Eat(Grass);
	void Eat(Algae);
	void Eat(Elephant);

	void IsInWrongArea(vector<WaterTerrain>);

	void LionInteract(Lion, vector<Lion>);


private:

};
#endif