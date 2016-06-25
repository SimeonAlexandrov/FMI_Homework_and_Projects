#include "Elephant.h"


Elephant::Elephant(Point coords, char gender, unsigned int age, unsigned int maxAge, unsigned int stamina, unsigned int healthPoints, unsigned int foodCapacity)
{
	m_coords = coords;
	m_gender = gender;
	m_age = age;
	m_maxAge = maxAge;
	m_stamina = stamina;
	m_healthPoints = healthPoints;
	m_foodCapacity = foodCapacity;
}
/*Point Elephant::FindPlants(vector<Grass> availablePlants)
{
	
}
*/

 Point Elephant::FindFood(std::vector<Grass> availablePlants)
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

 Point Elephant::FindFood(std::vector<Algae>)
{
	Point useless;
	return useless;
	//not used
}

 void Elephant::Eat(Grass g)
 {
	 if(m_healthPoints < 100)
	 {
		 m_healthPoints = min(100, int(m_healthPoints + m_foodCapacity));
		 g.SetCapacity(g.GetCapacity() - m_foodCapacity);
	 }
	 else
	 {
		 g.SetCapacity(g.GetCapacity() - m_foodCapacity);
	 }
 }

void Elephant::Eat(Algae a)
{
	//not needed
}

void Elephant::ElephantInteract(Elephant two, vector<Elephant> allElephants)
{
	if(two.GetGender() != GetGender())
	{
		for (int i = 0; i < two.GetRandomNumberOfKids(); i++)
		{
			Elephant baby;
			baby.SetKind(two.GetKind());
			baby.SetAge(0);
			baby.SetCoords(two.GetCoords().GetX() + 1, two.GetCoords().GetY() + 1);
			char tempGender;
			if(two.GetRandomGenderOfKids()== 0 )
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

			allElephants.push_back(baby);
		}
	}
}

void Elephant::IsInWrongArea(vector<WaterTerrain> allWaterTerrains)
{
	for ( unsigned int i = 0; i < allWaterTerrains.size(); i++)
	{
		if(allWaterTerrains[i].IsInWater(GetCoords()))
		{
			SetHealthPoints(GetHealthPoints() - 1);
		}
	}
}
