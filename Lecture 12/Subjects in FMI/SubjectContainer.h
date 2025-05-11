#pragma once
#include"SubjectInFMI.h"

class SubjectContainer
{
	SubjectInFMI** subjects;
	int count;
	int capacity;

	void free();
	void copyFrom(const SubjectContainer& other);
	void resize();
public:
	SubjectContainer();
	SubjectContainer(const SubjectContainer& other);
	SubjectContainer(int cap);
	SubjectContainer& operator=(const SubjectContainer& other);
	~SubjectContainer();

	int getCount()const;
	void addSubject(const SubjectInFMI& subj);
	SubjectInFMI* getTheMostFamousSubject()const;
};

