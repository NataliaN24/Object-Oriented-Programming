#pragma once
#include "Computer.h"

constexpr int MAX_NUMBER_GAMINGCONSOLE= 2;

class GamingConsole:public Computer
{
	const char* peripherals[MAX_NUMBER_GAMINGCONSOLE] = { "joystick","monitor"};
public :
	GamingConsole(const char* model, int power, int ram, double cpu);
	virtual void computer_TYPE()const override;
	virtual void computer_PERIPHERALS()const override;

};