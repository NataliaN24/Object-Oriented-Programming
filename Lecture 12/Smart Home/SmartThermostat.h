#pragma once
#include"Device.h"

class SmartThermostat:public Device
{
	int currentTemp;
	int desiredTemp;
public:
	SmartThermostat();
	SmartThermostat(const MyString& name, const MyString& producer, size_t price, int currentTemp,int desiredTemp);

	int getCurrentTemp()const;
	int getDesiredTemp()const;

	void turnOn() const override;
	void turnOff() const override;
	void printDetails()const override;
	Device* clone()const override;
};

