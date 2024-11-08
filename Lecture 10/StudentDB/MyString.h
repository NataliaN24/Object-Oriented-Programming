#pragma once
#include<iostream>
class MyString
{
	char* _data;
	size_t _size;
	size_t _allocatedDataSize;

	void copyFrom(const MyString& other);
	void free();
	explicit MyString(size_t stringLength);
	void resize(unsigned newAllocatedSize);
public:

	MyString();
	MyString(const MyString& other);
	MyString(const char* data);
	MyString& operator = (const MyString& other);
	~MyString();

	size_t getCapacity()const;
	size_t getSize()const;
	const char* c_str()const;

	MyString& operator+=(const MyString& other);

	char& operator[](size_t index);
	const char& operator[](size_t index)const;

	friend std::ostream& operator<<(std::ostream& os, const MyString& obj);
	friend std::istream& operator>>(std::istream& is, MyString& ref);
	friend MyString operator+(const MyString& lhs, const MyString& rhs);
};
bool operator==(const MyString& lhs, const MyString& rhs);
bool operator!=(const MyString& lhs, const MyString& rhs);
bool operator<(const MyString& lhs, const MyString& rhs);
bool operator<=(const MyString& lhs, const MyString& rhs);
bool operator>(const MyString& lhs, const MyString& rhs);
bool operator>=(const MyString& lhs, const MyString& rhs);