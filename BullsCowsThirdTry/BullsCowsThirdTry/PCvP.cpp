#include "PCvP.h"

PCvP::PCvP()
{
	PC();
	Human();
	m_guessCount = 0;
}

bool PCvP::HasWon()
{
	if (yugi.GetNumber() == computer.MakeGuess())
	{
		return true;
	}
	else
	{
		return false;
	}
}

void PCvP::Play()
{
	cout << "It is proven that any number can be guessed within 7 turns. Your number will be guessed by the computer." << endl;

	cout << "Player 1, open HumanSecretNumber.txt, input your secret number, save the file then close it. Please write down OK here when ready" << endl;
	string response;
	cin >> response;

	if (response == "OK")
	{
		yugi.ReadSecretNumberFromFile();
		for (int guessCounter = 0; guessCounter < 7; guessCounter++)
		{
			if (guessCounter == 6)
			{

				cout << "Computer has guessed your number" << yugi.GetNumber();
			}
			int guessNumber = computer.MakeGuess();
			cout << "Computer is trying to guess your number: " << guessNumber;
			cout << endl << "Player, list bulls and cows: " << endl;
			yugi.Respond(guessNumber);
			
		}
	}
}


void PCvP::SaveScore()
{
	ofstream file("Histrory.txt", ios_base::out | ios_base::app);
	if (!file.is_open())
	{
		cout << "error while opening the file" << endl;
	}
	else
	{
		file << endl << "Game mode: PvPC " << "\tSecret number is: " << yugi.GetNumber() << "\tGuesses needed: " << m_guessCount;
	}
}

void PCvP::ExportGuessCount(int count)
{
	m_guessCount = count;
}

int PCvP::GetGuessCount() const
{
	return m_guessCount;
}