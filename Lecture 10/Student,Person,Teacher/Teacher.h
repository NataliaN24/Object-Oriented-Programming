#pragma once
#include"Person.h"
#include<iostream>

class Teacher:public Person
{
	char** subject;
	size_t subjectsCount;

	void free();
	void copyFrom(const Teacher& other);
	void moveFrom(Teacher&& other);
public:
	Teacher(const char* name, int age, const char* const* subjects, size_t subjectsCount);
	
	Teacher(const Teacher& other);
	Teacher& operator=(const Teacher& other);
	Teacher(Teacher&& other) noexcept;
	Teacher& operator=(Teacher&& other) noexcept;
	~Teacher();
};

