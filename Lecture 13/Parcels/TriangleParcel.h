#pragma once
#include"Parcel.h"

class TriangleParcel :public Parcel
{
	double a;
	double b;
	double c;
public:
	TriangleParcel(double a, double b, double c);
	virtual double perimeter()const override;
	virtual double area()const override;
	virtual Parcel* clone()const override;
};

