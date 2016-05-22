#include "Soldier.h"

void Soldier::Work()
{
	cout << "Fighting against enemy\n";
}

Soldier::Soldier()
{
	m_name = "";
	m_age = 0;

}

Soldier::~Soldier()
{
}

Soldier::Soldier(string name, int age)
{
	m_name = name;
	m_age = age;
}
