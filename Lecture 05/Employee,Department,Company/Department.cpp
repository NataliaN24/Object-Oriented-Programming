#include "Department.h"
#include "Employee.h"
#include"Utils.h"

Department::Department()
{
	name[0] = '\0';
	count = 0;
	for (unsigned i = 0; i < max_size; i++)
	{
		employees[i] = Employee();
	}
}

Department::Department(const char* name)
{
	setChar(this->name, name, max_size);
}

Department::Department(const char* name, Employee* empl, unsigned cnt)
{
	setChar(this->name, name, max_size);
	if (cnt < max_size)
	{
		count = cnt;
		for (int i = 0; i < count; i++) {
			employees[i] = empl[i];
		}
		for (int i = count; i < max_size; i++) {
			employees[i] = Employee();
		}
	}
	else
	{
		throw errorCode::InvalidInput;
	}
}

const char* Department::getName() const
{
	return name;
}

errorCode Department::addEmployee(const Employee& other)
{
	if (count >= max_size)
	{
		return errorCode::InvalidInput;
	}
	else
	{
		employees[count++] = other;
		return errorCode::OK;
	}
}

errorCode Department::removeEmployee(unsigned id)
{
	for (int i = 0; i < count; i++)
	{
		if (employees[i].getId() == id) {
			std::swap(employees[i], employees[count - 1]);
			count--;
			return errorCode::OK;
		}
	}
	return errorCode::NotFound;

}