#pragma once
#include<iostream>
#pragma warning(disable:4996)

constexpr int maxSize = 8;//2+4+2=8
constexpr int minSize = 7;
constexpr int digits = 4;


class Registration
{
	char regNumber[maxSize+1];

public:

	Registration() = delete;
	Registration(const char* str);
	bool operator==(const Registration& other);
	bool operator!=(const Registration& other);
	const char* getRegNumber()const;

};
