#include "SubjectInFMI.h"

void SubjectInFMI::copyFrom(const SubjectInFMI& other)
{
    subject = other.subject;
    teacher = other.teacher;
    assistantCount = other.assistantCount;
    points = other.points;

    assistantNames = new MyString[assistantCount];
    for (int i = 0; i < assistantCount; ++i)
        assistantNames[i] = other.assistantNames[i];
}

void SubjectInFMI::free()
{
    delete[] assistantNames;
    assistantNames = nullptr;
}

SubjectInFMI::SubjectInFMI():subject(" "),teacher(""),assistantNames(nullptr),assistantCount(0),points(0)
{
}

SubjectInFMI::SubjectInFMI(const MyString& subject, const MyString& lecturer, const MyString* assistants, int count, int points)
    : subject(subject), teacher(lecturer), assistantCount(count), points(points) 
{
    assistantNames = new MyString[assistantCount];
    for (int i = 0; i < assistantCount; ++i)
        assistantNames[i] = assistants[i];
}

SubjectInFMI::SubjectInFMI(const SubjectInFMI& other)
{
    copyFrom(other);
}

SubjectInFMI& SubjectInFMI::operator=(const SubjectInFMI& other)
{
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

SubjectInFMI::~SubjectInFMI()
{
    free();
}

const MyString& SubjectInFMI::getLecturerName() const
{
    return teacher;
}

int SubjectInFMI::getPassPoints() const
{
    return points;
}

int SubjectInFMI::getAssistantCount() const
{
    return assistantCount;
}

const MyString* SubjectInFMI::getAssistantNames() const
{
    return assistantNames;
}

