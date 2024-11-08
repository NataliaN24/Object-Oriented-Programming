#pragma once
#include"StudentDB.h"

class FilteredStudentDB:public StudentDB
{
public:
	using Predicate = bool(*)(const Student&);
	void filter(Predicate pred);
	void limit(unsigned N);
};

