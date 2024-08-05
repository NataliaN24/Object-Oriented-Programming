#pragma once
#include<iostream>

namespace CONSTANTS
{
	constexpr size_t MAX_SIZE = 1024;
	constexpr size_t BYTE_SIZE = 8;
	constexpr size_t BUCKETS_COUNT = MAX_SIZE / BYTE_SIZE;
}

class Bitset
{
	unsigned char data[CONSTANTS::BUCKETS_COUNT] = { };

	unsigned getBucketIndex(unsigned number)const;
	unsigned char getMask(unsigned number)const;

public:
	Bitset() = default;

	bool contains(unsigned number)const;
	bool addNumber(unsigned number);
	bool removeNumber(unsigned number);
	void print()const;

	Bitset unionOfSets(const Bitset& rhs);
	Bitset interesectionOfSets(const Bitset& rhs);
};