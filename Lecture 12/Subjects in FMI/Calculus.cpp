#include "Calculus.h"

Calculus::Calculus(const MyString& subject, const MyString& lecturer, const MyString* assistants, int count, int points):
	SubjectInFMI(subject, lecturer, assistants, count, points)
{
}

bool Calculus::gradeToPass() const
{
	return 70 * getPassPoints() / 100;
}

void Calculus::getSubjectName() const
{
	std::cout << "Calculus" << std::endl;
}

SubjectInFMI* Calculus::clone() const
{
	return new Calculus(*this);
}
