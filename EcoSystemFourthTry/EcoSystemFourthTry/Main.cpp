#include<iostream>
#include<vector>
#include "Point.h"
#include "WaterTerrain.h"
#include "Weather.h"
#include "Plant.h"
#include "Grass.h"
#include  "Algae.h"
#include  "Animal.h"
#include "Elephant.h"
#include  "Manatee.h"
#include  "Shark.h"
#include  "Lion.h"
using namespace std;

void Engine(int turnNumber, vector<WaterTerrain> allWaterTerrains, vector<Weather> allWeatherConditions, vector<Grass> allGrassPoints, vector<Algae> allAlgaePoints, vector<Elephant> allElephants, vector<Manatee> allManatees, vector<Lion> allLions, vector<Shark> allSharks)
{
	for (int i = 0; i < turnNumber; i++)
	{
		//for each turn, for each grass we check for each weathercondition


		for (unsigned int j = 0; j < allGrassPoints.size(); j++)
		{
			for (unsigned int k = 0; k < allWeatherConditions.size(); k++)
			{
				if (allWeatherConditions[k].CheckIfPointIsInWeather(allGrassPoints[j].GetCoords()))
				{
					allGrassPoints[j].BeingRainedOn();
				}
			}
		}


		//same for algae


		for (unsigned int j = 0; j < allAlgaePoints.size(); j++)
		{
			for (unsigned int k = 0; k < allWeatherConditions.size(); k++)
			{
				if (allWeatherConditions[k].CheckIfPointIsInWeather(allGrassPoints[j].GetCoords()))
				{
					allAlgaePoints[j].BeingRainedOn();
				}
			}
		}


		// turn for elephants

		for (unsigned int j = 0; j < allElephants.size(); j++)
		{
			//finding destination, eating
			allElephants[j].MoveTo(allElephants[j].FindFood(allGrassPoints));
			for (unsigned int k = 0; k < allGrassPoints.size(); k++)
			{
				if (allElephants[j].GetCoords().GetX() == allGrassPoints[k].GetCoords().GetX() && allElephants[j].GetCoords().GetY() == allGrassPoints[k].GetCoords().GetY())
				{
					allElephants[j].Eat(allGrassPoints[k]);
				}
			}
			//interacting
			for (unsigned int k = 0; k < allElephants.size(); k++)
			{
				if (allElephants[j].GetCoords().GetX() == allElephants[k].GetCoords().GetX() && allElephants[j].GetCoords().GetY() == allElephants[k].GetCoords().GetY())
				{
					
					allElephants[j].ElephantInteract(allElephants[k], allElephants);
				}
			}
			allElephants[j].IsInWrongArea(allWaterTerrains);
		}

		//turn for lion

		for (unsigned int j = 0; j < allLions.size(); j++)
		{
			//finding destination, eating
			allLions[j].MoveTo(allLions[j].FindFood(allGrassPoints));
			for (unsigned int k = 0; k < allElephants.size(); k++)
			{
				if (allLions[j].GetCoords().GetX() == allElephants[k].GetCoords().GetX() && allLions[j].GetCoords().GetY() == allElephants[k].GetCoords().GetY())
				{
					allLions[j].Eat(allElephants[k]);
				}
			}
			//interacting
			for (unsigned int k = 0; k < allLions.size(); k++)
			{
				if (allLions[j].GetCoords().GetX() == allLions[k].GetCoords().GetX() && allLions[j].GetCoords().GetY() == allLions[k].GetCoords().GetY())
				{

					allLions[j].LionInteract(allLions[k], allLions);
				}
			}
			allLions[j].IsInWrongArea(allWaterTerrains);
		}

		//turn for manatee

		for (unsigned int j = 0; j < allManatees.size(); j++)
		{
			//finding destination, eating
			allManatees[j].MoveTo(allManatees[j].FindFood(allAlgaePoints));
			for (unsigned int k = 0; k < allAlgaePoints.size(); k++)
			{
				if (allManatees[j].GetCoords().GetX() == allAlgaePoints[k].GetCoords().GetX() && allManatees[j].GetCoords().GetY() == allAlgaePoints[k].GetCoords().GetY())
				{
					allManatees[j].Eat(allAlgaePoints[k]);
				}
			}
			//interacting
			for (unsigned int k = 0; k < allManatees.size(); k++)
			{
				if (allManatees[j].GetCoords().GetX() == allManatees[k].GetCoords().GetX() && allManatees[j].GetCoords().GetY() == allManatees[k].GetCoords().GetY())
				{

					allManatees[j].ManateeInteract(allManatees[k], allManatees);
				}
			}
			allManatees[j].IsInWrongArea(allWaterTerrains);
		}

		//turn for shark

		for (unsigned int j = 0; j < allSharks.size(); j++)
		{
			//finding destination, eating
			allSharks[j].MoveTo(allSharks[j].FindFood(allManatees));
			for (unsigned int k = 0; k < allManatees.size(); k++)
			{
				if (allSharks[j].GetCoords().GetX() == allManatees[k].GetCoords().GetX() && allSharks[j].GetCoords().GetY() == allManatees[k].GetCoords().GetY())
				{
					allSharks[j].Eat(allManatees[k]);
				}
			}
			//interacting
			for (unsigned int k = 0; k < allSharks.size(); k++)
			{
				if (allSharks[j].GetCoords().GetX() == allSharks[k].GetCoords().GetX() && allSharks[j].GetCoords().GetY() == allSharks[k].GetCoords().GetY())
				{

					allSharks[j].SharkInteract(allSharks[k], allSharks);
				}
			}
			allSharks[j].IsInWrongArea(allWaterTerrains);
		}
	}
	// Growing Old
	for (int j = 0; j < allElephants.size();j++)
	{
		allElephants[j].SetAge(allElephants[j].GetAge() + 1);
	}

	for (int j = 0; j < allLions.size(); j++)
	{
		allLions[j].SetAge(allLions[j].GetAge() + 1);
	}

	for (int j = 0; j < allManatees.size(); j++)
	{
		allManatees[j].SetAge(allManatees[j].GetAge() + 1);
	}

	for (int j = 0; j < allSharks.size(); j++)
	{
		allSharks[j].SetAge(allSharks[j].GetAge() + 1);
	}

	// GrimReaper

	for (int j = 0; j < allElephants.size(); j++)
	{
		if (allElephants[j].GetAge() >= allElephants[j].GetMaxAge())
		{
			allElephants.erase(allElephants.begin() + j);
		}
	}

	for (int j = 0; j < allLions.size(); j++)
	{
		allLions.erase(allLions.begin() + j);
	}

	for (int j = 0; j < allManatees.size(); j++)
	{
		allManatees.erase(allManatees.begin() + j);
	}

	for (int j = 0; j < allSharks.size(); j++)
	{
		allSharks.erase(allSharks.begin() + j);
	}

}

int main ()
{
	int numberTurns;

	vector<WaterTerrain> allWaterTerrains;
	//TODO:read from file
	vector<Weather> allWeatherConditions;
	//TODO:read from file

	vector<Grass> allGrassPoints;
	//TODO:read from file
	vector<Algae> allAlgaePoints;
	//TODO:read from file

	vector<Elephant>  allElephants;
	//TODO:read from file
	vector<Manatee> allManatees;
	//TODO:read from file
	vector<Lion> allLions;
	//TODO:read from file
	vector<Shark> allSharks;
	//TODO:read from file

	system("pause");
	return 0;
}