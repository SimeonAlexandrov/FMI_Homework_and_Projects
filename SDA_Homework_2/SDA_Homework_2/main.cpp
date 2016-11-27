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
#include<iostream>
#include<fstream>
#include<vector>

#include "Queue.h"
#include "Elevator.h"
using namespace std;

//TODO: argv


//vector<Instruction> OptimizeCall(vector<Instruction>, int, int);
vector<Instruction> LoadFromAFile(string s)
{
	vector<Instruction> ins;
	ifstream fin(s);

	vector<string> tokens;
	string something;
	while(fin >> something)
	{
		tokens.push_back(something);
	}

	for (int i = 2; i < tokens.size(); )
	{
		Instruction in;
		in.type = tokens[i];
		if(tokens[i] == "call")
		{
			in.direction = tokens[i + 1];
			in.floor = stoi(tokens[i + 2]);
			in.time = stoi(tokens[i + 3]); 
			i += 4;

		}
		else if (tokens[i] == "go")
		{
			in.direction = "";
			in.floor = stoi(tokens[i + 1]);
			in.time = stoi(tokens[i + 2]); 
			i += 3;
		}
		ins.push_back(in);
	}
	return ins;
}

void Simulate(Elevator, vector<Instruction>, Queue<Instruction>, Queue<Instruction>);

int main(int argc, char * argv[])
{
	string s = argv[1];

	vector<Instruction> test = LoadFromAFile(s);

	Elevator big;
	Queue<Instruction> q3;
	Queue<Instruction> q4;
	Simulate(big, test, q3, q4);
	return 0;
}



void Simulate(Elevator ele, vector<Instruction> ins, Queue<Instruction> quCall, Queue<Instruction> quGo)
{


	bool hasChangedSize = false;
	for (int i = 0; i < ins.size(); i++)
	{
		if (hasChangedSize)
			i = 0; // TODO: check
		ele.SetCounter(ins[i].time);
		int beforeSize = ins.size();
		//absolute bullshit
		//whether instruction have been deleted

		if (ins[i].floor == ele.GetCurrFloor())
		{

			ele.SetCounter(ins[i].time);
			if (ins[i].direction == "up")
				ins[i].direction = "down";
			else
				ins[i].direction = "up";

		}





		int approx = ele.EstimateTime(ins[i]);

		for (int j = 1; j < ins.size(); j++)
		{

			if (ins[j].floor == ins[i].floor && ins[j].time < ele.GetCounter() + approx)
			{
				ins.erase(ins.begin() + j); // checks for equivalent instructions and removes them
			}
		}
		vector<Instruction> tempGo;
		bool flagResize = false;

		for (int j = 1; j < ins.size(); j++)
		{
			bool existsInstruction = false;
			if (flagResize == true)
				j = 1;
			if (ins[j].type == "call" &&
				//ins[j].direction == ins[i].direction && 
				ins[j].time <= ele.GetCounter() + approx - 5 * (ele.GetCurrFloor() - ins[j].floor))
			{
				//vector<Instruction> tempCall = OptimizeCall(ins, j, approx);							//TODO: priority queue
				quCall.enqueue(ins[j]);
				ins.erase(ins.begin() + j);
				flagResize = true;
				existsInstruction = true;
			}

			else if (ins[j].type == "go" && ins[j].time <= ele.GetCounter() + approx)
			{
				bool flagForPoping = false;
				tempGo.push_back(ins[j]);
				for (int k = 0; k < tempGo.size() - 1; k++)
				{
					if (tempGo[k].floor == ins[j].floor && tempGo.size() > 1)
					{
						tempGo.pop_back();
						flagForPoping = true;
						ins.erase(ins.begin() + j);
						break;
					}
				}
				if (!flagForPoping)
				{
					quGo.enqueue(ins[j]);
				}
				flagResize = true;
				existsInstruction = true;
			}

			if (existsInstruction == false)
				flagResize = false;

		}
		if (!quCall.isEmpty())
		{
			while (!quCall.isEmpty())
			{
				ele.ExecuteInstruction(quCall.getFirstToEnter());
				quCall.dequeue();
			}

		}
		ele.ExecuteInstruction(ins[i]);
		ins.erase(ins.begin() + i);

		if (!quGo.isEmpty())
		{
			while (!quGo.isEmpty())
			{
				ele.ExecuteInstruction(quGo.getFirstToEnter());
				quGo.dequeue();
			}
		}

		int tempSize = ins.size();
		if (beforeSize != tempSize)
			hasChangedSize = true;
	}
}
//vector<Instruction> OptimizeCall(vector<Instruction> instructions, int j, int approx)
//{
//	vector<Instruction> optimizedCall;
//	for (int i =  j +  1; i < instructions.size(); i++)
//	{
//		if(instructions[i].floor < instructions[j].floor && instructions[i].time < approx && instructions[i].type == "call")
//		{
//			OptimizeCall(instructions, i, approx);
//		}
//
//		else
//		{
//			optimizedCall.push_back(instructions[i]);
//		}
//	}
//	return optimizedCall;
//}