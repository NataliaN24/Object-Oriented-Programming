#pragma once
#include "Set.h"
#include<iostream>

class InteresectionOfSets:public Set
{
private:

	Set** sets;
	int numOfSets;
	int currentIndex;

	void copyFrom(const  InteresectionOfSets& other);
	void moveFrom(InteresectionOfSets&& other)noexcept;
	void free();

public:

	InteresectionOfSets();
	InteresectionOfSets(const InteresectionOfSets& other);
	InteresectionOfSets(InteresectionOfSets&& other)noexcept;
	InteresectionOfSets& operator=(const InteresectionOfSets& other);
	InteresectionOfSets& operator=(InteresectionOfSets&& other)noexcept;

	InteresectionOfSets(Set** sets, int n,int index);
	bool contains(int element)const override;
	int nextElement() override;

	~InteresectionOfSets()override;
};