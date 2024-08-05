#include "EventCollection.h"

EventCollection EventCollection::eventsOnDate(const BulgarianDate& date) const
{
    EventCollection res;
    for (int i = 0; i < size; i++)
    {
        if (date.isEqualTo(events[i].getDate()) == 0)
        {
            res.addEvent(events[i]);
        }
        return res;
    }
}

int EventCollection::findEventByName(const char* name) const
{
    for (int i = 0; i < size; i++)
    {
        if (strcmp(events[i].getName(), name) == 0)
        {
            return i;
        }
   }
    return -1;
}

bool EventCollection::addEvent(const Event& event)
{
    if (size >= MAX_EVENT_SIZE)
    {
        return false;
    }
    events[size++] = event;
    return true;
}

bool EventCollection::removeEvent(const char* name)
{
    int index = findEventByName(name);
    if (index == -1)
    {
        return false;
    }
    events[index] = events[size - 1];
    size--;
    return true;
}

const Event& EventCollection::getByName(const char* name) const
{
    int index = findEventByName(name);
    if (index == -1)
    {
        return Event();
    }
    return events[index];
}

void EventCollection::print() const
{
    for (int i = 0; i < size; i++)
    {
        std::cout << events[i].getName() << std::endl;
    }
}