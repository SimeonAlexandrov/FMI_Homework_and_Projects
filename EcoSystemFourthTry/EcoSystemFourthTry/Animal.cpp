#include "Animal.h"

Animal::Animal()
{
	m_coords.Set(0, 0);
	m_gender = 'm';
	m_age = 0;
	m_maxAge = 100;
	m_stamina = 0;
	m_healthPoints = 100;
	m_foodCapacity = 0;
}
Animal::Animal(Point coords, char gender, unsigned int age, unsigned int maxAge, unsigned int stamina, unsigned int healthPoints, unsigned int foodCapacity)
{
	m_coords = coords;
	m_gender = gender;
	m_age = age;
	m_maxAge = maxAge;
	m_stamina = stamina;
	m_healthPoints = healthPoints;
	m_foodCapacity = foodCapacity;
}


void Animal::SetCoords(int x, int y)
{
	m_coords.Set(x, y);
}
void Animal::SetGender(char gender)
{
	m_gender = gender;
}
void Animal::SetAge(unsigned int age)
{
	m_age = age;
}
void Animal::SetMaxAge(unsigned int maxAge)
{
	m_maxAge = maxAge;
}
void Animal::SetStamina(unsigned int stamina)
{
	m_stamina = stamina;
}
void Animal::SetHealthPoints(unsigned int healthPoints)
{
	m_healthPoints = healthPoints;
}
void Animal::SetFoodCapacity(unsigned int foodCapacity)
{
	m_foodCapacity = foodCapacity;
}

void Animal::SetKind(string kind)
{
	m_kind = kind;
}

Point Animal::GetCoords() const
{
	Point toReturn;
	toReturn = m_coords;
	return toReturn;
}


char Animal::GetGender() const
{
	return m_gender;
}
unsigned int Animal::GetAge() const
{
	return m_age;
}
unsigned int Animal::GetMaxAge() const
{
	return m_maxAge;
}
unsigned int Animal::GetStamina() const
{
	return m_stamina;
}
unsigned int Animal::GetHealthPoints() const
{
	return m_healthPoints;
}
unsigned int Animal::GetFoodCapacity() const
{
	return m_foodCapacity;
}

string Animal::GetKind() const
{
	return m_kind;
}

void Animal::MoveTo(Point destination)
{
	if(m_coords.GetDistanceTo(destination) > m_stamina)
	{
		//can't move over there

	}
	else
	{
		m_coords.Set(destination.GetX(), destination.GetY());
	}
	
}

int Animal::GetRandomNumberOfKids()
{
	random_device random_device;
	mt19937 engine{ random_device() };
	uniform_int_distribution<int> dist(0, numberOfKids.size() - 1);

	int random_element = numberOfKids[dist(engine)];
	return random_element;
}

int Animal::GetRandomHealthPointsOfKids()
{
	SetHealthPointsOfKids();
	random_device random_device;
	mt19937 engine{ random_device() };
	uniform_int_distribution<int> dist(0, healthPointsOfKids.size() - 1);

	int random_element = healthPointsOfKids[dist(engine)];
	return random_element;
}

int Animal::GetRandomFoodCapacityOfKids()
{
	SetFoodCapacityOfKids();
	random_device random_device;
	mt19937 engine{ random_device() };
	uniform_int_distribution<int> dist(0, foodCapacityOfKids.size() - 1);

	int random_element = foodCapacityOfKids[dist(engine)];
	return random_element;
}

int Animal::GetRandomGenderOfKids()
{
	random_device random_device;
	mt19937 engine{ random_device() };
	uniform_int_distribution<int> dist(0, genderOfKids.size() - 1);

	int random_element = genderOfKids[dist(engine)];
	return random_element;
}

int Animal::GetRandomStaminaOfKids()
{
	SetStaminaOfKids();
	random_device random_device;
	mt19937 engine{ random_device() };
	uniform_int_distribution<int> dist(0, staminaOfKids.size() - 1);

	int random_element = staminaOfKids[dist(engine)];
	return random_element;
}



void Animal::SetHealthPointsOfKids()
{
	for (int i = 0; i <= 100; i++)
	{
		healthPointsOfKids.push_back(i);
	}
}

void Animal::SetFoodCapacityOfKids()
{
	for (int i = 0; i < 100; i++)
	{
		foodCapacityOfKids.push_back(i);
	}
}

void Animal::SetStaminaOfKids()
{
	for (int i = 0; i < 30; i++)
	{
		staminaOfKids.push_back(i);
	}
}
