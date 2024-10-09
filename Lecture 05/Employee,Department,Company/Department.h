#pragma once
#include "Employee.h"

class Department
{
	char name[max_length + 1];
	Employee employees[max_size];
	unsigned count;
public:
	Department();
	Department(const char*name);
	Department(const char* name, Employee* empl, unsigned cnt);
	const char* getName()const;
	errorCode addEmployee(const Employee& other);
	errorCode removeEmployee(unsigned id);
};

