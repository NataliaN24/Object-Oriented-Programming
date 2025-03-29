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
	void free();

public:
	Task();
	Task(const char* description,size_t priority,unsigned int min);
	Task(const Task& other)=delete;
	Task& operator=(const Task& other)=delete;
	~Task();

	void changeSatusToDone();
	void writeToFile(std::ofstream& ofs);
	Task(std::ifstream& ifs);
	const char* getDescr()const;
	bool getStatus()const;
	const Task& compare(const Task& rhs)const;

};
