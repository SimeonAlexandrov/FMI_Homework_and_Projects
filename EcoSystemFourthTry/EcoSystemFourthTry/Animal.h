#pragma once
#ifndef _ANIMAL_h
#define _ANIMAL_h
#include "Point.h"
#include "Plant.h"
#include "Grass.h"
#include "Algae.h"

#include<random>
#include<vector>


class Animal
{
public:
	Animal();
	Animal(Point coords, char gender, unsigned int age, unsigned int maxAge, unsigned int stamina, unsigned int healthPoints, unsigned int foodCapacity);
	//constructors
	void SetCoords(int, int);
	void SetGender(char);
	void SetAge(unsigned int);
	void SetMaxAge(unsigned int);
	void SetStamina(unsigned int);
	void SetHealthPoints(unsigned int);
	void SetFoodCapacity(unsigned int);
	void SetKind(string);


	Point GetCoords() const;
	char GetGender() const;
	unsigned int GetAge() const;
	unsigned int GetMaxAge() const;
	unsigned int GetStamina() const;
	unsigned int GetHealthPoints() const;
	unsigned int GetFoodCapacity() const;
	string GetKind() const;

	//setters and getters

	//тука да се нашибат 4 FindFood с различни параметри вектор съответно  от Grass, Algae, Manatee, Elephant

	virtual Point FindFood(std::vector<Grass>)=0;

	virtual Point FindFood(std::vector<Algae>)=0;
	
	void MoveTo(Point); //TODO: check for stamina, then move
	virtual void IsInWrongArea(vector<WaterTerrain>) = 0;
	
	// assess the situation in the new square
	//		then
	//		Eat or
	//		Fight or
	//		Make love <3
	virtual void Eat(Grass) = 0;
	virtual void Eat(Algae) = 0;
	
	int GetRandomNumberOfKids();
	int GetRandomHealthPointsOfKids();
	int GetRandomFoodCapacityOfKids();
	int GetRandomGenderOfKids();
	int GetRandomStaminaOfKids();

protected:
	//updated property: kind
	string m_kind;
	Point m_coords;
	char m_gender;
	unsigned int m_age, m_maxAge;
	unsigned int m_stamina;
	unsigned int m_healthPoints;
	unsigned int m_foodCapacity;

	bool IsDead();

	vector<int> numberOfKids = { 1,2,3,4,5 };
	vector<int> genderOfKids = { 0, 1 }; //zero for male. one for female
	vector<int> healthPointsOfKids;
	void SetHealthPointsOfKids();
	vector<int> foodCapacityOfKids;
	void SetFoodCapacityOfKids();
	vector<int> staminaOfKids;
	void SetStaminaOfKids();
};
#endif
