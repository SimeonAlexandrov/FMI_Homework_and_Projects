#include "Player.h"

Player::Player()
{
	m_number = 1023;
	SetA();
}

Player::Player(int number)
{
	m_number = number;
}

void Player::SetNumber(int number)
{
	m_number = number;
}

int Player::GetNumber() const
{
	return m_number;
}

void Player::Respond(int)
{
	cout << "Player is responding" << endl;
}

int Player::MakeGuess(int)
{
	return 0;
}

int Player::CheckForBulls(int input)
{
	int cntBulls = 0;
	if (input / 1000 == m_number / 1000)
	{
		cntBulls++;
	}
	if ((input / 100) % 10 == (m_number / 100) % 10)
	{
		cntBulls++;
	}
	if ((input / 10) % 10 == (m_number / 10) % 10)
	{
		cntBulls++;
	}
	if (input % 10 == m_number % 10)
	{
		cntBulls++;
	}

	if (cntBulls == 0)
	{
		return 0;
	}
	else
	{
		return cntBulls;
	}
}

int Player::CheckForCows(int input)
{
	int cntCows = 0;
	if (
		input / 1000 == (m_number / 100) % 10 ||
		input / 1000 == (m_number / 10) % 10 ||
		input / 1000 == (m_number % 10))
	{
		cntCows++;
	}
	if ((input / 100) % 10 == (m_number / 1000) ||

		(input / 100) % 10 == (m_number / 10) % 10 ||
		(input / 100) % 10 == (m_number % 10))
	{
		cntCows++;
	}
	if ((input / 10) % 10 == (m_number / 1000) ||
		(input / 10) % 10 == (m_number / 100) % 10 ||

		(input / 10) % 10 == (m_number % 10))
	{
		cntCows++;
	}
	if (input % 10 == (m_number / 1000) ||
		input % 10 == (m_number / 100) % 10 ||
		input % 10 == (m_number / 10) % 10
		)
	{
		cntCows++;
	}
	return cntCows;
}

void Player::SetA()
{
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			for (int k = 0; k <= 9; k++)
			{
				for (int l = 0; l <= 9; l++)
				{
					bool differentDigits = i != j && i != k && i != l && j != k && j != l && k != l;
					if (differentDigits)
					{
						int number = i * 1000 + j * 100 + k * 10 + l;
						a.push_back(number);
					}
				}
			}
		}
	}
}

bool Player::CheckIfNumberIsCorrect()
{
	if (find(a.begin(), a.end(), m_number) != a.end())
	{
		return true;
	}
	else
	{
		return false;
	}
}
