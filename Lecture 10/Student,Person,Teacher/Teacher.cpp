#include "Teacher.h"

static char** copyArrayOfString(const char* const* strings, size_t size)
{
	char** res = new char*[size];
	for (size_t i = 0; i < size; ++i)
	{
		res[i] = new char[strlen(strings[i]) + 1];
		strcpy(res[i], strings[i]);
	}
	return res;
}
static void freeArrayOfStrings(char** strings, unsigned size)
{
	for (size_t i = 0; i < size; ++i)
	{
		delete strings[i];
	}
	delete[]strings;

}
void Teacher::free()
{
	freeArrayOfStrings(subject, subjectsCount);
}

void Teacher::copyFrom(const Teacher& other)
{
	subject=copyArrayOfString(other.subject,other.subjectsCount);
	subjectsCount = other.subjectsCount;
}

void Teacher::moveFrom(Teacher&& other)
{
	subject = other.subject;
	subjectsCount = other.subjectsCount;

	other.subject = nullptr;
	other.subjectsCount = 0;
}

Teacher::Teacher(const char* name, int age, const char* const* subjects, size_t subjectsCount):Person(name,age)
{
	this->subject = copyArrayOfString(subjects, subjectsCount);
	this->subjectsCount = subjectsCount;
}

Teacher::Teacher(const Teacher& other)
{
	copyFrom(other);
}

Teacher& Teacher::operator=(const Teacher& other)
{
	if (this != &other)
	{
		Person::operator=(other);
		free(); 
		copyFrom(other); 
	}
	return *this;
}

Teacher::Teacher(Teacher&& other) noexcept
{
	moveFrom(std::move(other));
}

Teacher& Teacher::operator=(Teacher&& other) noexcept
{
	if (this != &other)
	{
		Person::operator=(std::move(other));
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

Teacher::~Teacher()
{
	free();
}
