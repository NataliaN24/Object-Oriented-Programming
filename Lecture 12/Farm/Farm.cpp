#include "Farm.h"

void Farm::free()
{
    for (size_t i = 0; i < animalsCount; i++)
        delete animals[i];
    delete[] animals;
}

void Farm::copyFrom(const Farm& other)
{
	animals = new Animal * [other.capacity];
	animalsCount = other.animalsCount;
	capacity = other.capacity;

	for (size_t i = 0; i < animalsCount; i++)
	{
		Animal* cloned = other.animals[i]->clone();
		if (cloned)
			animals[i] = cloned;
	}
}

void Farm::moveFrom(Farm&& other)
{
	animalsCount = other.animalsCount;
	capacity = other.capacity;

	animals = other.animals;
	other.animals = nullptr;

	other.animalsCount = other.capacity = 0;
}

void Farm::resize()
{
	Animal** newCollection = new Animal * [capacity *= 2];
	for (size_t i = 0; i < animalsCount; i++)
		newCollection[i] = animals[i]; 
	delete[] animals;
	animals = newCollection;
}

Farm::Farm()
{
	capacity = 8;
	animalsCount = 0;
	animals = new Animal * [capacity];
}

Farm::Farm(const Farm& other)
{
	copyFrom(other);
}

Farm& Farm::operator=(const Farm& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

Farm::Farm(Farm&& other) noexcept
{
	moveFrom(std::move(other));
}

Farm& Farm::operator=(Farm&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

Farm::~Farm()
{
	free();
}

void Farm::addAnimal(animalType type)
{
	if (animalsCount == capacity)
		resize();
	animals[animalsCount++] = animalFactory(type);
}

void Farm::addAnimal(const Animal& animal)
{
	if (animalsCount == capacity)
		resize();
	animals[animalsCount++] = animal.clone();
}

void Farm::roarAll() const
{
	for (size_t i = 0; i < animalsCount; i++)
		animals[i]->roar();
}

animalType Farm::getTypeByIndex(unsigned index) const
{
	if (index > animalsCount) {
		throw std::out_of_range("Invalid index");
	}
	return animals[index]->getType();
}