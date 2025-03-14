#include "Exam.h"

Exam::Exam():minPointsToPass(0),countOfTasks(0)
{
}

Exam::Exam(const Task* tasks, size_t number, size_t points)
{
    setTasks(tasks, number);
    setMinPoints(points);
}

void Exam::setTasks(const Task* tasks, size_t count)
{
    if (count >= maxTasks)
    {
        return;
    }
    for (int i = 0; i < count; ++i)
    {
        this->tasks[i] = tasks[i];
    }
}

void Exam::setMinPoints(size_t newMin)
{
    minPointsToPass = newMin;
}

void Exam::addTask(const Task& newTask)
{
    if (countOfTasks >= maxTasks)
    {
        return;
    }
    tasks[countOfTasks++] = newTask;
}

void Exam::writeToFile(const char* fileName)const
{
    std::ofstream ofs(fileName, std::ios::binary | std::ios::out);
    if (!ofs.is_open())
    {
        throw("error!");
    }
    if (countOfTasks >= maxTasks)
    {
        return;
    }
    ofs.write((const char*)&countOfTasks, sizeof(countOfTasks));
    for (int i = 0; i < countOfTasks; i++)
    {
        tasks[i].writeTaskToFile(ofs);
    }
    ofs.write((const char*)&minPointsToPass, sizeof(minPointsToPass));
}

void Exam::readFromFile(const char* fileName)
{

    std::ifstream ifs(fileName, std::ios::binary | std::ios::in);
    if (!ifs.is_open())
    {
        throw("error!");
    }
    ifs.read((char*)&countOfTasks, sizeof(countOfTasks));

    if (countOfTasks >= maxTasks) 
    {
        countOfTasks = maxTasks;
    }
    for (int i = 0; i < countOfTasks; i++)
    {
        tasks[i].readTaskFromFile(ifs);
    }
    ifs.read((char*)&minPointsToPass, sizeof(minPointsToPass));
}

void Exam::changeMin(size_t newMin) 
{
    minPointsToPass = newMin;
}

size_t Exam::getMax() const
{
    size_t maxPoints = 0;
    for (int i = 0; i < countOfTasks; i++)
    {
        maxPoints += tasks[i].getPoints();
    }
    return maxPoints;
}
