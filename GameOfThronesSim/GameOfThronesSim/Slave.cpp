#include "Slave.h"

Slave::Slave()
{
	m_name = "A girl has no name";
	m_age = 0;
}

Slave::Slave(string name, int age)
{
	m_name = name;
	m_age = age;
}

Slave::~Slave()
{
}

void Slave::SetName(string name)
{
	m_name = name;
}

void Slave::SetAge(int age)
{
	m_age = age;
}

string Slave::GetName()
{
	return m_name;
}

int Slave::GetAge()
{
	return m_age;
}

void Slave::Work()
{
	cout << "Slave working\n";
}
