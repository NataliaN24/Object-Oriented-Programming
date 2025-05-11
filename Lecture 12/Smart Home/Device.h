#pragma once
#include<iostream>
#include"MyString.h"

class Device
{
	MyString name;
	MyString producer;
	size_t price;
public:
	Device();
	Device(const MyString& _name, const MyString& prod, size_t pr);
	virtual ~Device();

	const char* getName()const;
	const char* getProducer()const;
	size_t getPrice()const;

	virtual void turnOn()const =0;
	virtual void turnOff()const=0;
	virtual void printDetails()const = 0;
	virtual Device* clone()const = 0;
};

