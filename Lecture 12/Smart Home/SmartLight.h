#pragma once
#include"Device.h"

class SmartLight:public Device
{
	int brightnessLevel;
public:
	SmartLight();
	SmartLight(const MyString& name, const MyString& producer, size_t price, int bright);
	
	int getBrightness()const;

	void turnOn() const override;
	void turnOff() const override;
	void printDetails()const override;
	Device* clone()const override;
};

