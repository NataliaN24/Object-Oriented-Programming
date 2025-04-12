#include "BinaryNumber.h"

void BinaryNumber::copyFrom(const BinaryNumber& other)
{
    bucketsCount = other.bucketsCount;
    data = new unsigned char[bucketsCount];
    for (int i = 0; i < bucketsCount; i++)
    {
        data[i] = other.data[i];
    }
}

void BinaryNumber::free()
{
    delete[]data;
}

BinaryNumber::BinaryNumber():data(nullptr),bucketsCount(0)
{
}

BinaryNumber::BinaryNumber(const char* str)
{
    int start = 0, end = 0;
    bool started = false;
    for (int i = 0; str[i] != '\0'; ++i)
    {
        if (str[i] == '1' && !started)
        {
            start = 1;
            started = true;
        }
        if (started && (str[i] == '0' || str[i] == '1'))
        {
            end = i;
        }
    }
    if (!started)
    {
        data = nullptr;
        bucketsCount = 0;
        return;
    }
    bucketsCount = (end - start + 1 + CONSTANTS::BYTE_SIZE - 1) / CONSTANTS::BYTE_SIZE;
    data = new unsigned char[bucketsCount]();

    unsigned int index = 0;
    for (size_t i = start; i <= end; ++i) {
        unsigned int bucketIndex = (i - start) / CONSTANTS::BYTE_SIZE;
        unsigned int bitIndex = (i - start) % CONSTANTS::BYTE_SIZE;
        if (str[i] == '1') {
            data[bucketIndex] |= (1 << (CONSTANTS::BYTE_SIZE - 1 - bitIndex));
        }
    }
}

BinaryNumber::BinaryNumber(const BinaryNumber& other)
{
    copyFrom(other);
}

BinaryNumber& BinaryNumber::operator=(const BinaryNumber& other)
{
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

BinaryNumber::~BinaryNumber()
{
    free();
}

bool BinaryNumber::operator==(const BinaryNumber& other) const
{
    if (bucketsCount != other.bucketsCount) {
        return false;
    }
    for (unsigned int i = 0; i < bucketsCount; ++i) {
        if (data[i] != other.data[i]) {
            return false;
        }
    }
    return true;
}

bool BinaryNumber::operator!=(const BinaryNumber& other) const
{
    return !(*this == other);
}

BinaryNumber BinaryNumber::operator&(const BinaryNumber& other)
{
    int minBucketSize = std::min(bucketsCount, other.bucketsCount);
    BinaryNumber result;
    result.bucketsCount = minBucketSize;
    result.data = new unsigned char[minBucketSize]();
    for (int i = 0; i < minBucketSize; i++) {
        result.data[i] = data[i] & other.data[i];
    }
    return result;
}

BinaryNumber BinaryNumber::operator|(const BinaryNumber& other)
{
    int minBucketSize = std::min(bucketsCount, other.bucketsCount);
    BinaryNumber result;
    result.bucketsCount = minBucketSize;
    result.data = new unsigned char[minBucketSize]();
    for (int i = 0; i < minBucketSize; i++) {
        result.data[i] = data[i] | other.data[i];
    }
    return result;
}

BinaryNumber BinaryNumber::operator^(const BinaryNumber& other)
{
    int minBucketSize = std::min(bucketsCount, other.bucketsCount);
    BinaryNumber result;
    result.bucketsCount = minBucketSize;
    result.data = new unsigned char[minBucketSize]();
    for (int i = 0; i < minBucketSize; i++) {
        result.data[i] = data[i] ^ other.data[i];
    }
    return result;
}

BinaryNumber BinaryNumber::operator+(const BinaryNumber& other)
{
    unsigned int maxBuckets = std::max(bucketsCount, other.bucketsCount);
    BinaryNumber result;
    result.bucketsCount = maxBuckets + 1; 
    result.data = new unsigned char[result.bucketsCount]();

    unsigned char carry = 0;
    for (unsigned int i = 0; i < maxBuckets; ++i) {
        unsigned char a = (i < bucketsCount) ? data[i] : 0;
        unsigned char b = (i < other.bucketsCount) ? other.data[i] : 0;
        unsigned char sum = a + b + carry;
        carry = (sum < a || sum < b) ? 1 : 0;
        result.data[i] = sum;
    }

    if (carry) {
        result.data[maxBuckets] = 1;  
    }

    return result;
}

BinaryNumber& BinaryNumber::operator<<(int shift)
{
    BinaryNumber result(*this);
    unsigned int byteShift = shift / CONSTANTS::BYTE_SIZE;
    unsigned int bitShift = shift % CONSTANTS::BYTE_SIZE;

    for (unsigned int i = bucketsCount - 1; i >= byteShift; --i)
    {
        result.data[i] = data[i - byteShift] << bitShift;
        if (i > 0) {
            result.data[i] |= data[i - byteShift - 1] >> (CONSTANTS::BYTE_SIZE - bitShift);
        }
    }

    return result;
}

BinaryNumber& BinaryNumber::operator>>(int shift)
{
    BinaryNumber result(*this);
    unsigned int byteShift = shift / CONSTANTS::BYTE_SIZE;
    unsigned int bitShift = shift % CONSTANTS::BYTE_SIZE;

    for (unsigned int i = 0; i < bucketsCount - byteShift; ++i) {
        result.data[i] = data[i + byteShift] >> bitShift;
        if (i + 1 < bucketsCount) {
            result.data[i] |= data[i + byteShift + 1] << (CONSTANTS::BYTE_SIZE - bitShift);
        }
    }

    return result;
}

std::ostream& operator<<(std::ostream& os, const BinaryNumber& other)
{
    bool started = false;
    for (unsigned int i = 0; i < other.bucketsCount; ++i) {
        for (unsigned int bit = 0; bit < CONSTANTS::BYTE_SIZE; ++bit) {
            unsigned char mask = CONSTANTS::getMask(bit);
            if ((other.data[i] & mask) != 0) {
                os << '1';
                started = true;
            }
            else if (started) {
                os << '0';
            }
        }
    }
    return os;
}

std::istream& operator>>(std::istream& is, BinaryNumber& other)
{
    char ch;
    other.bucketsCount = 0;
    other.data = nullptr;

    while (is >> ch && (ch == '0' || ch == '1')) {
       
        if ((other.bucketsCount * CONSTANTS::BYTE_SIZE) <= other.bucketsCount * CONSTANTS::BYTE_SIZE + 1) {
            unsigned int newBucketsCount = (other.bucketsCount + 1);
            unsigned char* newData = new unsigned char[newBucketsCount]();
            for (unsigned int i = 0; i < other.bucketsCount; ++i) {
                newData[i] = other.data[i];
            }
            delete[] other.data;
            other.data = newData;
        }

        unsigned int bucketIndex = (other.bucketsCount * CONSTANTS::BYTE_SIZE) / CONSTANTS::BYTE_SIZE;
        unsigned int bitIndex = (other.bucketsCount * CONSTANTS::BYTE_SIZE) % CONSTANTS::BYTE_SIZE;

        if (ch == '1') {
            other.data[bucketIndex] |= (1 << (CONSTANTS::BYTE_SIZE - 1 - bitIndex));
        }

        other.bucketsCount++;
    }

    return is;
}

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
