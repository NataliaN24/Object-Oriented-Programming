#pragma once
#include"SubjectInFMI.h"

class OOP:public SubjectInFMI
{
	int bonusPoints;
public:
	OOP(const MyString& subject, const MyString& lecturer, const MyString* assistants, int count, int points,int bonus);
	virtual bool gradeToPass()const override;
	virtual void getSubjectName() const override;
	virtual SubjectInFMI* clone()const override;

};

