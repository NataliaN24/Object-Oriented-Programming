#pragma once
#include"WorkItem.h"

class TaskGroup:public WorkItem
{
	WorkItem** tasks;
	int size;
	int capacity;

	void copyFrom(const TaskGroup& other);
	void free();
	void resize();
public:
	TaskGroup(const char* name);
	TaskGroup();
	TaskGroup(const TaskGroup& other);
	TaskGroup& operator=(const TaskGroup& other);
	~TaskGroup();

	void addTask(const WorkItem& task);
	virtual WorkItem* clone()const override;
	virtual bool status(long now)const override;
	virtual void print(size_t level = 0)const override;
};

bool allDone(WorkItem** tasks, int n, int now);