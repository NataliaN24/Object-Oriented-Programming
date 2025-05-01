#pragma once
#include"Vehicle.h"

class Van:public Vehicle
{
	unsigned int loadCapacity;
public:
	Van();
	Van(unsigned int year, unsigned int weight, unsigned int maxSpeed, unsigned int tires, const char* name, unsigned int loadCap);
	unsigned int getCapacity()const;
	virtual void readFrom(std::istream& is)override;
	virtual void writeTo(std::ostream& os)const override;
	virtual void print()const override;
};

