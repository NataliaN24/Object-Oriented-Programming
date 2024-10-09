#pragma once
#include<iostream>
#include<cstring>
#pragma warning (disable:4996)

namespace
{
 constexpr int max_length = 127;
 constexpr int max_size = 15;
 constexpr int max_departments = 10;

}
enum class errorCode
{
	OK,
	NotFound,
	Duplicate,
	InvalidInput
};

const char* setChar(char* ch1, const char* ch2, int len);