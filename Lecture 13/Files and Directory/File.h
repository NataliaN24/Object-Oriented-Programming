#pragma once
#include<iostream>
#pragma warning(disable:4996)

constexpr int MAX_FILE_NAME = 32;
class File
{
	char name[MAX_FILE_NAME + 1];
public:
	File() = default;
	File(const char* name);
	virtual File* clone()const = 0;
	void setName(const char* name);
	const char* getName()const;
	virtual void printContent()const = 0;
	virtual ~File() = default;


};

