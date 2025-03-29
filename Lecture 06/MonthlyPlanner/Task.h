#pragma once
#include<iostream>
#include<fstream>
#include<cstring>
#pragma warning(disable:4996)

class Task
{
	char* description;
	size_t priority;
	unsigned int minutes;
	bool status;
	void copyFrom(const Task& other);
	void free();

public:
	Task();
	Task(const char* description,size_t priority,unsigned int min);
	Task(const Task& other);
	Task& operator=(const Task& other);
	~Task();

	void changeSatusToDone();
	void writeToFile(std::ofstream& ofs);
	Task(std::ifstream& ifs);
	const char* getDescr()const;
	bool getStatus()const;
	unsigned int getMinutes()const;
	size_t getPriority()const;
	const Task& compare(const Task& rhs)const;

};
