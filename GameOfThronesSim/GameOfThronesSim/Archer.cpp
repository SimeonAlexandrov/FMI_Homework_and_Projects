#include "Archer.h"

void Archer::Work()
{
	cout << "Archer fighting\n";
}

Archer::Archer()
{
	m_name = "";
	m_age = 0;

}

Archer::~Archer()
{
}

Archer::Archer(string name, int age)
{
	m_name = name;
	m_age = age;
}
