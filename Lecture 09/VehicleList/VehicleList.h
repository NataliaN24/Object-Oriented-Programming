#pragma once
#include"Vehicle.h"


class VehicleList
{
	Vehicle** list; //since we don't have default constructor
	size_t size;
	size_t capacity;

	void copyFrom(const VehicleList& other);
	void free();
	void resize(size_t newCap);
public:
	VehicleList(int cap);
	VehicleList(const VehicleList& other);
	VehicleList& operator=(const VehicleList& other);
	~VehicleList();

	void addVehicle(const Vehicle& vehicle);
	Vehicle& operator[](size_t index);
	const Vehicle& operator[](size_t index)const;

	bool isEmpty()const;
	size_t getSize()const;
	size_t getCapacity()const;

	Vehicle* getByRegNumber(const Registration& reg);
};

