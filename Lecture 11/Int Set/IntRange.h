#pragma once
#include"IntSet.h"

class IntRange:public IntSet
{
	int start;
	int end;
public:
	IntRange();
	IntRange(int start, int end);

	virtual bool member(int x)const override;
	virtual int get(int i)const override ;
	virtual bool isSubsetOf(const IntSet& other)const override;
	virtual bool intersects(const IntSet& other)const override;

};

