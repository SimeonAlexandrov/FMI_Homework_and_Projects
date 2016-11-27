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
#pragma once
#include<string>
struct Instruction
{
	std::string type;
	std::string direction;
	int floor;
	int time;
};

class Elevator
{
public:
	Elevator();
	Elevator(std::string, int, int);
	int EstimateTime(Instruction);
	void ExecuteInstruction(Instruction);

	void SetDirection(std::string);
	void SetCurrFloor(int);
	void SetCounter(int);


	std::string GetDirection() const;
	int GetCurrFloor() const;
	int GetCounter() const;

private:
	void Print();
	std::string direction;
	int  counter;
	int currFloor;
};