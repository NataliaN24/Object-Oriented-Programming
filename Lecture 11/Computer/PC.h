#pragma once
#include"Computer.h"

constexpr int MAX_NUMBER_PC = 4;
class PC :public Computer
{
	const char* peripherals[MAX_NUMBER_PC] = { "mouse","keyboard","microphone","headphone" };
public:
	PC(const char* model, int power, int ram, double cpu);
	virtual void computer_TYPE()const override;
	virtual void computer_PERIPHERALS()const override;
};