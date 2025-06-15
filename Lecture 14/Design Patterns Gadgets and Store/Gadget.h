#pragma once
#include"MyString.h"
	
class Gadget
{

	MyString model;
	double price;
public:
	Gadget(const MyString& model, double price);
	const MyString& getmodel()const;
	void setModel(const MyString& model);
	double getPrice()const;
	void setPrice(double newPrice);

	virtual void print()const=0;
	virtual Gadget* clone()const = 0;
	virtual ~Gadget() = default;
};

