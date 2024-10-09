#pragma once
#include "Department.h"

class Company
{
	Department departments[max_departments];
	unsigned count;
public:
	Company();
	errorCode addDepartment(const char* name);
	errorCode removeDepartment(const char* name);
	errorCode addEmployees(const char* departmentName,const Employee&newEm);
	errorCode removeEmployee(const char* departmentName,unsigned id);
};
