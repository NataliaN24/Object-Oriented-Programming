#include "Bitset.h"

unsigned Bitset::getBucketIndex(unsigned number) const
{
    return number / CONSTANTS::BYTE_SIZE;
}

unsigned char Bitset::getMask(unsigned number) const
{
    unsigned indexInBucket = number % CONSTANTS::BYTE_SIZE;
    unsigned char mask = 1;
    mask = mask << (CONSTANTS::BYTE_SIZE - indexInBucket - 1);
    return mask;

}

bool Bitset::contains(unsigned number) const
{
    unsigned bucketIndex = getBucketIndex(number);
    unsigned char mask = getMask(number);
    return (mask & data[bucketIndex]);
}

bool Bitset::addNumber(unsigned number)
{
    if (number >= CONSTANTS::MAX_SIZE || contains(number))
    {
        return false;
    }
    unsigned bucketIndex = getBucketIndex(number);
    unsigned char mask = getMask(number);
    data[bucketIndex] |= mask;
    return true;
}

bool Bitset::removeNumber(unsigned number)
{
    if (number >= CONSTANTS::MAX_SIZE || !contains(number))
    {
        return false;
    }
    unsigned bucketIndex = getBucketIndex(number);
    unsigned char mask = getMask(number);
    data[bucketIndex] ^= mask;
    return true;
}

void Bitset::print() const
{
    std::cout << "{";
    unsigned current = 0;
    for (int i = 0; i < CONSTANTS::MAX_SIZE; i++)
    {
        if (contains(i))
        {
            std::cout << i << ' ';
        }
    }
    std::cout << "}" << std::endl;

}

Bitset Bitset::unionOfSets(const Bitset& rhs)
{
    Bitset result;
    for (int i = 0; i < CONSTANTS::BUCKETS_COUNT; i++)
    {
        result.data[i] =( data[i] | rhs.data[i]);
    }
    return result;

}

Bitset Bitset::interesectionOfSets(const Bitset& rhs)
{
    Bitset result;
    for (int i = 0; i < CONSTANTS::BUCKETS_COUNT; i++)
    {
        result.data[i] = (data[i] & rhs.data[i]);
    }
    return result;
}