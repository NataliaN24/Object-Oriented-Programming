#pragma once
#include<iostream>

class NVector
{
	int* data;
	size_t size;

	void copyFrom(const NVector& other);
	void free();
public:
	NVector(size_t size);
	NVector(const NVector& other);
	NVector& operator=(const NVector& other);
	~NVector();

	NVector& operator+=(const NVector& other);
	NVector& operator-= (const NVector & other);
	NVector& operator*=(size_t scalar);

	int& operator[](size_t index);
	int operator[](size_t index)const;
	size_t operator~()const;
	friend std::ostream& operator<<(std::ostream& os, const NVector& other);
	friend std::istream& operator>>(std::istream& is, NVector& other);
};
NVector operator+(const NVector& lhs, const NVector& rhs);
NVector operator-(const NVector& lhs, const NVector& rhs);
NVector operator*(const NVector& lhs, size_t scalar);
NVector operator*(size_t scalar, const NVector& rhs);
bool operator || (const NVector & lhs, const NVector & rhs);
size_t operator%(const NVector& lhs, const NVector& rhs);
bool operator|=(const NVector& lhs, const NVector& rhs);


