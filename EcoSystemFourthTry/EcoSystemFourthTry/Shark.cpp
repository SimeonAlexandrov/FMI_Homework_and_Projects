#pragma once
#include "Shark.h"


Shark::Shark(Point coords, char gender, unsigned int age, unsigned int maxAge, unsigned int stamina, unsigned int healthPoints, unsigned int foodCapacity)
{
	m_coords = coords;
	m_gender = gender;
	m_age = age;
	m_maxAge = maxAge;
	m_stamina = stamina;
	m_healthPoints = healthPoints;
	m_foodCapacity = foodCapacity;
}
/*Point Shark::FindManatees(vector<Grass> availableManatees)
{

}
*/

Point Shark::FindFood(std::vector<Grass> availableManatees)
{
	Point useless;
	return useless;
	//not used
}

Point Shark::FindFood(std::vector<Algae>)
{
	Point useless;
	return useless;
	//not used
}

Point Shark::FindFood(std::vector<Manatee> availableManatees)
{
	Point nearestPlant = availableManatees[0].GetCoords();
	double shortestDistance = m_coords.GetDistanceTo(availableManatees[0].GetCoords());

	for (unsigned int i = 1; i < availableManatees.size(); i++)
	{
		if (m_coords.GetDistanceTo(availableManatees[i].GetCoords()) <= shortestDistance)
		{
			shortestDistance = m_coords.GetDistanceTo(availableManatees[i].GetCoords());
			nearestPlant = availableManatees[i].GetCoords();
		}
	}
	return nearestPlant;
}

void Shark::Eat(Grass g)
{
	//not needed
}
void Shark::Eat(Algae a)
{
	//not needed
}
void Shark::Eat(Manatee m)
{
	m.SetHealthPoints(m.GetHealthPoints() - m_foodCapacity);
	m_healthPoints = min(100, int(m_healthPoints + m_foodCapacity));

}


void Shark::SharkInteract(Shark two, vector<Shark> allSharks)
{
	if (GetGender() != two.GetGender())
	{
		for (int i = 0; i < two.GetRandomNumberOfKids(); i++)
		{
			Shark baby;
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

			allSharks.push_back(baby);
		}
	}
	else
	{
		SetHealthPoints(GetHealthPoints() - two.GetFoodCapacity() / 2);
		two.SetHealthPoints(two.GetHealthPoints() - GetFoodCapacity() / 2);
	}
}

void Shark::IsInWrongArea(vector<WaterTerrain> allWaterTerrains)
{
	for (unsigned int i = 0; i < allWaterTerrains.size(); i++)
	{
		if (!allWaterTerrains[i].IsInWater(GetCoords()))
		{
			SetHealthPoints(GetHealthPoints() - 1);
		}
	}
}