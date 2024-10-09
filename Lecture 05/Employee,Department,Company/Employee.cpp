#include "Employee.h"

Employee::Employee():id(0),salary(0.0)
{
    name[0] = '\0';
    position[0] = '\0';
}

Employee::Employee(unsigned id, const char* name,const  char* pos, double salary):id(id),salary(salary)
{
    setChar(this->name, name, max_length);
    setChar(this->position, pos, max_length);
}

double Employee::getSalary() const
{
    return  salary;
}

unsigned Employee::getId() const
{
    return id;
}

errorCode Employee::updateSalary(double amount)
{
    if (salary == amount)
    {
        return errorCode::Duplicate;
    }
    if (amount <= 0)
    {
        return errorCode::InvalidInput;
    }
    if (salary != amount)
    {
        return errorCode::OK;
    }
}