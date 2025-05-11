#include "DSTR.h"

DSTR::DSTR(const MyString& subject, const MyString& lecturer, const MyString* assistants, int count, int points)
	: SubjectInFMI(subject, lecturer, assistants, count, points)
{
}

bool DSTR::gradeToPass() const
{
	return 60 * getPassPoints() / 100;
}

void DSTR::getSubjectName() const
{
	std::cout << "DSTR" << std::endl;
}

SubjectInFMI* DSTR::clone() const
{
	return new DSTR(*this);
}
