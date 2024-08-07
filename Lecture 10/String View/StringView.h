#pragma once
#pragma once
#include <fstream>
#include "MyString.h"

class StringView
{
	const char* begin;
	const char* end;

public:
	StringView(const char* b, const char* e);
	StringView(const char* str);
	StringView(const MyString& str);
	size_t length()const;
	char operator[](size_t index)const;
	StringView substr(size_t from, size_t length)const;
	friend std::ostream &operator<< (std::ostream & os, const StringView & strView);

};

