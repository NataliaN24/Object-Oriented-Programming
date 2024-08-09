#include "Animal.h"

Animal::Animal(animalType type):type(type)
{
}

animalType Animal::getType() const
{
	return type;
}
