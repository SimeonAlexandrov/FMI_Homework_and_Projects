#include "Priest.h"

void Priest::Work()
{
	cout << "Performing ritual\n";
}

Priest::Priest()
{
	m_name = "";
	m_age = 0;

}

Priest::~Priest()
{
}

Priest::Priest(string name, int age)
{
	m_name = name;
	m_age = age;
}
