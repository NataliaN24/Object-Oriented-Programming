#include "GamingConsole.h"

GamingConsole::GamingConsole(const char* model, int power, int ram, double cpu) :Computer(model, power, ram, cpu)
{
}

void GamingConsole::computer_TYPE() const
{
	std::cout << "Gaming Console" << std::endl;
}

void GamingConsole::computer_PERIPHERALS() const
{
	for (int i = 0; i < MAX_NUMBER_GAMINGCONSOLE; i++)
	{
		std::cout << peripherals[i] << " " << std::endl;
	}
}