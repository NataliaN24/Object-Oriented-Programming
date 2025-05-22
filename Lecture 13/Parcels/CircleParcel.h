#pragma once
#include"Parcel.h"

constexpr double pi = 3.14;

class CircleParcel:public Parcel
{
	double radius;
public:
	CircleParcel(double rad);
	virtual double perimeter()const override;
	virtual double area()const override;
	virtual Parcel* clone()const override;
};

