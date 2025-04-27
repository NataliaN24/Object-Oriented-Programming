#include "Student.h"

void Student::copyFrom(const Student& other)
{
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);
    fn = other.fn;
}

void Student::free()
{
    delete[]name;
}

Student::Student()
{
    name = new char[1];
    name[0] = '\0';
    fn = 0;

}

Student::Student(const Student& other)
{
    copyFrom(other);
}

Student& Student::operator=(const Student& other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}

Student::Student(const char* name, int fn)
{
    setName(name);
    setFn(fn);
}

Student::~Student()
{
    free();
}

void Student::setName(const char* newName)
{
    delete[]name;
    name = new char[strlen(newName) + 1];
    strcpy(name, newName);
    
}

void Student::setFn(int newFn)
{
    fn = newFn;
}

const char* Student::getName() const
{
    return name;
}

int Student::getFn() const
{
    return fn;
}
