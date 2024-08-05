#include "DynamicBitset.h"
#include<iostream>

using namespace CONSTANTS;

unsigned char CONSTANTS::getMask(unsigned int number)
{
    unsigned int index = number % BYTE_SIZE;
    unsigned char mask = 1;
    mask <<= (BYTE_SIZE - index - 1);
    return mask;
}

unsigned int CONSTANTS::getBucketIndex(unsigned int number)
{
    return number / BYTE_SIZE;
}

void DynamicBitset::copyFrom(const DynamicBitset& other)
{
    maxNumber = other.maxNumber;
    bucketsCount = other.bucketsCount;
    data = new unsigned char[bucketsCount];
    for (size_t i = 0; i < bucketsCount; i++)
    {
        data[i] = other.data[i];
    }
}

void DynamicBitset::free()
{
    delete[]data;
    data = nullptr;
    maxNumber = 0;
    bucketsCount = 0;
}

DynamicBitset::DynamicBitset(unsigned int max)
{
    maxNumber = max;
    bucketsCount = max / BYTE_SIZE + 1;
    data = new unsigned char[bucketsCount] {};
}

DynamicBitset::DynamicBitset(const DynamicBitset& other)
{
    copyFrom(other);
}

DynamicBitset& DynamicBitset::operator=(const DynamicBitset& other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}

DynamicBitset::~DynamicBitset()
{
    free();
}

void DynamicBitset::add(unsigned int n)
{
    if (n > maxNumber)
    {
        return;
    }
    unsigned int bucketIndex = getBucketIndex(n);
    unsigned char mask = getMask(n);
    data[bucketIndex] |= mask;
}

void DynamicBitset::remove(unsigned int n)
{
    if (n > maxNumber)
    {
        return;
    }
    unsigned int bucketIndex = getBucketIndex(n);
    unsigned char mask = getMask(n);
    data[bucketIndex] ^= mask;
}

bool DynamicBitset::contains(unsigned int n) const
{
    if (n > maxNumber)
    {
        return false;
    }
    unsigned int bucketIndex = getBucketIndex(n);
    unsigned char mask = getMask(n);
   return ( data[bucketIndex] &mask);
}

void DynamicBitset::print() const
{
    for (size_t i = 0; i <= maxNumber; i++) {
        if (contains(i)) {
            std::cout << i << ' ';
        }
    }

    std::cout << std::endl;
}

DynamicBitset unionOfSets(const DynamicBitset& lhs, const DynamicBitset& rhs)
{
    DynamicBitset result(std::max(lhs.maxNumber, rhs.maxNumber));
    unsigned int commonBuckets = std::min(lhs.bucketsCount, rhs.bucketsCount);

    for (size_t i = 0; i < commonBuckets; ++i)
    {
        result.data[i] = lhs.data[i] | rhs.data[i];
    }
    const DynamicBitset& largerSet = lhs.maxNumber > rhs.maxNumber ? lhs : rhs;
    unsigned int largerSetBuckets = largerSet.bucketsCount;
    for (size_t i = commonBuckets; i < largerSetBuckets; ++i)
    {
        result.data[i] = largerSet.data[i];
    }
    return result;
}

DynamicBitset intersectionOfSets(const DynamicBitset& lhs, const DynamicBitset& rhs)
{
    DynamicBitset result(std::min(lhs.maxNumber, rhs.maxNumber));
    unsigned int commonBuckets = std::min(lhs.bucketsCount, rhs.bucketsCount);
    for (size_t i = 0; i < commonBuckets; ++i)
    {
        result.data[i] = lhs.data[i] & rhs.data[i];
    }
    return result;
  
}