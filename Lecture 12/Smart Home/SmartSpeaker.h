#pragma once
#include"Device.h"

class SmartSpeaker:public Device
{
	size_t volume;

public:
	SmartSpeaker();
	SmartSpeaker(const MyString& name, const MyString& producer, size_t price, size_t vol);

	size_t getVolume()const;

	void turnOn() const override;
	void turnOff() const override;
	void printDetails()const override;

	Device* clone()const override;

};

