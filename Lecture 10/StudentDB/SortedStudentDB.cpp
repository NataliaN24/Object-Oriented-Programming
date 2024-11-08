#include "SortedStudentDB.h"

void SortedStudentDB::sortBy(comparator criteria)
{
	for (unsigned i = 0; i < size - 1; i++)
	{
		int minIndex = i;
		for (int j = i + 1; j < size; j++)
		{
			if (criteria(students[j], students[minIndex]))
			{
				minIndex=j;
			}
		}
		if (minIndex != i)
		{
			std::swap(students[i], students[minIndex]);
		}
	}
}
bool compareByName(const Student& a, const Student& b)
{
	return a.getName() < b.getName();
}

bool compareByFn(const Student& a, const Student& b)
{
	return a.getFn() < b.getFn();
}

bool compareByCourse(const Student& a, const Student& b)
{
	return a.getCourse() < b.getCourse();
}