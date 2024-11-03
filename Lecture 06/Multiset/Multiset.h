#pragma once
#include <iostream>
#include <assert.h>

class Multiset
{
	uint8_t* buckets;
	unsigned n;
	unsigned bucketsCount;
	const unsigned elementsInBucket = 4;
	const unsigned maxOccurrences = 3;

	void free();
	void copyFrom(const Multiset& other);
	void printNumber(unsigned num, unsigned occurrences)const;
	void addNumberMultipleTimes(unsigned num, unsigned times);

public:
	explicit Multiset(unsigned n);
	Multiset(const Multiset& other);
	Multiset& operator=(const Multiset& other);
	~Multiset();

	bool addNumber(unsigned num);
	bool removeNumber(unsigned num);
	unsigned getCountOfOccurrences(unsigned num)const;
	void printSets()const;

	friend Multiset intersect(const Multiset& s1, const Multiset& s2);
	friend Multiset unionSets(const Multiset& s1, const Multiset& s2);
	
};
