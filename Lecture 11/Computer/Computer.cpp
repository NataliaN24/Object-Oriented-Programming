#include "Computer.h"


Computer::Computer(const char* model, int power, int ram, double cpu):power_SUPPLY(power),RAM_memory(ram),CPU_power(cpu)
{
	if (std::strlen(model) < MAX_SIZE)
	{
		std::strcpy(model_VIDEOCARD, model);
	}
	else
	{
		throw std::out_of_range("Error!");
	}
}

void Computer::setModel(const char* model)
{
	if (std::strlen(model) < MAX_SIZE)
	{
		std::strcpy(model_VIDEOCARD, model);
	}
	else
	{
		throw std::out_of_range("Error!");
	}

}

void Computer::setPower(int power)
{
	power_SUPPLY = power;
}

void Computer::setRam(int ram)
{
	RAM_memory = ram;
}

void Computer::setCPU(double cpu)
{
	CPU_power = cpu;
}
