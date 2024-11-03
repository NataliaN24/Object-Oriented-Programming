#include "Multiset.h"

void Multiset::free()
{
    delete[]buckets;
    buckets = nullptr;
    n = bucketsCount = 0;
    
}

void Multiset::copyFrom(const Multiset& other)
{
    n = other.n;
    bucketsCount = other.bucketsCount;
    buckets = new uint8_t[bucketsCount];//is this necessary?
    for (int i = 0; i < bucketsCount; i++)
    {
        buckets[i] = other.buckets[i];
    }
}

void Multiset::printNumber(unsigned num, unsigned occurrences) const
{
    for (unsigned i = 0; i < occurrences; i++)
    {
        std::cout << num << " ";
    }
}

void Multiset::addNumberMultipleTimes(unsigned num, unsigned times)
{
    if (times > maxOccurrences)
    {
        times = maxOccurrences;
    }
    for (unsigned i = 0; i < times; i++)
    {
        addNumber(num);
    }
}

Multiset::Multiset(unsigned n)
{
    this->n = n;
    bucketsCount = n / elementsInBucket + 1;
    buckets = new uint8_t[bucketsCount]{ 0 };
}

Multiset::Multiset(const Multiset& other)
{
    copyFrom(other);
}

Multiset& Multiset::operator=(const Multiset& other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }

    return *this;
}

Multiset::~Multiset()
{
    free();
}

bool Multiset::addNumber(unsigned num)
{
    unsigned bucket = num / elementsInBucket;
    unsigned index = num % elementsInBucket;
    uint8_t& currentBucket = buckets[bucket];
    uint8_t mask = 1;
    unsigned occurrences = getCountOfOccurrences(num);
    mask <<= index * 2;
    switch (occurrences)
    {
    case 0:
    case 2:
    {
        currentBucket |= mask;
        return true;
    }
    case 1:
    {
        mask = ~mask;
        currentBucket &= mask;
        mask = ~mask;
        mask <<= 1;
        currentBucket |= mask;
        return true;
    }
    default:return false;
    }
   
}

bool Multiset::removeNumber(unsigned num) {
    unsigned bucket = num / elementsInBucket;
    unsigned index = num % elementsInBucket;

    uint8_t& currBucket = buckets[bucket];
    uint8_t mask = 1;
    unsigned occurrences = getCountOfOccurrences(num);

    mask <<= index * 2;

    switch (occurrences)
    {
    case 3:
    case 1:
    {
        mask = ~mask;
        currBucket &= mask;
        return true;
    }
    case 2: {
        currBucket |= mask;
        mask <<= 1;
        mask = ~mask;
        currBucket &= mask;
        return true;
    }
    default: return false;
    }
}

unsigned Multiset::getCountOfOccurrences(unsigned num) const
{
    unsigned bucket = num / elementsInBucket;
    unsigned index = num % elementsInBucket;

    uint8_t& currentBucket = buckets[bucket];
    uint8_t mask = 1;
    mask <<= index * 2;
    bool isFirstUp = ((currentBucket & mask) == mask);
    mask <<= 1;
    bool isSecondUp = ((currentBucket & mask) == mask);
    return (isFirstUp * (1 << 0) + isSecondUp*(1 << 1));
}

void Multiset::printSets() const
{
    std::cout << '{';
    for (unsigned i = 0; i < n; i++)
    {
        unsigned occurrences = getCountOfOccurrences(i);
        printNumber(i, occurrences);
    }
    std::cout << '}';

}

Multiset intersect(const Multiset& s1, const Multiset& s2)
{
    assert(s1.n == s2.n);

    int n = s1.n;
    Multiset res(n);

    for (unsigned i = 0; i < n; i++)
    {
        unsigned occurrencesInS1 = s1.getCountOfOccurrences(i);
        unsigned occurrencesInS2 = s2.getCountOfOccurrences(i);
        unsigned occurrences = occurrencesInS1 < occurrencesInS2 ? occurrencesInS1 : occurrencesInS2;
        res.addNumberMultipleTimes(i, occurrences);
    }

    return res;
}

Multiset unionSets(const Multiset& s1, const Multiset& s2)
{
    assert(s1.n == s2.n);

    int n = s1.n;
    Multiset res(n);

    for (unsigned i = 0; i < s1.bucketsCount; i++)
    {
        unsigned occurrencesInS1 = s1.getCountOfOccurrences(i);
        unsigned occurrencesInS2 = s2.getCountOfOccurrences(i);
        unsigned occurrences = occurrencesInS1 + occurrencesInS2;
        res.addNumberMultipleTimes(i, occurrences);
    }

    return res;
}