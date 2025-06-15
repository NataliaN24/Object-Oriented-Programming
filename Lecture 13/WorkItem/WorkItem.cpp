#include "WorkItem.h"

void WorkItem::copyFrom(const WorkItem& other)
{
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);
}

void WorkItem::free()
{
    delete[]name;
}

WorkItem::WorkItem()
{
    name = new char[1];
    name[0] = '\0';
}

WorkItem::WorkItem(const char* name)
{
    setName(name);
}

WorkItem::WorkItem(const WorkItem& other)
{
    copyFrom(other);
}

WorkItem& WorkItem::operator=(const WorkItem& other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}

WorkItem::~WorkItem()
{
    free();
}

void WorkItem::setName(const char* name)
{
    if (!name)
    {
        throw("error");
    }
    delete[]this->name;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

const char* WorkItem::getName() const
{
    return name;
}
