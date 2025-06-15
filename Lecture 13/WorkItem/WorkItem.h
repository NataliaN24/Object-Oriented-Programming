#pragma once
#include<iostream>
#pragma warning(disable:4996)

class WorkItem
{
	char* name;

	void copyFrom(const WorkItem& other);
	void free();

public:
	WorkItem();
	WorkItem(const char* name);
	WorkItem(const WorkItem& other);
	WorkItem& operator=(const WorkItem& other);
	virtual ~WorkItem();

	void setName(const char* newname);
	const char* getName()const;

	virtual bool status(long now)const=0;
	virtual void print(size_t level = 0)const = 0;
	virtual WorkItem* clone()const = 0;
};

