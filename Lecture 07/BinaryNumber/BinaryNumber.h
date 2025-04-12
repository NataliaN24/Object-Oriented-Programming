#pragma once
#include<iostream>
#include<fstream>

namespace CONSTANTS
{
	constexpr size_t BYTE_SIZE = 8;

	unsigned char getMask(unsigned int number);
	unsigned int getBucketIndex(unsigned int number);
}

class BinaryNumber
{
	unsigned char* data;
	unsigned int bucketsCount;
	void copyFrom(const BinaryNumber& other);
	void free();
public:
	BinaryNumber();
	BinaryNumber(const char* str);
	BinaryNumber(const BinaryNumber& other);
	BinaryNumber& operator=(const BinaryNumber& other);
	~BinaryNumber();

	bool operator==(const BinaryNumber& other)const;
	bool operator!=(const BinaryNumber& other)const;
	BinaryNumber operator&(const BinaryNumber& other);
	BinaryNumber operator|(const BinaryNumber& other);
	BinaryNumber operator^(const BinaryNumber& other);
	BinaryNumber operator+(const BinaryNumber& other);
	BinaryNumber& operator<<(int number);
	BinaryNumber& operator>>(int number);
	friend std::ostream& operator<<(std::ostream& os, const BinaryNumber& other);
	friend std::istream& operator>>(std::istream& is, BinaryNumber& other);


};
