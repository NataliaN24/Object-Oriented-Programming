#include "Company.h"

Company::Company()
{
    count = 0;
    for (int i = 0; i < max_departments; i++)
    {
        departments[i] = Department();
    }
}

errorCode Company::addDepartment(const char* name)
{
    if (count >= max_departments) {
        return errorCode::InvalidInput;
    }
    else
    {
        departments[count++] = Department(name);
        return errorCode::OK;
    }
}

errorCode Company::removeDepartment(const char* name)
{
    for (int i = 0; i < count; i++)
    {
        if (strcmp(departments[i].getName(), name) == 0)
        {
            std::swap(departments[i], departments[count - 1]);
            count--;
            return errorCode::OK;
        }
   }
    return errorCode::NotFound;
}

errorCode Company::addEmployees(const char* departmentName, const Employee& newEm)
{
    for (int i = 0; i < count; i++)
    {
        if (strcmp(departments[i].getName(), departmentName) == 0)
        {
             departments[i].addEmployee(newEm);
             return errorCode::OK;

        }
    }
    errorCode result = addDepartment(departmentName);
    if (result != errorCode::OK)
    {
        return result;
    }
    return departments[count - 1].addEmployee(newEm);
    return errorCode::OK;
}

errorCode Company::removeEmployee(const char* departmentName, unsigned id)
{
    for (int i = 0; i < count; i++)
    {
        if (strcmp(departments[i].getName(), departmentName) == 0)
        {
            departments[i].removeEmployee(id);
            return errorCode::OK;
        }
    }
    return errorCode::NotFound;
}