#include "OOP.h"



OOP::OOP(const MyString& subject, const MyString& lecturer, const MyString* assistants, int count, int points,int bonus):
    SubjectInFMI(subject, lecturer, assistants, count, points+bonus)
{
}

bool OOP::gradeToPass() const
{
    return 80 * getPassPoints() / 100;
}

void OOP::getSubjectName() const
{
    std::cout << "OOP" << std::endl;
}

SubjectInFMI* OOP::clone() const
{
    return new OOP(*this);
}
