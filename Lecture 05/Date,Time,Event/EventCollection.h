#pragma once
#include"Event.h"
namespace
{
	constexpr int MAX_EVENT_SIZE = 30;
}

class EventCollection
{
	Event events[MAX_EVENT_SIZE];
	size_t size = 0;

	EventCollection eventsOnDate(const BulgarianDate& date)const;
	int findEventByName(const char* name)const;
public:

	bool addEvent(const Event& event);
	bool removeEvent(const char* name);
	const Event& getByName(const char* name)const;
	void print()const;
};