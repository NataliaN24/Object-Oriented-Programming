#include "SubjectContainer.h"

void SubjectContainer::free()
{
    for (int i = 0; i < count; ++i)
        delete subjects[i];
    delete[] subjects;
}

void SubjectContainer::copyFrom(const SubjectContainer& other)
{
    count = other.count;
    capacity = other.capacity;
    subjects = new SubjectInFMI * [capacity];
    for (int i = 0; i < count; ++i)
        subjects[i] = other.subjects[i]->clone();
}

void SubjectContainer::resize()
{
    capacity *= 2;
    SubjectInFMI** newSubjects = new SubjectInFMI * [capacity];
    for (int i = 0; i < count; ++i)
        newSubjects[i] = subjects[i];
    delete[] subjects;
    subjects = newSubjects;
}

SubjectContainer::SubjectContainer() : subjects(nullptr), count(0), capacity(4) {
    subjects = new SubjectInFMI * [capacity];
}

SubjectContainer::SubjectContainer(const SubjectContainer& other)
{
    copyFrom(other);
}

SubjectContainer::SubjectContainer(int cap): subjects(nullptr), count(0), capacity(cap) 
{
    subjects = new SubjectInFMI * [capacity];
}

SubjectContainer& SubjectContainer::operator=(const SubjectContainer& other)
{
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

SubjectContainer::~SubjectContainer()
{
    free();
}

int SubjectContainer::getCount() const
{
    return count;
}

void SubjectContainer::addSubject(const SubjectInFMI& subj)
{
    if (count == capacity)
    {
        resize();
    }
    subjects[count++] = subj.clone();
}

SubjectInFMI* SubjectContainer::getTheMostFamousSubject() const
{
    int maxOccurence = 0;
    SubjectInFMI* mostFamous = nullptr;
    for (int i = 0; i < count; i++)
    {
        int currentCount = 0;
        for (int j = 0; j < count; j++)
        {
            if (strcmp(subjects[i]->getLecturerName().c_str(), subjects[j]->getLecturerName().c_str()) == 0)
            {
                currentCount++;
             }
        }
        if (currentCount > maxOccurence)
        {
            maxOccurence = currentCount;
            mostFamous = subjects[i];
        }
    }
    return mostFamous;
}
