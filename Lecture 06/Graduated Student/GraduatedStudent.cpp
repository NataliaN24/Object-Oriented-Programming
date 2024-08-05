#include "GraduatedStudent.h"
#include <cstring>
#pragma warning(disable:4996)

void GraduatedStudent::copyFrom(const GraduatedStudent& other)
{
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);

    grades = new int[other.gradesCount];
    for (int i = 0; i < other.gradesCount; ++i)
    {
        grades[i] = other.grades[i];
    }
    gradesCount = other.gradesCount;

    if (strlen(other.quote) > CONSTANTS::QUOTE_MAX_SIZE)
    {
        return;
    }
    else
    {
        strcpy(quote, other.quote);
    }
}

void GraduatedStudent::free()
{
    delete[]name;
    delete[]grades;

    name = nullptr;
    grades = nullptr;
    gradesCount = 0;
    strcpy(name, " ");
}

GraduatedStudent::GraduatedStudent(const char* name, const int* grades, size_t count, const char* quote)
{
    setName(name);
    setGrades(grades, count);
    setQuote(quote);
}

GraduatedStudent::GraduatedStudent(const GraduatedStudent& other)
{
    copyFrom(other);
}

GraduatedStudent& GraduatedStudent::operator=(const GraduatedStudent& other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}

GraduatedStudent::~GraduatedStudent()
{
    free();
}

void GraduatedStudent::setName(const char* newName)
{
    if (!newName || name == newName)
    {
        return;
    }
    delete[]name;
    name = new char[strlen(newName) + 1];
    strcpy(name, newName);
}

void GraduatedStudent::setGrades(const int* newGrades, size_t count)
{
    if (!newGrades || grades == newGrades || count == 0)
    {
        return;
    }
    delete[]grades;
    grades = new int[count];
    for (int i = 0; i < count; i++)
    {
        grades[i] = newGrades[i];
    }
    gradesCount = count;
}

void GraduatedStudent::setQuote(const char* newQuote)
{
    if (!newQuote||strlen(newQuote) > CONSTANTS::QUOTE_MAX_SIZE)
    {
        return;
    }
    strcpy(quote, newQuote);
}

const char* GraduatedStudent::getName() const
{
    return name;
}

const int* GraduatedStudent::getGrades() const
{
    return grades;
}

size_t GraduatedStudent::getGradesCount() const
{
    return gradesCount;
}

const char* GraduatedStudent::getQuote() const
{
    return quote;
}
