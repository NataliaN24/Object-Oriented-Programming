#pragma once
#include "Gadget.h"

class Computer:public Gadget
{
	
public:
	Computer(const MyString& model, double price);
	virtual Gadget* clone()const override;
	virtual void print() const override;
};
