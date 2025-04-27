#pragma once
#include"Registration.h"

class Vehicle
{
	Registration regNumber;
	char* description;

	void copyFrom(const Vehicle& other);
	void free();
public:
	Vehicle() = delete;
	Vehicle(const Vehicle& other);
	Vehicle& operator=(const Vehicle& other);
	Vehicle(const Registration& number, const char* descr);
	~Vehicle();

	const Registration& getRegistration() const;
	const char* getDescription() const;
};

