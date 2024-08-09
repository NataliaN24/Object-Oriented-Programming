#include "Dog.h"

Dog::Dog() : Animal(animalType::dog)
{}

void Dog::roar() const
{
	std::cout << "Wof wof" << std::endl;
}

Animal* Dog::clone() const
{
	Animal* newObj = new (std::nothrow) Dog(*this);
	return newObj;
}