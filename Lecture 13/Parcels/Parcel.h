#pragma once
#include<iostream>

class Parcel
{

public:

	virtual double perimeter()const=0;
	virtual double area()const=0;
	virtual Parcel* clone()const = 0;
	virtual ~Parcel() = default;

};

