#pragma once
#pragma warning (disable: 4996)
#include<iostream>
//I am using MyStringSSO  class from task 01

class MyString
{
private:
	static const int max_length = 15;
	size_t length;
	union
	{
		struct
		{
			char* data;
			size_t capacity;
		} string;
		char ch[max_length + 1];
	};
	void copyFrom(const MyString&);
	void moveFrom(MyString&&);
	void free();
	void check(int)const;

public:
	MyString();
	MyString(const char*);
	MyString(const MyString&);
	~MyString();
	MyString& operator=(const MyString&);

	MyString(MyString&&);
	MyString& operator=(MyString&&);

	MyString& operator+=(const MyString&);
	char& operator[](size_t);
	char operator[](size_t) const;

	MyString substr(size_t, size_t) const;

	const char* c_str() const;
	friend std::istream& operator>>(std::istream&, MyString&);

	void clear();
	bool empty()const;
	void append(char);
	int compare(const MyString&)const;

};
char* expand(const char*, int);
std::ostream& operator<<(std::ostream&, const MyString&);
MyString operator+(const MyString&, const MyString&);
bool operator<(const MyString&, const MyString&);
bool operator>(const MyString, const MyString&);
bool operator<=(const MyString&, const MyString&);
bool operator>=(const MyString&, const MyString&);
bool operator==(const MyString&, const MyString&);
bool operator!=(const MyString&, const MyString&);