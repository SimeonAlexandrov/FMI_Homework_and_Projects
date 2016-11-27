/**
*
* Solution to homework task
* Data Structures Course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Simeon Aleksandrov
* @idnumber 61916
* @task 2
* @compiler Visual C++
*
*/
#include "Elevator.h"
#include<iostream>
Elevator::Elevator()
{
	direction = "";
	counter = 0;
	currFloor = 1;
}

Elevator::Elevator(std::string up, int cnt, int floor)
{
	direction = up;
	counter = cnt;
	currFloor = floor;
}

int Elevator::EstimateTime(Instruction ins)
{

	return abs(currFloor - ins.floor) * 5;
}

void Elevator::ExecuteInstruction(Instruction ins)
{
	//it should add the first time of the first instruction
	counter += EstimateTime(ins);

	if (currFloor < ins.floor)
	{
		direction = "up";

	}
	else if (currFloor > ins.floor)
	{
		direction = "down";
	}
	else
	{
		if (direction == "down")
			direction = "up";
		else
			direction = "down";
	}
	currFloor = ins.floor;
	Print();
}

void Elevator::SetDirection(std::string b)
{
	direction = b;
}

void Elevator::SetCurrFloor(int f)
{
	currFloor = f;
}

void Elevator::SetCounter(int c)
{
	counter = c;
}

std::string Elevator::GetDirection() const
{
	return direction;
}

int Elevator::GetCurrFloor() const
{
	return currFloor;
}

int Elevator::GetCounter() const
{
	return counter;
}

void Elevator::Print()
{
	std::cout << counter << " " << currFloor << " " << direction << std::endl;
}
