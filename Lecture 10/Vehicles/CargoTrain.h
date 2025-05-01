#pragma once
#include"Vehicle.h"

class CargoTrain:public Vehicle
{
	unsigned int loadedDepotNumber;
public:
	CargoTrain();
	CargoTrain(unsigned int year, unsigned int weight, unsigned int maxSpeed, unsigned int wagones, const char* name, unsigned int loadedDepotNumber);
	unsigned int getLoadedDepotNumber()const;
	virtual void readFrom(std::istream& is)override;
	virtual void writeTo(std::ostream& os)const override;
	virtual void print()const override;
};
