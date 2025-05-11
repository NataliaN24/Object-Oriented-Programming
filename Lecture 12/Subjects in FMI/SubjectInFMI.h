#pragma once
#include<iostream>
#include"MyString.h"

class SubjectInFMI
{
	MyString subject;
	MyString teacher;
	MyString* assistantNames;
    int assistantCount;
	int points;

	void copyFrom(const SubjectInFMI& other);
	void free();
public:
    SubjectInFMI();
    SubjectInFMI(const MyString& subject, const MyString& lecturer, const MyString* assistants, int count, int points);
    SubjectInFMI(const SubjectInFMI& other);
    SubjectInFMI& operator=(const SubjectInFMI& other);
    virtual ~SubjectInFMI();

    const MyString& getLecturerName() const;
    int getPassPoints() const;
    int getAssistantCount() const;
    const MyString* getAssistantNames() const;

    virtual bool gradeToPass()const=0;
    virtual  void getSubjectName() const = 0;
    virtual SubjectInFMI* clone()const = 0;

};

