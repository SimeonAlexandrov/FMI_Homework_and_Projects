#include "anEmpire.h"

Empire::Empire()
{
	m_name = "";
}

Empire::~Empire()
{
	citizens.clear();
}

Empire::Empire(string name)
{
	m_name = name;
}

void Empire::AddNew(Citizen m_citizen)
{
	switch (m_citizen)
	{
	case slave: s = new Slave; citizens.push_back(s); break;
	case soldier:  s = new Soldier; citizens.push_back(s); break;
	case scholar: s = new Scholar; citizens.push_back(s); break;
	case priest: s = new Priest; citizens.push_back(s); break;
	case trader: s = new Trader; citizens.push_back(s); break;
	case archer: s = new Archer; citizens.push_back(s); break;
	case swordsman: s = new Swordsman; citizens.push_back(s); break;
	case emperor: s = new Emperor; citizens.push_back(s); break;
	}
}

int Empire::CountCitizens()
{
	return citizens.size();
}

