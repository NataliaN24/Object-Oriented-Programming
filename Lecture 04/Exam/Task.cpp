#include "Task.h"

void Task::free()
{
    delete[] name;
    delete[] description;
    name = nullptr;
    description = nullptr;
    points = 0;
}

void Task::copyFrom(const Task& other)
{
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);
    description = new char[strlen(other.description) + 1];
    strcpy(description, other.description);
    points = other.points;
}

Task::Task()
{
    name = nullptr;
    description = nullptr;
    points = 0;
}

Task::Task(const Task& other)
{
    copyFrom(other);
}

Task& Task::operator=(const Task& other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}

Task::Task(const char* name, const char* descr, unsigned int p)
{
    changeName(name);
    changeDescription(descr);
    changePoints(p);

}

void Task::changeDescription(const char* newDescr)
{
    if (this->description && strcmp(this->description, newDescr) == 0)
    {
        return;
    }
    if (!newDescr || strlen(newDescr) == 0)
    {
        throw std::invalid_argument("Invalid description");
    }
    delete[]description;
    description = new char[strlen(newDescr) + 1];
    strcpy(description, newDescr);
}

void Task::changeName(const char* newName)
{
    if (this->name && strcmp(this->name, newName) == 0)
    {
        return;
    }
    if (!newName || strlen(newName) == 0) 
    { 
        throw std::invalid_argument("Invalid name");
    }
    delete[]name;
    name = new char[strlen(newName) + 1];
    strcpy(name, newName);

}

void Task::changePoints(unsigned int newPoints)
{
    points = newPoints;
}

void Task::writeTaskToFile(std::ofstream& ofs)const
{
    size_t nameLen = strlen(name) + 1;
    size_t descLen = strlen(description) + 1;
    ofs.write((const char*)&nameLen, sizeof(nameLen));
    ofs.write(name, nameLen);
    ofs.write((const char*)&descLen, sizeof(descLen));
    ofs.write(description, descLen);
    ofs.write((const char*)&points, sizeof(points));
}

void Task::readTaskFromFile(std::ifstream& ifs)
{
    free();
    size_t nameLen;
    size_t descrLen;
    ifs.read((char*)&nameLen, sizeof(nameLen));
    name = new char[nameLen];
    ifs.read(name, nameLen);
    name[nameLen] = '\0';
    ifs.read((char*)&descrLen, sizeof(descrLen));
    description = new char[descrLen];
    ifs.read(description, descrLen);
    description[descrLen] = '\0';
    ifs.read((char*)&points, sizeof(points));
}

unsigned int Task::getPoints() const
{
    return points;
}

Task::~Task()
{
    free();
}
