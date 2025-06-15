#include "SingleTask.h"

SingleTask::SingleTask(const char* name, long long startTime, long long duration):WorkItem(name)
{
    this->startTime = startTime;
    this->duration = duration;
}

bool SingleTask::status(long now) const
{
    return (startTime + duration <= now);
}

void SingleTask::print(size_t level) const
{
    for (int i = 0; i < level; i++)
    {
        std::cout << " " << "SingleTask" << getName() << '\n';
    }
}

long long SingleTask::getStartTime() const
{
    return startTime;
}

long long SingleTask::getDuration() const
{
    return duration;
}

WorkItem* SingleTask::clone() const
{
    return new SingleTask(*this);
}
