#include "Swordsman.h"

void Swordsman::Work()
{
	cout << "Swordsman fighting\n";
}

Swordsman::Swordsman()
{
	m_name = "";
	m_age = 0;

}

Swordsman::~Swordsman()
{
}

Swordsman::Swordsman(string name, int age)
{
	m_name = name;
	m_age = age;
}
