#pragma once
#include"Vehicle.h"
class PassengerTrain :public Vehicle
{
	unsigned int passengerNumber;
public:
	PassengerTrain();
	PassengerTrain(unsigned int year, unsigned int weight, unsigned int maxSpeed, unsigned int wagones, const char* name, unsigned int passNumber);
	unsigned int getPassengerNumber()const;

	virtual void readFrom(std::istream& is)override;
	virtual void writeTo(std::ostream& os)const override;
	virtual void print()const override;
};

