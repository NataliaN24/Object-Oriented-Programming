#include "Student.h"

Student::Student(const MyString& name, unsigned fn, unsigned course)
{
    setName(name);
    setFn(fn);
    setCourse(course);
}

const MyString& Student::getName() const
{
    return name;
}

unsigned Student::getFn() const
{
    return fn;
}

unsigned Student::getCourse() const
{
    return course;
}

void Student::setName(const MyString& newName)
{
    name = newName;
}

void Student::setFn(unsigned newFN)
{
    fn = newFN;
}

void Student::setCourse(unsigned newCourse)
{
    course = newCourse;
}
