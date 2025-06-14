#pragma once
#include<iostream>
#include<fstream>
#pragma warning(disable:4996)

class my_string
{
	char* str;

	void copyFrom(const my_string& other);
	void free();

public:
	my_string();
	my_string(const char* str);
	my_string(const my_string& other);
	my_string& operator=(const my_string& other);
	~my_string();


	const char* c_str()const;
	size_t length()const;

	const char& operator[](size_t index)const;
	char& operator[](size_t index);
	
	friend std::ostream& operator<<(std::ostream& os, const my_string& obj);

};

