#pragma once

namespace CONSTANTS
{
	constexpr int QUOTE_MAX_SIZE = 30;
}

class GraduatedStudent
{
	char* name=nullptr;
	int* grades = nullptr;
	size_t gradesCount = 0;
	char quote[CONSTANTS::QUOTE_MAX_SIZE + 1] = " ";

	void copyFrom(const  GraduatedStudent& other);
	void free();

public:

	GraduatedStudent(const char* name, const int* grades, size_t count, const char* quote);
	GraduatedStudent(const GraduatedStudent& other);
	GraduatedStudent& operator=(const GraduatedStudent& other);
	~GraduatedStudent();

	void setName(const char* newName);
	void setGrades(const int* newGrades, size_t count);
	void setQuote(const char* newQuote);
	const char* getName()const;
	const int*getGrades()const;
	size_t getGradesCount()const;
	const char* getQuote()const;
};