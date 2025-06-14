#pragma once
#include"my_string.h"

class EventBase
{
public:
	virtual void print()const=0;
	virtual void serialize()const = 0;
	virtual ~EventBase() = default;
	virtual EventBase* clone()const = 0;
};

