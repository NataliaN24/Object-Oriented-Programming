#pragma once
#include"Computer.h"

constexpr int MAX_NUMBER_LAPTOP = 3;

class Laptop:public Computer
{
	const char* peripherals[MAX_NUMBER_LAPTOP] = { "mousepad","keyboard","monitor" };
public:
	Laptop(const char* model, int power, int ram, double cpu);
	virtual void computer_TYPE()const override;
	virtual void computer_PERIPHERALS()const override;
};
