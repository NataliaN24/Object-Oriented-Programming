#include "Factory.h"


Gadget* createProduct(const MyString& type, const MyString& model, double price, double weight )
{
	if (type == "Computer")
	{
		return new Computer(model, price);
	}
	else if (type == "Laptop")
	{
		return new Laptop(model, price, weight);
	}
	return nullptr;
}
