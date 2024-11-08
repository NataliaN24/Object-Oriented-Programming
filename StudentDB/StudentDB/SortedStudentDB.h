#pragma once
#include"StudentDB.h"

class SortedStudentDB:public StudentDB
{

public:
	using comparator = bool(*)(const Student& lhs, const Student& rhs);
	void sortBy(comparator criteria);
};

bool compareByName(const Student& a, const Student& b);

bool compareByFn(const Student& a, const Student& b);

bool compareByCourse(const Student& a, const Student& b);