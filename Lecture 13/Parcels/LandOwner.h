#pragma once
#include"Parcel.h"
#include"ParcelFactory.h"

class LandOwner
{
	Parcel** parcels;
	int count;
	int capacity;

	void copyFrom(const LandOwner& other);
	void free();
	void resize(int newCap);
public:
	LandOwner();
	LandOwner(const LandOwner& other);
	LandOwner& operator=(const LandOwner& other);
	~LandOwner();

	void addParcel(const Parcel &other);
	void addParcel(const char*str);
	void removeParcel(int index);

	double getTotalPerimeter()const;
	double getTotalArea()const;
};

