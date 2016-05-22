#pragma once
#include<string>
#include<iostream>
using namespace std;
class Slave
{
public:
	Slave();
	Slave(string, int);
	~Slave();

	void SetName(string);
	void SetAge(int);
	string GetName();
	int GetAge();

	virtual void Work();

protected:
	string m_name;
	int m_age;

};

