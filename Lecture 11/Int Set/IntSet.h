#pragma once
#include<iostream>

class IntSet
{
protected:
	int* numbers;
	int count;
	void copyFrom(const IntSet& other);
	void free();
public:
	IntSet();
	IntSet(const IntSet& other);
	IntSet& operator=(const IntSet& other);
	IntSet(const int* numbers, int cnt);
	virtual~IntSet();

	virtual bool member(int x)const=0;
	virtual int get(int i)const;
	virtual bool isSubsetOf(const IntSet&other)const ;
	virtual bool intersects(const IntSet&other)const ;

};

