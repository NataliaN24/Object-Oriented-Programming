#pragma once
#include<iostream>
#pragma warning(disable:4996)

class Student
{
	char* name;
	int fn;

	void copyFrom(const Student& other);
	void free();

public:
	Student();
	Student(const Student& other);
	Student& operator=(const Student& other);
	Student(const char* name, int fn);
	~Student();

	void setName(const char* newName);
	void setFn(int newFn);

	const char* getName()const;
	int getFn()const;

};

