#include "Emperor.h"

void Emperor::Work()
{
	cout << "Ruling the empire\n";
}

Emperor::Emperor()
{
	m_name = "";
	m_age = 0;

}

Emperor::~Emperor()
{
}

Emperor::Emperor(string name, int age)
{
	m_name = name;
	m_age = age;
}
