#pragma once
#include<iostream>
#include<fstream>
#include <stdexcept>

namespace CONSTANTS
{
    constexpr int BYTE = 8;
    constexpr int ONE = 1;
    constexpr int INDEX_MOST_SIGNIFICANT_BIT = 7;
}

namespace HELPER_FUNCTIONS 
{
    unsigned int minimum(unsigned int n1, unsigned int n2);
    unsigned int maximum(unsigned int n1, unsigned int n2);
}

class MultiSet 
{
private:

    unsigned int n;
    unsigned int k;
    unsigned char* buckets;

    void copyFrom(const MultiSet& other);
    void moveFrom(MultiSet&& other)noexcept;
    void free();
    void calculateValues(unsigned int num, unsigned int& index, unsigned int& shift, unsigned char& mask, unsigned char& count) const;
    unsigned int getNrOfBuckets()const;

public:

    MultiSet();
    MultiSet(const MultiSet& other);
    MultiSet( MultiSet&& other)noexcept;
    MultiSet&operator =(const MultiSet& other);
    MultiSet& operator =( MultiSet&& other)noexcept;
    ~MultiSet();

    void setLargestNum(unsigned int largestNum);
    void setK(unsigned int k);

    MultiSet(unsigned int largestNumber, unsigned int bitsNeeded);
   
    void add(unsigned int num);
    unsigned int count(unsigned int num) const;

    void printNumbers() const;
    void printMemoryRepresentation() const;

    void serialize(std::ofstream &ofs) const;
    void deserialize(std::ifstream&ifs);

    friend MultiSet intersection(const MultiSet& set1, const MultiSet& set2);
    friend MultiSet difference(const MultiSet& set1, const MultiSet& set2);
    friend MultiSet complement(const MultiSet& set);
};