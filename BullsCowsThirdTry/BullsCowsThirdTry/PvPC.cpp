#include "PvPC.h"

PvPC::PvPC()
{
	Human();
	PC();
	m_guessCount = 0;
}

PvPC::PvPC(Human one, PC two)
{
	yugi = one;
	computer = two;
}




void PvPC::Play()
{
	computer.SelectRandom();
	cout << "Computer has chosen a secret number" << endl;
	int guessCount = 0;
	int userGuess;
	do
	{
		guessCount++;
		cout << "Make a guess: ";
		cin >> userGuess;
		if (HasWon(yugi.MakeGuess(userGuess)))
		{
			cout << "Congratulations, you have guessed computers number right";
			ExportGuessCount(guessCount);
			break;
		}
		else
		{
			cout << endl << "Computer lists bulls and cows: " << endl;
			computer.Respond(userGuess);
		}
		

	} while (!HasWon(yugi.MakeGuess(userGuess)));

}

bool PvPC::HasWon(int number)
{
	if (computer.GetNumber() == yugi.MakeGuess(number))
	{
		return true;
	}
	else
	{
		return false;
	}
	
}

void PvPC::ExportGuessCount(int count)
{
	m_guessCount = count;
}

void PvPC::SaveScore()
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
