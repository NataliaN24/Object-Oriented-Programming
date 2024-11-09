#pragma once
#include<iostream>
#include<cstring>
#pragma warning(disable:4996)


constexpr int MAX_SIZE = 50;
class Computer
{
protected:
	char model_VIDEOCARD[MAX_SIZE];
	int power_SUPPLY;
	int RAM_memory;
	double CPU_power;

public:
	Computer(const char* model, int power, int ram, double cpu);
	void setModel(const char* model);
	void setPower(int power);
	void setRam(int ram);
	void setCPU(double cpu);
	
	virtual void computer_TYPE()const = 0;
	virtual void computer_PERIPHERALS()const = 0;
	virtual ~Computer() = default;

	
};

