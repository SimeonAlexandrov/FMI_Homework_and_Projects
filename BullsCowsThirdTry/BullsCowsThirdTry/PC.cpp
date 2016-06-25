#include "PC.h"

PC::PC()
{
	m_number = SelectRandom();
}



int PC::SelectRandom()
{
	SetA();
	random_device random_device;
	mt19937 engine{ random_device() };
	uniform_int_distribution<int> dist(0, a.size() - 1);

	int random_element = a[dist(engine)];

	return random_element;

}

int PC::MakeGuess()
{
	// some complex algoriths should be here
	return SelectRandom();
}



void PC::Respond(int number)
{
	cout <<  "bulls: "<< CheckForBulls(number) << endl << "cows: " << CheckForCows(number) << endl;

}
