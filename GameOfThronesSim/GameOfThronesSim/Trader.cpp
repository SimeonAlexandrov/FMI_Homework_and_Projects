#pragma once
#include "Trader.h"

void Trader::Work()
{
	cout << "Trading\n";
}

Trader::Trader()
{
	m_name = "";
	m_age = 0;
}

Trader::~Trader()
{
}

Trader::Trader(string name, int age)
{
		name = m_name;
		age = m_age;
}




