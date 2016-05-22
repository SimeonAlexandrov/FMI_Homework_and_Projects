#pragma once
#include<string>
#include<vector>

#include "Slave.h"
#include "Trader.h"
#include "Priest.h"
#include "Soldier.h"
#include "Scholar.h"
#include "Archer.h"
#include "Swordsman.h"
#include "Emperor.h"
#include "anEmpire.h"

using namespace std;

enum Citizen
{
	slave,
	soldier,
	scholar,
	priest,
	trader,
	archer,
	swordsman,
	emperor
};

class Empire 
{
public:
	Empire();
	~Empire();
	Empire(string);
	void AddNew(Citizen m_citizen);
	int CountCitizens();
	
	//void SetName(string);
	//string GetName();

private:
	Citizen m_citizen;
	string m_name;
	vector<Slave*> citizens;
	Slave* s;
	

};