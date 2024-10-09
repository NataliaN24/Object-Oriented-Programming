#pragma once
#include"Utils.h"

class Employee
{
	unsigned   id;
	char name[max_length + 1];
	char position[max_length + 1];
	double salary;

public:
	Employee();
	Employee(unsigned id, const char* name, const char* pos, double salary);
	double getSalary()const;
	unsigned getId()const;
	errorCode updateSalary(double amount);	
};