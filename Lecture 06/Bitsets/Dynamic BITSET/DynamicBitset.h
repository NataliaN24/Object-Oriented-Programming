#pragma once
namespace CONSTANTS
{
	constexpr size_t BYTE_SIZE=8;

	unsigned char getMask(unsigned int number);
	unsigned int getBucketIndex(unsigned int number);
}
class DynamicBitset
{
	unsigned char* data;
	unsigned int maxNumber;
	unsigned int bucketsCount;

	void copyFrom(const DynamicBitset& other);
	void free();
public:
	DynamicBitset(unsigned int max);
	DynamicBitset(const DynamicBitset& other);
	DynamicBitset& operator=(const DynamicBitset& other);
	~DynamicBitset();

	void add(unsigned int n);
	void remove(unsigned int n);
	bool contains(unsigned int n)const;
	void print()const;

	friend DynamicBitset unionOfSets(const DynamicBitset& lhs, const DynamicBitset& rhs);
	friend DynamicBitset intersectionOfSets(const DynamicBitset& lhs, const DynamicBitset& rhs);
};