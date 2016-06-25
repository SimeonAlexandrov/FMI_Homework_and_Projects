#pragma once
#ifndef _SHARK_h
#define _SHARK_h
#include "Animal.h"
#include "Manatee.h"
class Shark : public Animal
{
public:
	Shark() {};
	Shark(Point coords, char gender, unsigned int age, unsigned int maxAge, unsigned int stamina, unsigned int healthPoints, unsigned int foodCapacity);
	Point FindFood(std::vector<Grass>);
	Point FindFood(std::vector<Manatee>);
	Point FindFood(std::vector<Algae>);

	void Eat(Grass);
	void Eat(Algae);
	void Eat(Manatee);

	void IsInWrongArea(vector<WaterTerrain>);


	void SharkInteract(Shark, vector<Shark>);
private:

};
#endif