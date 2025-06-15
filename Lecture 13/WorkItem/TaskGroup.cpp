#include "TaskGroup.h"

void TaskGroup::copyFrom(const TaskGroup& other)
{
    size = other.size;
    capacity = other.capacity;
    tasks = new WorkItem * [capacity];
    for (int i = 0; i < size; ++i) {
        tasks[i] = other.tasks[i]->clone();
    }
}

void TaskGroup::free()
{
    for (int i = 0; i < size; ++i) {
        delete tasks[i];
    }
    delete[] tasks;
    size = 0;
    capacity = 0;
}

void TaskGroup::resize()
{
    capacity *= 2;
    WorkItem** newTasks = new WorkItem * [capacity];
    for (int i = 0; i < size; ++i) {
        newTasks[i] = tasks[i];
    }
    delete[] tasks;
    tasks = newTasks;
}

TaskGroup::TaskGroup(const char* name) : WorkItem(name), size(0), capacity(8) {
    tasks = new WorkItem * [capacity];
}

TaskGroup::TaskGroup(const TaskGroup& other):WorkItem(other)
{
    copyFrom(other);
}

TaskGroup& TaskGroup::operator=(const TaskGroup& other)
{
    if (this != &other) {
        free();
        copyFrom(other);
        WorkItem::operator=(other);
    }
    return *this;
}

TaskGroup::~TaskGroup()
{
    free();
}

void TaskGroup::addTask(const WorkItem& task)
{
    if (size >= capacity) {
        resize();
    }
    tasks[size++] = task.clone();
}

WorkItem* TaskGroup::clone() const
{
    return new TaskGroup(*this);
}

bool TaskGroup::status(long now) const
{
    for (int i = 0; i < size; i++)
    {
        if (!tasks[i]->status(now))
        {
            return false;
        }
   }
    return true;
}

void TaskGroup::print(size_t level) const
{
    for (size_t i = 0; i < level; ++i) std::cout << ' ';
    std::cout << getName() << " (Group)\n";
    for (int i = 0; i < size; ++i) {
        tasks[i]->print(level + 2);
    }
}
bool allDone(WorkItem** tasks, int n, int now) {
    for (int i = 0; i < n; ++i) {
        if (!tasks[i]->status(now))
            return false;
    }
    return true;
}