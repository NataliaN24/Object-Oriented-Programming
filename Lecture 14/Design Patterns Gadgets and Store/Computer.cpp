#include "Computer.h"

Computer::Computer(const MyString& model, double price):Gadget(model,price)
{
}

Gadget* Computer::clone() const
{
	return new Computer(*this);
}

void Computer::print() const
{
	std::cout << getmodel() << " " << getPrice() << " ";
}
