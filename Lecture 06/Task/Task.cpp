#include "Task.h"

Task::Task() :description(nullptr), priority(1), minutes(0), status(false) {
	description = new char[1];
	description[0] = '\0';
}

Task::Task(const char* description, size_t priority, unsigned int min)
{
		this->description = new char[strlen(description) + 1];
		strcpy(this->description, description);
		this->priority = priority;
		this->minutes = min;
		status = false;
}

void Task::free()
{
	delete[]description;
}

Task::~Task()
{
	free();
}

void Task::changeSatusToDone()
{
	status = true;
}

void Task::writeToFile(std::ofstream& ofs)
{
	if (!ofs.is_open()) {
		throw("Error opening the file!");
	}
	ofs << description << '\n' << priority << ' ' << minutes << ' ' << status << '\n';
}

Task::Task(std::ifstream& ifs)
{
	char buffer[1024];
	ifs.getline(buffer, 1024);
	description = new char[strlen(buffer) + 1];
	strcpy(description, buffer);
	ifs >> priority >> minutes >> status;
	ifs.ignore();
}

const char* Task::getDescr() const
{
	return description;
}

bool Task::getStatus() const
{
	return status;
}

const Task& Task::compare(const Task& rhs)const
{
	if (priority > rhs.priority)
	{
		return *this;
	}
	else if (priority < rhs.priority)
	{
		return rhs;
	}
	else
	{
		if (minutes > rhs.minutes) {
			return rhs;
		}
		else {
			return *this;
		}
	}
}
