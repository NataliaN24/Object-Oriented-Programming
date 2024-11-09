#include "UnionOfSets.h"

void UnionOfSets::copyFrom(const UnionOfSets& other)
{
	numOfSets = other.numOfSets;
	sets = new Set * [numOfSets];
	for (int i = 0; i < numOfSets; i++)
	{
		sets[i] = other.sets[i];
	}
	currentIndex = other.currentIndex;
}

void UnionOfSets::moveFrom(UnionOfSets&& other)noexcept
{
	numOfSets = other.numOfSets;
	sets = other.sets;
	currentIndex = other.currentIndex;

	other.sets = nullptr;
	other.numOfSets = 0;
	other.currentIndex = -1;
}

void  UnionOfSets::free()
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

UnionOfSets::UnionOfSets()
{
	sets = nullptr;
	numOfSets = 0;
	currentIndex = -1;
}

UnionOfSets::UnionOfSets(Set** sets, int numOfSets, int index) :sets(sets), numOfSets(numOfSets) ,currentIndex(index) {}

UnionOfSets::UnionOfSets(const  UnionOfSets& other)
{
	copyFrom(other);
}

UnionOfSets::UnionOfSets(UnionOfSets&& other)noexcept
{
	moveFrom(std::move(other));
}

UnionOfSets& UnionOfSets:: operator=(const  UnionOfSets& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return*this;
}

UnionOfSets& UnionOfSets:: operator=(UnionOfSets&& other)noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return*this;
}

bool UnionOfSets::contains(int element)const
{
	for (int i = 0; i < numOfSets; i++)
	{
		if (sets[i]->contains(element))
		{
			return true;
		}
	}
	return false;
}

UnionOfSets::~UnionOfSets()
{
	free();
}

int UnionOfSets::nextElement()
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