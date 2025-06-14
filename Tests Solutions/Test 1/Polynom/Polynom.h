#pragma once
#include<fstream>
#include<iostream>

constexpr char NEW_LINE = '\n';
class Polynom
{
	size_t *coefficients;
	size_t count;

	void copyFrom(const Polynom& other);
	void free();
	void resize(size_t newSize);
public:
	Polynom();
	Polynom(size_t* arr, size_t n);
	Polynom(const Polynom& other);
	Polynom& operator=(const Polynom& other);
	~Polynom();

	explicit Polynom(size_t n);
	void load(std::ifstream& ifs);
	void print()const;
	void add(const Polynom& other);

};

int getCharCount(std::ifstream& ifs);