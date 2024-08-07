#pragma once
#include <iostream>
#include "StringPool.h"

class ImmutableString
{
public:
	ImmutableString(const char* data);
	ImmutableString(const ImmutableString& other);
	ImmutableString& operator=(const ImmutableString& other) = delete;
	~ImmutableString();

	size_t getLength()const;
	char operator[](size_t index)const;
	const char* c_str()const;

private:
	const char* data;
	size_t length;

	void copyFrom(const ImmutableString& other);
	void free();

	static StringPool pool;
};
std::ostream& operator<<(std::ostream& os, const ImmutableString& str);
bool operator<(const ImmutableString& lhs, const ImmutableString& rhs);
bool operator<=(const ImmutableString& lhs, const ImmutableString& rhs);
bool operator>=(const ImmutableString& lhs, const ImmutableString& rhs);
bool operator>(const ImmutableString& lhs, const ImmutableString& rhs);
bool operator==(const ImmutableString& lhs, const ImmutableString& rhs);
bool operator!=(const ImmutableString& lhs, const ImmutableString& rhs);