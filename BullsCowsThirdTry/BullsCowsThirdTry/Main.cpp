#include <iostream>
#include "PvP.h"
#include "PvPC.h"
#include "Human.h"
#include "PC.h"
#include "PCvP.h"
#include "Presenter.h"
using namespace std;

void Menu()
{
	cout << "Please select a game mode" << endl;
	int response;
	cout << "\t Press 1 for PvP mode" << endl;
	cout << "\t Press 2 for PvPC mode" << endl;
	cout << "\t Press 3 for PCvP mode" << endl;
	cin >> response;
	if (response == 1)
	{
		PvP newGame; 
		newGame.Play();
	}
	else if (response == 2)
	{

			PvPC newGame;
			newGame.Play();
		
	}
	else if (response == 3)
	{
		PCvP newGame;
		newGame.Play();
	}
	else
	{
		cout << "wrong input";
	}
	
}

int main()
{
	Menu();

	return 0;
}



//test reading from a file
//Human moni;
//moni.ReadSecretNumberFromFile();
//cout << moni.GetNumber();

//newGame.Play();
//Human mutu;
//mutu.SetNumber(1234);
//Human mongoleco;
//mongoleco.SetNumber(5678);
//PvP secondGame(mutu, mongoleco);
//
//Human bakura;
//bakura.SetNumber(1357);
//Human joey;
//joey.SetNumber(9753);
//
//PvP thirdGame = secondGame;
//
//secondGame.Print();
//thirdGame.Print();