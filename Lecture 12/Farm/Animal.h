#pragma once
#include<iostream>
enum  class animalType
{
	dog,
	cat,
	cow
};

class Animal
{
	animalType type;

public:
	Animal(animalType type);
	virtual void roar()const = 0;
	virtual Animal* clone()const = 0;
	virtual ~Animal() = default;
	animalType getType()const;
};