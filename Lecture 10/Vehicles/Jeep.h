#pragma once
#include"Vehicle.h"

class Jeep:public Vehicle
{
	bool is4x4;
public:
	Jeep();
	Jeep(unsigned int year, unsigned int weight, unsigned int maxSpeed, unsigned int tires, const char* name,bool is4x4);
	bool getIs4X4()const;

	virtual void readFrom(std::istream& is)override;
	virtual void writeTo(std::ostream& os)const override;
	virtual void print()const override;
};

