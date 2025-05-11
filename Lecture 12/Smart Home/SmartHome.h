#pragma once
#include"Device.h"

class SmartHome
{
	Device** devices;
	int count;
	int capacity;

	void free();
	void copyFrom(const SmartHome& other);
	void resize(int newCap);
public:
	SmartHome();
	SmartHome(int cap);
	SmartHome(const SmartHome& other);
	SmartHome& operator=(const SmartHome& other);
	~SmartHome();

	void addDevice(Device*device);
	void addDevice(const Device& device);
	void removeDevice(int index);
	const Device* operator[](int index)const;
	Device* operator[](int index);
	void print()const;
	void turnOn(int index, const Device& d);
	void turnOff(int index, const Device& d);
	double getAverage(const MyString&producer);
	
};

