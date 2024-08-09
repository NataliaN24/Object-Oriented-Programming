#pragma once
#include"Animal.h"
#include"AnimalFactory.h"

class Farm
{
	Animal** animals;
	size_t animalsCount;
	size_t capacity;

	void free();
	void copyFrom(const Farm& other);
	void moveFrom(Farm&& other);
	void resize();
public:

	  Farm();
	  Farm(const Farm& other);
	  Farm& operator=(const Farm& other);
	  Farm(Farm&& other) noexcept;
	  Farm& operator=(Farm&& other) noexcept;
	  ~Farm();
	  void addAnimal(animalType type);
	  void addAnimal(const Animal& animal);
	  void roarAll()const;
	  animalType getTypeByIndex(unsigned index)const;
};
