#include "DynamicBitset2.h"

void DynamicBitset2::freeDynamic()
{
    delete[]buckets;
}

void DynamicBitset2::copyDynamic(const DynamicBitset2& other)
{
    buckets = new uint8_t[other.bucketsCount];
    for (int i = 0; i < other.bucketsCount; ++i)
    {
        buckets[i] = other.buckets[i];
    }
}

unsigned DynamicBitset2::getBucketIndex(unsigned num) const
{
    return num / elementsInBucket;
}

DynamicBitset2::DynamicBitset2(const DynamicBitset2& other)
{
    copyDynamic(other);
}

DynamicBitset2& DynamicBitset2::operator=(const DynamicBitset2& other)
{
    if (this != &other)
    {
        freeDynamic();
        copyDynamic(other);
        bucketsCount = other.bucketsCount;
        N = other.N;
   }
    return *this;
}

DynamicBitset2::~DynamicBitset2()
{
    freeDynamic();
}

DynamicBitset2::DynamicBitset2(unsigned n)
{
    bucketsCount = n / elementsInBucket+1;
    buckets = new uint8_t[bucketsCount];
    this->N = n;
}

void DynamicBitset2::add(unsigned num)
{
    if (num > N)
    {
        return;
    }
    unsigned bucketIndex = num / elementsInBucket;
    unsigned bitIndex = num % elementsInBucket;
    uint8_t mask = 1 << bitIndex;
    buckets[bucketIndex] |= mask;
}

void DynamicBitset2::remove(unsigned num)
{
    unsigned bucketIndex = num / elementsInBucket;
    unsigned bitIndex = num % elementsInBucket;
    uint8_t mask = 1 << bitIndex;
    buckets[bitIndex] ^= mask;
}

bool DynamicBitset2::contains(unsigned num) const
{
    unsigned bucketIndex = num / elementsInBucket;
    unsigned bitIndex = num % elementsInBucket;
    uint8_t mask = 1 << bitIndex;
    return buckets[bitIndex] & mask;
}

void DynamicBitset2::print() const
{
    std::cout << '{';
    for (int i = 0; i <= N; i++)
    {
        if (contains(i))
        {
            std::cout << i << " ";

        }
    }
    std::cout << '}';
}

DynamicBitset2 unionSets(const DynamicBitset2& lhs, const DynamicBitset2& rhs)
{
    DynamicBitset2 result(std::max(lhs.N, rhs.N));
    unsigned minBucketsCount = std::min(lhs.bucketsCount
        , rhs.bucketsCount);
    for (int i = 0; i < minBucketsCount; i++)
    {
        result.buckets[i] = lhs.buckets[i] | rhs.buckets[i];
    }
    const DynamicBitset2& biggerN = lhs.bucketsCount > rhs.bucketsCount ? lhs : rhs;
    for (int i = minBucketsCount; i < biggerN.bucketsCount; i++)
    {
        result.buckets[i] = biggerN.buckets[i];
    }
    return result;
    
}

DynamicBitset2 intersectSets(const DynamicBitset2& lhs, const DynamicBitset2& rhs)
{
    DynamicBitset2 result(std::min(lhs.N, rhs.N));
    unsigned bucketsCount = std::min(lhs.bucketsCount, rhs.bucketsCount);
    for (int i = 0; i < bucketsCount; i++)
    {
        result.buckets[i] = rhs.buckets[i] & lhs.buckets[i];
    }
    return result;
}
