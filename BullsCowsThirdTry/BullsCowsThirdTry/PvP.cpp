#include "PvP.h"

PvP::PvP()
{
	Human();
	Human();
	m_guessCount = 0;
}

PvP::PvP(Human one, Human two)
{
	yugi = one;
	kaiba = two;
}


void PvP::Play()
{
	string firstResponse;
	cout << "Would you like to play in challenge mode? (7 turns) " << endl;
	cin >> firstResponse;
	if (firstResponse == "YES")
	{
		cout << "Player 1, open HumanSecretNumber.txt, input your secret number, save the file then close it. Please write down OK here when ready" << endl;
		string response;
		cin >> response;
		if (response == "OK")
		{
			yugi.ReadSecretNumberFromFile();
			int guessNumber;
			int guessCounter = 0;
			do
			{
				if (guessCounter == 7)
				{
					cout << "Game Over. You lose";
				}
				guessCounter++;
				cout << endl << "Player 2, make a guess: ";

				cin >> guessNumber;

				if (HasWon(kaiba.MakeGuess(guessNumber)))
				{
					cout << "Congratulations, you have guessed it right!" << endl;
					ExportGuessCount(guessCounter);
					break;
				}
				cout << endl << "Player 1, list bulls and cows: " << endl;
				yugi.Respond(kaiba.MakeGuess(guessNumber));

			} while (!HasWon(kaiba.MakeGuess(guessNumber)));
			SaveScore();
		}
		else
		{
			cout << "Follow the instructions, please. Try again... " << endl;
		}
	}
	else
	{
		cout << "Player 1, open HumanSecretNumber.txt, input your secret number, save the file then close it. Please write down OK here when ready" << endl;
		string response;
		cin >> response;
		if (response == "OK")
		{
			yugi.ReadSecretNumberFromFile();
			int guessNumber;
			int guessCounter = 0;
			do
			{
				guessCounter++;
				cout << endl << "Player 2, make a guess: ";

				cin >> guessNumber;

				if (HasWon(kaiba.MakeGuess(guessNumber)))
				{
					cout << "Congratulations, you have guessed it right!" << endl;
					ExportGuessCount(guessCounter);
					break;
				}
				cout << endl << "Player 1, list bulls and cows: " << endl;
				yugi.Respond(kaiba.MakeGuess(guessNumber));

			} while (!HasWon(kaiba.MakeGuess(guessNumber)));
			SaveScore();
		}
		else
		{
			cout << "Follow the instructions, please. Try again... " << endl;
		}
	}
	
	

}

bool PvP::HasWon(int number)
{
	if (kaiba.MakeGuess(number) == yugi.GetNumber())
	{
		return true;
	}
	else
	{
		return false;
	}
}

void PvP::SaveScore()
{
	ofstream file("Histrory.txt", ios_base::out | ios_base::app);
	if (!file.is_open())
	{
		cout << "error while opening the file" << endl;
	}
	else
	{
		file << endl << "Game mode: PvP " << "\tSecret number is: " << yugi.GetNumber() << "\tGuesses needed: " << GetGuessCount();
	}
}

void PvP::Print()
{
	cout << "Player1's number" << yugi.GetNumber() << endl;
	cout << "Player2's number" << kaiba.GetNumber() << endl;

}

void PvP::ExportGuessCount(int count)
{
	m_guessCount = count;
}

int PvP::GetGuessCount() const
{
	return m_guessCount;
}
