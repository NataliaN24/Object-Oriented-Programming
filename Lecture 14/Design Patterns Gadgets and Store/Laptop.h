#pragma once
#include"Gadget.h"

class Laptop:public Gadget
{
	double weight;

public:
	Laptop(const MyString& model, double price, double weight);
	void print()const override;

	void setWeight(double w);
	double getWeight()const;

	virtual Gadget* clone()const override;
};
