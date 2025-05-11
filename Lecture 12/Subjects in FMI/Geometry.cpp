#include "Geometry.h"

Geometry::Geometry(const MyString& subject, const MyString& lecturer, const MyString* assistants, int count, int points):
    SubjectInFMI(subject,lecturer,assistants,count,points)
{
}

bool Geometry::gradeToPass() const
{
    return 75 * getPassPoints() / 100;
}

void Geometry::getSubjectName() const
{
    std::cout << "Geometry" << std::endl;
}

SubjectInFMI* Geometry::clone() const
{
    return new Geometry(*this);
}
