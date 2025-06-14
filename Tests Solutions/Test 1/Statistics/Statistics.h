#pragma once
#include<iostream>
#include<fstream>
constexpr char INTERVAL = ' ';

class Statistics
{
	double* arr;
	size_t size;

	void copyFrom(const Statistics& other);
	void free();
	void resize(size_t newSize);

public:
	Statistics();
	Statistics(const double* a, size_t n);
	Statistics(const Statistics& other);
	Statistics& operator=(const Statistics& other);
	~Statistics();

	void load(std::ifstream& ifs);
	double min()const;
	double printAvg()const;
	Statistics& combine(const Statistics& other);
	void print()const;

};

int getCharCount(std::ifstream& ifs);