#pragma once
#include"IntSet.h"

class ArraySet:public IntSet
{
	int capacity;

public:
	ArraySet(int n);
	virtual bool member(int x)const override;
	int getIndex(int x)const;
	bool insert(int x);
	bool remove(int x) ;
};

