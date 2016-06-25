#include "Manatee.h"


Manatee::Manatee(Point coords, char gender, unsigned int age, unsigned int maxAge, unsigned int stamina, unsigned int healthPoints, unsigned int foodCapacity)
{
	m_coords = coords;
	m_gender = gender;
	m_age = age;
	m_maxAge = maxAge;
	m_stamina = stamina;
	m_healthPoints = healthPoints;
	m_foodCapacity = foodCapacity;
}

Point Manatee::FindFood(std::vector<Algae> availablePlants)
{
	Point nearestPlant = availablePlants[0].GetCoords();
	double shortestDistance = m_coords.GetDistanceTo(availablePlants[0].GetCoords());

	for (unsigned int i = 1; i < availablePlants.size(); i++)
	{
		if (m_coords.GetDistanceTo(availablePlants[i].GetCoords()) <= shortestDistance)
		{
			shortestDistance = m_coords.GetDistanceTo(availablePlants[i].GetCoords());
			nearestPlant = availablePlants[i].GetCoords();
		}
	}
	return nearestPlant;
}


Point Manatee::FindFood(std::vector<Grass>)
{
	Point useless;
	return useless;
	//not used
}


void Manatee::Eat(Grass g)
{
	//not needed
}

void Manatee::Eat(Algae a)
{
	if (m_healthPoints < 100)
	{
		m_healthPoints = min(100, int(m_healthPoints + m_foodCapacity));
		a.SetCapacity(a.GetCapacity() - m_foodCapacity);
	}
	else
	{
		a.SetCapacity(a.GetCapacity() - m_foodCapacity);
	}
}

void Manatee::ManateeInteract(Manatee two, vector<Manatee> allManatees)
{
	if (GetGender() != two.GetGender())
	{
		for (int i = 0; i < two.GetRandomNumberOfKids(); i++)
		{
			Manatee baby;
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

			allManatees.push_back(baby);
		}
	}
}

void Manatee::IsInWrongArea(vector<WaterTerrain> allWaterTerrains)
{
	for (unsigned int i = 0; i < allWaterTerrains.size(); i++)
	{
		if (!allWaterTerrains[i].IsInWater(GetCoords()))
		{
			SetHealthPoints(GetHealthPoints() - 1);
		}
	}
}