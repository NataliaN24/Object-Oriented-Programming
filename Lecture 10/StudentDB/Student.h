#pragma once
#include"MyString.h"
#include<iostream>

class Student
{
	MyString name;
	unsigned fn;
	unsigned course;
public:
	Student() = default;
	Student(const MyString& name, unsigned fn, unsigned course);
	const MyString& getName()const;
	unsigned getFn()const;
	unsigned getCourse()const;
	void setName(const MyString& newName);
	void setFn(unsigned newFN);
	void setCourse(unsigned newCourse);
};

