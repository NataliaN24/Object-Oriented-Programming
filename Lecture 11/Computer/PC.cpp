#include "PC.h"

PC::PC(const char* model, int power, int ram, double cpu):Computer(model,power,ram,cpu)
{
}

void PC::computer_TYPE() const
{
	std::cout << "PC" << std::endl;
}

void PC::computer_PERIPHERALS() const
{
	for (int i = 0; i < MAX_NUMBER_PC; i++)
	{
		std::cout << peripherals[i] << " " << std::endl;
	}
}