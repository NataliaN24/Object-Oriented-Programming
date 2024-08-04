#include "Event.h"

void Event::setName(const char* name)
{
    if (strlen(name) > 20)
    {
        return;
    }
    else
    {
        strcpy(this->name, name);
    }
}

void Event::validateTimes()
{
    if (compareTimes(startTime, endTime) <= -1)
    {
        std::swap(startTime, endTime);
    }
}

Event::Event():Event(" ",1,1,1,0,0,0,0,0,0)
{
}

Event::Event(const char* name, const Date& date, const Time& start, const Time& eend)
{
    setName(name);
    validateTimes();
}

Event::Event(const char* name, unsigned day, unsigned month, unsigned year, unsigned startHours, unsigned startMins, unsigned startSc, unsigned endHours, unsigned endMin, unsigned endSec)
{
    setName(name);
    validateTimes();
}

const char* Event::getName() const
{
    return name;
}

const Date& Event::getDate() const
{
    return date;
}

const Time& Event::getStartTime() const
{
    return startTime;
}

const Time& Event::getEndTime() const
{
    return endTime;
}
