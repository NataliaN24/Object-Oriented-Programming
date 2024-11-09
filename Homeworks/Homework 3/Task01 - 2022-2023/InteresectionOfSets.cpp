#include "InteresectionOfSets.h"

void InteresectionOfSets::copyFrom(const  InteresectionOfSets& other)
{
	numOfSets = other.numOfSets;
	sets = new Set*[numOfSets];
	for (int i = 0; i < numOfSets; i++)
	{
		sets[i] = other.sets[i];
	}
	currentIndex = other.currentIndex;
}

void InteresectionOfSets::moveFrom(InteresectionOfSets&& other)noexcept
{
	numOfSets = other.numOfSets;
	sets = other.sets;
	currentIndex = other.currentIndex;

	other.sets = nullptr;
	other.numOfSets = 0;
	other.currentIndex = -1;
}

void InteresectionOfSets::free()
{
	if (sets != nullptr)
	{
		for (int i = 0; i < numOfSets; i++)
		{
			delete sets[i];
		}
		delete[]sets;
		sets = nullptr;
	}
	numOfSets = 0;
	currentIndex = -1;
}

InteresectionOfSets::InteresectionOfSets(Set** sets, int n,int index):sets(sets),numOfSets(n),currentIndex(index) {}

InteresectionOfSets::InteresectionOfSets()
{
	sets = nullptr;
	numOfSets = 0;
	currentIndex = 0;
}

InteresectionOfSets::InteresectionOfSets(const InteresectionOfSets& other)
{
	copyFrom(other);
}

InteresectionOfSets::InteresectionOfSets(InteresectionOfSets&& other)noexcept
{
	moveFrom(std::move(other));
}

InteresectionOfSets& InteresectionOfSets:: operator=(const InteresectionOfSets& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return*this;
}

InteresectionOfSets& InteresectionOfSets:: operator=(InteresectionOfSets&& other)noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return*this;
}

bool InteresectionOfSets::contains(int element)const
{
	for (int i = 0; i < numOfSets; i++) 
	{
		if (!sets[i]->contains(element))
		{
			return false;
		}
	}
	return true;
}

InteresectionOfSets::~InteresectionOfSets()
{
	free();
}

int InteresectionOfSets::nextElement()
{
	while (currentIndex < numOfSets)
	{
		int element = sets[currentIndex]->nextElement();
		if (element != -1)
		{
			return element;
		}
		currentIndex++;
	}
	return -1;
}