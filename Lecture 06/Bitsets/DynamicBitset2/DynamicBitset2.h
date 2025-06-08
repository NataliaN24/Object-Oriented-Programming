#pragma once
#include <iostream>

class DynamicBitset2
{
	uint8_t* buckets = nullptr;
	unsigned bucketsCount = 0;
	unsigned N = 0;
	const unsigned elementsInBucket = sizeof(uint8_t) * 8;//1 byte for sizeof(uint8_t)*8=8 elements in bucket equivalent to constexpr unsigned int BYTE_SIZE = 8;

	void freeDynamic();
	void copyDynamic(const DynamicBitset2& other);
	unsigned getBucketIndex(unsigned num)const;
public:
	DynamicBitset2() = default;
	DynamicBitset2(const DynamicBitset2& other);
	DynamicBitset2& operator=(const DynamicBitset2& other);
	~DynamicBitset2();
	explicit DynamicBitset2(unsigned n);

	void add(unsigned num);
	void remove(unsigned num);
	bool contains(unsigned num)const;
	void print()const;

	friend DynamicBitset2 unionSets(const DynamicBitset2& lhs, const DynamicBitset2& rhs);
	friend DynamicBitset2 intersectSets(const DynamicBitset2& lhs, const DynamicBitset2& rhs);


	
};


