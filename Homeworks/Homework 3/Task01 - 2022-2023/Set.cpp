#include "Set.h"

void  Set::copyFrom(const Set& other)
{
	elements = new int[other.size];

	for (int i = 0; i < other.size; ++i)
	{
		elements[i] = other.elements[i];
	}

	size = other.size;
}

void  Set::moveFrom(Set&& other)noexcept
{
	elements = other.elements;
	size = other.size;

	other.elements = nullptr;
	other.size = 0;
}

void  Set::free()
{
	delete[]elements;
	elements = nullptr;
	size = 0;
}

Set::Set()
{
	elements = nullptr;
	size = 0;
}

Set::Set( int* elements, int size):elements(elements),size(size) {}

Set::Set(const Set& other)
{
	copyFrom(other);
}

Set::Set(Set&& other)noexcept
{
	moveFrom(std::move(other));
}

Set& Set:: operator= (const Set& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

Set& Set::operator=(Set&& other)noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

Set::~Set()
{
	free();
}
