#pragma once
#include"Parcel.h"

class RectangleParcel:public Parcel
{
	double a;
	double b;
public:
	RectangleParcel(double a, double b);
	virtual double perimeter()const override;
	virtual double area()const override;
	virtual Parcel* clone()const override;
};

