#pragma once
#include"Date.h"
#include"Time.h"

typedef BulgarianDate Date;

class Event
{
	char name[21];
	Date date;
	Time startTime;
	Time endTime;

	void setName(const char* name);
	void validateTimes();

public:
	Event();
	Event(const char* name, const Date& date, const Time& start, const Time& eend);
	Event(const char* name, unsigned day, unsigned month, unsigned year, unsigned startHours, unsigned startMins,
		unsigned startSc, unsigned endHours, unsigned endMin, unsigned endSec);
	const char* getName()const;
	const Date& getDate()const;
	const Time& getStartTime()const;
	const Time& getEndTime()const;
};

