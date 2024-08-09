#include "Cat.h"

Cat::Cat():Animal(animalType::cat)
{
}

void Cat::roar() const
{
    std::cout << "Meow meow" << std::endl;
}

Animal* Cat::clone() const
{
    Animal* obj = new(std::nothrow)Cat(*this);
    return obj;
}