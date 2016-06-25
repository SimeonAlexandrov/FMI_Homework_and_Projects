#pragma once
#include "Lion.h"


Lion::Lion(Point coords, char gender, unsigned int age, unsigned int maxAge, unsigned int stamina, unsigned int healthPoints, unsigned int foodCapacity)
{
	m_coords = coords;
	m_gender = gender;
	m_age = age;
	m_maxAge = maxAge;
	m_stamina = stamina;
	m_healthPoints = healthPoints;
	m_foodCapacity = foodCapacity;
}
/*Point Lion::FindElephants(vector<Grass> availableElephants)
{

}
*/

Point Lion::FindFood(std::vector<Grass> availableElephants)
{
	Point useless;
	return useless;
	//not used
}

Point Lion::FindFood(std::vector<Algae>)
{
	Point useless;
	return useless;
	//not used
}


Point Lion::FindFood(std::vector<Elephant> availableElephants)
{
	Point nearestPlant = availableElephants[0].GetCoords();
	double shortestDistance = m_coords.GetDistanceTo(availableElephants[0].GetCoords());

	for (unsigned int i = 1; i < availableElephants.size(); i++)
	{
		if (m_coords.GetDistanceTo(availableElephants[i].GetCoords()) <= shortestDistance)
		{
			shortestDistance = m_coords.GetDistanceTo(availableElephants[i].GetCoords());
			nearestPlant = availableElephants[i].GetCoords();
		}
	}
	return nearestPlant;
}

void Lion::Eat(Elephant e)
{
	e.SetHealthPoints(e.GetHealthPoints() - m_foodCapacity);
	m_healthPoints = min(100, int(m_healthPoints + m_foodCapacity));

}

void Lion::Eat(Grass g)
{
	//not needed
}

void Lion::Eat(Algae a)
{
	//not needed
}

//void Lion::Fight(Lion l)
//{
//	m_healthPoints -= l.GetFoodCapacity() / 2;
//	l.SetHealthPoints(l.GetHealthPoints() - m_foodCapacity / 2);
//}

void Lion::LionInteract(Lion two, vector<Lion> allLions)
{
	if (GetGender() != two.GetGender())
	{
		for (int i = 0; i < two.GetRandomNumberOfKids(); i++)
		{
			Lion baby;
			baby.SetKind(two.GetKind());
			baby.SetAge(0);
			baby.SetCoords(two.GetCoords().GetX() + 1, two.GetCoords().GetY() + 1);
			char tempGender;
			if (two.GetRandomGenderOfKids() == 0)
			{
				tempGender = 'm';
			}
			else
			{
				tempGender = 'f';
			}
			baby.SetGender(tempGender);
			baby.SetMaxAge(two.GetMaxAge());
			baby.SetHealthPoints(two.GetRandomHealthPointsOfKids());
			baby.SetFoodCapacity(two.GetRandomFoodCapacityOfKids());
			baby.SetStamina(two.GetRandomStaminaOfKids());

			allLions.push_back(baby);
		}
	}
	else
	{
		SetHealthPoints(GetHealthPoints() - two.GetFoodCapacity()/2);
		two.SetHealthPoints(two.GetHealthPoints() - GetFoodCapacity() / 2);
	}
}

void Lion::IsInWrongArea(vector<WaterTerrain> allWaterTerrains)
{
	for ( unsigned int i = 0; i < allWaterTerrains.size(); i++)
	{
		if (allWaterTerrains[i].IsInWater(GetCoords()))
		{
			SetHealthPoints(GetHealthPoints() - 1);
		}
	}
}
