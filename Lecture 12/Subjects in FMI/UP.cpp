#include "UP.h"

UP::UP(const MyString& subject, const MyString& lecturer, const MyString* assistants, int count, int points):
    SubjectInFMI(subject, lecturer, assistants, count, points)
{
}

bool UP::gradeToPass() const
{
    return 50 * getPassPoints() / 100;
}

void UP::getSubjectName() const
{
    std::cout << "UP" << std::endl;
}

SubjectInFMI* UP::clone() const
{
    return new UP(*this);
}
