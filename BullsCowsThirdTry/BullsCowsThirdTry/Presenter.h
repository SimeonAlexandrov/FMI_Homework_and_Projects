#pragma once
#include "PvP.h"
#include "PvPC.h"
#include "Human.h"
#include "PC.h"
#include "PCvP.h"

class Presenter
{
	// Чрез тия два метода би трябвало да стане "разплитането" от конзолата. Идеята е, че само на едно място ще променяме cin i cout, ако имаме нужда
	// Друг е въпросът, че нямам време и нерви да го направя това

public:
	void GetInput();
	void Print();
	
};