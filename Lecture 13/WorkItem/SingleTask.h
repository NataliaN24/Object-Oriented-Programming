#pragma once
#include"WorkItem.h"

class SingleTask:public WorkItem
{
	long long startTime;
	long long duration;

public:

	SingleTask(const char* name, long long startTime, long long duration);
	virtual bool status(long now)const override;
	virtual void print(size_t level = 0)const override;
	long long getStartTime()const;
	long long getDuration()const;
	virtual WorkItem* clone()const override;
};

