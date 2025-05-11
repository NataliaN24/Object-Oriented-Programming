#pragma once
#include "SubjectInFMI.h"

class DSTR:public SubjectInFMI
{
public:
    DSTR(const MyString& subject, const MyString& lecturer, const MyString* assistants, int count, int points);
    virtual bool gradeToPass()const override;
    virtual void getSubjectName() const override;
    virtual SubjectInFMI* clone()const override;
};

