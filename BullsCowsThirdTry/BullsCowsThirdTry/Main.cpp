#include <iostream>
#include "PvP.h"
#include "PvPC.h"
#include "Human.h"
using namespace std;

int main()
{
	PvPC newGame;

	newGame.Play();

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