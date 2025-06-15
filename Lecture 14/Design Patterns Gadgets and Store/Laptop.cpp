#include "Laptop.h"

Laptop::Laptop(const MyString& model, double price, double weight):Gadget(model,price)
{
	this->weight = weight;
}

void Laptop::print() const
{
	std::cout << getmodel() << " " << getPrice() << " " << weight;
}

void Laptop::setWeight(double w)
{
	weight = w;
}

double Laptop::getWeight() const
{
	return weight;
}

Gadget* Laptop::clone() const
{
	return new Laptop(*this);
}
