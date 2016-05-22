#pragma once
#include "Scholar.h"

void Scholar::Work()
{
	cout << "Researching science\n";
}

Scholar::Scholar()
{
	m_name = "";
	m_age = 0;

}

Scholar::~Scholar()
{
}

Scholar::Scholar(string name, int age)
{
	m_name = name;
	m_age = age;
}
