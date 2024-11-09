#include "Laptop.h"

Laptop::Laptop(const char* model, int power, int ram, double cpu):Computer(model, power, ram, cpu)
{
}

void Laptop::computer_TYPE() const
{
	std::cout << "Laptop" << std::endl;
}

void Laptop::computer_PERIPHERALS() const
{
		for (int i = 0; i < MAX_NUMBER_LAPTOP; i++)
	{
		std::cout << peripherals[i] << " " << std::endl;
	}
}