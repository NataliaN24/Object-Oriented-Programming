#include "SmartHome.h"

void SmartHome::free()
{
	for (int i = 0; i < count; ++i)
		delete devices[i];
	delete[] devices;
}

void SmartHome::copyFrom(const SmartHome& other)
{
	count = other.count;
	capacity = other.capacity;
	devices = new Device * [capacity];
	for (int i = 0; i < count; i++)
	{
		devices[i] = other.devices[i]->clone();
	}
}

void SmartHome::resize(int newCap)
{
	Device** copyDev = new Device * [newCap];
	for (int i = 0; i < count; i++)
	{
		copyDev[i] = devices[i];
	}
	capacity = newCap;
	delete[]devices;
	devices = copyDev;
}

SmartHome::SmartHome():devices(nullptr),count(0),capacity(4)
{
	devices = new Device * [capacity];
}

SmartHome::SmartHome(int cap)
{
	devices = new Device * [cap];
	count = 0;
}

SmartHome::SmartHome(const SmartHome& other)
{
	copyFrom(other);
}

SmartHome& SmartHome::operator=(const SmartHome& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

SmartHome::~SmartHome()
{
	for (int i = 0; i < capacity; i++)
	{
		delete devices[i];
	}
	delete[]devices;
}

void SmartHome::addDevice(Device* device)
{
	if (count == capacity)
	{
		resize(capacity * 2);
	}
	devices[count++] = device;

}

void SmartHome::addDevice(const Device& device)
{
	if (count == capacity)
	{
		resize(capacity * 2);
	}
	//devices[count++] = device.clone();
	Device* cloned = device.clone();
	addDevice(cloned);
}

void SmartHome::removeDevice(int index)
{
	if (index < 0 || index >= count || devices[index] == nullptr)
		return;
	delete devices[index];
	for (int i = index; i < count - 1; ++i)
	{
		devices[i] = devices[i + 1];
	}
	count--;

}

const Device* SmartHome::operator[](int index) const
{
	return devices[index];
}

Device* SmartHome::operator[](int index)
{
	return devices[index];
}

void SmartHome::print() const
{
	for (int i = 0; i < count; i++)
	{
		devices[i]->printDetails();
	}
}

void SmartHome::turnOn(int index, const Device& d)
{
	if (index >= 0 && index < count && devices[index])
		devices[index]->turnOn();
}

void SmartHome::turnOff(int index, const Device& d)
{
	if (index >= 0 && index < count && devices[index])
		devices[index]->turnOff();
}

double SmartHome::getAverage(const MyString& producer)
{
	int totalPrice = 0;
	int totalDevices = 0;
	for (int i = 0; i < count; i++)
	{
		if (strcmp(devices[i]->getProducer(), producer.c_str()) == 0)
		{
			totalDevices++;
			totalPrice += devices[i]->getPrice();
		}
	}
	double average = totalPrice / totalDevices;
	return average;
	
}
