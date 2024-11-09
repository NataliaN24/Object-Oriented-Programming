#pragma once
#include "Set.h"
#include<iostream>

class UnionOfSets:public Set
{
private:

	Set** sets;
	int numOfSets;
	int currentIndex;

	void copyFrom(const UnionOfSets& other);
	void moveFrom(UnionOfSets&& other)noexcept;
	void free();

public:

	UnionOfSets();
	UnionOfSets(const  UnionOfSets& other);
	UnionOfSets(UnionOfSets&& other)noexcept;
	UnionOfSets(Set** sets, int n,int index);
	UnionOfSets& operator=(const  UnionOfSets& other);
	UnionOfSets& operator=(UnionOfSets&& other)noexcept;
	 int nextElement() override;

	bool contains(int element)const override;
	~UnionOfSets()override;
};