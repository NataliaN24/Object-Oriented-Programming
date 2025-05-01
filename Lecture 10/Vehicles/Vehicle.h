#pragma once
#include<iostream>
#include<fstream>
#pragma warning(disable:4996)

class Vehicle
{
	unsigned int yearOfCreation;
	unsigned int weight;
	unsigned int maxSpeed;
	unsigned int NumberOfTiresOrWagons;
	char *name;

	void copyFrom(const Vehicle& other);
	void free();
public:
	Vehicle();
	Vehicle(unsigned int year, unsigned int weight, unsigned int maxSpeed, unsigned int tires, const char* name);
	Vehicle(const Vehicle& other);
	Vehicle& operator=(const Vehicle& other);
	virtual ~Vehicle();

	unsigned int getYear()const;
	unsigned int getWeight()const;
	unsigned int getSpeed()const;
	unsigned int getTires()const;
	const char* getName()const;

	virtual void readFrom(std::istream& is);
	virtual void writeTo(std::ostream& os)const;

	virtual void print()const;

}; 
