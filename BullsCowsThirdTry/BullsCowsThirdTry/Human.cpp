#include "Human.h"

Human::Human()
{
	m_number = 1023;
}

Human::Human(int number)
{
	m_number = number;
}

void Human::Respond(int number)
{
	int respondBulls;
	int respondCows;
	cout << "\tbulls: ";
	cin >> respondBulls;
	cout << "\tcows: ";
	cin >> respondCows;
	if (respondBulls != CheckForBulls(number) || respondCows != CheckForCows(number))
	{
		cout << "wrong input" << endl;
		// could be made with recursion 
	}
}

int Human::MakeGuess(int number)
{
	return number;
}

void Human::ReadSecretNumberFromFile()
{
	ifstream file;
	file.open("HumanSecretNumberHere.txt");
		if (!file.is_open())
		{
			cout << "error while opening the file";
		}
		else
		{
			string line;
			getline(file, line);
			m_number = atoi(line.c_str());
		}
}
